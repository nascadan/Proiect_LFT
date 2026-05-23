%{
#include "y.tab.h"
#include <string.h>
%}
%option noyywrap
%%
mv                  { return MV_COMMAND; }
-[a-zA-Z\-]+        { yylval.strval = strdup(yytext); return PARAM_NAME; }
[a-zA-Z\_0-9\.]+      { yylval.strval = strdup(yytext); return PARAM_VALUE; }
[ \t]               ;
"\n"                return *yytext;
.                   return yytext[0];
%%
