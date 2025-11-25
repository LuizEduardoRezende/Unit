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
%token T_STRING_LITERAL T_ID T_FLOAT_LITERAL T_INT_LITERAL
%token T_LE T_GE T_EQ T_NE
%token T_UNIT_TYPE

%type <name> T_ID
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
statement: for_statement { }
statement: if_statement { } 
statement: print_statement { }


// --- 1. DECLARAÇÃO DE VARIÁVEL (Foco: Unidade no Tipo) ---
declaration_statement:
    // ex: float vel;
    T_FLOAT T_ID[name] ';' {
        $$ = new VarDcl($name, UNIT_ADIMENSIONAL, "float");
    }

declaration_statement:   
    // ex: float vel = 0.0;
    T_FLOAT T_ID[name] '=' expression ';' {
        $$ = new VarDcl($name, UNIT_ADIMENSIONAL, "float", $4);
    }

declaration_statement:
    // ex: float:seconds tempo_gasto;
    T_FLOAT ':' T_UNIT_TYPE[unit] T_ID[name] ';' { 
        $$ = new VarDcl($name, $unit, "float");
    }

declaration_statement:
    // ex: float:seconds tempo = distancia / velocidade;
    T_FLOAT ':' T_UNIT_TYPE[unit] T_ID[name] '=' expression ';' {
        $$ = new VarDcl($name, $unit, "float", $6);
    }

declaration_statement:
    // ex: int i;
    T_INT T_ID[name] ';' {
        $$ = new VarDcl($name, UNIT_ADIMENSIONAL, "int");
    }

declaration_statement:
    // ex: int i = 0;
    T_INT T_ID[name] '=' expression ';' {
        $$ = new VarDcl($name, UNIT_ADIMENSIONAL, "int", $4);
    }

declaration_statement:
    // ex: int:meters dist;
    T_INT ':' T_UNIT_TYPE[unit] T_ID[name] ';' {
        $$ = new VarDcl($name, $unit, "int");
    }

declaration_statement:
        // ex: int:meters dist = 100;
    T_INT ':' T_UNIT_TYPE[unit] T_ID[name] '=' expression ';' {
        $$ = new VarDcl($name, $unit, "int", $6);
    }



// --- 2. ATRIBUIÇÃO DE VARIÁVEL (Foco: Checagem de Unidade) ---
assignment_statement:
    T_ID '=' expression ';' {

    }
;

// --- 3. EXPRESSÕES ARITMÉTICAS ---
expression:
    primary                             { $$ = $1; }
|   expression '+' primary              { } // Apenas unidades iguais podem somar
|   expression '-' primary              { }
|   expression '*' primary              { } // Multiplicação pode mudar a unidade
|   expression '/' primary              { } // Divisão pode mudar a unidade
;

primary:
    T_FLOAT_LITERAL                     { } // Números simples são adimensionais (ex: o '2' em vel * 2)
|   T_ID                                { }
|   '(' expression ')'                  { }
|   T_INT_LITERAL                       { }
;

// --- 4. FLUXO DE CONTROLE ---
for_statement:
    T_FOR '(' assignment_statement condition ';' for_assignment_statement ')' '{' statements '}' { $$ = NULL; }
|   T_FOR '(' declaration_statement condition ';' for_assignment_statement ')' '{' statements '}' { $$ = NULL; }
;

for_assignment_statement:
    T_ID '=' expression { 

    }
;

if_statement:
    T_IF '(' condition ')' '{' statements '}' { $$ = NULL; }
|   T_IF '(' condition ')' '{' statements '}' T_ELSE '{' statements '}' { $$ = NULL; }
;

condition: expression '<' expression { 

    }

condition: expression '>' expression {

    }

condition: expression T_LE expression {

    }

condition: expression T_GE expression {

    }

condition: expression T_EQ expression {

    }

condition: expression T_NE expression {

    }


// --- 5. I/O SIMPLES ---
print_statement:
    T_PRINTF '(' T_STRING_LITERAL ')' ';'        { $$ = NULL; }
|   T_PRINTF '(' T_ID ')' ';'                    { $$ = NULL; }
|   T_PRINTF '(' T_STRING_LITERAL T_ID ')' ';'   { $$ = NULL; }
;

%%

// Função principal de bison/yacc
int main(void) {
    int parse_result = yyparse();
    
    if (parse_result == 0 && error_count == 0) {
        printf("Parse concluido com sucesso.\n");
        return 0;
    } else {
        if (error_count > 0) {
            printf("Total de erros encontrados: %d\n", error_count);
        }
        return 1;
    }
}

// Tratamento de erro do Parser
int yyerror(const char *s) {
    printf("ERRO na linha %d: %s\n", yylineno, s);
    error_count++;
    return 0;
}