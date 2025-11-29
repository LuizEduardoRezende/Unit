%{
#include <stdio.h>
#include <stdlib.h>

class Node;

#include "unit.tab.h"
int yyerror(const char *s);

char *build_file_name;
int error_count = 0;

// Definição das unidades para simplificar o código
#define UNIT_METERS 1
#define UNIT_SECONDS 2
#define UNIT_M_PER_S 3
#define UNIT_SQ_METER 4
#define UNIT_ADIMENSIONAL 5
%}

%option yylineno

%%

[ \t\n\r]+                      /* Ignora espaços e quebras de linha */

"//".*                          /* Comentário de linha - ignora até o final da linha */
"/*"([^*]|\*+[^*/])*\*+"/"      /* Comentário de bloco */

"float"     { return T_FLOAT; }
"int"       { return T_INT; }
"for"       { return T_FOR; }
"if"        { return T_IF; }
"else"      { return T_ELSE; }
"printf"    { return T_PRINTF; }

"="         { return '='; }
"!= "       { return T_NE; }
"<"         { return '<'; }
">"         { return '>'; }
"<="        { return T_LE; }
">="        { return T_GE; }
"=="        { return T_EQ; }
"("         { return '('; }
")"         { return ')'; }
"{"         { return '{'; }
"}"         { return '}'; }
";"         { return ';'; }
"+"         { return '+'; }
"-"         { return '-'; }
"*"         { return '*'; }
"/"         { return '/'; }
":"         { return ':'; }

\"[^\"]*\"  { yylval.name = strdup(yytext); return T_STRING_LITERAL; }

"meters"            { yylval.unit = UNIT_METERS; return T_UNIT_TYPE; }
"seconds"           { yylval.unit = UNIT_SECONDS; return T_UNIT_TYPE; }
"m_per_s"           { yylval.unit = UNIT_M_PER_S; return T_UNIT_TYPE; }
"square_meter"      { yylval.unit = UNIT_SQ_METER; return T_UNIT_TYPE; }

[a-zA-Z_][a-zA-Z0-9_]* { 
    yylval.name = strdup(yytext);
    return T_ID; 
}

[0-9]+\.[0-9]+ {
    yylval.flt = atof(yytext);
    return T_FLOAT_LITERAL;
}

[0-9]+ {
    yylval.integer = atoi(yytext);
    return T_INT_LITERAL;
}


.                   { printf("Erro Léxico: Caractere inesperado '%s'\n", yytext); }

%%

int yyerror(const char *s) {
    fprintf(stderr, "%d:%d: %s\n", 
        yylineno, 0, s);
    error_count++;
    return 1;
}

int yywrap() {
    return 1;
}

int main(int argc, char *argv[]) {
    
    if (argc <= 1) {
        fprintf(stderr, "Sintaxe: %s nome_do_programa\n",
            argv[0]);
        return 1;
    }

    build_file_name = argv[1];
    yyin = fopen(build_file_name, "r");
    if (yyin == NULL) {
        fprintf(stderr, "Não foi possível abrir o arquivo %s.\n", build_file_name);
        return 1;
    }

    //yydebug = 1;
    yyparse();

    if (yyin)
        fclose(yyin);
    
    return error_count;
}