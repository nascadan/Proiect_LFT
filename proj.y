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
%type<strval> all_options line
%%

total:       line                { printf("%s\n", $1); free($1); }
            | total '\n' line    { printf("%s\n", $3); free($3); }
            | total '\n'         {  }
            ;

line:       MV_COMMAND all_options PARAM_VALUE PARAM_VALUE      {
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "Move-Item -Path %s -Destination %s %s", $3, $4, $2);
                                                                    $$ = result;
                                                                }
            | MV_COMMAND PARAM_VALUE PARAM_VALUE all_options    {
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "Move-Item -Path %s -Destination %s %s", $2, $3, $4);
                                                                    $$ = result;
                                                                }
            ;

all_options:    PARAM_NAME                                      {
                                                                    char intermediar[128] = "";
                                                                    convertMVParamName($1, intermediar);
                                                                    $$ = strdup(intermediar);
                                                                }
                | PARAM_NAME PARAM_VALUE                        {
                                                                    char intermediar[128] = "";
                                                                    convertMVParamName($1, intermediar);
                                                                    char* result = malloc(256);
                                                                    sprintf(result, "%s %s", intermediar, $2);
                                                                    $$ = result;
                                                                }
                | all_options PARAM_NAME                        {
                                                                    char intermediar[128] = "";
                                                                    convertMVParamName($2, intermediar);
                                                                    char* result = malloc(256);
                                                                    sprintf(result, "%s %s", $1, intermediar);
                                                                    $$ = result;
                                                                }
                | all_options PARAM_NAME PARAM_VALUE            {
                                                                    char intermediar[128] = "";
                                                                    convertMVParamName($2, intermediar);
                                                                    char* result = malloc(256);
                                                                    sprintf(result, "%s %s %s", $1, intermediar, $3);
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
