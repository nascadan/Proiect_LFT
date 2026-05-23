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
%token<strval> PARAM_NAME PARAM_VALUE PATH_PARAM_VALUE
%type<strval> all_options line option_value src_and_dst
%%

total:       line               { printf("%s\n", $1); }
            | total '\n' line   { printf("%s\n", $3); }
            ;
line:       MV_COMMAND all_options src_and_dst                  {
                                                                    sprintf($$, "Move-Item %s %s", $2, $3);
                                                                }
            | MV_COMMAND src_and_dst all_options                {
                                                                    sprintf($$, "Move-Item %s %s", $3, $2);
                                                                }
            ;
src_and_dst:    PATH_PARAM_VALUE PATH_PARAM_VALUE             {
                                                        sprintf($$, "-Path %s -Destination %s ", $1, $2);
                                                    }
all_options:    PARAM_NAME option_value             {   char* intermediar;
                                                        convertMVParamName($1, intermediar);
                                                        sprintf($$, "%s %s", intermediar, $2);
                                                    }
                | PARAM_NAME option_value all_options   {  char* intermediar;
                                                            convertMVParamName($2, intermediar);
                                                            sprintf($$, "%s %s %s", $1, intermediar, $3);
                                                        }
                ;
option_value:   PARAM_VALUE                         { sprintf($$, "%s", $1); }
                |                                   { sprintf($$, ""); }
                ;

%%
int main(void*)
{
    return yyparse();
}
int yyerror(char* s)
{
    printf("Eroare intampinata: %s\n", s);
    return -1;
}
void convertMVParamName(char* pname, char* output) {
    if(strcmp(pname, "-f") == 0 || strcmp(pname, "--force") == 0)
        sprintf(output, "-Force");
}