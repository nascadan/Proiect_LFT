%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int yylex();
int yyerror(char*);
void convertMVParamName(char*, char*);
void convertLSParamName(char*, char*);
%}

%union {
    int intval;
    char* strval;
}

%token MV_COMMAND LS_COMMAND
%token<strval> PARAM_NAME PARAM_VALUE CMD_SEPARATOR
%type<strval> mv_all_options line path_dst mv_line ls_line ls_all_options
%right PARAM_NAME       //DE PUS IN DOCUMENTATIE - am rezolvat un caz de ambiguitate in care analizorul de sintaxa nu stia cum sa trateze o valoare de parametru,
%left PARAM_VALUE       //intrucat nu avea vreo asociere intre un parametru propriu-zis si valoarea sa
%%

total:       line                           { printf("%s", $1); free($1); }
            | total CMD_SEPARATOR line      { printf("%s %s", $2, $3); free($3); free($2); }
            ;

line:       mv_line
            | ls_line
            ;
ls_line:    LS_COMMAND ls_all_options                           {
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "Get-ChildItem %s", $2);
                                                                    $$ = result;
                                                                }

            | LS_COMMAND ls_all_options PARAM_VALUE               {
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "Get-ChildItem -Path %s %s", $3, $2);
                                                                    $$ = result;
                                                                }
            | LS_COMMAND PARAM_VALUE ls_all_options             {
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "Get-ChildItem %s %s", $2, $3);
                                                                    $$ = result;
                                                                }
            ;

ls_all_options:    PARAM_NAME PARAM_VALUE                          {
                                                                    char intermediar[128] = "";
                                                                    convertLSParamName($1, intermediar);
                                                                    char* result = malloc(256);
                                                                    sprintf(result, "%s %s", intermediar, $2);
                                                                    $$ = result;
                                                                }
                | PARAM_NAME                                    {
                                                                    char intermediar[128] = "";
                                                                    convertLSParamName($1, intermediar);
                                                                    $$ = strdup(intermediar);
                                                                } 
                | PARAM_NAME PARAM_VALUE ls_all_options           {
                                                                    char intermediar[128] = "";
                                                                    convertLSParamName($2, intermediar);
                                                                    char* result = malloc(256);
                                                                    sprintf(result, "%s %s %s", $1, intermediar, $3);
                                                                    $$ = result;
                                                                }
                | PARAM_NAME ls_all_options                        {
                                                                    char intermediar[128] = "";
                                                                    convertLSParamName($2, intermediar);
                                                                    char* result = malloc(256);
                                                                    sprintf(result, "%s %s", $1, intermediar);
                                                                    $$ = result;
                                                                }
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

void convertLSParamName(char* pname, char* output) {
    if(strcmp(pname, "-L") == 0 || strcmp(pname, "--dereference") == 0) {
        strcpy(output, "-FollowSymlink");
    } else if(strcmp(pname, "-A") == 0 || strcmp(pname, "--almost-all") == 0){
        strcpy(output, "");
    } else if(strcmp(pname, "-R") == 0 || strcmp(pname, "--recursive") == 0){
        strcpy(output, "-Recurse");
    }else if(strcmp(pname, "-d")==0 || strcmp(pname, "--directory") == 0){
        strcpy(output, "-Directory");
    }

    else if(strcmp(pname, "-s")==0 || strcmp(pname, "--size") == 0 || strcmp(pname, "-m") == 0 || strcmp(pname, "-N") == 0 || strcmp(pname, "--literal") == 0 || strcmp(pname, "-l") == 0 || strcmp(pname, "-a") == 0 || strcmp(pname, "--all") == 0){
        strcpy(output, "");
    }
}
