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
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#line 17 "proj.y"
typedef union YYSTYPE {
    int intval;
    char* strval;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 50 "y.tab.c"

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
#define PARAM_NAME 267
#define PARAM_VALUE 268
#define CMD_SEPARATOR 269
#define YYERRCODE 256
typedef int YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    0,    2,    2,    2,    2,    2,    2,    2,
    2,    2,    2,    5,    5,    5,    5,    5,    6,    6,
    6,    6,    4,    4,    3,    1,    1,    1,    1,    7,
    7,    8,    8,    8,    8,    9,    9,    9,    9,   10,
   10,   10,   10,   11,   11,   11,   11,   12,   12,   12,
   12,   13,   13,   13,   13,   15,   15,   14,   14,   16,
   16,   16,   16,   16,   17,   17,   17,   17,   18,   18,
   18,   19,   19,   19,   19,   20,   21,   21,
};
static const YYINT yylen[] = {                            2,
    1,    3,    2,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    2,    3,    3,    1,    2,    2,    1,
    3,    2,    3,    3,    2,    2,    1,    3,    2,    1,
    2,    2,    1,    3,    2,    2,    3,    3,    2,    2,
    1,    3,    2,    2,    3,    3,    2,    2,    1,    3,
    2,    2,    3,    3,    2,    2,    1,    1,    2,    1,
    2,    3,    3,    2,    2,    1,    3,    2,    1,    2,
    2,    2,    1,    3,    2,    1,    1,    2,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,   76,    0,
    0,    1,    4,    5,    6,    7,    8,    9,   10,   11,
   12,   13,    0,    0,    0,    0,    0,    0,    0,    0,
   31,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   71,   70,   78,    0,    0,
   29,   25,   23,   24,    0,   22,   16,   15,    0,   35,
    0,   43,   38,   37,    0,   51,   46,   45,   59,   56,
   53,   54,    0,   68,   63,   62,    0,   75,    2,   28,
   21,   34,   42,   50,   67,   74,
};
#if defined(YYDESTRUCT_CALL) || defined(YYSTYPE_TOSTRING)
static const YYINT yystos[] = {                           0,
  257,  258,  259,  260,  261,  262,  263,  264,  265,  266,
  271,  273,  275,  276,  278,  280,  282,  284,  287,  289,
  291,  292,  267,  268,  272,  274,  267,  268,  277,  267,
  279,  267,  268,  281,  267,  268,  283,  267,  268,  285,
  286,  267,  268,  288,  267,  268,  290,  268,  269,  268,
  272,  268,  274,  272,  268,  277,  277,  268,  268,  279,
  268,  281,  281,  268,  268,  283,  283,  268,  285,  268,
  286,  285,  268,  288,  288,  268,  268,  290,  273,  272,
  277,  279,  281,  283,  288,  290,
};
#endif /* YYDESTRUCT_CALL || YYSTYPE_TOSTRING */
static const YYINT yydgoto[] = {                         11,
   25,   12,   26,   13,   14,   29,   15,   31,   16,   34,
   17,   37,   18,   40,   41,   19,   44,   20,   47,   21,
   22,
};
static const YYINT yysindex[] = {                      -210,
 -209, -207, -267, -205, -203, -192, -190, -188,    0, -259,
 -258,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0, -186, -255, -224, -201, -184, -171, -211, -182,
    0, -180, -168, -167, -178, -165, -164, -162, -161, -160,
 -162, -176, -158, -157, -174,    0,    0,    0, -210, -201,
    0,    0,    0,    0, -171,    0,    0,    0, -267,    0,
 -168,    0,    0,    0, -165,    0,    0,    0,    0,    0,
    0,    0, -158,    0,    0,    0, -155,    0,    0,    0,
    0,    0,    0,    0,    0,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    3,   15,    0,    0,    0,   16,   17,    0,   18,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   19,    0,    0,    0,   20,   21,   22,   23,
    0,   24,   25,   26,   27,   28,   29,    1,    4,   30,
   31,   32,   33,   34,   35,    0,    0,    0,   36,    6,
    0,    0,    0,    0,    8,    0,    0,    0,   37,    0,
   10,    0,    0,    0,   12,    0,    0,    0,    0,    0,
    0,    0,   14,    0,    0,    0,   38,    0,    0,    0,
    0,    0,    0,    0,    0,    0,
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
    0,    0,    0,    0,    0,    0,
};
#endif
static const YYINT yygindex[] = {                         0,
   47,   51,   78,    0,    0,   40,    0,   39,    0,   13,
    0,    7,    0,  -36,   66,    0,   -2,    0,  -38,    0,
    0,
};
#define YYTABLESIZE 307
static const YYINT yytable[] = {                         30,
   58,   69,   17,   57,   72,   26,   78,   19,   48,   40,
   49,   48,   52,   65,   30,   60,   69,   77,   27,   20,
   18,   14,   33,   41,   36,   39,   49,   44,   47,   55,
   52,   66,   61,   64,   73,    3,   32,   72,   86,   74,
   75,   66,   67,   24,   62,   63,    1,    2,    3,    4,
    5,    6,    7,    8,    9,   10,   58,   23,   24,   27,
   28,   32,   33,   35,   36,   23,   56,   57,   60,   51,
   85,   84,   54,   83,   38,   39,   42,   43,   45,   46,
   23,   50,   27,   55,   30,   59,   32,   61,   35,   65,
   42,   73,   45,   77,   81,   27,   80,   82,   32,   79,
   64,   35,   53,   68,   38,   71,   70,   39,   42,    0,
   76,   45,    0,    0,    0,    0,    0,    0,    0,    0,
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
    0,    0,    0,    0,    0,    0,    0,    0,   58,   58,
   57,   17,   57,   26,   26,   19,   19,   40,   40,   48,
   48,   65,   65,   30,   60,   69,   77,   27,   20,   18,
   14,   33,   41,   36,   39,   49,   44,   47,   55,   52,
   66,   61,   64,   73,    3,   32,   72,
};
static const YYINT yycheck[] = {                        267,
    0,   38,    0,    0,   41,    0,   45,    0,  268,    0,
  269,    0,  268,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   77,   42,
   43,   35,   36,  268,   32,   33,  257,  258,  259,  260,
  261,  262,  263,  264,  265,  266,  268,  267,  268,  267,
  268,  267,  268,  267,  268,  267,   27,   28,   30,   23,
   73,   65,   26,   61,  267,  268,  267,  268,  267,  268,
  267,  268,  267,  268,  267,  268,  267,  268,  267,  268,
  267,  268,  267,  268,   55,  267,   50,   59,  267,   49,
  268,  267,   25,  268,  267,   40,  268,  268,  267,   -1,
  268,  267,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
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
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  268,  269,
  267,  269,  269,  268,  269,  268,  269,  268,  269,  268,
  269,  268,  269,  269,  269,  269,  269,  269,  269,  269,
  269,  269,  269,  269,  269,  269,  269,  269,  269,  269,
  269,  269,  269,  269,  269,  269,  269,
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
   -1,   -1,   -1,   -1,   -1,   -1,
};
#endif
#define YYFINAL 11
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 269
#define YYUNDFTOKEN 293
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
"HISTORY_COMMAND","PARAM_NAME","PARAM_VALUE","CMD_SEPARATOR","$accept","total",
"mv_all_options","line","path_dst","mv_line","ls_line","ls_all_options",
"pwd_line","pwd_all_options","touch_line","touch_all_options","rm_line",
"rm_all_options","grep_line","grep_all_options","grep_args","cat_line",
"cat_all_options","ps_line","ps_all_options","clear_line","history_line",
"illegal-symbol",
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
"ls_line : LS_COMMAND ls_all_options",
"ls_line : LS_COMMAND ls_all_options PARAM_VALUE",
"ls_line : LS_COMMAND PARAM_VALUE ls_all_options",
"ls_line : LS_COMMAND",
"ls_line : LS_COMMAND PARAM_VALUE",
"ls_all_options : PARAM_NAME PARAM_VALUE",
"ls_all_options : PARAM_NAME",
"ls_all_options : PARAM_NAME PARAM_VALUE ls_all_options",
"ls_all_options : PARAM_NAME ls_all_options",
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
#line 443 "proj.y"

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
#line 616 "y.tab.c"

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
#line 29 "proj.y"
	{ printf("%s", yystack.l_mark[0].strval); free(yystack.l_mark[0].strval); }
#line 1289 "y.tab.c"
break;
case 2:
#line 30 "proj.y"
	{ printf("%s %s", yystack.l_mark[-1].strval, yystack.l_mark[0].strval); free(yystack.l_mark[0].strval); free(yystack.l_mark[-1].strval); }
#line 1294 "y.tab.c"
break;
case 3:
#line 31 "proj.y"
	{ printf("%s", yystack.l_mark[0].strval); free(yystack.l_mark[0].strval); }
#line 1299 "y.tab.c"
break;
case 14:
#line 46 "proj.y"
	{
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "Get-ChildItem %s", yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 1308 "y.tab.c"
break;
case 15:
#line 52 "proj.y"
	{
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "Get-ChildItem -Path %s %s", yystack.l_mark[0].strval, yystack.l_mark[-1].strval);
                                                                    yyval.strval = result;
                                                                }
#line 1317 "y.tab.c"
break;
case 16:
#line 57 "proj.y"
	{
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "Get-ChildItem -Path %s %s", yystack.l_mark[-1].strval, yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 1326 "y.tab.c"
break;
case 17:
#line 62 "proj.y"
	{
                                                                    yyval.strval = strdup("Get-ChildItem");
                                                                }
#line 1333 "y.tab.c"
break;
case 18:
#line 65 "proj.y"
	{
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "Get-ChildItem -Path %s", yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 1342 "y.tab.c"
break;
case 19:
#line 72 "proj.y"
	{
                                                                    char intermediar[128] = "";
                                                                    convertLSParamName(yystack.l_mark[-1].strval, intermediar);
                                                                    char* result = malloc(256);
                                                                    sprintf(result, "%s %s", intermediar, yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 1353 "y.tab.c"
break;
case 20:
#line 79 "proj.y"
	{
                                                                    char intermediar[128] = "";
                                                                    convertLSParamName(yystack.l_mark[0].strval, intermediar);
                                                                    yyval.strval = strdup(intermediar);
                                                                }
#line 1362 "y.tab.c"
break;
case 21:
#line 84 "proj.y"
	{
                                                                    char intermediar[128] = "";
                                                                    convertLSParamName(yystack.l_mark[-2].strval, intermediar);
                                                                    char* result = malloc(256);
                                                                    sprintf(result, "%s %s %s", intermediar, yystack.l_mark[-1].strval, yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 1373 "y.tab.c"
break;
case 22:
#line 91 "proj.y"
	{
                                                                    char intermediar[128] = "";
                                                                    convertLSParamName(yystack.l_mark[-1].strval, intermediar);
                                                                    char* result = malloc(256);
                                                                    sprintf(result, "%s %s", intermediar, yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 1384 "y.tab.c"
break;
case 23:
#line 100 "proj.y"
	{
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "Move-Item %s %s", yystack.l_mark[0].strval, yystack.l_mark[-1].strval);
                                                                    yyval.strval = result;
                                                                }
#line 1393 "y.tab.c"
break;
case 24:
#line 105 "proj.y"
	{
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "Move-Item %s %s", yystack.l_mark[-1].strval, yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 1402 "y.tab.c"
break;
case 25:
#line 111 "proj.y"
	{
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "-Path %s -Destination %s", yystack.l_mark[-1].strval, yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 1411 "y.tab.c"
break;
case 26:
#line 118 "proj.y"
	{
                                                                    char intermediar[128] = "";
                                                                    convertMVParamName(yystack.l_mark[-1].strval, intermediar);
                                                                    char* result = malloc(256);
                                                                    sprintf(result, "%s %s", intermediar, yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 1422 "y.tab.c"
break;
case 27:
#line 125 "proj.y"
	{
                                                                    char intermediar[128] = "";
                                                                    convertMVParamName(yystack.l_mark[0].strval, intermediar);
                                                                    yyval.strval = strdup(intermediar);
                                                                }
#line 1431 "y.tab.c"
break;
case 28:
#line 130 "proj.y"
	{
                                                                    char intermediar[128] = "";
                                                                    convertMVParamName(yystack.l_mark[-2].strval, intermediar);
                                                                    char* result = malloc(256);
                                                                    sprintf(result, "%s %s %s", intermediar, yystack.l_mark[-1].strval, yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 1442 "y.tab.c"
break;
case 29:
#line 137 "proj.y"
	{
                                                                    char intermediar[128] = "";
                                                                    convertMVParamName(yystack.l_mark[-1].strval, intermediar);
                                                                    char* result = malloc(256);
                                                                    sprintf(result, "%s %s", intermediar, yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 1453 "y.tab.c"
break;
case 30:
#line 146 "proj.y"
	{
                                                                    yyval.strval = strdup("Get-Location");
                                                                }
#line 1460 "y.tab.c"
break;
case 31:
#line 149 "proj.y"
	{
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "Get-Location %s", yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 1469 "y.tab.c"
break;
case 32:
#line 156 "proj.y"
	{
                                                                    char intermediar[128] = "";
                                                                    convertPWDParamName(yystack.l_mark[-1].strval, intermediar);
                                                                    char* result = malloc(256);
                                                                    sprintf(result, "%s %s", intermediar, yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 1480 "y.tab.c"
break;
case 33:
#line 163 "proj.y"
	{
                                                                    char intermediar[128] = "";
                                                                    convertPWDParamName(yystack.l_mark[0].strval, intermediar);
                                                                    yyval.strval = strdup(intermediar);
                                                                }
#line 1489 "y.tab.c"
break;
case 34:
#line 168 "proj.y"
	{
                                                                    char intermediar[128] = "";
                                                                    convertPWDParamName(yystack.l_mark[-2].strval, intermediar);
                                                                    char* result = malloc(256);
                                                                    sprintf(result, "%s %s %s", intermediar, yystack.l_mark[-1].strval, yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 1500 "y.tab.c"
break;
case 35:
#line 175 "proj.y"
	{
                                                                    char intermediar[128] = "";
                                                                    convertPWDParamName(yystack.l_mark[-1].strval, intermediar);
                                                                    char* result = malloc(256);
                                                                    sprintf(result, "%s %s", intermediar, yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 1511 "y.tab.c"
break;
case 36:
#line 184 "proj.y"
	{
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "New-Item -ItemType File -Path %s", yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 1520 "y.tab.c"
break;
case 37:
#line 189 "proj.y"
	{
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "New-Item -ItemType File -Path %s %s", yystack.l_mark[0].strval, yystack.l_mark[-1].strval);
                                                                    yyval.strval = result;
                                                                }
#line 1529 "y.tab.c"
break;
case 38:
#line 194 "proj.y"
	{
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "New-Item -ItemType File -Path %s %s", yystack.l_mark[-1].strval, yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 1538 "y.tab.c"
break;
case 39:
#line 199 "proj.y"
	{
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "New-Item -ItemType File %s", yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 1547 "y.tab.c"
break;
case 40:
#line 206 "proj.y"
	{
                                                                    char intermediar[128] = "";
                                                                    convertTouchParamName(yystack.l_mark[-1].strval, intermediar);
                                                                    char* result = malloc(256);
                                                                    sprintf(result, "%s %s", intermediar, yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 1558 "y.tab.c"
break;
case 41:
#line 213 "proj.y"
	{
                                                                    char intermediar[128] = "";
                                                                    convertTouchParamName(yystack.l_mark[0].strval, intermediar);
                                                                    yyval.strval = strdup(intermediar);
                                                                }
#line 1567 "y.tab.c"
break;
case 42:
#line 218 "proj.y"
	{
                                                                    char intermediar[128] = "";
                                                                    convertTouchParamName(yystack.l_mark[-2].strval, intermediar);
                                                                    char* result = malloc(256);
                                                                    sprintf(result, "%s %s %s", intermediar, yystack.l_mark[-1].strval, yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 1578 "y.tab.c"
break;
case 43:
#line 225 "proj.y"
	{
                                                                    char intermediar[128] = "";
                                                                    convertTouchParamName(yystack.l_mark[-1].strval, intermediar);
                                                                    char* result = malloc(256);
                                                                    sprintf(result, "%s %s", intermediar, yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 1589 "y.tab.c"
break;
case 44:
#line 234 "proj.y"
	{
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "Remove-Item -Path %s", yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 1598 "y.tab.c"
break;
case 45:
#line 239 "proj.y"
	{
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "Remove-Item -Path %s %s", yystack.l_mark[0].strval, yystack.l_mark[-1].strval);
                                                                    yyval.strval = result;
                                                                }
#line 1607 "y.tab.c"
break;
case 46:
#line 244 "proj.y"
	{
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "Remove-Item -Path %s %s", yystack.l_mark[-1].strval, yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 1616 "y.tab.c"
break;
case 47:
#line 249 "proj.y"
	{
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "Remove-Item %s", yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 1625 "y.tab.c"
break;
case 48:
#line 256 "proj.y"
	{
                                                                    char intermediar[128] = "";
                                                                    convertRMParamName(yystack.l_mark[-1].strval, intermediar);
                                                                    char* result = malloc(256);
                                                                    sprintf(result, "%s %s", intermediar, yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 1636 "y.tab.c"
break;
case 49:
#line 263 "proj.y"
	{
                                                                    char intermediar[128] = "";
                                                                    convertRMParamName(yystack.l_mark[0].strval, intermediar);
                                                                    yyval.strval = strdup(intermediar);
                                                                }
#line 1645 "y.tab.c"
break;
case 50:
#line 268 "proj.y"
	{
                                                                    char intermediar[128] = "";
                                                                    convertRMParamName(yystack.l_mark[-2].strval, intermediar);
                                                                    char* result = malloc(256);
                                                                    sprintf(result, "%s %s %s", intermediar, yystack.l_mark[-1].strval, yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 1656 "y.tab.c"
break;
case 51:
#line 275 "proj.y"
	{
                                                                    char intermediar[128] = "";
                                                                    convertRMParamName(yystack.l_mark[-1].strval, intermediar);
                                                                    char* result = malloc(256);
                                                                    sprintf(result, "%s %s", intermediar, yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 1667 "y.tab.c"
break;
case 52:
#line 284 "proj.y"
	{
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "Select-String %s", yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 1676 "y.tab.c"
break;
case 53:
#line 289 "proj.y"
	{
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "Select-String %s %s", yystack.l_mark[0].strval, yystack.l_mark[-1].strval);
                                                                    yyval.strval = result;
                                                                }
#line 1685 "y.tab.c"
break;
case 54:
#line 294 "proj.y"
	{
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "Select-String %s %s", yystack.l_mark[-1].strval, yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 1694 "y.tab.c"
break;
case 55:
#line 299 "proj.y"
	{
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "Select-String %s", yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 1703 "y.tab.c"
break;
case 56:
#line 306 "proj.y"
	{
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "-Pattern %s -Path %s", yystack.l_mark[-1].strval, yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 1712 "y.tab.c"
break;
case 57:
#line 311 "proj.y"
	{
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "-Pattern %s", yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 1721 "y.tab.c"
break;
case 58:
#line 318 "proj.y"
	{
                                                                    char intermediar[128] = "";
                                                                    convertGrepParamName(yystack.l_mark[0].strval, intermediar);
                                                                    yyval.strval = strdup(intermediar);
                                                                }
#line 1730 "y.tab.c"
break;
case 59:
#line 323 "proj.y"
	{
                                                                    char intermediar[128] = "";
                                                                    convertGrepParamName(yystack.l_mark[-1].strval, intermediar);
                                                                    char* result = malloc(256);
                                                                    sprintf(result, "%s %s", intermediar, yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 1741 "y.tab.c"
break;
case 60:
#line 332 "proj.y"
	{
                                                                    yyval.strval = strdup("Get-Content");
                                                                }
#line 1748 "y.tab.c"
break;
case 61:
#line 335 "proj.y"
	{
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "Get-Content -Path %s", yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 1757 "y.tab.c"
break;
case 62:
#line 340 "proj.y"
	{
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "Get-Content -Path %s %s", yystack.l_mark[0].strval, yystack.l_mark[-1].strval);
                                                                    yyval.strval = result;
                                                                }
#line 1766 "y.tab.c"
break;
case 63:
#line 345 "proj.y"
	{
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "Get-Content -Path %s %s", yystack.l_mark[-1].strval, yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 1775 "y.tab.c"
break;
case 64:
#line 350 "proj.y"
	{
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "Get-Content %s", yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 1784 "y.tab.c"
break;
case 65:
#line 357 "proj.y"
	{
                                                                    char intermediar[128] = "";
                                                                    convertCatParamName(yystack.l_mark[-1].strval, intermediar);
                                                                    char* result = malloc(256);
                                                                    sprintf(result, "%s %s", intermediar, yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 1795 "y.tab.c"
break;
case 66:
#line 364 "proj.y"
	{
                                                                    char intermediar[128] = "";
                                                                    convertCatParamName(yystack.l_mark[0].strval, intermediar);
                                                                    yyval.strval = strdup(intermediar);
                                                                }
#line 1804 "y.tab.c"
break;
case 67:
#line 369 "proj.y"
	{
                                                                    char intermediar[128] = "";
                                                                    convertCatParamName(yystack.l_mark[-2].strval, intermediar);
                                                                    char* result = malloc(256);
                                                                    sprintf(result, "%s %s %s", intermediar, yystack.l_mark[-1].strval, yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 1815 "y.tab.c"
break;
case 68:
#line 376 "proj.y"
	{
                                                                    char intermediar[128] = "";
                                                                    convertCatParamName(yystack.l_mark[-1].strval, intermediar);
                                                                    char* result = malloc(256);
                                                                    sprintf(result, "%s %s", intermediar, yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 1826 "y.tab.c"
break;
case 69:
#line 385 "proj.y"
	{
                                                                    yyval.strval = strdup("Get-Process");
                                                                }
#line 1833 "y.tab.c"
break;
case 70:
#line 388 "proj.y"
	{
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "Get-Process %s", yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 1842 "y.tab.c"
break;
case 71:
#line 393 "proj.y"
	{
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "Get-Process %s", yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 1851 "y.tab.c"
break;
case 72:
#line 400 "proj.y"
	{
                                                                    char intermediar[128] = "";
                                                                    convertPSParamName(yystack.l_mark[-1].strval, intermediar);
                                                                    char* result = malloc(256);
                                                                    sprintf(result, "%s %s", intermediar, yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 1862 "y.tab.c"
break;
case 73:
#line 407 "proj.y"
	{
                                                                    char intermediar[128] = "";
                                                                    convertPSParamName(yystack.l_mark[0].strval, intermediar);
                                                                    yyval.strval = strdup(intermediar);
                                                                }
#line 1871 "y.tab.c"
break;
case 74:
#line 412 "proj.y"
	{
                                                                    char intermediar[128] = "";
                                                                    convertPSParamName(yystack.l_mark[-2].strval, intermediar);
                                                                    char* result = malloc(256);
                                                                    sprintf(result, "%s %s %s", intermediar, yystack.l_mark[-1].strval, yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 1882 "y.tab.c"
break;
case 75:
#line 419 "proj.y"
	{
                                                                    char intermediar[128] = "";
                                                                    convertPSParamName(yystack.l_mark[-1].strval, intermediar);
                                                                    char* result = malloc(256);
                                                                    sprintf(result, "%s %s", intermediar, yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 1893 "y.tab.c"
break;
case 76:
#line 428 "proj.y"
	{
                                                                    yyval.strval = strdup("Clear-Host");
                                                                }
#line 1900 "y.tab.c"
break;
case 77:
#line 433 "proj.y"
	{
                                                                    yyval.strval = strdup("Get-History");
                                                                }
#line 1907 "y.tab.c"
break;
case 78:
#line 436 "proj.y"
	{
                                                                    char* result = malloc(512);
                                                                    sprintf(result, "Get-History -Count %s", yystack.l_mark[0].strval);
                                                                    yyval.strval = result;
                                                                }
#line 1916 "y.tab.c"
break;
#line 1918 "y.tab.c"
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
