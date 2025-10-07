%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

extern int yylineno; // Declaração da variável de linha do flex

// Tabela de Símbolos Simplificada (para guardar o tipo/unidade da variável)
typedef struct {
    char *name;
    int type_unit;
} Symbol;

// Simulação de uma tabela de símbolos (máximo 100 variáveis)
Symbol symbol_table[100];
int symbol_count = 0;

// Contador de erros global
int error_count = 0;

// Funções de ajuda
Symbol* new_symbol(const char *id, int unit);
Symbol* symbol_exists(const char *id);

int get_symbol_unit(const char *id);
int check_unit_compatibility(int left_unit, int right_unit, const char *op);

int yylex(void);
int yyerror(const char *s);

#define UNIT_METERS 1
#define UNIT_SECONDS 2
#define UNIT_M_PER_S 3
#define UNIT_SQ_METER 4
#define UNIT_ADIMENSIONAL 5

%}

%define parse.error detailed

/* atributos dos tokens */
%union {
    int integer;
    double real;
    char *string;
    int unit; // Para retornar o tipo de unidade
    void *node; // Placeholder para AST nodes (não implementado aqui)
}

%token T_FLOAT T_INT T_FOR T_IF T_ELSE T_PRINTF
%token T_STRING_LITERAL T_ID T_FLOAT_LITERAL T_INT_LITERAL
%token T_LE T_GE T_EQ T_NE
%token T_UNIT_TYPE // Tokens de unidade explícitos


// Definindo o tipo de retorno para as expressões (a unidade resultante)
%type <node> program statements statement declaration_statement assignment_statement for_statement if_statement print_statement for_assignment_statement
%type <unit> expression primary
%type <integer> condition
%type <string> T_ID
%type <unit> T_UNIT_TYPE


%start program

%%

program:
    statements { $$ = NULL; }
;

statements:
    statement { $$ = NULL; }
|   statements statement { $$ = NULL; }
;

statement:
    declaration_statement { $$ = NULL; }
|   assignment_statement { $$ = NULL; }
|   for_statement { $$ = NULL; }
|   if_statement { $$ = NULL; }
|   print_statement { $$ = NULL; }
;

// --- 1. DECLARAÇÃO DE VARIÁVEL (Foco: Unidade no Tipo) ---
declaration_statement:
    T_FLOAT T_ID ';' {
        // ex: float vel;
        new_symbol($2, UNIT_ADIMENSIONAL);
        $$ = NULL;
    }
|   T_FLOAT T_ID '=' expression ';' {
        // ex: float vel = 0.0;
        new_symbol($2, UNIT_ADIMENSIONAL);
        check_unit_compatibility(UNIT_ADIMENSIONAL, $4, "ASSIGN");
        $$ = NULL;
    }
|   T_FLOAT ':' T_UNIT_TYPE T_ID ';' { 
        // ex: float:seconds tempo_gasto;
        new_symbol($4, $3);
        $$ = NULL;
    }
|   T_FLOAT ':' T_UNIT_TYPE T_ID '=' expression ';' {
        // ex: float:seconds tempo = distancia / velocidade;
        new_symbol($4, $3);
        check_unit_compatibility($3, $6, "ASSIGN");
        $$ = NULL;
    }
|   T_INT T_ID ';' {
        // ex: int i;
        new_symbol($2, UNIT_ADIMENSIONAL);
        $$ = NULL;
    }
|   T_INT T_ID '=' expression ';' {
        // ex: int i = 0;
        new_symbol($2, UNIT_ADIMENSIONAL);
        check_unit_compatibility(UNIT_ADIMENSIONAL, $4, "ASSIGN");
        $$ = NULL;
    }
|   T_INT ':' T_UNIT_TYPE T_ID ';' {
        // ex: int:meters dist;
        new_symbol($4, $3);
        $$ = NULL;
    }
|   T_INT ':' T_UNIT_TYPE T_ID '=' expression ';' {
        // ex: int:meters dist = 100;
        new_symbol($4, $3);
        check_unit_compatibility($3, $6, "ASSIGN");
        $$ = NULL;
    }
;

// --- 2. ATRIBUIÇÃO DE VARIÁVEL (Foco: Checagem de Unidade) ---
assignment_statement:
    T_ID '=' expression ';' {
        int target_unit = get_symbol_unit($1);
        check_unit_compatibility(target_unit, $3, "ASSIGN"); 
        $$ = NULL;
    }
;

// --- 3. EXPRESSÕES ARITMÉTICAS ---
expression:
    primary                             { $$ = $1; }
|   expression '+' primary           { check_unit_compatibility($1, $3, "+"); $$ = $1; } // Apenas unidades iguais podem somar
|   expression '-' primary          { check_unit_compatibility($1, $3, "-"); $$ = $1; }
|   expression '*' primary           { $$ = check_unit_compatibility($1, $3, "*"); } // Multiplicação pode mudar a unidade
|   expression '/' primary            { $$ = check_unit_compatibility($1, $3, "/"); } // Divisão pode mudar a unidade
;

primary:
    T_FLOAT_LITERAL                     { $$ = UNIT_ADIMENSIONAL; } // Números simples são adimensionais (ex: o '2' em vel * 2)
|   T_ID                                { $$ = get_symbol_unit($1); }
|   '(' expression ')'        { $$ = $2; }
|   T_INT_LITERAL                       { $$ = UNIT_ADIMENSIONAL; }
;

// --- 4. FLUXO DE CONTROLE ---
for_statement:
    T_FOR '(' assignment_statement condition ';' for_assignment_statement ')' '{' statements '}' { $$ = NULL; }
|   T_FOR '(' declaration_statement condition ';' for_assignment_statement ')' '{' statements '}' { $$ = NULL; }
;

for_assignment_statement:
    T_ID '=' expression { 
        int target_unit = get_symbol_unit($1);
        check_unit_compatibility(target_unit, $3, "ASSIGN"); 
        $$ = NULL; 
    }
;

if_statement:
    T_IF '(' condition ')' '{' statements '}' { $$ = NULL; }
|   T_IF '(' condition ')' '{' statements '}' T_ELSE '{' statements '}' { $$ = NULL; }
;

condition:
    expression '<' expression { 
        check_unit_compatibility($1, $3, "<"); 
        $$ = 0; // Retorno simbólico
    }
|   expression '>' expression {
        check_unit_compatibility($1, $3, ">");
        $$ = 0;
    }
|   expression T_LE expression {
        check_unit_compatibility($1, $3, "<=");
        $$ = 0;
    }
|   expression T_GE expression {
        check_unit_compatibility($1, $3, "GE");
        $$ = 0;
    }
|   expression T_EQ expression {
        check_unit_compatibility($1, $3, "EQ");
        $$ = 0;
    }
|   expression T_NE expression {
        check_unit_compatibility($1, $3, "!=");
        $$ = 0;
    }
;

// --- 5. I/O SIMPLES ---
print_statement:
    T_PRINTF '(' T_STRING_LITERAL ')' ';' { $$ = NULL; }
|   T_PRINTF '(' T_ID ')' ';' { $$ = NULL; }
|   T_PRINTF '(' T_STRING_LITERAL T_ID ')' ';' { $$ = NULL; }
;

%%

// --- Implementação Simbólica das Funções de Unidade ---

// Adiciona uma variável à tabela de símbolos (com alocação dinâmica)
Symbol* new_symbol(const char *name, int type_unit) {
    if (symbol_count < 100) {
        symbol_table[symbol_count].name = strdup(name);
        symbol_table[symbol_count].type_unit = type_unit;
        Symbol *result = &symbol_table[symbol_count];
        symbol_count++;
        return result;
    }
    return NULL;
}

Symbol* symbol_exists(const char *name) {
    for (int i = 0; i < symbol_count; i++) {
        if (strcmp(symbol_table[i].name, name) == 0) {
            return &symbol_table[i];
        }
    }
    return NULL;
}

int get_symbol_unit(const char *name) {
    for (int i = 0; i < symbol_count; i++) {
        if (strcmp(symbol_table[i].name, name) == 0) {
            return symbol_table[i].type_unit;
        }
    }
    char msg[300];
    snprintf(msg, sizeof(msg), "ERRO FATAL: Variavel '%s' nao declarada.", name);
    yyerror(msg);
    return UNIT_ADIMENSIONAL;
}

// Ação principal: Checagem de Compatibilidade de Unidades
int check_unit_compatibility(int left_unit, int right_unit, const char *op) {
    if (strcmp(op, "+") == 0 || strcmp(op, "-") == 0 || strcmp(op, "<") == 0 || (strcmp(op, ">") == 0 || strcmp(op, "<=") == 0 || strcmp(op, "GE") == 0 || strcmp(op, "EQ") == 0)) {
        if (left_unit == UNIT_ADIMENSIONAL && right_unit != UNIT_ADIMENSIONAL) return right_unit;
        if (right_unit == UNIT_ADIMENSIONAL && left_unit != UNIT_ADIMENSIONAL) return left_unit;
        
        if (left_unit != right_unit) {
            char msg[300];
            snprintf(msg, sizeof(msg), "ERRO DE UNIDADE: Nao e possivel %s unidades diferentes.", op);
            yyerror(msg);
        }
        return left_unit;
    }
    if (strcmp(op, "*") == 0) {
        if (left_unit == UNIT_ADIMENSIONAL && right_unit == UNIT_ADIMENSIONAL) return UNIT_ADIMENSIONAL;
        if (right_unit == UNIT_ADIMENSIONAL) return left_unit;
        if (left_unit == UNIT_ADIMENSIONAL) return right_unit;
        if (left_unit == UNIT_METERS && right_unit == UNIT_METERS) return UNIT_SQ_METER;
        if (left_unit == UNIT_M_PER_S && right_unit == UNIT_SECONDS) return UNIT_METERS;
        if (left_unit == UNIT_SECONDS && right_unit == UNIT_M_PER_S) return UNIT_METERS;

        // Multiplicação não aceita
        // Exemplo: meters * seconds = meters*seconds (não simplificado aqui)
        char msg[300];
        snprintf(msg, sizeof(msg), "ERRO DE UNIDADE: Multiplicacao de unidades sem regra definida.");
        yyerror(msg);
        return UNIT_ADIMENSIONAL;
    }
    if (strcmp(op, "/") == 0) {
        if (left_unit == UNIT_METERS && right_unit == UNIT_SECONDS) return UNIT_M_PER_S;
        
        if (left_unit == right_unit) return UNIT_ADIMENSIONAL;

        if (right_unit == UNIT_ADIMENSIONAL) return left_unit;
        
        if (left_unit == UNIT_METERS && right_unit == UNIT_M_PER_S) return UNIT_SECONDS;

        if (left_unit == UNIT_M_PER_S && right_unit == UNIT_SECONDS) return UNIT_METERS;
        
        // Divisão não aceita
        // Exemplo: seconds / meters
        char msg[300];
        snprintf(msg, sizeof(msg), "ERRO DE UNIDADE: Divisao de unidades sem regra definida.");
        yyerror(msg);
        return UNIT_ADIMENSIONAL;
    }
    if (strcmp(op, "ASSIGN") == 0) {
        if (left_unit != UNIT_ADIMENSIONAL && right_unit == UNIT_ADIMENSIONAL) {
            return left_unit;
        }
        if (left_unit != right_unit) {
            char msg[300];
            snprintf(msg, sizeof(msg), "ERRO DE UNIDADE: Atribuicao de unidade incompativel.");
            yyerror(msg);
        }

        //atribuição de unidades iguais ou adimensionais, é permitida
        return left_unit;

    }
    return UNIT_ADIMENSIONAL;
}

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