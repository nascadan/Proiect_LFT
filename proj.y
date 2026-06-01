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

%token MV_COMMAND LS_COMMAND PWD_COMMAND TOUCH_COMMAND RM_COMMAND GREP_COMMAND CAT_COMMAND PS_COMMAND CLEAR_COMMAND HISTORY_COMMAND MKDIR_COMMAND CP_COMMAND HEAD_COMMAND PKILL_COMMAND IP_COMMAND NETSTAT_COMMAND CURL_COMMAND
%token<strval> PARAM_NAME PARAM_VALUE CMD_SEPARATOR HEAD_PARAM
%token<intval> INT_VALUE
%type<strval> mv_all_options line path_dst mv_line ls_line ls_all_options pwd_line pwd_all_options touch_line touch_all_options rm_line rm_all_options grep_line grep_all_options grep_args cat_line cat_all_options ps_line ps_all_options clear_line history_line mkdir_line mkdir_all_options cp_line cp_all_options cp_file_dest head_line head_all_options head_all_paths pkill_line pkill_all_options pkill_param ip_line ip_all_options netstat_line curl_line curl_all_options

%right PARAM_NAME
%left PARAM_VALUE
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
            | mkdir_line
            | cp_line
            | head_line
            | pkill_line
            | ip_line
            | netstat_line
            | curl_line
            ;

//--------------------------------- ls ----------------------------------------
ls_line:    LS_COMMAND ls_all_options                               {
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "Get-ChildItem %s", $2);
                                                                    $$ = result;
                                                                }
            | LS_COMMAND ls_all_options PARAM_VALUE                 {
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "Get-ChildItem %s %s", $2, $3);
                                                                    $$ = result;
                                                                }
            | LS_COMMAND PARAM_VALUE ls_all_options                 {
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "Get-ChildItem %s %s", $3, $2);
                                                                    $$ = result;
                                                                }
            | LS_COMMAND                                            {
                                                                    $$ = strdup("Get-ChildItem");
                                                                }
            | LS_COMMAND PARAM_VALUE                                {
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "Get-ChildItem -Path %s", $2);
                                                                    $$ = result;
                                                                }
            ;

ls_all_options: PARAM_NAME                                    {
                                                                    char intermediar[128] = "";
                                                                    convertLSParamName($1, intermediar);
                                                                    $$ = strdup(intermediar);
                                                                } 
                | PARAM_NAME ls_all_options                        {
                                                                    char intermediar[128] = "";
                                                                    convertLSParamName($1, intermediar);
                                                                    char* result = malloc(256);
                                                                    if(strcmp(intermediar, "") == 0)
                                                                        sprintf(result, "%s", $2);
                                                                    else
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
            | MKDIR_COMMAND mkdir_all_options                         {
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "New-Item -ItemType Directory %s", $2);
                                                                    $$ = result;
                                                                }
            | MKDIR_COMMAND PARAM_VALUE                               {
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "New-Item -ItemType Directory -Path %s", $2);
                                                                    $$ = result;
                                                                }
            ;

mkdir_all_options: PARAM_NAME                                    {
                                                                    char intermediar[128] = "";
                                                                    convertMKDIRParamName($1, intermediar);
                                                                    $$ = strdup(intermediar);
                                                                } 
                | PARAM_NAME mkdir_all_options                        {
                                                                    char intermediar[128] = "";
                                                                    convertMKDIRParamName($1, intermediar);
                                                                    char* result = malloc(256);
                                                                    if(strcmp(intermediar, "") == 0)
                                                                        sprintf(result, "%s", $2);
                                                                    else
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
            | CP_COMMAND cp_file_dest                           {
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "Copy-Item %s", $2);
                                                                    $$ = result;
                                                                }
            ;

cp_file_dest: PARAM_VALUE PARAM_VALUE                           {
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "%s -Destination %s", $1, $2);
                                                                    $$ = result;
                                                                }
              ;

cp_all_options: PARAM_NAME                                    {
                                                                    char intermediar[128] = "";
                                                                    convertCPParamName($1, intermediar);
                                                                    $$ = strdup(intermediar);
                                                                } 
                | PARAM_NAME cp_all_options                        {
                                                                    char intermediar[128] = "";
                                                                    convertCPParamName($1, intermediar);
                                                                    char* result = malloc(256);
                                                                    if(strcmp(intermediar, "") == 0)
                                                                        sprintf(result, "%s", $2);
                                                                    else
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
                ;

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
            | MV_COMMAND path_dst                                  {
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "Move-Item %s", $2);
                                                                    $$ = result;
                                                                }
            ;
path_dst: PARAM_VALUE PARAM_VALUE                               {
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "-Path %s -Destination %s", $1, $2);
                                                                    $$ = result;
                                                                }
            ;

mv_all_options: PARAM_NAME                                    {
                                                                    char intermediar[128] = "";
                                                                    convertMVParamName($1, intermediar);
                                                                    $$ = strdup(intermediar);
                                                                } 
                | PARAM_NAME mv_all_options                        {
                                                                    char intermediar[128] = "";
                                                                    convertMVParamName($1, intermediar);
                                                                    char* result = malloc(256);
                                                                    if(strcmp(intermediar, "") == 0)
                                                                        sprintf(result, "%s", $2);
                                                                    else
                                                                        sprintf(result, "%s %s", intermediar, $2);
                                                                    $$ = result;
                                                                }
                ;

//--------------------------------- pwd ----------------------------------------
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

//--------------------------------- touch ----------------------------------------
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

//--------------------------------- rm ----------------------------------------
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

//--------------------------------- grep ----------------------------------------
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

//--------------------------------- cat ----------------------------------------
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

//--------------------------------- ps ----------------------------------------
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
                                                                    sprintf(result, "Get-Process -Name %s", $2);
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

//--------------------------------- clear ----------------------------------------
clear_line: CLEAR_COMMAND                                       {
                                                                    $$ = strdup("Clear-Host");
                                                                }
            ;

//--------------------------------- history ----------------------------------------
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

int main()
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

void convertMKDIRParamName(char* pname, char* output) {
    if(strcmp(pname, "-p") == 0 || strcmp(pname, "--parents") == 0 || strcmp(pname, "-v")==0 || strcmp(pname, "--verbose") == 0) {
        strcpy(output, "");
    }
}

void convertCPParamName(char* pname, char* output) {
    if(strcmp(pname, "-f") == 0 || strcmp(pname, "--force")==0) {
        strcpy(output, "-Force");
    }
    else if(strcmp(pname, "-r") == 0 || strcmp(pname, "-R") == 0 || strcmp(pname, "--recursive") == 0) {
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
    else if(strcmp(pname, "-f") == 0 || strcmp(pname, "--full") == 0) {
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
