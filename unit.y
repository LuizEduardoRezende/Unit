%{
#include "nodes.h"
int yylex(void);
int yyerror(const char *s);

extern int error_count;

#define UNIT_METERS 1
#define UNIT_SECONDS 2
#define UNIT_M_PER_S 3
#define UNIT_SQ_METER 4
#define UNIT_ADIMENSIONAL 5
%}

%define parse.error verbose

%token T_FLOAT T_INT T_FOR T_IF T_ELSE T_PRINTF
%token <name> T_STRING_LITERAL T_ID
%token <flt> T_FLOAT_LITERAL
%token <integer> T_INT_LITERAL
%token T_LE T_GE T_EQ T_NE
%token T_UNIT_TYPE

%type <unit> T_UNIT_TYPE
%type <node> program statements statement declaration_statement assignment_statement for_statement if_statement print_statement for_assignment_statement
%type <node> expression primary
%type <node> condition

%start program

%union {
    int integer;
    float flt;
    char *name;
    int unit; 
    Node *node;
}

%%

program: statements {    
    Program pg($statements);
    pg.printAst();

    SemanticVarDecl vd;
    vd.check(&pg);
    //vd.printFoundVars();
}

statements: statements[ss] statement        { $ss->append($statement); $$ = $ss; }
statements: statement                       { $$ = new Stmts($statement);}

statement: declaration_statement { $$ = $1; }
statement: assignment_statement { $$ = $1; }
statement: for_statement { $$ = $1; }
statement: if_statement { $$ = $1; } 
statement: print_statement { $$ = $1; }


// --- 1. DECLARAÇÃO DE VARIÁVEL (Foco: Unidade no Tipo) ---
declaration_statement:
    // ex: float vel;
    T_FLOAT T_ID[name] ';' {
        $$ = new VarDcl($name, UNIT_ADIMENSIONAL, "float");
    }

declaration_statement:   
    // ex: float vel = 0.0;
    T_FLOAT T_ID[name] '=' expression[val] ';' {
        $$ = new VarDcl($name, UNIT_ADIMENSIONAL, "float", $val);
    }

declaration_statement:
    // ex: float:seconds tempo_gasto;
    T_FLOAT ':' T_UNIT_TYPE[unit] T_ID[name] ';' { 
        $$ = new VarDcl($name, $unit, "float");
    }

declaration_statement:
    // ex: float:seconds tempo = distancia / velocidade;
    T_FLOAT ':' T_UNIT_TYPE[unit] T_ID[name] '=' expression[val] ';' {
        $$ = new VarDcl($name, $unit, "float", $val);
    }

declaration_statement:
    // ex: int i;
    T_INT T_ID[name] ';' {
        $$ = new VarDcl($name, UNIT_ADIMENSIONAL, "int");
    }

declaration_statement:
    // ex: int i = 0;
    T_INT T_ID[name] '=' expression[val] ';' {
        $$ = new VarDcl($name, UNIT_ADIMENSIONAL, "int", $val);
    }

declaration_statement:
    // ex: int:meters dist;
    T_INT ':' T_UNIT_TYPE[unit] T_ID[name] ';' {
        $$ = new VarDcl($name, $unit, "int");
    }

declaration_statement:
        // ex: int:meters dist = 100;
    T_INT ':' T_UNIT_TYPE[unit] T_ID[name] '=' expression[val] ';' {
        $$ = new VarDcl($name, $unit, "int", $val);
    }



// --- 2. ATRIBUIÇÃO DE VARIÁVEL (Foco: Checagem de Unidade) ---
assignment_statement:
    T_ID '=' expression ';' {
        $$ = new Store($1, $3);
    }
;

// --- 3. EXPRESSÕES ARITMÉTICAS ---
expression:
    primary                             { $$ = $1; }
|   expression '+' primary              { $$ = new BinaryOp($1, '+', $3); } // Apenas unidades iguais podem somar
|   expression '-' primary              { $$ = new BinaryOp($1, '-', $3); } // Apenas unidades iguais podem subtrair
|   expression '*' primary              { $$ = new BinaryOp($1, '*', $3); } // Multiplicação pode mudar a unidade
|   expression '/' primary              { $$ = new BinaryOp($1, '/', $3); } // Divisão pode mudar a unidade
;

primary:
    T_FLOAT_LITERAL                     { $$ = new ConstDouble($1); } // Números simples são adimensionais (ex: o '2' em vel * 2)
|   T_ID                                { $$ = new Load($1); }
|   '(' expression ')'                  { $$ = $2; }
|   T_INT_LITERAL                       { $$ = new ConstInteger($1); }
;

// --- 4. FLUXO DE CONTROLE ---
for_statement:
    T_FOR '(' assignment_statement condition ';' for_assignment_statement ')' '{' statements[stmts] '}' { 
        $$ = new For($3, $4, $6, $stmts); 
    }
|   T_FOR '(' declaration_statement condition ';' for_assignment_statement ')' '{' statements[stmts] '}' { 
        $$ = new For($3, $4, $6, $stmts); 
    }
;

for_assignment_statement: T_ID '=' expression { $$ = new Store($1, $3); }

if_statement:
    T_IF '(' condition ')' '{' statements[stmts] '}' { 
        $$ = new If($3, $stmts); 
    }
|   T_IF '(' condition ')' '{' statements[stmts1] '}' T_ELSE '{' statements[stmts2] '}' { 
        $$ = new If($3, $stmts1, $stmts2); 
    }
;

condition: expression '<' expression { 
        $$ = new CompOp($1, "<", $3);
    }

condition: expression '>' expression {
        $$ = new CompOp($1, ">", $3);
    }

condition: expression T_LE expression {
        $$ = new CompOp($1, "<=", $3);
    }

condition: expression T_GE expression {
        $$ = new CompOp($1, ">=", $3);
    }

condition: expression T_EQ expression {
        $$ = new CompOp($1, "==", $3);
    }

condition: expression T_NE expression {
        $$ = new CompOp($1, "!=", $3);
    }


// --- 5. I/O SIMPLES ---
print_statement:
    T_PRINTF '(' T_STRING_LITERAL ')' ';'        { $$ = new Print(new ConstString($3)); }
|   T_PRINTF '(' T_ID ')' ';'                    { $$ = new Print(new Load($3)); }
|   T_PRINTF '(' T_STRING_LITERAL T_ID ')' ';'   { $$ = new Print(new Load($4)); }
;

%%
