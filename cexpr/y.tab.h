#define NUM 257
#define VAR 258
#define DUMP 259
#define CLEAR 260
#define EQUAL 261
#define ADD_EQUAL 262
#define SUB_EQUAL 263
#define MUL_EQUAL 264
#define DIV_EQUAL 265
#define REM_EQUAL 266
#define LSHIFT_EQUAL 267
#define RSHIFT_EQUAL 268
#define AND_EQUAL 269
#define XOR_EQUAL 270
#define OR_EQUAL 271
#define BIT_OR 272
#define BIT_XOR 273
#define BIT_AND 274
#define LSHIFT 275
#define RSHIFT 276
#define ADD 277
#define SUB 278
#define MUL 279
#define DIV 280
#define REM 281
#define BIT_NOT 282
#define OPEN_PAREN 283
#define CLOSE_PAREN 284
#define SEMICOLON 285
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
  int num;
  char *string;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;
