#include<vector>
#include<string>
#include<iostream>
#include<set>
#include<map>

// Definições de unidades para uso na análise semântica
#ifndef UNIT_DEFS
#define UNIT_DEFS
#define UNIT_METERS 1
#define UNIT_SECONDS 2
#define UNIT_M_PER_S 3
#define UNIT_SQ_METER 4
#define UNIT_ADIMENSIONAL 5
#endif

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

class ConstString: public Node {
    protected:
        string value;

    public:
        ConstString(string value) {
            this->value = value;
        }

        string astLabel() override {
            string res;
            for (char c : value) {
                if (c == '"') {
                    res += "\\\"";
                } else {
                    res += c;
                }
            }
            return res;
        }
};

class CompOp: public Node {
    protected:
        string oper;
    public:
        CompOp(Node *left, string oper, Node *right) {
            this->oper = oper;
            this->append(left);
            this->append(right);
        }
        string astLabel() override {
            return oper;
        }
};

class For: public Node {
    public:
        For(Node *init, Node *cond, Node *incr, Node *body) {
            if (init) this->append(init);
            if (cond) this->append(cond);
            if (incr) this->append(incr);
            if (body) this->append(body);
        }
        string astLabel() override {
            return "For";
        }
};

class If: public Node {
    public:
        If(Node *cond, Node *then_stmts, Node *else_stmts = NULL) {
            if (cond) this->append(cond);
            if (then_stmts) this->append(then_stmts);
            if (else_stmts) this->append(else_stmts);
        }
        string astLabel() override {
            return "If";
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
        
        char getOper() {
            return oper;
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
            r.append("Print ");
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
            if (n == NULL) return;

            //declara o nó da árvore no grafo
            cout << "N" << (long)(n) << 
                    "[label=\"" << n->astLabel() << "\"]" <<
            "\n";

            for(Node* c : n->children){
                if (c == NULL) continue;
                
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
            printAstRecursive(this);
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

        int getUnit() {
            return unit;
        }

        string getType() {
            return type;
        }
};

struct Symbol {
    string name;
    string type;
    int unit;
};

class SemanticVarDecl {
    private:
        map<string, Symbol> symbolTable;

        // Método auxiliar para inferir a unidade de uma expressão
        int inferUnit(Node *n) {
            if (n == NULL) return UNIT_ADIMENSIONAL;

            // Constantes são adimensionais
            if (dynamic_cast<ConstInteger*>(n) || dynamic_cast<ConstDouble*>(n)) {
                return UNIT_ADIMENSIONAL;
            }

            // Variáveis retornam sua unidade da tabela
            if (Load *l = dynamic_cast<Load*>(n)) {
                if (symbolTable.count(l->getName())) {
                    return symbolTable[l->getName()].unit;
                }
                return UNIT_ADIMENSIONAL;
            }

            // Operações binárias aplicam as regras físicas
            if (BinaryOp *b = dynamic_cast<BinaryOp*>(n)) {
                int u1 = inferUnit(b->getChildren()[0]);
                int u2 = inferUnit(b->getChildren()[1]);
                char op = b->getOper();

                if (op == '+' || op == '-') {
                    if (u1 == u2) return u1;
                    // Permite somar/subtrair adimensional (ex: tempo - 5)
                    if (u2 == UNIT_ADIMENSIONAL) return u1;
                    if (u1 == UNIT_ADIMENSIONAL) return u2;
                    
                    extern char* build_file_name;
                    cerr << build_file_name << ":" << b->getLineNo() << ": "
                         << "Semantic Error: Incompatible units in operation '" << op << "'\n";
                    return UNIT_ADIMENSIONAL;
                }

                if (op == '*') {
                    if (u1 == UNIT_ADIMENSIONAL) return u2;
                    if (u2 == UNIT_ADIMENSIONAL) return u1;
                    if (u1 == UNIT_METERS && u2 == UNIT_METERS) return UNIT_SQ_METER;
                    if ((u1 == UNIT_M_PER_S && u2 == UNIT_SECONDS) || (u1 == UNIT_SECONDS && u2 == UNIT_M_PER_S)) return UNIT_METERS;
                    
                    extern char* build_file_name;
                    cerr << build_file_name << ":" << b->getLineNo() << ": "
                         << "Semantic Error: Invalid multiplication of units\n";
                    return UNIT_ADIMENSIONAL;
                }

                if (op == '/') {
                    if (u2 == UNIT_ADIMENSIONAL) return u1;
                    if (u1 == UNIT_METERS && u2 == UNIT_SECONDS) return UNIT_M_PER_S;
                    if (u1 == UNIT_METERS && u2 == UNIT_METERS) return UNIT_ADIMENSIONAL;                    
                    if (u1 == UNIT_METERS && u2 == UNIT_M_PER_S) return UNIT_SECONDS;
                    
                    extern char* build_file_name;
                    cerr << build_file_name << ":" << b->getLineNo() << ": "
                         << "Semantic Error: Invalid division of units\n";
                    return UNIT_ADIMENSIONAL;
                }
            }
            
            return UNIT_ADIMENSIONAL;
        }

    public:
        void check(Node *n) {
            if (n == NULL) return; 

            for(Node *c : n->getChildren()){
                check(c);
            }

            // 1. Registra variáveis
            VarDcl *vardcl = dynamic_cast<VarDcl*>(n);
            if(vardcl != NULL) {
                Symbol s;
                s.name = vardcl->getName();
                s.unit = vardcl->getUnit();
                s.type = vardcl->getType();
                symbolTable[s.name] = s;
                
                // Se houver inicialização, verifica compatibilidade
                if (vardcl->getChildren().size() > 0) {
                    int exprUnit = inferUnit(vardcl->getChildren()[0]);
                    if (exprUnit != s.unit && exprUnit != UNIT_ADIMENSIONAL && s.unit != UNIT_ADIMENSIONAL) {
                         extern char* build_file_name;
                         cerr << build_file_name << ":" << vardcl->getLineNo() << ": "
                              << "Semantic Error: Initializing variable '" << s.name << "' with incompatible unit\n";
                    }
                }
            }

            // 2. Verifica atribuições e compatibilidade de unidades
            Store *store = dynamic_cast<Store*>(n);
            if(store != NULL) {
                if(symbolTable.count(store->getName()) == 0) {
                    extern char* build_file_name;
                    cerr << build_file_name << ":" << store->getLineNo() << ": ";
                    cout << "Semantic Error: Variable '" << store->getName() << "' assigned before declaration\n";
                } else {
                    // Verificação de Unidade na Atribuição
                    int varUnit = symbolTable[store->getName()].unit;
                    int exprUnit = inferUnit(store->getChildren()[0]);

                    if (varUnit != exprUnit && exprUnit != UNIT_ADIMENSIONAL && varUnit != UNIT_ADIMENSIONAL) {
                        extern char* build_file_name;
                        cerr << build_file_name << ":" << store->getLineNo() << ": "
                             << "Semantic Error: Assigning incompatible unit to '" << store->getName() << "'\n";
                    }
                }
            }


            
            // 3. Verifica usos
            Load *load = dynamic_cast<Load*>(n);
            if(load != NULL) {
                if(symbolTable.count(load->getName()) == 0) {
                    extern char* build_file_name;
                    cerr << build_file_name << ":" << load->getLineNo() << ": ";
                    cout << "Semantic Error: Variable '" << load->getName() << "' used before declaration\n";
                }
            }


        }
                
        void printFoundVars() {
            cout << "--- Symbol Table ---\n";
            for(auto const& [key, val] : symbolTable) {
                cout << "Var: " << key << " | Type: " << val.type << " | Unit ID: " << val.unit << "\n";
            }
            cout << "--------------------\n";
        }

};