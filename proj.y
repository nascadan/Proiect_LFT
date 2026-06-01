%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int yylex();
int yyerror(char*);
void convertMVParamName(char*, char*);
void convertLSParamName(char*, char*);
void convertMKDIRParamName(char*, char*);
void convertCPParamName(char*, char*);
void convertHeadParams(char*, int, char*);
void convertPKILLParamName(char*, char*);
void convertCURLParamName(char*, char*);
%}

%union {
    int intval;
    char* strval;
}

%token MV_COMMAND LS_COMMAND MKDIR_COMMAND CP_COMMAND HEAD_COMMAND PKILL_COMMAND IP_COMMAND NETSTAT_COMMAND CURL_COMMAND
%token<strval> PARAM_NAME PARAM_VALUE CMD_SEPARATOR HEAD_PARAM
%token<intval> INT_VALUE
%type<strval> mv_all_options line path_dst mv_line ls_line ls_all_options mkdir_line mkdir_all_options cp_line cp_all_options cp_file_dest head_line head_all_options head_all_paths pkill_line pkill_all_options pkill_param ip_line ip_all_options netstat_line curl_line curl_all_options
%right PARAM_NAME       //DE PUS IN DOCUMENTATIE - am rezolvat un caz de ambiguitate in care analizorul de sintaxa nu stia cum sa trateze o valoare de parametru,
%left PARAM_VALUE       //intrucat nu avea vreo asociere intre un parametru propriu-zis si valoarea sa
%%

total:       line                           { printf("%s", $1); free($1); }
            | total CMD_SEPARATOR line      { printf("%s %s", $2, $3); free($3); free($2); }
            ;

line:       mv_line
            | ls_line
            | mkdir_line
            | cp_line
            | head_line
            | pkill_line
            | ip_line
            | netstat_line
            | curl_line
            ;

//--------------------------------- ls ----------------------------------------
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

//--------------------------------- mkdir ----------------------------------------
mkdir_line: MKDIR_COMMAND mkdir_all_options PARAM_VALUE               {
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "New-Item -ItemType Directory -Path %s %s", $3, $2);
                                                                    $$ = result;
                                                                }
            | MKDIR_COMMAND PARAM_VALUE mkdir_all_options             {
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "New-Item -Path %s -ItemType Directory %s", $2, $3);
                                                                    $$ = result;
                                                                }
            ;

mkdir_all_options:    PARAM_NAME PARAM_VALUE                          {
                                                                    char intermediar[128] = "";
                                                                    convertMKDIRParamName($1, intermediar);
                                                                    char* result = malloc(256);
                                                                    if(strcmp(intermediar, "") == 0)
                                                                        strcpy(result, "");
                                                                    else
                                                                        sprintf(result, "%s %s", intermediar, $2);
                                                                    $$ = result;
                                                                }
                | PARAM_NAME                                    {
                                                                    char intermediar[128] = "";
                                                                    convertMKDIRParamName($1, intermediar);
                                                                    $$ = strdup(intermediar);
                                                                } 
                | PARAM_NAME PARAM_VALUE mkdir_all_options           {
                                                                    char intermediar[128] = "";
                                                                    convertMKDIRParamName($1, intermediar);
                                                                    char* result = malloc(256);
                                                                    if(strcmp(intermediar, "") == 0)
                                                                        sprintf(result, "%s", $3);
                                                                    else
                                                                        sprintf(result, "%s %s %s", intermediar, $2, $3);
                                                                    $$ = result;
                                                                }
                | PARAM_NAME mkdir_all_options                        {
                                                                    char intermediar[128] = "";
                                                                    convertMKDIRParamName($1, intermediar);
                                                                    char* result = malloc(256);
                                                                    sprintf(result, "%s %s", intermediar, $2);
                                                                    $$ = result;
                                                                }
                ;


//--------------------------------- cp ----------------------------------------
cp_line:    CP_COMMAND cp_all_options cp_file_dest              {
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "Copy-Item %s %s", $3, $2);
                                                                    $$ = result;
                                                                }
            | CP_COMMAND cp_file_dest cp_all_options            {
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "Copy-Item %s %s", $2, $3);
                                                                    $$ = result;
                                                                }
            ;

cp_file_dest: PARAM_VALUE PARAM_VALUE                           {
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "%s -Destination %s", $1, $2);
                                                                    $$ = result;
                                                                }
              ;

cp_all_options:    PARAM_NAME PARAM_VALUE                          {
                                                                    char intermediar[128] = "";
                                                                    convertCPParamName($1, intermediar);
                                                                    char* result = malloc(256);
                                                                    if(strcmp(intermediar, "") == 0)
                                                                        strcpy(result, "");
                                                                    else
                                                                        sprintf(result, "%s %s", intermediar, $2);
                                                                    $$ = result;
                                                                }
                | PARAM_NAME                                    {
                                                                    char intermediar[128] = "";
                                                                    convertCPParamName($1, intermediar);
                                                                    $$ = strdup(intermediar);
                                                                } 
                | PARAM_NAME PARAM_VALUE cp_all_options           {
                                                                    char intermediar[128] = "";
                                                                    convertCPParamName($1, intermediar);
                                                                    char* result = malloc(256);
                                                                    if(strcmp(intermediar, "") == 0)
                                                                        sprintf(result, "%s", $3);
                                                                    else
                                                                        sprintf(result, "%s %s %s", intermediar, $2, $3);
                                                                    $$ = result;
                                                                }
                | PARAM_NAME cp_all_options                        {
                                                                    char intermediar[128] = "";
                                                                    convertCPParamName($1, intermediar);
                                                                    char* result = malloc(256);
                                                                    sprintf(result, "%s %s", intermediar, $2);
                                                                    $$ = result;
                                                                }
                ;


//--------------------------------- head ----------------------------------------
head_line: HEAD_COMMAND head_all_options head_all_paths         {
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "Get-Content %s -Path %s", $2, $3);
                                                                    $$ = result;
                                                                }
            ;
head_all_paths: PARAM_VALUE                                     { $$ = strdup($1); }
                | PARAM_VALUE head_all_paths                    {
                                                                    char* result = malloc(512);
                                                                    sprintf(result,"%s %s", $1, $2);
                                                                    $$ = result;
                                                                }
                ;

head_all_options:   HEAD_PARAM INT_VALUE                    {
                                                                    char* result = malloc(256);
                                                                    char intermediar[128] = "";
                                                                    convertHeadParams($1, $2, intermediar);
                                                                    strcpy(result, intermediar);
                                                                    $$ = result;
                                                                }
                    | HEAD_PARAM INT_VALUE head_all_options   {
                                                                    char* result = malloc(512);
                                                                    char intermediar[128] = "";
                                                                    convertHeadParams($1, $2, intermediar);
                                                                    sprintf(result, "%s %s", intermediar, $3);
                                                                    $$ = result;
                                                                }
                    | PARAM_NAME head_all_options               {
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "%s", $2);
                                                                    $$ = result;
                                                                }
                    ;

//--------------------------------- pkill ----------------------------------------
pkill_line: PKILL_COMMAND PARAM_VALUE                           {
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "Stop-Process %s", $2);
                                                                    $$ = result;
                                                                }
            | PKILL_COMMAND pkill_all_options                   {
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "Stop-Process %s", $2);
                                                                    $$ = result;
                                                                }
            ;

pkill_all_options:  pkill_param PARAM_VALUE                      {
                                                                    char intermediar[128] = "";
                                                                    convertPKILLParamName($1, intermediar);
                                                                    char* result = malloc(256);
                                                                    sprintf(result, "%s %s", intermediar, $2);
                                                                    $$ = result;
                                                                }
                    | pkill_param                                {
                                                                    char intermediar[128] = "";
                                                                    convertPKILLParamName($1, intermediar);
                                                                    char* result = malloc(256);
                                                                    sprintf(result, "%s", intermediar);
                                                                    $$ = result;
                                                                }
                    | pkill_param PARAM_VALUE pkill_all_options  {
                                                                    char intermediar[128] = "";
                                                                    convertPKILLParamName($1, intermediar);
                                                                    char* result = malloc(256);
                                                                    sprintf(result, "%s %s %s", intermediar, $2, $3);
                                                                    $$ = result;
                                                                }
                    | pkill_param pkill_all_options              {
                                                                    char intermediar[128] = "";
                                                                    convertPKILLParamName($1, intermediar);
                                                                    char* result = malloc(256);
                                                                    sprintf(result, "%s %s", intermediar, $2);
                                                                    $$ = result;
                                                                }
                    ;

pkill_param:        PARAM_NAME                                  {
                                                                    $$ = strdup($1);
                                                                }
                    | INT_VALUE                                 {
                                                                    char* conversion = malloc(10);
                                                                    sprintf(conversion, "%d", $1);
                                                                    $$ = conversion;
                                                                }
                    ;

//--------------------------------- ip ----------------------------------------
ip_line:    IP_COMMAND PARAM_VALUE                              {
                                                                    char* result = malloc(20);
                                                                    strcpy(result, "Get-NetIpAddress");
                                                                    $$ = result;
                                                                }
            | IP_COMMAND ip_all_options PARAM_VALUE             {
                                                                    char* result = malloc(20);
                                                                    strcpy(result, "Get-NetIpAddress");
                                                                    $$ = result;
                                                                }
            ;

ip_all_options: PARAM_NAME
                | PARAM_NAME ip_all_options


//--------------------------------- netstat ----------------------------------------
netstat_line:   NETSTAT_COMMAND netstat_all_options netstat_arg     {
                                                                        char* result = malloc(22);
                                                                        strcpy(result, "Get-NetTcpConnection");
                                                                        $$ = result;
                                                                    }
                ;

netstat_arg: PARAM_VALUE
            |
            ;

netstat_all_options:    PARAM_NAME
                        | PARAM_NAME netstat_all_options
                        ;

//--------------------------------- curl ----------------------------------------
curl_line:  CURL_COMMAND curl_all_options PARAM_VALUE               {
                                                                        char* result = malloc(512);
                                                                        sprintf(result, "Invoke-WebRequest -Uri %s %s", $3, $2);
                                                                        $$ = result;
                                                                    }
            | CURL_COMMAND PARAM_VALUE curl_all_options             {
                                                                        char* result = malloc(512);
                                                                        sprintf(result, "Invoke-WebRequest -Uri %s %s", $2, $3);
                                                                        $$ = result;
                                                                    }
            ;

curl_all_options:       PARAM_NAME PARAM_VALUE                      {
                                                                        char intermediar[128] = "";
                                                                        convertCURLParamName($1, intermediar);
                                                                        char* result = malloc(256);
                                                                        sprintf(result, "%s %s", intermediar, $2);
                                                                        $$ = result;
                                                                    }
                        | PARAM_NAME                                {
                                                                        char intermediar[128] = "";
                                                                        convertCURLParamName($1, intermediar);
                                                                        $$ = strdup(intermediar);
                                                                    }
                        | PARAM_NAME PARAM_VALUE curl_all_options   {
                                                                        char intermediar[128] = "";
                                                                        convertCURLParamName($1, intermediar);
                                                                        char* result = malloc(256);
                                                                        sprintf(result, "%s %s %s", intermediar, $2, $3);
                                                                        $$ = result;
                                                                    }
                        | PARAM_NAME curl_all_options               {
                                                                        char intermediar[128] = "";
                                                                        convertCURLParamName($1, intermediar);
                                                                        char* result = malloc(256);
                                                                        sprintf(result, "%s %s", intermediar, $2);
                                                                        $$ = result;
                                                                    }
                        ;

//--------------------------------- mv ----------------------------------------
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
                                                                    if(strcmp(intermediar, "") == 0)
                                                                        strcpy(result, "");
                                                                    else
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
                                                                    if(strcmp(intermediar, "") == 0)
                                                                        strcpy(result, "");
                                                                    else
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
void convertMKDIRParamName(char* pname, char* output) {
    if(strcmp(pname, "-p") == 0 || strcmp(pname, "--parents") == 0 || strcmp(pname, "-v")==0 || strcmp(pname, "--verbose") == 0) {
        strcpy(output, "");
    }
}
void convertCPParamName(char* pname, char* output) {
    if(strcmp(pname, "-f") == 0 || strcmp(pname, "--force")==0) {
        strcpy(output, "-Force");
    }
    else if(strcmp(pname, "-r") == 0 || strcmp(pname, "-R") == 0 || strcmp(pname, "--recursive")) {
        strcpy(output, "-Recurse");
    }
    else if(strcmp(pname, "-H") == 0 || strcmp(pname, "-l") == 0 || strcmp(pname, "--link") == 0 || strcmp(pname, "-L") == 0 || strcmp(pname, "--dereference") == 0 || strcmp(pname, "-s") == 0 || strcmp(pname, "--symbolic-link") == 0) {
        strcpy(output, "");
    }
}
void convertHeadParams(char* pname, int pvalue, char* output) {
    if(strcmp(pname, "-n") == 0 || strcmp(pname, "--lines") == 0) {
        if(pvalue < 0)
            sprintf(output, "-Tail %d", -pvalue);
        else
            sprintf(output, "-TotalCount %d", pvalue);
    }
    else if(strcmp(pname, "-c") == 0 || strcmp(pname, "--bytes") == 0) {
        if(pvalue < 0)
            sprintf(output, "-Encoding Byte -Tail %d", -pvalue);
        else
            sprintf(output, "-Encoding Byte -TotalCount %d", pvalue);
    }
    else
        strcpy(output, "");
}
void convertPKILLParamName(char* pname, char* output) {
    if(strcmp(pname, "-9") == 0 || strcmp(pname, "-SIGKILL") == 0) {
        strcpy(output, "-Force");
    }
    else if(strcmp(pname, "-P") == 0 || strcmp(pname, "--parent") == 0) {
        strcpy(output, "-Id");
    }
    else if(strcmp(pname, "-f") == 0 || strcmp(pname, "--full")) {
        strcpy(output, "-Name");
    }
    else {
        strcpy(output, "");
    }
}
void convertCURLParamName(char* pname, char* output) {
    if(strcmp(pname, "-d") == 0 || strcmp(pname, "--data") == 0) {
        strcpy(output, "-Body");
    }
    else if(strcmp(pname, "-o")==0 || strcmp(pname, "--output") == 0) {
        strcpy(output, "-OutFile");
    }
    else if(strcmp(pname, "-T") == 0 || strcmp(pname, "--output-file") == 0) {
        strcpy(output, "-InFile");
    }
    else if(strcmp(pname, "-A") == 0 || strcmp(pname, "--user-agent") == 0) {
        strcpy(output, "-UserAgent");
    }
    else {
        strcpy(output, "");
    }
}
