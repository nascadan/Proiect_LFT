%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int yylex();
int yyerror(char*);
void convertMVParamName(char*, char*);
%}

%union {
    int intval;
    char* strval;
}

%token MV_COMMAND
%token<strval> PARAM_NAME PARAM_VALUE
%type<strval> mv_all_options line path_dst mv_line
%right PARAM_NAME       //DE PUS IN DOCUMENTATIE - am rezolvat un caz de ambiguitate in care analizorul de sintaxa nu stia cum sa trateze o valoare de parametru,
%left PARAM_VALUE       //intrucat nu avea vreo asociere intre un parametru propriu-zis si valoarea sa
%%

total:       line                { printf("%s\n", $1); free($1); }
            | line '\n' total   { printf("%s\n", $1); free($1); }
            ;

line:       mv_line
            | //alta linie... 
            ;
mv_line:    MV_COMMAND mv_all_options path_dst                     {
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "Move-Item %s %s", $3, $2);
                                                                    $$ = result;
                                                                }
            | MV_COMMAND path_dst mv_all_options                   {
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "Move-Item %s %s", $2, $3);
                                                                    $$ = result;
                                                                }
            ;
path_dst: PARAM_VALUE PARAM_VALUE                               {
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "-Path %s -Destination %s", $1, $2);
                                                                    $$ = result;
                                                                }
            ;

mv_all_options:    PARAM_NAME PARAM_VALUE                          {
                                                                    char intermediar[128] = "";
                                                                    convertMVParamName($1, intermediar);
                                                                    char* result = malloc(256);
                                                                    sprintf(result, "%s %s", intermediar, $2);
                                                                    $$ = result;
                                                                }
                | PARAM_NAME                                    {
                                                                    char intermediar[128] = "";
                                                                    convertMVParamName($1, intermediar);
                                                                    $$ = strdup(intermediar);
                                                                } 
                | PARAM_NAME PARAM_VALUE mv_all_options           {
                                                                    char intermediar[128] = "";
                                                                    convertMVParamName($2, intermediar);
                                                                    char* result = malloc(256);
                                                                    sprintf(result, "%s %s %s", $1, intermediar, $3);
                                                                    $$ = result;
                                                                }
                | PARAM_NAME mv_all_options                        {
                                                                    char intermediar[128] = "";
                                                                    convertMVParamName($2, intermediar);
                                                                    char* result = malloc(256);
                                                                    sprintf(result, "%s %s", $1, intermediar);
                                                                    $$ = result;
                                                                }
                ;
%%

int main(void)
{
    return yyparse();
}

int yyerror(char* s)
{
    printf("Eroare intampinata: %s\n", s);
    return -1;
}

void convertMVParamName(char* pname, char* output) {
    if(strcmp(pname, "-f") == 0 || strcmp(pname, "--force") == 0) {
        strcpy(output, "-Force");
    } else {
        strcpy(output, pname);
    }
}
