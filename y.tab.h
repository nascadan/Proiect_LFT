#ifndef _yy_defines_h_
#define _yy_defines_h_

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
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union YYSTYPE {
    int intval;
    char* strval;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;

#endif /* _yy_defines_h_ */
