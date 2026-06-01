%{
#include "y.tab.h"
#include <string.h>
%}
%option noyywrap
%%
ls                  { return LS_COMMAND; }
mv                  { return MV_COMMAND; }
mkdir               { return MKDIR_COMMAND; }
cp                  { return CP_COMMAND; }
head                { return HEAD_COMMAND; }
pkill               { return PKILL_COMMAND; }
ip                  { return IP_COMMAND; }
netstat             { return NETSTAT_COMMAND; }
curl                { return CURL_COMMAND; }
(\-c)|(\-\-bytes)|(\-n)|(\-\-lines)     { yylval.strval = strdup(yytext); return HEAD_PARAM; }
\-?[0-9]+           { yylval.intval = atoi(yytext); return INT_VALUE;}
\-(\-)?[a-zA-Z\-]+        { yylval.strval = strdup(yytext); return PARAM_NAME; }
[a-zA-Z\_0-9\.\/\:\\]+      { yylval.strval = strdup(yytext); return PARAM_VALUE; }
[ \t]               ;
(\n|\|)             { yylval.strval = strdup(yytext); return CMD_SEPARATOR; }
.                   return yytext[0];
%%
