%{
#include "y.tab.h"
#include <string.h>
%}
%option noyywrap
%%
ls                  { return LS_COMMAND; }
mv                  { return MV_COMMAND; }
pwd                 { return PWD_COMMAND; }
touch               { return TOUCH_COMMAND; }
rm                  { return RM_COMMAND; }
grep                { return GREP_COMMAND; }
cat                 { return CAT_COMMAND; }
ps                  { return PS_COMMAND; }
clear               { return CLEAR_COMMAND; }
history             { return HISTORY_COMMAND; }
\-[a-zA-Z\-]+        { yylval.strval = strdup(yytext); return PARAM_NAME; }
[a-zA-Z\_0-9\.\/\:\\]+      { yylval.strval = strdup(yytext); return PARAM_VALUE; }
[ \t]               ;
(\n|\|)             { yylval.strval = strdup(yytext); return CMD_SEPARATOR; }
.                   return yytext[0];
%%
