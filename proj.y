%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int yylex();
int yyerror(char*);
void convertMVParamName(char*, char*);
void convertLSParamName(char*, char*);
void convertPWDParamName(char*, char*);
void convertTouchParamName(char*, char*);
void convertRMParamName(char*, char*);
void convertGrepParamName(char*, char*);
void convertCatParamName(char*, char*);
void convertPSParamName(char*, char*);
%}

%union {
    int intval;
    char* strval;
}

%token MV_COMMAND LS_COMMAND PWD_COMMAND TOUCH_COMMAND RM_COMMAND GREP_COMMAND CAT_COMMAND PS_COMMAND CLEAR_COMMAND HISTORY_COMMAND
%token<strval> PARAM_NAME PARAM_VALUE CMD_SEPARATOR
%type<strval> mv_all_options line path_dst mv_line ls_line ls_all_options pwd_line pwd_all_options touch_line touch_all_options rm_line rm_all_options grep_line grep_all_options grep_args cat_line cat_all_options ps_line ps_all_options clear_line history_line
%right PARAM_NAME       //DE PUS IN DOCUMENTATIE - am rezolvat un caz de ambiguitate in care analizorul de sintaxa nu stia cum sa trateze o valoare de parametru,
%left PARAM_VALUE       //intrucat nu avea vreo asociere intre un parametru propriu-zis si valoarea sa
%%

total:       line                           { printf("%s", $1); free($1); }
            | total CMD_SEPARATOR line      { printf("%s %s", $2, $3); free($3); free($2); }
            | total CMD_SEPARATOR           { printf("%s", $2); free($2); }
            ;

line:       mv_line
            | ls_line
            | pwd_line
            | touch_line
            | rm_line
            | grep_line
            | cat_line
            | ps_line
            | clear_line
            | history_line
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
                                                                    sprintf(result, "Get-ChildItem -Path %s %s", $2, $3);
                                                                    $$ = result;
                                                                }
            | LS_COMMAND                                        {
                                                                    $$ = strdup("Get-ChildItem");
                                                                }
            | LS_COMMAND PARAM_VALUE                            {
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "Get-ChildItem -Path %s", $2);
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
                                                                    convertLSParamName($1, intermediar);
                                                                    char* result = malloc(256);
                                                                    sprintf(result, "%s %s %s", intermediar, $2, $3);
                                                                    $$ = result;
                                                                }
                | PARAM_NAME ls_all_options                        {
                                                                    char intermediar[128] = "";
                                                                    convertLSParamName($1, intermediar);
                                                                    char* result = malloc(256);
                                                                    sprintf(result, "%s %s", intermediar, $2);
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
                                                                    convertMVParamName($1, intermediar);
                                                                    char* result = malloc(256);
                                                                    sprintf(result, "%s %s %s", intermediar, $2, $3);
                                                                    $$ = result;
                                                                }
                | PARAM_NAME mv_all_options                        {
                                                                    char intermediar[128] = "";
                                                                    convertMVParamName($1, intermediar);
                                                                    char* result = malloc(256);
                                                                    sprintf(result, "%s %s", intermediar, $2);
                                                                    $$ = result;
                                                                }
                ;

pwd_line:   PWD_COMMAND                                         {
                                                                    $$ = strdup("Get-Location");
                                                                }
            | PWD_COMMAND pwd_all_options                       {
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "Get-Location %s", $2);
                                                                    $$ = result;
                                                                }
            ;

pwd_all_options: PARAM_NAME PARAM_VALUE                         {
                                                                    char intermediar[128] = "";
                                                                    convertPWDParamName($1, intermediar);
                                                                    char* result = malloc(256);
                                                                    sprintf(result, "%s %s", intermediar, $2);
                                                                    $$ = result;
                                                                }
                | PARAM_NAME                                    {
                                                                    char intermediar[128] = "";
                                                                    convertPWDParamName($1, intermediar);
                                                                    $$ = strdup(intermediar);
                                                                }
                | PARAM_NAME PARAM_VALUE pwd_all_options        {
                                                                    char intermediar[128] = "";
                                                                    convertPWDParamName($1, intermediar);
                                                                    char* result = malloc(256);
                                                                    sprintf(result, "%s %s %s", intermediar, $2, $3);
                                                                    $$ = result;
                                                                }
                | PARAM_NAME pwd_all_options                    {
                                                                    char intermediar[128] = "";
                                                                    convertPWDParamName($1, intermediar);
                                                                    char* result = malloc(256);
                                                                    sprintf(result, "%s %s", intermediar, $2);
                                                                    $$ = result;
                                                                }
                ;

touch_line: TOUCH_COMMAND PARAM_VALUE                           {
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "New-Item -ItemType File -Path %s", $2);
                                                                    $$ = result;
                                                                }
            | TOUCH_COMMAND touch_all_options PARAM_VALUE       {
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "New-Item -ItemType File -Path %s %s", $3, $2);
                                                                    $$ = result;
                                                                }
            | TOUCH_COMMAND PARAM_VALUE touch_all_options       {
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "New-Item -ItemType File -Path %s %s", $2, $3);
                                                                    $$ = result;
                                                                }
            | TOUCH_COMMAND touch_all_options                   {
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "New-Item -ItemType File %s", $2);
                                                                    $$ = result;
                                                                }
            ;

touch_all_options: PARAM_NAME PARAM_VALUE                       {
                                                                    char intermediar[128] = "";
                                                                    convertTouchParamName($1, intermediar);
                                                                    char* result = malloc(256);
                                                                    sprintf(result, "%s %s", intermediar, $2);
                                                                    $$ = result;
                                                                }
                | PARAM_NAME                                    {
                                                                    char intermediar[128] = "";
                                                                    convertTouchParamName($1, intermediar);
                                                                    $$ = strdup(intermediar);
                                                                }
                | PARAM_NAME PARAM_VALUE touch_all_options      {
                                                                    char intermediar[128] = "";
                                                                    convertTouchParamName($1, intermediar);
                                                                    char* result = malloc(256);
                                                                    sprintf(result, "%s %s %s", intermediar, $2, $3);
                                                                    $$ = result;
                                                                }
                | PARAM_NAME touch_all_options                  {
                                                                    char intermediar[128] = "";
                                                                    convertTouchParamName($1, intermediar);
                                                                    char* result = malloc(256);
                                                                    sprintf(result, "%s %s", intermediar, $2);
                                                                    $$ = result;
                                                                }
                ;

rm_line:    RM_COMMAND PARAM_VALUE                              {
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "Remove-Item -Path %s", $2);
                                                                    $$ = result;
                                                                }
            | RM_COMMAND rm_all_options PARAM_VALUE             {
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "Remove-Item -Path %s %s", $3, $2);
                                                                    $$ = result;
                                                                }
            | RM_COMMAND PARAM_VALUE rm_all_options             {
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "Remove-Item -Path %s %s", $2, $3);
                                                                    $$ = result;
                                                                }
            | RM_COMMAND rm_all_options                         {
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "Remove-Item %s", $2);
                                                                    $$ = result;
                                                                }
            ;

rm_all_options: PARAM_NAME PARAM_VALUE                          {
                                                                    char intermediar[128] = "";
                                                                    convertRMParamName($1, intermediar);
                                                                    char* result = malloc(256);
                                                                    sprintf(result, "%s %s", intermediar, $2);
                                                                    $$ = result;
                                                                }
                | PARAM_NAME                                    {
                                                                    char intermediar[128] = "";
                                                                    convertRMParamName($1, intermediar);
                                                                    $$ = strdup(intermediar);
                                                                }
                | PARAM_NAME PARAM_VALUE rm_all_options         {
                                                                    char intermediar[128] = "";
                                                                    convertRMParamName($1, intermediar);
                                                                    char* result = malloc(256);
                                                                    sprintf(result, "%s %s %s", intermediar, $2, $3);
                                                                    $$ = result;
                                                                }
                | PARAM_NAME rm_all_options                     {
                                                                    char intermediar[128] = "";
                                                                    convertRMParamName($1, intermediar);
                                                                    char* result = malloc(256);
                                                                    sprintf(result, "%s %s", intermediar, $2);
                                                                    $$ = result;
                                                                }
                ;

grep_line:  GREP_COMMAND grep_args                              {
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "Select-String %s", $2);
                                                                    $$ = result;
                                                                }
            | GREP_COMMAND grep_all_options grep_args           {
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "Select-String %s %s", $3, $2);
                                                                    $$ = result;
                                                                }
            | GREP_COMMAND grep_args grep_all_options           {
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "Select-String %s %s", $2, $3);
                                                                    $$ = result;
                                                                }
            | GREP_COMMAND grep_all_options                     {
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "Select-String %s", $2);
                                                                    $$ = result;
                                                                }
            ;

grep_args:  PARAM_VALUE PARAM_VALUE                             {
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "-Pattern %s -Path %s", $1, $2);
                                                                    $$ = result;
                                                                }
            | PARAM_VALUE                                       {
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "-Pattern %s", $1);
                                                                    $$ = result;
                                                                }
            ;

grep_all_options: PARAM_NAME                                    {
                                                                    char intermediar[128] = "";
                                                                    convertGrepParamName($1, intermediar);
                                                                    $$ = strdup(intermediar);
                                                                }
                | PARAM_NAME grep_all_options                   {
                                                                    char intermediar[128] = "";
                                                                    convertGrepParamName($1, intermediar);
                                                                    char* result = malloc(256);
                                                                    sprintf(result, "%s %s", intermediar, $2);
                                                                    $$ = result;
                                                                }
                ;

cat_line:   CAT_COMMAND                                         {
                                                                    $$ = strdup("Get-Content");
                                                                }
            | CAT_COMMAND PARAM_VALUE                           {
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "Get-Content -Path %s", $2);
                                                                    $$ = result;
                                                                }
            | CAT_COMMAND cat_all_options PARAM_VALUE           {
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "Get-Content -Path %s %s", $3, $2);
                                                                    $$ = result;
                                                                }
            | CAT_COMMAND PARAM_VALUE cat_all_options           {
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "Get-Content -Path %s %s", $2, $3);
                                                                    $$ = result;
                                                                }
            | CAT_COMMAND cat_all_options                       {
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "Get-Content %s", $2);
                                                                    $$ = result;
                                                                }
            ;

cat_all_options: PARAM_NAME PARAM_VALUE                         {
                                                                    char intermediar[128] = "";
                                                                    convertCatParamName($1, intermediar);
                                                                    char* result = malloc(256);
                                                                    sprintf(result, "%s %s", intermediar, $2);
                                                                    $$ = result;
                                                                }
                | PARAM_NAME                                    {
                                                                    char intermediar[128] = "";
                                                                    convertCatParamName($1, intermediar);
                                                                    $$ = strdup(intermediar);
                                                                }
                | PARAM_NAME PARAM_VALUE cat_all_options        {
                                                                    char intermediar[128] = "";
                                                                    convertCatParamName($1, intermediar);
                                                                    char* result = malloc(256);
                                                                    sprintf(result, "%s %s %s", intermediar, $2, $3);
                                                                    $$ = result;
                                                                }
                | PARAM_NAME cat_all_options                    {
                                                                    char intermediar[128] = "";
                                                                    convertCatParamName($1, intermediar);
                                                                    char* result = malloc(256);
                                                                    sprintf(result, "%s %s", intermediar, $2);
                                                                    $$ = result;
                                                                }
                ;

ps_line:    PS_COMMAND                                          {
                                                                    $$ = strdup("Get-Process");
                                                                }
            | PS_COMMAND ps_all_options                         {
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "Get-Process %s", $2);
                                                                    $$ = result;
                                                                }
            | PS_COMMAND PARAM_VALUE                            {
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "Get-Process %s", $2);
                                                                    $$ = result;
                                                                }
            ;

ps_all_options: PARAM_NAME PARAM_VALUE                          {
                                                                    char intermediar[128] = "";
                                                                    convertPSParamName($1, intermediar);
                                                                    char* result = malloc(256);
                                                                    sprintf(result, "%s %s", intermediar, $2);
                                                                    $$ = result;
                                                                }
                | PARAM_NAME                                    {
                                                                    char intermediar[128] = "";
                                                                    convertPSParamName($1, intermediar);
                                                                    $$ = strdup(intermediar);
                                                                }
                | PARAM_NAME PARAM_VALUE ps_all_options         {
                                                                    char intermediar[128] = "";
                                                                    convertPSParamName($1, intermediar);
                                                                    char* result = malloc(256);
                                                                    sprintf(result, "%s %s %s", intermediar, $2, $3);
                                                                    $$ = result;
                                                                }
                | PARAM_NAME ps_all_options                     {
                                                                    char intermediar[128] = "";
                                                                    convertPSParamName($1, intermediar);
                                                                    char* result = malloc(256);
                                                                    sprintf(result, "%s %s", intermediar, $2);
                                                                    $$ = result;
                                                                }
                ;

clear_line: CLEAR_COMMAND                                       {
                                                                    $$ = strdup("Clear-Host");
                                                                }
            ;

history_line: HISTORY_COMMAND                                   {
                                                                    $$ = strdup("Get-History");
                                                                }
            | HISTORY_COMMAND PARAM_VALUE                       {
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "Get-History -Count %s", $2);
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

void convertPWDParamName(char* pname, char* output) {
    strcpy(output, "");
}

void convertTouchParamName(char* pname, char* output) {
    strcpy(output, pname);
}

void convertRMParamName(char* pname, char* output) {
    if(strcmp(pname, "-r") == 0 || strcmp(pname, "-R") == 0 || strcmp(pname, "--recursive") == 0) {
        strcpy(output, "-Recurse");
    } else if(strcmp(pname, "-f") == 0 || strcmp(pname, "--force") == 0) {
        strcpy(output, "-Force");
    } else if(strcmp(pname, "-i") == 0) {
        strcpy(output, "-Confirm");
    } else {
        strcpy(output, pname);
    }
}

void convertGrepParamName(char* pname, char* output) {
    if(strcmp(pname, "-v") == 0 || strcmp(pname, "--invert-match") == 0) {
        strcpy(output, "-NotMatch");
    } else if(strcmp(pname, "-i") == 0 || strcmp(pname, "--ignore-case") == 0) {
        strcpy(output, "");
    } else {
        strcpy(output, pname);
    }
}

void convertCatParamName(char* pname, char* output) {
    strcpy(output, pname);
}

void convertPSParamName(char* pname, char* output) {
    strcpy(output, "");
}
