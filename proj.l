/* proj.l */
%{
#include "y.tab.h"  
#include <string.h>  
%}
%option noyywrap
%%
mv                  { return MV_COMMAND; }
-[a-z]+             { strcpy(yylval.strval, yytext); return PARAM_NAME; }
[a-zA-Z\\_0-9\.]+     { strcpy(yylval.strval, yytext); return PARAM_VALUE; }
[ \t]               ;
"\n"                return *yytext;
%%