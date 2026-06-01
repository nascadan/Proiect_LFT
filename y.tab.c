/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 2
#define YYMINOR 0
#define YYPATCH 20241231

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#undef YYBTYACC
#define YYBTYACC 0
#define YYDEBUGSTR YYPREFIX "debug"
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "proj.y"
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
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#line 22 "proj.y"
typedef union YYSTYPE {
    int intval;
    char* strval;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 55 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

#if !(defined(yylex) || defined(YYSTATE))
int YYLEX_DECL();
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define MV_COMMAND 257
#define LS_COMMAND 258
#define PWD_COMMAND 259
#define TOUCH_COMMAND 260
#define RM_COMMAND 261
#define GREP_COMMAND 262
#define CAT_COMMAND 263
#define PS_COMMAND 264
#define CLEAR_COMMAND 265
#define HISTORY_COMMAND 266
#define MKDIR_COMMAND 267
#define CP_COMMAND 268
#define HEAD_COMMAND 269
#define PKILL_COMMAND 270
#define IP_COMMAND 271
#define NETSTAT_COMMAND 272
#define CURL_COMMAND 273
#define PARAM_NAME 274
#define PARAM_VALUE 275
#define CMD_SEPARATOR 276
#define HEAD_PARAM 277
#define INT_VALUE 278
#define YYERRCODE 256
typedef int YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    0,    2,    2,    2,    2,    2,    2,    2,
    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,
    5,    5,    5,    5,    5,    6,    6,    6,    6,   22,
   22,   23,   23,   23,   23,   24,   24,   26,   25,   25,
   25,   25,   27,   29,   29,   28,   28,   28,   30,   30,
   31,   31,   31,   31,   32,   32,   33,   33,   34,   34,
   35,   39,   39,   38,   38,   36,   36,   37,   37,   37,
   37,    4,    4,    3,    1,    1,    1,    1,    7,    7,
    8,    8,    8,    8,    9,    9,    9,    9,   10,   10,
   10,   10,   11,   11,   11,   11,   12,   12,   12,   12,
   13,   13,   13,   13,   15,   15,   14,   14,   16,   16,
   16,   16,   16,   17,   17,   17,   17,   18,   18,   18,
   19,   19,   19,   19,   20,   21,   21,
};
static const YYINT yylen[] = {                            2,
    1,    3,    2,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    2,    3,    3,    1,    2,    2,    1,    3,    2,    3,
    3,    2,    1,    3,    2,    3,    3,    2,    2,    1,
    3,    2,    3,    1,    2,    2,    3,    2,    2,    2,
    2,    1,    3,    2,    1,    1,    2,    3,    1,    2,
    3,    1,    0,    1,    2,    3,    3,    2,    1,    3,
    2,    3,    3,    2,    2,    1,    3,    2,    1,    2,
    2,    1,    3,    2,    2,    3,    3,    2,    2,    1,
    3,    2,    2,    3,    3,    2,    2,    1,    3,    2,
    2,    3,    3,    2,    2,    1,    1,    2,    1,    2,
    3,    3,    2,    2,    1,    3,    2,    1,    2,    2,
    2,    1,    3,    2,    1,    1,    2,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,  125,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    1,    4,
    5,    6,    7,    8,    9,   10,   11,   12,   13,   14,
   15,   16,   17,   18,   19,   20,    0,    0,    0,    0,
    0,    0,    0,    0,   80,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  120,
  119,  127,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   55,   49,   56,   50,    0,    0,   57,    0,
    0,    0,    0,    0,    0,    0,    0,   78,   74,   72,
   73,    0,   29,   23,   22,    0,   84,    0,   92,   87,
   86,    0,  100,   95,   94,  108,  105,  102,  103,    0,
  117,  112,  111,    0,  124,    0,   35,   31,   30,    0,
   42,   38,   36,   37,   48,    0,    0,   43,    0,   54,
   60,   58,   65,   62,   61,    0,   71,   67,   66,    2,
   77,   28,   83,   91,   99,  116,  123,   34,   41,   47,
   45,   53,   70,
};
#if defined(YYDESTRUCT_CALL) || defined(YYSTYPE_TOSTRING)
static const YYINT yystos[] = {                           0,
  257,  258,  259,  260,  261,  262,  263,  264,  265,  266,
  267,  268,  269,  270,  271,  272,  273,  280,  282,  284,
  285,  287,  289,  291,  293,  296,  298,  300,  301,  302,
  304,  307,  310,  313,  315,  316,  274,  275,  281,  283,
  274,  275,  286,  274,  288,  274,  275,  290,  274,  275,
  292,  274,  275,  294,  295,  274,  275,  297,  274,  275,
  299,  275,  274,  275,  303,  274,  275,  305,  306,  274,
  277,  308,  274,  275,  278,  311,  312,  274,  275,  314,
  274,  318,  274,  275,  317,  276,  275,  281,  275,  283,
  281,  275,  286,  286,  275,  275,  288,  275,  290,  290,
  275,  275,  292,  292,  275,  294,  275,  295,  294,  275,
  297,  297,  275,  275,  299,  275,  303,  303,  275,  275,
  305,  275,  306,  305,  308,  278,  275,  309,  275,  311,
  314,  275,  318,  275,  319,  275,  317,  317,  275,  282,
  281,  286,  288,  290,  292,  297,  299,  303,  305,  308,
  309,  311,  317,
};
#endif /* YYDESTRUCT_CALL || YYSTYPE_TOSTRING */
static const YYINT yydgoto[] = {                         18,
   39,   19,   40,   20,   21,   43,   22,   45,   23,   48,
   24,   51,   25,   54,   55,   26,   58,   27,   61,   28,
   29,   30,   65,   31,   68,   69,   32,   72,  128,   33,
   76,   77,   34,   80,   35,   36,   85,   82,  135,
};
static const YYINT yysindex[] = {                      -187,
 -171, -169, -263, -165, -158, -153, -151, -149,    0, -262,
 -147, -145, -175, -186, -143, -259, -141, -257,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0, -139, -254, -215, -210,
 -137, -181, -188, -135,    0, -133, -167, -162, -131, -155,
 -129, -115, -114, -113, -115, -126, -111, -110, -124,    0,
    0,    0, -121, -108, -107, -119, -106, -105, -103, -175,
 -118, -102,    0,    0,    0,    0, -184, -100,    0,  -99,
 -259,  -98, -117,  -96,  -95, -187, -210,    0,    0,    0,
    0, -181,    0,    0,    0, -263,    0, -167,    0,    0,
    0, -155,    0,    0,    0,    0,    0,    0,    0, -111,
    0,    0,    0,  -93,    0, -108,    0,    0,    0, -103,
    0,    0,    0,    0,    0, -175, -102,    0, -269,    0,
    0,    0,    0,    0,    0,  -96,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    3,   23,    0,    0,    0,   24,   25,    0,   26,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   27,    0,    0,    0,
   28,   29,   30,   31,    0,   32,   33,   34,   35,   36,
   37,    1,    4,   38,   39,   40,   41,   42,   43,    0,
    0,    0,   44,    0,    0,   45,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   46,  -92,    0,    0,
    6,   47,   48,    0,    0,   49,    8,    0,    0,    0,
    0,   10,    0,    0,    0,   50,    0,   12,    0,    0,
    0,   14,    0,    0,    0,    0,    0,    0,    0,   16,
    0,    0,    0,   51,    0,   18,    0,    0,    0,   20,
    0,    0,    0,    0,    0,  -91,   52,    0,   53,    0,
    0,    0,    0,    0,    0,   22,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,
};
#if YYBTYACC
static const YYINT yycindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,
};
#endif
static const YYINT yygindex[] = {                         0,
   58,   78,  128,    0,    0,   55,    0,  -37,    0,   54,
    0,   13,    0,   59,  118,    0,   -2,    0,  -57,    0,
    0,    0,    2,    0,   -8,  107,    0,  -70,   60,    0,
  -60,    0,    0,  101,    0,    0,  -16,  104,    0,
};
#define YYTABLESIZE 329
static const YYINT yytable[] = {                        125,
  107,  115,   24,  106,   73,   64,   97,   75,   75,   26,
   44,   89,   62,   97,   81,  114,  130,   32,   86,   39,
   89,   68,   79,  109,  118,  126,   76,   27,   25,   21,
   82,   90,   85,   88,   98,   93,   96,  104,  101,  115,
  110,  113,  122,   33,   40,   52,   63,   69,    3,   81,
  121,   44,   51,  111,  112,  150,  147,  121,  143,   38,
  124,  103,  104,   37,  117,  118,  137,  138,  152,    1,
    2,    3,    4,    5,    6,    7,    8,    9,   10,   11,
   12,   13,   14,   15,   16,   17,   95,   73,   74,   73,
  129,   75,   41,   75,   88,   93,   94,   91,   70,   99,
  100,   71,   37,   38,   41,   42,   46,  146,   46,   47,
  106,  149,  101,  109,  145,   49,   50,  148,   49,  153,
   52,   53,   56,   57,   59,   60,   63,   64,   66,   67,
   78,   79,   83,   84,   37,   87,   41,   92,   44,   96,
   46,   98,   49,  102,  141,  105,  142,   56,  110,   59,
  114,  144,   63,  116,   66,  120,   83,  136,   52,  126,
  107,   53,   56,  140,  113,   63,   90,  119,  122,   67,
   66,  108,  127,   78,  123,  132,  134,   83,  131,  139,
   59,    0,   59,   46,  133,    0,  151,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  107,  107,  106,   24,  106,
   64,   64,   75,   75,   26,   26,   89,   89,   97,   97,
  114,  114,   32,   32,   39,   39,   68,   68,   79,  109,
  118,  126,   76,   27,   25,   21,   82,   90,   85,   88,
   98,   93,   96,  104,  101,  115,  110,  113,  122,   33,
   40,   52,   63,   69,    3,   81,  121,   44,   51,
};
static const YYINT yycheck[] = {                         70,
    0,   59,    0,    0,  274,    0,   44,    0,  278,    0,
  274,    0,  275,    0,  274,    0,   77,    0,  276,    0,
  275,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   56,   57,  126,  114,   66,   96,  275,
   69,   49,   50,  274,   63,   64,   83,   84,  129,  257,
  258,  259,  260,  261,  262,  263,  264,  265,  266,  267,
  268,  269,  270,  271,  272,  273,  275,  274,  275,  274,
  275,  278,  274,  278,   37,   41,   42,   40,  274,   46,
   47,  277,  274,  275,  274,  275,  274,  110,  274,  275,
   52,  120,  275,   55,  102,  274,  275,  116,  274,  136,
  274,  275,  274,  275,  274,  275,  274,  275,  274,  275,
  274,  275,  274,  275,  274,  275,  274,  275,  274,  275,
  274,  275,  274,  275,   87,  275,   92,  274,  275,  274,
  275,   98,  274,  275,  274,  275,  274,  275,  274,  278,
  275,  275,  274,   86,  275,  274,   39,  275,  275,  275,
  274,   54,  275,  274,   68,  275,  275,  274,   78,  275,
  274,   -1,  275,  275,   81,   -1,  127,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  275,  276,  274,  276,  276,
  275,  276,  275,  276,  275,  276,  275,  276,  275,  276,
  275,  276,  275,  276,  275,  276,  275,  276,  276,  276,
  276,  276,  276,  276,  276,  276,  276,  276,  276,  276,
  276,  276,  276,  276,  276,  276,  276,  276,  276,  276,
  276,  276,  276,  276,  276,  276,  276,  276,  276,
};
#if YYBTYACC
static const YYINT yyctable[] = {                        -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
};
#endif
#define YYFINAL 18
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 278
#define YYUNDFTOKEN 320
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
#ifndef NULL
#define NULL (void*)0
#endif
static const char *const yyname[] = {

"$end",NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,
NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,
NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,
NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,
NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,
NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,
NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,
NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,
NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,
NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,
NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,
NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,
NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,
NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,
NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,
NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,
NULL,"error","MV_COMMAND","LS_COMMAND","PWD_COMMAND","TOUCH_COMMAND",
"RM_COMMAND","GREP_COMMAND","CAT_COMMAND","PS_COMMAND","CLEAR_COMMAND",
"HISTORY_COMMAND","MKDIR_COMMAND","CP_COMMAND","HEAD_COMMAND","PKILL_COMMAND",
"IP_COMMAND","NETSTAT_COMMAND","CURL_COMMAND","PARAM_NAME","PARAM_VALUE",
"CMD_SEPARATOR","HEAD_PARAM","INT_VALUE","$accept","total","mv_all_options",
"line","path_dst","mv_line","ls_line","ls_all_options","pwd_line",
"pwd_all_options","touch_line","touch_all_options","rm_line","rm_all_options",
"grep_line","grep_all_options","grep_args","cat_line","cat_all_options",
"ps_line","ps_all_options","clear_line","history_line","mkdir_line",
"mkdir_all_options","cp_line","cp_all_options","cp_file_dest","head_line",
"head_all_options","head_all_paths","pkill_line","pkill_all_options",
"pkill_param","ip_line","ip_all_options","netstat_line","curl_line",
"curl_all_options","netstat_all_options","netstat_arg","illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : total",
"total : line",
"total : total CMD_SEPARATOR line",
"total : total CMD_SEPARATOR",
"line : mv_line",
"line : ls_line",
"line : pwd_line",
"line : touch_line",
"line : rm_line",
"line : grep_line",
"line : cat_line",
"line : ps_line",
"line : clear_line",
"line : history_line",
"line : mkdir_line",
"line : cp_line",
"line : head_line",
"line : pkill_line",
"line : ip_line",
"line : netstat_line",
"line : curl_line",
"ls_line : LS_COMMAND ls_all_options",
"ls_line : LS_COMMAND ls_all_options PARAM_VALUE",
"ls_line : LS_COMMAND PARAM_VALUE ls_all_options",
"ls_line : LS_COMMAND",
"ls_line : LS_COMMAND PARAM_VALUE",
"ls_all_options : PARAM_NAME PARAM_VALUE",
"ls_all_options : PARAM_NAME",
"ls_all_options : PARAM_NAME PARAM_VALUE ls_all_options",
"ls_all_options : PARAM_NAME ls_all_options",
"mkdir_line : MKDIR_COMMAND mkdir_all_options PARAM_VALUE",
"mkdir_line : MKDIR_COMMAND PARAM_VALUE mkdir_all_options",
"mkdir_all_options : PARAM_NAME PARAM_VALUE",
"mkdir_all_options : PARAM_NAME",
"mkdir_all_options : PARAM_NAME PARAM_VALUE mkdir_all_options",
"mkdir_all_options : PARAM_NAME mkdir_all_options",
"cp_line : CP_COMMAND cp_all_options cp_file_dest",
"cp_line : CP_COMMAND cp_file_dest cp_all_options",
"cp_file_dest : PARAM_VALUE PARAM_VALUE",
"cp_all_options : PARAM_NAME PARAM_VALUE",
"cp_all_options : PARAM_NAME",
"cp_all_options : PARAM_NAME PARAM_VALUE cp_all_options",
"cp_all_options : PARAM_NAME cp_all_options",
"head_line : HEAD_COMMAND head_all_options head_all_paths",
"head_all_paths : PARAM_VALUE",
"head_all_paths : PARAM_VALUE head_all_paths",
"head_all_options : HEAD_PARAM INT_VALUE",
"head_all_options : HEAD_PARAM INT_VALUE head_all_options",
"head_all_options : PARAM_NAME head_all_options",
"pkill_line : PKILL_COMMAND PARAM_VALUE",
"pkill_line : PKILL_COMMAND pkill_all_options",
"pkill_all_options : pkill_param PARAM_VALUE",
"pkill_all_options : pkill_param",
"pkill_all_options : pkill_param PARAM_VALUE pkill_all_options",
"pkill_all_options : pkill_param pkill_all_options",
"pkill_param : PARAM_NAME",
"pkill_param : INT_VALUE",
"ip_line : IP_COMMAND PARAM_VALUE",
"ip_line : IP_COMMAND ip_all_options PARAM_VALUE",
"ip_all_options : PARAM_NAME",
"ip_all_options : PARAM_NAME ip_all_options",
"netstat_line : NETSTAT_COMMAND netstat_all_options netstat_arg",
"netstat_arg : PARAM_VALUE",
"netstat_arg :",
"netstat_all_options : PARAM_NAME",
"netstat_all_options : PARAM_NAME netstat_all_options",
"curl_line : CURL_COMMAND curl_all_options PARAM_VALUE",
"curl_line : CURL_COMMAND PARAM_VALUE curl_all_options",
"curl_all_options : PARAM_NAME PARAM_VALUE",
"curl_all_options : PARAM_NAME",
"curl_all_options : PARAM_NAME PARAM_VALUE curl_all_options",
"curl_all_options : PARAM_NAME curl_all_options",
"mv_line : MV_COMMAND mv_all_options path_dst",
"mv_line : MV_COMMAND path_dst mv_all_options",
"path_dst : PARAM_VALUE PARAM_VALUE",
"mv_all_options : PARAM_NAME PARAM_VALUE",
"mv_all_options : PARAM_NAME",
"mv_all_options : PARAM_NAME PARAM_VALUE mv_all_options",
"mv_all_options : PARAM_NAME mv_all_options",
"pwd_line : PWD_COMMAND",
"pwd_line : PWD_COMMAND pwd_all_options",
"pwd_all_options : PARAM_NAME PARAM_VALUE",
"pwd_all_options : PARAM_NAME",
"pwd_all_options : PARAM_NAME PARAM_VALUE pwd_all_options",
"pwd_all_options : PARAM_NAME pwd_all_options",
"touch_line : TOUCH_COMMAND PARAM_VALUE",
"touch_line : TOUCH_COMMAND touch_all_options PARAM_VALUE",
"touch_line : TOUCH_COMMAND PARAM_VALUE touch_all_options",
"touch_line : TOUCH_COMMAND touch_all_options",
"touch_all_options : PARAM_NAME PARAM_VALUE",
"touch_all_options : PARAM_NAME",
"touch_all_options : PARAM_NAME PARAM_VALUE touch_all_options",
"touch_all_options : PARAM_NAME touch_all_options",
"rm_line : RM_COMMAND PARAM_VALUE",
"rm_line : RM_COMMAND rm_all_options PARAM_VALUE",
"rm_line : RM_COMMAND PARAM_VALUE rm_all_options",
"rm_line : RM_COMMAND rm_all_options",
"rm_all_options : PARAM_NAME PARAM_VALUE",
"rm_all_options : PARAM_NAME",
"rm_all_options : PARAM_NAME PARAM_VALUE rm_all_options",
"rm_all_options : PARAM_NAME rm_all_options",
"grep_line : GREP_COMMAND grep_args",
"grep_line : GREP_COMMAND grep_all_options grep_args",
"grep_line : GREP_COMMAND grep_args grep_all_options",
"grep_line : GREP_COMMAND grep_all_options",
"grep_args : PARAM_VALUE PARAM_VALUE",
"grep_args : PARAM_VALUE",
"grep_all_options : PARAM_NAME",
"grep_all_options : PARAM_NAME grep_all_options",
"cat_line : CAT_COMMAND",
"cat_line : CAT_COMMAND PARAM_VALUE",
"cat_line : CAT_COMMAND cat_all_options PARAM_VALUE",
"cat_line : CAT_COMMAND PARAM_VALUE cat_all_options",
"cat_line : CAT_COMMAND cat_all_options",
"cat_all_options : PARAM_NAME PARAM_VALUE",
"cat_all_options : PARAM_NAME",
"cat_all_options : PARAM_NAME PARAM_VALUE cat_all_options",
"cat_all_options : PARAM_NAME cat_all_options",
"ps_line : PS_COMMAND",
"ps_line : PS_COMMAND ps_all_options",
"ps_line : PS_COMMAND PARAM_VALUE",
"ps_all_options : PARAM_NAME PARAM_VALUE",
"ps_all_options : PARAM_NAME",
"ps_all_options : PARAM_NAME PARAM_VALUE ps_all_options",
"ps_all_options : PARAM_NAME ps_all_options",
"clear_line : CLEAR_COMMAND",
"history_line : HISTORY_COMMAND",
"history_line : HISTORY_COMMAND PARAM_VALUE",

};
#endif

#if YYDEBUG
int      yydebug;
#endif

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;
int      yynerrs;

#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
YYLTYPE  yyloc; /* position returned by actions */
YYLTYPE  yylloc; /* position from the lexer */
#endif

#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
#ifndef YYLLOC_DEFAULT
#define YYLLOC_DEFAULT(loc, rhs, n) \
do \
{ \
    if (n == 0) \
    { \
        (loc).first_line   = YYRHSLOC(rhs, 0).last_line; \
        (loc).first_column = YYRHSLOC(rhs, 0).last_column; \
        (loc).last_line    = YYRHSLOC(rhs, 0).last_line; \
        (loc).last_column  = YYRHSLOC(rhs, 0).last_column; \
    } \
    else \
    { \
        (loc).first_line   = YYRHSLOC(rhs, 1).first_line; \
        (loc).first_column = YYRHSLOC(rhs, 1).first_column; \
        (loc).last_line    = YYRHSLOC(rhs, n).last_line; \
        (loc).last_column  = YYRHSLOC(rhs, n).last_column; \
    } \
} while (0)
#endif /* YYLLOC_DEFAULT */
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */
#if YYBTYACC

#ifndef YYLVQUEUEGROWTH
#define YYLVQUEUEGROWTH 32
#endif
#endif /* YYBTYACC */

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#ifndef YYINITSTACKSIZE
#define YYINITSTACKSIZE 200
#endif

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    YYLTYPE  *p_base;
    YYLTYPE  *p_mark;
#endif
} YYSTACKDATA;
#if YYBTYACC

struct YYParseState_s
{
    struct YYParseState_s *save;    /* Previously saved parser state */
    YYSTACKDATA            yystack; /* saved parser stack */
    int                    state;   /* saved parser state */
    int                    errflag; /* saved error recovery status */
    int                    lexeme;  /* saved index of the conflict lexeme in the lexical queue */
    YYINT                  ctry;    /* saved index in yyctable[] for this conflict */
};
typedef struct YYParseState_s YYParseState;
#endif /* YYBTYACC */
/* variables for the parser stack */
static YYSTACKDATA yystack;
#if YYBTYACC

/* Current parser state */
static YYParseState *yyps = NULL;

/* yypath != NULL: do the full parse, starting at *yypath parser state. */
static YYParseState *yypath = NULL;

/* Base of the lexical value queue */
static YYSTYPE *yylvals = NULL;

/* Current position at lexical value queue */
static YYSTYPE *yylvp = NULL;

/* End position of lexical value queue */
static YYSTYPE *yylve = NULL;

/* The last allocated position at the lexical value queue */
static YYSTYPE *yylvlim = NULL;

#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
/* Base of the lexical position queue */
static YYLTYPE *yylpsns = NULL;

/* Current position at lexical position queue */
static YYLTYPE *yylpp = NULL;

/* End position of lexical position queue */
static YYLTYPE *yylpe = NULL;

/* The last allocated position at the lexical position queue */
static YYLTYPE *yylplim = NULL;
#endif

/* Current position at lexical token queue */
static YYINT  *yylexp = NULL;

static YYINT  *yylexemes = NULL;
#endif /* YYBTYACC */
#line 736 "proj.y"

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
#line 804 "y.tab.c"

/* For use in generated program */
#define yydepth (int)(yystack.s_mark - yystack.s_base)
#if YYBTYACC
#define yytrial (yyps->save)
#endif /* YYBTYACC */

#if YYDEBUG
#include <stdio.h>	/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    YYLTYPE *newps;
#endif

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == NULL)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == NULL)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    newps = (YYLTYPE *)realloc(data->p_base, newsize * sizeof(*newps));
    if (newps == NULL)
        return YYENOMEM;

    data->p_base = newps;
    data->p_mark = newps + i;
#endif

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;

#if YYDEBUG
    if (yydebug)
        fprintf(stderr, "%sdebug: stack size increased to %d\n", YYPREFIX, newsize);
#endif
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    free(data->p_base);
#endif
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif /* YYPURE || defined(YY_NO_LEAKS) */
#if YYBTYACC

static YYParseState *
yyNewState(unsigned size)
{
    YYParseState *p = (YYParseState *) malloc(sizeof(YYParseState));
    if (p == NULL) return NULL;

    p->yystack.stacksize = size;
    if (size == 0)
    {
        p->yystack.s_base = NULL;
        p->yystack.l_base = NULL;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        p->yystack.p_base = NULL;
#endif
        return p;
    }
    p->yystack.s_base    = (YYINT *) malloc(size * sizeof(YYINT));
    if (p->yystack.s_base == NULL) return NULL;
    p->yystack.l_base    = (YYSTYPE *) malloc(size * sizeof(YYSTYPE));
    if (p->yystack.l_base == NULL) return NULL;
    memset(p->yystack.l_base, 0, size * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    p->yystack.p_base    = (YYLTYPE *) malloc(size * sizeof(YYLTYPE));
    if (p->yystack.p_base == NULL) return NULL;
    memset(p->yystack.p_base, 0, size * sizeof(YYLTYPE));
#endif

    return p;
}

static void
yyFreeState(YYParseState *p)
{
    yyfreestack(&p->yystack);
    free(p);
}
#endif /* YYBTYACC */

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab
#if YYBTYACC
#define YYVALID        do { if (yyps->save)            goto yyvalid; } while(0)
#define YYVALID_NESTED do { if (yyps->save && \
                                yyps->save->save == 0) goto yyvalid; } while(0)
#endif /* YYBTYACC */

int
YYPARSE_DECL()
{
    int yym, yyn, yystate, yyresult;
#if YYBTYACC
    int yynewerrflag;
    YYParseState *yyerrctx = NULL;
#endif /* YYBTYACC */
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    YYLTYPE  yyerror_loc_range[3]; /* position of error start/end (0 unused) */
#endif
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != NULL)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
    if (yydebug)
        fprintf(stderr, "%sdebug[<# of symbols on state stack>]\n", YYPREFIX);
#endif
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    memset(yyerror_loc_range, 0, sizeof(yyerror_loc_range));
#endif

#if YYBTYACC
    yyps = yyNewState(0); if (yyps == NULL) goto yyenomem;
    yyps->save = NULL;
#endif /* YYBTYACC */
    yym = 0;
    /* yyn is set below */
    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yystack.p_mark = yystack.p_base;
#endif
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
#if YYBTYACC
        do {
        if (yylvp < yylve)
        {
            /* we're currently re-reading tokens */
            yylval = *yylvp++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yylloc = *yylpp++;
#endif
            yychar = *yylexp++;
            break;
        }
        if (yyps->save)
        {
            /* in trial mode; save scanner results for future parse attempts */
            if (yylvp == yylvlim)
            {   /* Enlarge lexical value queue */
                size_t p = (size_t) (yylvp - yylvals);
                size_t s = (size_t) (yylvlim - yylvals);

                s += YYLVQUEUEGROWTH;
                if ((yylexemes = (YYINT *)realloc(yylexemes, s * sizeof(YYINT))) == NULL) goto yyenomem;
                if ((yylvals   = (YYSTYPE *)realloc(yylvals, s * sizeof(YYSTYPE))) == NULL) goto yyenomem;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                if ((yylpsns   = (YYLTYPE *)realloc(yylpsns, s * sizeof(YYLTYPE))) == NULL) goto yyenomem;
#endif
                yylvp   = yylve = yylvals + p;
                yylvlim = yylvals + s;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                yylpp   = yylpe = yylpsns + p;
                yylplim = yylpsns + s;
#endif
                yylexp  = yylexemes + p;
            }
            *yylexp = (YYINT) YYLEX;
            *yylvp++ = yylval;
            yylve++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            *yylpp++ = yylloc;
            yylpe++;
#endif
            yychar = *yylexp++;
            break;
        }
        /* normal operation, no conflict encountered */
#endif /* YYBTYACC */
        yychar = YYLEX;
#if YYBTYACC
        } while (0);
#endif /* YYBTYACC */
        if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
            fprintf(stderr, "%s[%d]: state %d, reading token %d (%s)",
                            YYDEBUGSTR, yydepth, yystate, yychar, yys);
#ifdef YYSTYPE_TOSTRING
#if YYBTYACC
            if (!yytrial)
#endif /* YYBTYACC */
                fprintf(stderr, " <%s>", YYSTYPE_TOSTRING(yychar, yylval));
#endif
            fputc('\n', stderr);
        }
#endif
    }
#if YYBTYACC

    /* Do we have a conflict? */
    if (((yyn = yycindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
        yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
        YYINT ctry;

        if (yypath)
        {
            YYParseState *save;
#if YYDEBUG
            if (yydebug)
                fprintf(stderr, "%s[%d]: CONFLICT in state %d: following successful trial parse\n",
                                YYDEBUGSTR, yydepth, yystate);
#endif
            /* Switch to the next conflict context */
            save = yypath;
            yypath = save->save;
            save->save = NULL;
            ctry = save->ctry;
            if (save->state != yystate) YYABORT;
            yyFreeState(save);

        }
        else
        {

            /* Unresolved conflict - start/continue trial parse */
            YYParseState *save;
#if YYDEBUG
            if (yydebug)
            {
                fprintf(stderr, "%s[%d]: CONFLICT in state %d. ", YYDEBUGSTR, yydepth, yystate);
                if (yyps->save)
                    fputs("ALREADY in conflict, continuing trial parse.\n", stderr);
                else
                    fputs("Starting trial parse.\n", stderr);
            }
#endif
            save                  = yyNewState((unsigned)(yystack.s_mark - yystack.s_base + 1));
            if (save == NULL) goto yyenomem;
            save->save            = yyps->save;
            save->state           = yystate;
            save->errflag         = yyerrflag;
            save->yystack.s_mark  = save->yystack.s_base + (yystack.s_mark - yystack.s_base);
            memcpy (save->yystack.s_base, yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
            save->yystack.l_mark  = save->yystack.l_base + (yystack.l_mark - yystack.l_base);
            memcpy (save->yystack.l_base, yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            save->yystack.p_mark  = save->yystack.p_base + (yystack.p_mark - yystack.p_base);
            memcpy (save->yystack.p_base, yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
            ctry                  = yytable[yyn];
            if (yyctable[ctry] == -1)
            {
#if YYDEBUG
                if (yydebug && yychar >= YYEOF)
                    fprintf(stderr, "%s[%d]: backtracking 1 token\n", YYDEBUGSTR, yydepth);
#endif
                ctry++;
            }
            save->ctry = ctry;
            if (yyps->save == NULL)
            {
                /* If this is a first conflict in the stack, start saving lexemes */
                if (!yylexemes)
                {
                    yylexemes = (YYINT *) malloc((YYLVQUEUEGROWTH) * sizeof(YYINT));
                    if (yylexemes == NULL) goto yyenomem;
                    yylvals   = (YYSTYPE *) malloc((YYLVQUEUEGROWTH) * sizeof(YYSTYPE));
                    if (yylvals == NULL) goto yyenomem;
                    yylvlim   = yylvals + YYLVQUEUEGROWTH;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    yylpsns   = (YYLTYPE *) malloc((YYLVQUEUEGROWTH) * sizeof(YYLTYPE));
                    if (yylpsns == NULL) goto yyenomem;
                    yylplim   = yylpsns + YYLVQUEUEGROWTH;
#endif
                }
                if (yylvp == yylve)
                {
                    yylvp  = yylve = yylvals;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    yylpp  = yylpe = yylpsns;
#endif
                    yylexp = yylexemes;
                    if (yychar >= YYEOF)
                    {
                        *yylve++ = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                        *yylpe++ = yylloc;
#endif
                        *yylexp  = (YYINT) yychar;
                        yychar   = YYEMPTY;
                    }
                }
            }
            if (yychar >= YYEOF)
            {
                yylvp--;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                yylpp--;
#endif
                yylexp--;
                yychar = YYEMPTY;
            }
            save->lexeme = (int) (yylvp - yylvals);
            yyps->save   = save;
        }
        if (yytable[yyn] == ctry)
        {
#if YYDEBUG
            if (yydebug)
                fprintf(stderr, "%s[%d]: state %d, shifting to state %d\n",
                                YYDEBUGSTR, yydepth, yystate, yyctable[ctry]);
#endif
            if (yychar < 0)
            {
                yylvp++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                yylpp++;
#endif
                yylexp++;
            }
            if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                goto yyoverflow;
            yystate = yyctable[ctry];
            *++yystack.s_mark = (YYINT) yystate;
            *++yystack.l_mark = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            *++yystack.p_mark = yylloc;
#endif
            yychar  = YYEMPTY;
            if (yyerrflag > 0) --yyerrflag;
            goto yyloop;
        }
        else
        {
            yyn = yyctable[ctry];
            goto yyreduce;
        }
    } /* End of code dealing with conflicts */
#endif /* YYBTYACC */
    if (((yyn = yysindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
#if YYDEBUG
        if (yydebug)
            fprintf(stderr, "%s[%d]: state %d, shifting to state %d\n",
                            YYDEBUGSTR, yydepth, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        *++yystack.p_mark = yylloc;
#endif
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if (((yyn = yyrindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag != 0) goto yyinrecovery;
#if YYBTYACC

    yynewerrflag = 1;
    goto yyerrhandler;
    goto yyerrlab; /* redundant goto avoids 'unused label' warning */

yyerrlab:
    /* explicit YYERROR from an action -- pop the rhs of the rule reduced
     * before looking for error recovery */
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yystack.p_mark -= yym;
#endif

    yynewerrflag = 0;
yyerrhandler:
    while (yyps->save)
    {
        int ctry;
        YYParseState *save = yyps->save;
#if YYDEBUG
        if (yydebug)
            fprintf(stderr, "%s[%d]: ERROR in state %d, CONFLICT BACKTRACKING to state %d, %d tokens\n",
                            YYDEBUGSTR, yydepth, yystate, yyps->save->state,
                    (int)(yylvp - yylvals - yyps->save->lexeme));
#endif
        /* Memorize most forward-looking error state in case it's really an error. */
        if (yyerrctx == NULL || yyerrctx->lexeme < yylvp - yylvals)
        {
            /* Free old saved error context state */
            if (yyerrctx) yyFreeState(yyerrctx);
            /* Create and fill out new saved error context state */
            yyerrctx                 = yyNewState((unsigned)(yystack.s_mark - yystack.s_base + 1));
            if (yyerrctx == NULL) goto yyenomem;
            yyerrctx->save           = yyps->save;
            yyerrctx->state          = yystate;
            yyerrctx->errflag        = yyerrflag;
            yyerrctx->yystack.s_mark = yyerrctx->yystack.s_base + (yystack.s_mark - yystack.s_base);
            memcpy (yyerrctx->yystack.s_base, yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
            yyerrctx->yystack.l_mark = yyerrctx->yystack.l_base + (yystack.l_mark - yystack.l_base);
            memcpy (yyerrctx->yystack.l_base, yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yyerrctx->yystack.p_mark = yyerrctx->yystack.p_base + (yystack.p_mark - yystack.p_base);
            memcpy (yyerrctx->yystack.p_base, yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
            yyerrctx->lexeme         = (int) (yylvp - yylvals);
        }
        yylvp          = yylvals   + save->lexeme;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        yylpp          = yylpsns   + save->lexeme;
#endif
        yylexp         = yylexemes + save->lexeme;
        yychar         = YYEMPTY;
        yystack.s_mark = yystack.s_base + (save->yystack.s_mark - save->yystack.s_base);
        memcpy (yystack.s_base, save->yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
        yystack.l_mark = yystack.l_base + (save->yystack.l_mark - save->yystack.l_base);
        memcpy (yystack.l_base, save->yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        yystack.p_mark = yystack.p_base + (save->yystack.p_mark - save->yystack.p_base);
        memcpy (yystack.p_base, save->yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
        ctry           = ++save->ctry;
        yystate        = save->state;
        /* We tried shift, try reduce now */
        if ((yyn = yyctable[ctry]) >= 0) goto yyreduce;
        yyps->save     = save->save;
        save->save     = NULL;
        yyFreeState(save);

        /* Nothing left on the stack -- error */
        if (!yyps->save)
        {
#if YYDEBUG
            if (yydebug)
                fprintf(stderr, "%sdebug[%d,trial]: trial parse FAILED, entering ERROR mode\n",
                                YYPREFIX, yydepth);
#endif
            /* Restore state as it was in the most forward-advanced error */
            yylvp          = yylvals   + yyerrctx->lexeme;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yylpp          = yylpsns   + yyerrctx->lexeme;
#endif
            yylexp         = yylexemes + yyerrctx->lexeme;
            yychar         = yylexp[-1];
            yylval         = yylvp[-1];
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yylloc         = yylpp[-1];
#endif
            yystack.s_mark = yystack.s_base + (yyerrctx->yystack.s_mark - yyerrctx->yystack.s_base);
            memcpy (yystack.s_base, yyerrctx->yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
            yystack.l_mark = yystack.l_base + (yyerrctx->yystack.l_mark - yyerrctx->yystack.l_base);
            memcpy (yystack.l_base, yyerrctx->yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yystack.p_mark = yystack.p_base + (yyerrctx->yystack.p_mark - yyerrctx->yystack.p_base);
            memcpy (yystack.p_base, yyerrctx->yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
            yystate        = yyerrctx->state;
            yyFreeState(yyerrctx);
            yyerrctx       = NULL;
        }
        yynewerrflag = 1;
    }
    if (yynewerrflag == 0) goto yyinrecovery;
#endif /* YYBTYACC */

    YYERROR_CALL("syntax error");
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yyerror_loc_range[1] = yylloc; /* lookahead position is error start position */
#endif

#if !YYBTYACC
    goto yyerrlab; /* redundant goto avoids 'unused label' warning */
yyerrlab:
#endif
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if (((yyn = yysindex[*yystack.s_mark]) != 0) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    fprintf(stderr, "%s[%d]: state %d, error recovery shifting to state %d\n",
                                    YYDEBUGSTR, yydepth, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                /* lookahead position is error end position */
                yyerror_loc_range[2] = yylloc;
                YYLLOC_DEFAULT(yyloc, yyerror_loc_range, 2); /* position of error span */
                *++yystack.p_mark = yyloc;
#endif
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    fprintf(stderr, "%s[%d]: error recovery discarding state %d\n",
                                    YYDEBUGSTR, yydepth, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                /* the current TOS position is the error start position */
                yyerror_loc_range[1] = *yystack.p_mark;
#endif
#if defined(YYDESTRUCT_CALL)
#if YYBTYACC
                if (!yytrial)
#endif /* YYBTYACC */
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    YYDESTRUCT_CALL("error: discarding state",
                                    yystos[*yystack.s_mark], yystack.l_mark, yystack.p_mark);
#else
                    YYDESTRUCT_CALL("error: discarding state",
                                    yystos[*yystack.s_mark], yystack.l_mark);
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */
#endif /* defined(YYDESTRUCT_CALL) */
                --yystack.s_mark;
                --yystack.l_mark;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                --yystack.p_mark;
#endif
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
            fprintf(stderr, "%s[%d]: state %d, error recovery discarding token %d (%s)\n",
                            YYDEBUGSTR, yydepth, yystate, yychar, yys);
        }
#endif
#if defined(YYDESTRUCT_CALL)
#if YYBTYACC
        if (!yytrial)
#endif /* YYBTYACC */
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            YYDESTRUCT_CALL("error: discarding token", yychar, &yylval, &yylloc);
#else
            YYDESTRUCT_CALL("error: discarding token", yychar, &yylval);
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */
#endif /* defined(YYDESTRUCT_CALL) */
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
    yym = yylen[yyn];
#if YYDEBUG
    if (yydebug)
    {
        fprintf(stderr, "%s[%d]: state %d, reducing by rule %d (%s)",
                        YYDEBUGSTR, yydepth, yystate, yyn, yyrule[yyn]);
#ifdef YYSTYPE_TOSTRING
#if YYBTYACC
        if (!yytrial)
#endif /* YYBTYACC */
            if (yym > 0)
            {
                int i;
                fputc('<', stderr);
                for (i = yym; i > 0; i--)
                {
                    if (i != yym) fputs(", ", stderr);
                    fputs(YYSTYPE_TOSTRING(yystos[yystack.s_mark[1-i]],
                                           yystack.l_mark[1-i]), stderr);
                }
                fputc('>', stderr);
            }
#endif
        fputc('\n', stderr);
    }
#endif
    if (yym > 0)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)

    /* Perform position reduction */
    memset(&yyloc, 0, sizeof(yyloc));
#if YYBTYACC
    if (!yytrial)
#endif /* YYBTYACC */
    {
        YYLLOC_DEFAULT(yyloc, &yystack.p_mark[-yym], yym);
        /* just in case YYERROR is invoked within the action, save
           the start of the rhs as the error start position */
        yyerror_loc_range[1] = yystack.p_mark[1-yym];
    }
#endif

    switch (yyn)
    {
case 1:
#line 36 "proj.y"
	{ printf("%s", yystack.l_mark[0].strval); free(yystack.l_mark[0].strval); }
#line 1477 "y.tab.c"
break;
case 2:
#line 37 "proj.y"
	{ printf("%s %s", yystack.l_mark[-1].strval, yystack.l_mark[0].strval); free(yystack.l_mark[0].strval); free(yystack.l_mark[-1].strval); }
#line 1482 "y.tab.c"
break;
case 3:
#line 38 "proj.y"
	{ printf("%s", yystack.l_mark[0].strval); free(yystack.l_mark[0].strval); }
#line 1487 "y.tab.c"
break;
case 21:
#line 61 "proj.y"
	{
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "Get-ChildItem %s", yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 1496 "y.tab.c"
break;
case 22:
#line 66 "proj.y"
	{
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "Get-ChildItem %s %s", yystack.l_mark[-1].strval, yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 1505 "y.tab.c"
break;
case 23:
#line 71 "proj.y"
	{
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "Get-ChildItem %s %s", yystack.l_mark[0].strval, yystack.l_mark[-1].strval);
                                                                    yyval.strval = result;
                                                                }
#line 1514 "y.tab.c"
break;
case 24:
#line 76 "proj.y"
	{
                                                                    yyval.strval = strdup("Get-ChildItem");
                                                                }
#line 1521 "y.tab.c"
break;
case 25:
#line 79 "proj.y"
	{
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "Get-ChildItem -Path %s", yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 1530 "y.tab.c"
break;
case 26:
#line 86 "proj.y"
	{
                                                                    char intermediar[128] = "";
                                                                    convertLSParamName(yystack.l_mark[-1].strval, intermediar);
                                                                    char* result = malloc(256);
                                                                    sprintf(result, "%s %s", intermediar, yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 1541 "y.tab.c"
break;
case 27:
#line 93 "proj.y"
	{
                                                                    char intermediar[128] = "";
                                                                    convertLSParamName(yystack.l_mark[0].strval, intermediar);
                                                                    yyval.strval = strdup(intermediar);
                                                                }
#line 1550 "y.tab.c"
break;
case 28:
#line 98 "proj.y"
	{
                                                                    char intermediar[128] = "";
                                                                    convertLSParamName(yystack.l_mark[-2].strval, intermediar);
                                                                    char* result = malloc(256);
                                                                    sprintf(result, "%s %s %s", intermediar, yystack.l_mark[-1].strval, yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 1561 "y.tab.c"
break;
case 29:
#line 105 "proj.y"
	{
                                                                    char intermediar[128] = "";
                                                                    convertLSParamName(yystack.l_mark[-1].strval, intermediar);
                                                                    char* result = malloc(256);
                                                                    sprintf(result, "%s %s", intermediar, yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 1572 "y.tab.c"
break;
case 30:
#line 115 "proj.y"
	{
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "New-Item -ItemType Directory -Path %s %s", yystack.l_mark[0].strval, yystack.l_mark[-1].strval);
                                                                    yyval.strval = result;
                                                                }
#line 1581 "y.tab.c"
break;
case 31:
#line 120 "proj.y"
	{
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "New-Item -Path %s -ItemType Directory %s", yystack.l_mark[-1].strval, yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 1590 "y.tab.c"
break;
case 32:
#line 127 "proj.y"
	{
                                                                    char intermediar[128] = "";
                                                                    convertMKDIRParamName(yystack.l_mark[-1].strval, intermediar);
                                                                    char* result = malloc(256);
                                                                    if(strcmp(intermediar, "") == 0)
                                                                        strcpy(result, "");
                                                                    else
                                                                        sprintf(result, "%s %s", intermediar, yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 1604 "y.tab.c"
break;
case 33:
#line 137 "proj.y"
	{
                                                                    char intermediar[128] = "";
                                                                    convertMKDIRParamName(yystack.l_mark[0].strval, intermediar);
                                                                    yyval.strval = strdup(intermediar);
                                                                }
#line 1613 "y.tab.c"
break;
case 34:
#line 142 "proj.y"
	{
                                                                    char intermediar[128] = "";
                                                                    convertMKDIRParamName(yystack.l_mark[-2].strval, intermediar);
                                                                    char* result = malloc(256);
                                                                    if(strcmp(intermediar, "") == 0)
                                                                        sprintf(result, "%s", yystack.l_mark[0].strval);
                                                                    else
                                                                        sprintf(result, "%s %s %s", intermediar, yystack.l_mark[-1].strval, yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 1627 "y.tab.c"
break;
case 35:
#line 152 "proj.y"
	{
                                                                    char intermediar[128] = "";
                                                                    convertMKDIRParamName(yystack.l_mark[-1].strval, intermediar);
                                                                    char* result = malloc(256);
                                                                    sprintf(result, "%s %s", intermediar, yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 1638 "y.tab.c"
break;
case 36:
#line 162 "proj.y"
	{
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "Copy-Item %s %s", yystack.l_mark[0].strval, yystack.l_mark[-1].strval);
                                                                    yyval.strval = result;
                                                                }
#line 1647 "y.tab.c"
break;
case 37:
#line 167 "proj.y"
	{
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "Copy-Item %s %s", yystack.l_mark[-1].strval, yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 1656 "y.tab.c"
break;
case 38:
#line 174 "proj.y"
	{
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "%s -Destination %s", yystack.l_mark[-1].strval, yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 1665 "y.tab.c"
break;
case 39:
#line 181 "proj.y"
	{
                                                                    char intermediar[128] = "";
                                                                    convertCPParamName(yystack.l_mark[-1].strval, intermediar);
                                                                    char* result = malloc(256);
                                                                    if(strcmp(intermediar, "") == 0)
                                                                        strcpy(result, "");
                                                                    else
                                                                        sprintf(result, "%s %s", intermediar, yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 1679 "y.tab.c"
break;
case 40:
#line 191 "proj.y"
	{
                                                                    char intermediar[128] = "";
                                                                    convertCPParamName(yystack.l_mark[0].strval, intermediar);
                                                                    yyval.strval = strdup(intermediar);
                                                                }
#line 1688 "y.tab.c"
break;
case 41:
#line 196 "proj.y"
	{
                                                                    char intermediar[128] = "";
                                                                    convertCPParamName(yystack.l_mark[-2].strval, intermediar);
                                                                    char* result = malloc(256);
                                                                    if(strcmp(intermediar, "") == 0)
                                                                        sprintf(result, "%s", yystack.l_mark[0].strval);
                                                                    else
                                                                        sprintf(result, "%s %s %s", intermediar, yystack.l_mark[-1].strval, yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 1702 "y.tab.c"
break;
case 42:
#line 206 "proj.y"
	{
                                                                    char intermediar[128] = "";
                                                                    convertCPParamName(yystack.l_mark[-1].strval, intermediar);
                                                                    char* result = malloc(256);
                                                                    sprintf(result, "%s %s", intermediar, yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 1713 "y.tab.c"
break;
case 43:
#line 216 "proj.y"
	{
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "Get-Content %s -Path %s", yystack.l_mark[-1].strval, yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 1722 "y.tab.c"
break;
case 44:
#line 222 "proj.y"
	{ yyval.strval = strdup(yystack.l_mark[0].strval); }
#line 1727 "y.tab.c"
break;
case 45:
#line 223 "proj.y"
	{
                                                                    char* result = malloc(512);
                                                                    sprintf(result,"%s %s", yystack.l_mark[-1].strval, yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 1736 "y.tab.c"
break;
case 46:
#line 230 "proj.y"
	{
                                                                    char* result = malloc(256);
                                                                    char intermediar[128] = "";
                                                                    convertHeadParams(yystack.l_mark[-1].strval, yystack.l_mark[0].intval, intermediar);
                                                                    strcpy(result, intermediar);
                                                                    yyval.strval = result;
                                                                }
#line 1747 "y.tab.c"
break;
case 47:
#line 237 "proj.y"
	{
                                                                    char* result = malloc(512);
                                                                    char intermediar[128] = "";
                                                                    convertHeadParams(yystack.l_mark[-2].strval, yystack.l_mark[-1].intval, intermediar);
                                                                    sprintf(result, "%s %s", intermediar, yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 1758 "y.tab.c"
break;
case 48:
#line 244 "proj.y"
	{
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "%s", yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 1767 "y.tab.c"
break;
case 49:
#line 252 "proj.y"
	{
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "Stop-Process %s", yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 1776 "y.tab.c"
break;
case 50:
#line 257 "proj.y"
	{
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "Stop-Process %s", yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 1785 "y.tab.c"
break;
case 51:
#line 264 "proj.y"
	{
                                                                    char intermediar[128] = "";
                                                                    convertPKILLParamName(yystack.l_mark[-1].strval, intermediar);
                                                                    char* result = malloc(256);
                                                                    sprintf(result, "%s %s", intermediar, yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 1796 "y.tab.c"
break;
case 52:
#line 271 "proj.y"
	{
                                                                    char intermediar[128] = "";
                                                                    convertPKILLParamName(yystack.l_mark[0].strval, intermediar);
                                                                    char* result = malloc(256);
                                                                    sprintf(result, "%s", intermediar);
                                                                    yyval.strval = result;
                                                                }
#line 1807 "y.tab.c"
break;
case 53:
#line 278 "proj.y"
	{
                                                                    char intermediar[128] = "";
                                                                    convertPKILLParamName(yystack.l_mark[-2].strval, intermediar);
                                                                    char* result = malloc(256);
                                                                    sprintf(result, "%s %s %s", intermediar, yystack.l_mark[-1].strval, yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 1818 "y.tab.c"
break;
case 54:
#line 285 "proj.y"
	{
                                                                    char intermediar[128] = "";
                                                                    convertPKILLParamName(yystack.l_mark[-1].strval, intermediar);
                                                                    char* result = malloc(256);
                                                                    sprintf(result, "%s %s", intermediar, yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 1829 "y.tab.c"
break;
case 55:
#line 294 "proj.y"
	{
                                                                    yyval.strval = strdup(yystack.l_mark[0].strval);
                                                                }
#line 1836 "y.tab.c"
break;
case 56:
#line 297 "proj.y"
	{
                                                                    char* conversion = malloc(10);
                                                                    sprintf(conversion, "%d", yystack.l_mark[0].intval);
                                                                    yyval.strval = conversion;
                                                                }
#line 1845 "y.tab.c"
break;
case 57:
#line 305 "proj.y"
	{
                                                                    char* result = malloc(20);
                                                                    strcpy(result, "Get-NetIpAddress");
                                                                    yyval.strval = result;
                                                                }
#line 1854 "y.tab.c"
break;
case 58:
#line 310 "proj.y"
	{
                                                                    char* result = malloc(20);
                                                                    strcpy(result, "Get-NetIpAddress");
                                                                    yyval.strval = result;
                                                                }
#line 1863 "y.tab.c"
break;
case 61:
#line 322 "proj.y"
	{
                                                                        char* result = malloc(22);
                                                                        strcpy(result, "Get-NetTcpConnection");
                                                                        yyval.strval = result;
                                                                    }
#line 1872 "y.tab.c"
break;
case 66:
#line 338 "proj.y"
	{
                                                                        char* result = malloc(512);
                                                                        sprintf(result, "Invoke-WebRequest -Uri %s %s", yystack.l_mark[0].strval, yystack.l_mark[-1].strval);
                                                                        yyval.strval = result;
                                                                    }
#line 1881 "y.tab.c"
break;
case 67:
#line 343 "proj.y"
	{
                                                                        char* result = malloc(512);
                                                                        sprintf(result, "Invoke-WebRequest -Uri %s %s", yystack.l_mark[-1].strval, yystack.l_mark[0].strval);
                                                                        yyval.strval = result;
                                                                    }
#line 1890 "y.tab.c"
break;
case 68:
#line 350 "proj.y"
	{
                                                                        char intermediar[128] = "";
                                                                        convertCURLParamName(yystack.l_mark[-1].strval, intermediar);
                                                                        char* result = malloc(256);
                                                                        sprintf(result, "%s %s", intermediar, yystack.l_mark[0].strval);
                                                                        yyval.strval = result;
                                                                    }
#line 1901 "y.tab.c"
break;
case 69:
#line 357 "proj.y"
	{
                                                                        char intermediar[128] = "";
                                                                        convertCURLParamName(yystack.l_mark[0].strval, intermediar);
                                                                        yyval.strval = strdup(intermediar);
                                                                    }
#line 1910 "y.tab.c"
break;
case 70:
#line 362 "proj.y"
	{
                                                                        char intermediar[128] = "";
                                                                        convertCURLParamName(yystack.l_mark[-2].strval, intermediar);
                                                                        char* result = malloc(256);
                                                                        sprintf(result, "%s %s %s", intermediar, yystack.l_mark[-1].strval, yystack.l_mark[0].strval);
                                                                        yyval.strval = result;
                                                                    }
#line 1921 "y.tab.c"
break;
case 71:
#line 369 "proj.y"
	{
                                                                        char intermediar[128] = "";
                                                                        convertCURLParamName(yystack.l_mark[-1].strval, intermediar);
                                                                        char* result = malloc(256);
                                                                        sprintf(result, "%s %s", intermediar, yystack.l_mark[0].strval);
                                                                        yyval.strval = result;
                                                                    }
#line 1932 "y.tab.c"
break;
case 72:
#line 379 "proj.y"
	{
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "Move-Item %s %s", yystack.l_mark[0].strval, yystack.l_mark[-1].strval);
                                                                    yyval.strval = result;
                                                                }
#line 1941 "y.tab.c"
break;
case 73:
#line 384 "proj.y"
	{
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "Move-Item %s %s", yystack.l_mark[-1].strval, yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 1950 "y.tab.c"
break;
case 74:
#line 390 "proj.y"
	{
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "-Path %s -Destination %s", yystack.l_mark[-1].strval, yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 1959 "y.tab.c"
break;
case 75:
#line 397 "proj.y"
	{
                                                                    char intermediar[128] = "";
                                                                    convertMVParamName(yystack.l_mark[-1].strval, intermediar);
                                                                    char* result = malloc(256);
                                                                    if(strcmp(intermediar, "") == 0)
                                                                        strcpy(result, "");
                                                                    else
                                                                        sprintf(result, "%s %s", intermediar, yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 1973 "y.tab.c"
break;
case 76:
#line 407 "proj.y"
	{
                                                                    char intermediar[128] = "";
                                                                    convertMVParamName(yystack.l_mark[0].strval, intermediar);
                                                                    yyval.strval = strdup(intermediar);
                                                                }
#line 1982 "y.tab.c"
break;
case 77:
#line 412 "proj.y"
	{
                                                                    char intermediar[128] = "";
                                                                    convertMVParamName(yystack.l_mark[-2].strval, intermediar);
                                                                    char* result = malloc(256);
                                                                    if(strcmp(intermediar, "") == 0)
                                                                        sprintf(result, "%s", yystack.l_mark[0].strval);
                                                                    else
                                                                        sprintf(result, "%s %s %s", intermediar, yystack.l_mark[-1].strval, yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 1996 "y.tab.c"
break;
case 78:
#line 422 "proj.y"
	{
                                                                    char intermediar[128] = "";
                                                                    convertMVParamName(yystack.l_mark[-1].strval, intermediar);
                                                                    char* result = malloc(256);
                                                                    sprintf(result, "%s %s", intermediar, yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 2007 "y.tab.c"
break;
case 79:
#line 432 "proj.y"
	{
                                                                    yyval.strval = strdup("Get-Location");
                                                                }
#line 2014 "y.tab.c"
break;
case 80:
#line 435 "proj.y"
	{
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "Get-Location %s", yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 2023 "y.tab.c"
break;
case 81:
#line 442 "proj.y"
	{
                                                                    char intermediar[128] = "";
                                                                    convertPWDParamName(yystack.l_mark[-1].strval, intermediar);
                                                                    char* result = malloc(256);
                                                                    sprintf(result, "%s %s", intermediar, yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 2034 "y.tab.c"
break;
case 82:
#line 449 "proj.y"
	{
                                                                    char intermediar[128] = "";
                                                                    convertPWDParamName(yystack.l_mark[0].strval, intermediar);
                                                                    yyval.strval = strdup(intermediar);
                                                                }
#line 2043 "y.tab.c"
break;
case 83:
#line 454 "proj.y"
	{
                                                                    char intermediar[128] = "";
                                                                    convertPWDParamName(yystack.l_mark[-2].strval, intermediar);
                                                                    char* result = malloc(256);
                                                                    sprintf(result, "%s %s %s", intermediar, yystack.l_mark[-1].strval, yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 2054 "y.tab.c"
break;
case 84:
#line 461 "proj.y"
	{
                                                                    char intermediar[128] = "";
                                                                    convertPWDParamName(yystack.l_mark[-1].strval, intermediar);
                                                                    char* result = malloc(256);
                                                                    sprintf(result, "%s %s", intermediar, yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 2065 "y.tab.c"
break;
case 85:
#line 471 "proj.y"
	{
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "New-Item -ItemType File -Path %s", yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 2074 "y.tab.c"
break;
case 86:
#line 476 "proj.y"
	{
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "New-Item -ItemType File -Path %s %s", yystack.l_mark[0].strval, yystack.l_mark[-1].strval);
                                                                    yyval.strval = result;
                                                                }
#line 2083 "y.tab.c"
break;
case 87:
#line 481 "proj.y"
	{
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "New-Item -ItemType File -Path %s %s", yystack.l_mark[-1].strval, yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 2092 "y.tab.c"
break;
case 88:
#line 486 "proj.y"
	{
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "New-Item -ItemType File %s", yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 2101 "y.tab.c"
break;
case 89:
#line 493 "proj.y"
	{
                                                                    char intermediar[128] = "";
                                                                    convertTouchParamName(yystack.l_mark[-1].strval, intermediar);
                                                                    char* result = malloc(256);
                                                                    sprintf(result, "%s %s", intermediar, yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 2112 "y.tab.c"
break;
case 90:
#line 500 "proj.y"
	{
                                                                    char intermediar[128] = "";
                                                                    convertTouchParamName(yystack.l_mark[0].strval, intermediar);
                                                                    yyval.strval = strdup(intermediar);
                                                                }
#line 2121 "y.tab.c"
break;
case 91:
#line 505 "proj.y"
	{
                                                                    char intermediar[128] = "";
                                                                    convertTouchParamName(yystack.l_mark[-2].strval, intermediar);
                                                                    char* result = malloc(256);
                                                                    sprintf(result, "%s %s %s", intermediar, yystack.l_mark[-1].strval, yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 2132 "y.tab.c"
break;
case 92:
#line 512 "proj.y"
	{
                                                                    char intermediar[128] = "";
                                                                    convertTouchParamName(yystack.l_mark[-1].strval, intermediar);
                                                                    char* result = malloc(256);
                                                                    sprintf(result, "%s %s", intermediar, yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 2143 "y.tab.c"
break;
case 93:
#line 522 "proj.y"
	{
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "Remove-Item -Path %s", yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 2152 "y.tab.c"
break;
case 94:
#line 527 "proj.y"
	{
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "Remove-Item -Path %s %s", yystack.l_mark[0].strval, yystack.l_mark[-1].strval);
                                                                    yyval.strval = result;
                                                                }
#line 2161 "y.tab.c"
break;
case 95:
#line 532 "proj.y"
	{
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "Remove-Item -Path %s %s", yystack.l_mark[-1].strval, yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 2170 "y.tab.c"
break;
case 96:
#line 537 "proj.y"
	{
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "Remove-Item %s", yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 2179 "y.tab.c"
break;
case 97:
#line 544 "proj.y"
	{
                                                                    char intermediar[128] = "";
                                                                    convertRMParamName(yystack.l_mark[-1].strval, intermediar);
                                                                    char* result = malloc(256);
                                                                    sprintf(result, "%s %s", intermediar, yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 2190 "y.tab.c"
break;
case 98:
#line 551 "proj.y"
	{
                                                                    char intermediar[128] = "";
                                                                    convertRMParamName(yystack.l_mark[0].strval, intermediar);
                                                                    yyval.strval = strdup(intermediar);
                                                                }
#line 2199 "y.tab.c"
break;
case 99:
#line 556 "proj.y"
	{
                                                                    char intermediar[128] = "";
                                                                    convertRMParamName(yystack.l_mark[-2].strval, intermediar);
                                                                    char* result = malloc(256);
                                                                    sprintf(result, "%s %s %s", intermediar, yystack.l_mark[-1].strval, yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 2210 "y.tab.c"
break;
case 100:
#line 563 "proj.y"
	{
                                                                    char intermediar[128] = "";
                                                                    convertRMParamName(yystack.l_mark[-1].strval, intermediar);
                                                                    char* result = malloc(256);
                                                                    sprintf(result, "%s %s", intermediar, yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 2221 "y.tab.c"
break;
case 101:
#line 573 "proj.y"
	{
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "Select-String %s", yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 2230 "y.tab.c"
break;
case 102:
#line 578 "proj.y"
	{
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "Select-String %s %s", yystack.l_mark[0].strval, yystack.l_mark[-1].strval);
                                                                    yyval.strval = result;
                                                                }
#line 2239 "y.tab.c"
break;
case 103:
#line 583 "proj.y"
	{
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "Select-String %s %s", yystack.l_mark[-1].strval, yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 2248 "y.tab.c"
break;
case 104:
#line 588 "proj.y"
	{
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "Select-String %s", yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 2257 "y.tab.c"
break;
case 105:
#line 595 "proj.y"
	{
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "-Pattern %s -Path %s", yystack.l_mark[-1].strval, yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 2266 "y.tab.c"
break;
case 106:
#line 600 "proj.y"
	{
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "-Pattern %s", yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 2275 "y.tab.c"
break;
case 107:
#line 607 "proj.y"
	{
                                                                    char intermediar[128] = "";
                                                                    convertGrepParamName(yystack.l_mark[0].strval, intermediar);
                                                                    yyval.strval = strdup(intermediar);
                                                                }
#line 2284 "y.tab.c"
break;
case 108:
#line 612 "proj.y"
	{
                                                                    char intermediar[128] = "";
                                                                    convertGrepParamName(yystack.l_mark[-1].strval, intermediar);
                                                                    char* result = malloc(256);
                                                                    sprintf(result, "%s %s", intermediar, yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 2295 "y.tab.c"
break;
case 109:
#line 622 "proj.y"
	{
                                                                    yyval.strval = strdup("Get-Content");
                                                                }
#line 2302 "y.tab.c"
break;
case 110:
#line 625 "proj.y"
	{
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "Get-Content -Path %s", yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 2311 "y.tab.c"
break;
case 111:
#line 630 "proj.y"
	{
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "Get-Content -Path %s %s", yystack.l_mark[0].strval, yystack.l_mark[-1].strval);
                                                                    yyval.strval = result;
                                                                }
#line 2320 "y.tab.c"
break;
case 112:
#line 635 "proj.y"
	{
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "Get-Content -Path %s %s", yystack.l_mark[-1].strval, yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 2329 "y.tab.c"
break;
case 113:
#line 640 "proj.y"
	{
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "Get-Content %s", yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 2338 "y.tab.c"
break;
case 114:
#line 647 "proj.y"
	{
                                                                    char intermediar[128] = "";
                                                                    convertCatParamName(yystack.l_mark[-1].strval, intermediar);
                                                                    char* result = malloc(256);
                                                                    sprintf(result, "%s %s", intermediar, yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 2349 "y.tab.c"
break;
case 115:
#line 654 "proj.y"
	{
                                                                    char intermediar[128] = "";
                                                                    convertCatParamName(yystack.l_mark[0].strval, intermediar);
                                                                    yyval.strval = strdup(intermediar);
                                                                }
#line 2358 "y.tab.c"
break;
case 116:
#line 659 "proj.y"
	{
                                                                    char intermediar[128] = "";
                                                                    convertCatParamName(yystack.l_mark[-2].strval, intermediar);
                                                                    char* result = malloc(256);
                                                                    sprintf(result, "%s %s %s", intermediar, yystack.l_mark[-1].strval, yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 2369 "y.tab.c"
break;
case 117:
#line 666 "proj.y"
	{
                                                                    char intermediar[128] = "";
                                                                    convertCatParamName(yystack.l_mark[-1].strval, intermediar);
                                                                    char* result = malloc(256);
                                                                    sprintf(result, "%s %s", intermediar, yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 2380 "y.tab.c"
break;
case 118:
#line 676 "proj.y"
	{
                                                                    yyval.strval = strdup("Get-Process");
                                                                }
#line 2387 "y.tab.c"
break;
case 119:
#line 679 "proj.y"
	{
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "Get-Process %s", yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 2396 "y.tab.c"
break;
case 120:
#line 684 "proj.y"
	{
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "Get-Process -Name %s", yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 2405 "y.tab.c"
break;
case 121:
#line 691 "proj.y"
	{
                                                                    char intermediar[128] = "";
                                                                    convertPSParamName(yystack.l_mark[-1].strval, intermediar);
                                                                    char* result = malloc(256);
                                                                    sprintf(result, "%s %s", intermediar, yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 2416 "y.tab.c"
break;
case 122:
#line 698 "proj.y"
	{
                                                                    char intermediar[128] = "";
                                                                    convertPSParamName(yystack.l_mark[0].strval, intermediar);
                                                                    yyval.strval = strdup(intermediar);
                                                                }
#line 2425 "y.tab.c"
break;
case 123:
#line 703 "proj.y"
	{
                                                                    char intermediar[128] = "";
                                                                    convertPSParamName(yystack.l_mark[-2].strval, intermediar);
                                                                    char* result = malloc(256);
                                                                    sprintf(result, "%s %s %s", intermediar, yystack.l_mark[-1].strval, yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 2436 "y.tab.c"
break;
case 124:
#line 710 "proj.y"
	{
                                                                    char intermediar[128] = "";
                                                                    convertPSParamName(yystack.l_mark[-1].strval, intermediar);
                                                                    char* result = malloc(256);
                                                                    sprintf(result, "%s %s", intermediar, yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 2447 "y.tab.c"
break;
case 125:
#line 720 "proj.y"
	{
                                                                    yyval.strval = strdup("Clear-Host");
                                                                }
#line 2454 "y.tab.c"
break;
case 126:
#line 726 "proj.y"
	{
                                                                    yyval.strval = strdup("Get-History");
                                                                }
#line 2461 "y.tab.c"
break;
case 127:
#line 729 "proj.y"
	{
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "Get-History -Count %s", yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 2470 "y.tab.c"
break;
#line 2472 "y.tab.c"
    default:
        break;
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yystack.p_mark -= yym;
#endif
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
        {
            fprintf(stderr, "%s[%d]: after reduction, ", YYDEBUGSTR, yydepth);
#ifdef YYSTYPE_TOSTRING
#if YYBTYACC
            if (!yytrial)
#endif /* YYBTYACC */
                fprintf(stderr, "result is <%s>, ", YYSTYPE_TOSTRING(yystos[YYFINAL], yyval));
#endif
            fprintf(stderr, "shifting from state 0 to final state %d\n", YYFINAL);
        }
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        *++yystack.p_mark = yyloc;
#endif
        if (yychar < 0)
        {
#if YYBTYACC
            do {
            if (yylvp < yylve)
            {
                /* we're currently re-reading tokens */
                yylval = *yylvp++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                yylloc = *yylpp++;
#endif
                yychar = *yylexp++;
                break;
            }
            if (yyps->save)
            {
                /* in trial mode; save scanner results for future parse attempts */
                if (yylvp == yylvlim)
                {   /* Enlarge lexical value queue */
                    size_t p = (size_t) (yylvp - yylvals);
                    size_t s = (size_t) (yylvlim - yylvals);

                    s += YYLVQUEUEGROWTH;
                    if ((yylexemes = (YYINT *)realloc(yylexemes, s * sizeof(YYINT))) == NULL)
                        goto yyenomem;
                    if ((yylvals   = (YYSTYPE *)realloc(yylvals, s * sizeof(YYSTYPE))) == NULL)
                        goto yyenomem;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    if ((yylpsns   = (YYLTYPE *)realloc(yylpsns, s * sizeof(YYLTYPE))) == NULL)
                        goto yyenomem;
#endif
                    yylvp   = yylve = yylvals + p;
                    yylvlim = yylvals + s;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    yylpp   = yylpe = yylpsns + p;
                    yylplim = yylpsns + s;
#endif
                    yylexp  = yylexemes + p;
                }
                *yylexp = (YYINT) YYLEX;
                *yylvp++ = yylval;
                yylve++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                *yylpp++ = yylloc;
                yylpe++;
#endif
                yychar = *yylexp++;
                break;
            }
            /* normal operation, no conflict encountered */
#endif /* YYBTYACC */
            yychar = YYLEX;
#if YYBTYACC
            } while (0);
#endif /* YYBTYACC */
            if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
                fprintf(stderr, "%s[%d]: state %d, reading token %d (%s)\n",
                                YYDEBUGSTR, yydepth, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if (((yyn = yygindex[yym]) != 0) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
    {
        fprintf(stderr, "%s[%d]: after reduction, ", YYDEBUGSTR, yydepth);
#ifdef YYSTYPE_TOSTRING
#if YYBTYACC
        if (!yytrial)
#endif /* YYBTYACC */
            fprintf(stderr, "result is <%s>, ", YYSTYPE_TOSTRING(yystos[yystate], yyval));
#endif
        fprintf(stderr, "shifting from state %d to state %d\n", *yystack.s_mark, yystate);
    }
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    *++yystack.p_mark = yyloc;
#endif
    goto yyloop;
#if YYBTYACC

    /* Reduction declares that this path is valid. Set yypath and do a full parse */
yyvalid:
    if (yypath) YYABORT;
    while (yyps->save)
    {
        YYParseState *save = yyps->save;
        yyps->save = save->save;
        save->save = yypath;
        yypath = save;
    }
#if YYDEBUG
    if (yydebug)
        fprintf(stderr, "%s[%d]: state %d, CONFLICT trial successful, backtracking to state %d, %d tokens\n",
                        YYDEBUGSTR, yydepth, yystate, yypath->state, (int)(yylvp - yylvals - yypath->lexeme));
#endif
    if (yyerrctx)
    {
        yyFreeState(yyerrctx);
        yyerrctx = NULL;
    }
    yylvp          = yylvals + yypath->lexeme;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yylpp          = yylpsns + yypath->lexeme;
#endif
    yylexp         = yylexemes + yypath->lexeme;
    yychar         = YYEMPTY;
    yystack.s_mark = yystack.s_base + (yypath->yystack.s_mark - yypath->yystack.s_base);
    memcpy (yystack.s_base, yypath->yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
    yystack.l_mark = yystack.l_base + (yypath->yystack.l_mark - yypath->yystack.l_base);
    memcpy (yystack.l_base, yypath->yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yystack.p_mark = yystack.p_base + (yypath->yystack.p_mark - yypath->yystack.p_base);
    memcpy (yystack.p_base, yypath->yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
    yystate        = yypath->state;
    goto yyloop;
#endif /* YYBTYACC */

yyoverflow:
    YYERROR_CALL("yacc stack overflow");
#if YYBTYACC
    goto yyabort_nomem;
yyenomem:
    YYERROR_CALL("memory exhausted");
yyabort_nomem:
#endif /* YYBTYACC */
    yyresult = 2;
    goto yyreturn;

yyabort:
    yyresult = 1;
    goto yyreturn;

yyaccept:
#if YYBTYACC
    if (yyps->save) goto yyvalid;
#endif /* YYBTYACC */
    yyresult = 0;

yyreturn:
#if defined(YYDESTRUCT_CALL)
    if (yychar != YYEOF && yychar != YYEMPTY)
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        YYDESTRUCT_CALL("cleanup: discarding token", yychar, &yylval, &yylloc);
#else
        YYDESTRUCT_CALL("cleanup: discarding token", yychar, &yylval);
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */

    {
        YYSTYPE *pv;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        YYLTYPE *pp;

        for (pv = yystack.l_base, pp = yystack.p_base; pv <= yystack.l_mark; ++pv, ++pp)
             YYDESTRUCT_CALL("cleanup: discarding state",
                             yystos[*(yystack.s_base + (pv - yystack.l_base))], pv, pp);
#else
        for (pv = yystack.l_base; pv <= yystack.l_mark; ++pv)
             YYDESTRUCT_CALL("cleanup: discarding state",
                             yystos[*(yystack.s_base + (pv - yystack.l_base))], pv);
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */
    }
#endif /* defined(YYDESTRUCT_CALL) */

#if YYBTYACC
    if (yyerrctx)
    {
        yyFreeState(yyerrctx);
        yyerrctx = NULL;
    }
    while (yyps)
    {
        YYParseState *save = yyps;
        yyps = save->save;
        save->save = NULL;
        yyFreeState(save);
    }
    while (yypath)
    {
        YYParseState *save = yypath;
        yypath = save->save;
        save->save = NULL;
        yyFreeState(save);
    }
#endif /* YYBTYACC */
    yyfreestack(&yystack);
    return (yyresult);
}
