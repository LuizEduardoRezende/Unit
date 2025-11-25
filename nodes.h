#include<vector>
#include<string>
#include<iostream>
#include<set>

extern int yylineno;

using namespace std;

class Program;

class Node {
    protected:
        vector<Node*> children;
        int lineno;

    public:
        Node() {
            lineno = yylineno;
        }

        int getLineNo() {
            return lineno;
        }

        void append(Node *n){
            children.push_back(n);
        }

        virtual string astLabel(){
            return "";
        }

        vector<Node*> &getChildren(){
            return children;
        }

    friend class Program;
};

class Load: public Node {
    protected:
        string name;

    public:
        Load(string name) {
            this->name = name;
        }
        string astLabel() override {
            string r;
            r.append("Load ");
            r.append(name);
            return r;
        }

        string getName() {
            return name;
        }
};

class Store: public Node {
    protected:
        string name;

    public:
        Store(string name, Node *expr) {
            this->name = name;
            this->append(expr);
        }

        string astLabel() override {
            string r;
            r.append("Store ");
            r.append(name);
            return r;
        }
        
        string getName() {
            return name;
        }
};

class ConstInteger: public Node {
    protected:
        int value;

    public:
        ConstInteger(int value) {
            this->value = value;
        }

        string astLabel() override {
            return to_string(value);
        }
};

class ConstDouble: public Node {
    protected:
        double value;

    public:
        ConstDouble(double value) {
            this->value = value;
        }

        string astLabel() override {
            return to_string(value);
        }
};

class BinaryOp: public Node {
    protected:
        char oper;

    public:
        BinaryOp(Node *left, char oper, Node *right) {
            this->oper = oper;
            this->append(left);
            this->append(right);
        }
    string astLabel() override {
            string r;
            r.push_back(oper);
            return r;
        }

};

class Print: public Node {
    protected:

    public:
        Print(Node *expr) {
            this->append(expr);
        }
        string astLabel() override {
            string r;
            r.append("Print");
            r.append(children[0]->astLabel());
            return r;
        }
};

class Stmts: public Node {
    protected:

    public:
        Stmts(Node *stmt) {
            this->append(stmt);
        }

        string astLabel() override {
            string r;
            r.append("Stmts");
            return r;
        }
};

class Program: public Node {
    protected:
        void printAstRecursive(Node *n){

            //declara o nó da árvore no grafo
            cout << "N" << (long)(n) << 
                    "[label=\"" << n->astLabel() << "\"]" <<
            "\n";

            for(Node* c : n->children){
                
                cout << "N" << (long)(n) << "--" <<
                        "N" << (long)(c) << "\n";

                printAstRecursive(c);
            }
        }

    public:
        Program(Node *stmts) {
            this->append(stmts);
        }
        void printAst(){
            cout << "graph {\n";
            printAstRecursive(children[0]);
            cout << "}\n";
        }

    string astLabel() override {
            string r;
            r.append("Program");
            return r;
        }
};

class VarDcl: public Node {
    protected:
        string name;
        int unit;
        string type;

    public:
        VarDcl(string name, int unit, string type, Node *expr = NULL) {
            this->name = name;
            this->unit = unit;
            this->type = type;
            if (expr != NULL) {
                this->append(expr);
            }
        }
        string astLabel() override {
            string r;
            r.append("VarDecl ");
            r.append(name);
            return r;
        }

        string getName() {
            return name;
        }
};


class SemanticVarDecl {
    private:
        set<string> vars;
    public:
        void check(Node *n) {
            for(Node *c : n->getChildren()){
                check(c);
            }

            Store *store = dynamic_cast<Store*>(n);
            if(store != NULL) {
                vars.insert(store->getName());
            }

            Load *load = dynamic_cast<Load*>(n);
            if(load != NULL) {
                if(vars.count(load->getName()) == 0) {
                    extern char* build_file_name;
                    cerr << build_file_name << ":" 
                        << load->getLineNo() << ": ";
                    cout << "Semantic Error: Variable '" << load->getName() << "' used before declaration\n";
                    
                }
            }

        }
        
        void printFoundVars() {
            for(string v : vars) {
                cout << "Found: " << v << "\n";
            }
        }

};