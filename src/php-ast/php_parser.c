/* A Bison parser, made by GNU Bison 2.1.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* Written by Richard Stallman by simplifying the original so called
   ``semantic'' parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "php-ast.c"

/* Pure parsers.  */
#define YYPURE 1

/* Using locations.  */
#define YYLSP_NEEDED 1



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     T_REQUIRE_ONCE = 258,
     T_REQUIRE = 259,
     T_EVAL = 260,
     T_INCLUDE_ONCE = 261,
     T_INCLUDE = 262,
     T_LOGICAL_OR = 263,
     T_LOGICAL_XOR = 264,
     T_LOGICAL_AND = 265,
     T_PRINT = 266,
     T_SR_EQUAL = 267,
     T_SL_EQUAL = 268,
     T_XOR_EQUAL = 269,
     T_OR_EQUAL = 270,
     T_AND_EQUAL = 271,
     T_MOD_EQUAL = 272,
     T_CONCAT_EQUAL = 273,
     T_DIV_EQUAL = 274,
     T_MUL_EQUAL = 275,
     T_MINUS_EQUAL = 276,
     T_PLUS_EQUAL = 277,
     T_BOOLEAN_OR = 278,
     T_BOOLEAN_AND = 279,
     T_IS_NOT_IDENTICAL = 280,
     T_IS_IDENTICAL = 281,
     T_IS_NOT_EQUAL = 282,
     T_IS_EQUAL = 283,
     T_IS_GREATER_OR_EQUAL = 284,
     T_IS_SMALLER_OR_EQUAL = 285,
     T_SR = 286,
     T_SL = 287,
     T_INSTANCEOF = 288,
     T_UNSET_CAST = 289,
     T_BOOL_CAST = 290,
     T_OBJECT_CAST = 291,
     T_ARRAY_CAST = 292,
     T_STRING_CAST = 293,
     T_DOUBLE_CAST = 294,
     T_INT_CAST = 295,
     T_DEC = 296,
     T_INC = 297,
     T_CLONE = 298,
     T_NEW = 299,
     T_EXIT = 300,
     T_IF = 301,
     T_ELSEIF = 302,
     T_ELSE = 303,
     T_ENDIF = 304,
     T_LNUMBER = 305,
     T_DNUMBER = 306,
     T_STRING = 307,
     T_STRING_VARNAME = 308,
     T_VARIABLE = 309,
     T_NUM_STRING = 310,
     T_INLINE_HTML = 311,
     T_CHARACTER = 312,
     T_BAD_CHARACTER = 313,
     T_ENCAPSED_AND_WHITESPACE = 314,
     T_CONSTANT_ENCAPSED_STRING = 315,
     T_ECHO = 316,
     T_DO = 317,
     T_WHILE = 318,
     T_ENDWHILE = 319,
     T_FOR = 320,
     T_ENDFOR = 321,
     T_FOREACH = 322,
     T_ENDFOREACH = 323,
     T_DECLARE = 324,
     T_ENDDECLARE = 325,
     T_AS = 326,
     T_SWITCH = 327,
     T_ENDSWITCH = 328,
     T_CASE = 329,
     T_DEFAULT = 330,
     T_BREAK = 331,
     T_CONTINUE = 332,
     T_FUNCTION = 333,
     T_CONST = 334,
     T_RETURN = 335,
     T_TRY = 336,
     T_CATCH = 337,
     T_THROW = 338,
     T_USE = 339,
     T_GLOBAL = 340,
     T_PUBLIC = 341,
     T_PROTECTED = 342,
     T_PRIVATE = 343,
     T_FINAL = 344,
     T_ABSTRACT = 345,
     T_STATIC = 346,
     T_VAR = 347,
     T_UNSET = 348,
     T_ISSET = 349,
     T_EMPTY = 350,
     T_HALT_COMPILER = 351,
     T_CLASS = 352,
     T_INTERFACE = 353,
     T_EXTENDS = 354,
     T_IMPLEMENTS = 355,
     T_OBJECT_OPERATOR = 356,
     T_DOUBLE_ARROW = 357,
     T_LIST = 358,
     T_ARRAY = 359,
     T_CLASS_C = 360,
     T_METHOD_C = 361,
     T_FUNC_C = 362,
     T_LINE = 363,
     T_FILE = 364,
     T_COMMENT = 365,
     T_DOC_COMMENT = 366,
     T_OPEN_TAG = 367,
     T_OPEN_TAG_WITH_ECHO = 368,
     T_CLOSE_TAG = 369,
     T_WHITESPACE = 370,
     T_START_HEREDOC = 371,
     T_END_HEREDOC = 372,
     T_DOLLAR_OPEN_CURLY_BRACES = 373,
     T_CURLY_OPEN = 374,
     T_PAAMAYIM_NEKUDOTAYIM = 375,
     T_ASPECT = 376,
     T_BEFORE = 377,
     T_AROUND = 378,
     T_AFTER = 379,
     T_POINTCUT = 380,
     T_EXEC = 381,
     T_CALL = 382,
     T_SET = 383,
     T_GET = 384,
     T_THIS = 385,
     T_WITHIN = 386
   };
#endif
/* Tokens.  */
#define T_REQUIRE_ONCE 258
#define T_REQUIRE 259
#define T_EVAL 260
#define T_INCLUDE_ONCE 261
#define T_INCLUDE 262
#define T_LOGICAL_OR 263
#define T_LOGICAL_XOR 264
#define T_LOGICAL_AND 265
#define T_PRINT 266
#define T_SR_EQUAL 267
#define T_SL_EQUAL 268
#define T_XOR_EQUAL 269
#define T_OR_EQUAL 270
#define T_AND_EQUAL 271
#define T_MOD_EQUAL 272
#define T_CONCAT_EQUAL 273
#define T_DIV_EQUAL 274
#define T_MUL_EQUAL 275
#define T_MINUS_EQUAL 276
#define T_PLUS_EQUAL 277
#define T_BOOLEAN_OR 278
#define T_BOOLEAN_AND 279
#define T_IS_NOT_IDENTICAL 280
#define T_IS_IDENTICAL 281
#define T_IS_NOT_EQUAL 282
#define T_IS_EQUAL 283
#define T_IS_GREATER_OR_EQUAL 284
#define T_IS_SMALLER_OR_EQUAL 285
#define T_SR 286
#define T_SL 287
#define T_INSTANCEOF 288
#define T_UNSET_CAST 289
#define T_BOOL_CAST 290
#define T_OBJECT_CAST 291
#define T_ARRAY_CAST 292
#define T_STRING_CAST 293
#define T_DOUBLE_CAST 294
#define T_INT_CAST 295
#define T_DEC 296
#define T_INC 297
#define T_CLONE 298
#define T_NEW 299
#define T_EXIT 300
#define T_IF 301
#define T_ELSEIF 302
#define T_ELSE 303
#define T_ENDIF 304
#define T_LNUMBER 305
#define T_DNUMBER 306
#define T_STRING 307
#define T_STRING_VARNAME 308
#define T_VARIABLE 309
#define T_NUM_STRING 310
#define T_INLINE_HTML 311
#define T_CHARACTER 312
#define T_BAD_CHARACTER 313
#define T_ENCAPSED_AND_WHITESPACE 314
#define T_CONSTANT_ENCAPSED_STRING 315
#define T_ECHO 316
#define T_DO 317
#define T_WHILE 318
#define T_ENDWHILE 319
#define T_FOR 320
#define T_ENDFOR 321
#define T_FOREACH 322
#define T_ENDFOREACH 323
#define T_DECLARE 324
#define T_ENDDECLARE 325
#define T_AS 326
#define T_SWITCH 327
#define T_ENDSWITCH 328
#define T_CASE 329
#define T_DEFAULT 330
#define T_BREAK 331
#define T_CONTINUE 332
#define T_FUNCTION 333
#define T_CONST 334
#define T_RETURN 335
#define T_TRY 336
#define T_CATCH 337
#define T_THROW 338
#define T_USE 339
#define T_GLOBAL 340
#define T_PUBLIC 341
#define T_PROTECTED 342
#define T_PRIVATE 343
#define T_FINAL 344
#define T_ABSTRACT 345
#define T_STATIC 346
#define T_VAR 347
#define T_UNSET 348
#define T_ISSET 349
#define T_EMPTY 350
#define T_HALT_COMPILER 351
#define T_CLASS 352
#define T_INTERFACE 353
#define T_EXTENDS 354
#define T_IMPLEMENTS 355
#define T_OBJECT_OPERATOR 356
#define T_DOUBLE_ARROW 357
#define T_LIST 358
#define T_ARRAY 359
#define T_CLASS_C 360
#define T_METHOD_C 361
#define T_FUNC_C 362
#define T_LINE 363
#define T_FILE 364
#define T_COMMENT 365
#define T_DOC_COMMENT 366
#define T_OPEN_TAG 367
#define T_OPEN_TAG_WITH_ECHO 368
#define T_CLOSE_TAG 369
#define T_WHITESPACE 370
#define T_START_HEREDOC 371
#define T_END_HEREDOC 372
#define T_DOLLAR_OPEN_CURLY_BRACES 373
#define T_CURLY_OPEN 374
#define T_PAAMAYIM_NEKUDOTAYIM 375
#define T_ASPECT 376
#define T_BEFORE 377
#define T_AROUND 378
#define T_AFTER 379
#define T_POINTCUT 380
#define T_EXEC 381
#define T_CALL 382
#define T_SET 383
#define T_GET 384
#define T_THIS 385
#define T_WITHIN 386




/* Copy the first part of user declarations.  */
#line 1 "php_parser.y"

/*
   +----------------------------------------------------------------------+
   | Zend Engine                                                          |
   +----------------------------------------------------------------------+
   | Copyright (c) 1998-2006 Zend Technologies Ltd. (http://www.zend.com) |
   +----------------------------------------------------------------------+
   | This source file is subject to version 2.00 of the Zend license,     |
   | that is bundled with this package in the file LICENSE, and is        | 
   | available through the world-wide-web at the following url:           |
   | http://www.zend.com/license/2_00.txt.                                |
   | If you did not receive a copy of the Zend license and are unable to  |
   | obtain it through the world-wide-web, please send a note to          |
   | license@zend.com so we can mail you a copy immediately.              |
   +----------------------------------------------------------------------+
   | Authors: Andi Gutmans <andi@zend.com>                                |
   |          Zeev Suraski <zeev@zend.com>                                |
   +----------------------------------------------------------------------+
*/

/* $Id: php_parser.c,v 1.5 2007/01/06 03:20:11 wcandillon Exp $ */

/* 
 * LALR shift/reduce conflicts and how they are resolved:
 *
 * - 2 shift/reduce conflicts due to the dangeling elseif/else ambiguity.  Solved by shift.
 * - 1 shift/reduce conflict due to arrays within encapsulated strings. Solved by shift. 
 * - 1 shift/reduce conflict due to objects within encapsulated strings.  Solved by shift.
 * 
 */

#define YYERROR_VERBOSE
#define YYSTYPE char*
void yyerror(char* s);
extern int yylex();
extern int yywrap();
extern int yylocationp();
extern int getLineno();
char* file_name;
char* _xml_output;
int _error=0;


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 222 of yacc.c.  */
#line 401 "php_parser.c"

#if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
# define YYSIZE_T __SIZE_TYPE__
#endif
#if ! defined (YYSIZE_T) && defined (size_t)
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T) && (defined (__STDC__) || defined (__cplusplus))
# include <stddef.h> /* INFRINGES ON USER NAME SPACE */
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T)
# define YYSIZE_T unsigned int
#endif

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

//#if ! defined (yyoverflow) || YYERROR_VERBOSE
#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

#define XML_ALLOC(X) malloc(X)
#define XML_FREE(X) free(X)
# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if defined (__STDC__) || defined (__cplusplus)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     define YYINCLUDED_STDLIB_H
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning. */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2005 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM ((YYSIZE_T) -1)
#  endif
#  ifdef __cplusplus
extern "C" {
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if (! defined (malloc) && ! defined (YYINCLUDED_STDLIB_H) \
	&& (defined (__STDC__) || defined (__cplusplus)))
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if (! defined (free) && ! defined (YYINCLUDED_STDLIB_H) \
	&& (defined (__STDC__) || defined (__cplusplus)))
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifdef __cplusplus
}
#  endif
# endif
#endif /* ! defined (yyoverflow) || YYERROR_VERBOSE */


#if (! defined (yyoverflow) \
     && (! defined (__cplusplus) \
	 || (defined (YYSTYPE_IS_TRIVIAL) && YYSTYPE_IS_TRIVIAL)))
/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  short int yyss;
  char *yyxs; // Yijun Yu: for XML
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)
// Yijun Yu: for yyxs
/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short int) + sizeof (YYSTYPE))				\
     + sizeof(char *) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined (__GNUC__) && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;		\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (0)
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (0)

#endif

#if defined (__STDC__) || defined (__cplusplus)
   typedef signed char yysigned_char;
#else
   typedef short int yysigned_char;
#endif

/* YYFINAL -- State number of the termination state. */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   4343

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  161
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  181
/* YYNRULES -- Number of rules. */
#define YYNRULES  471
/* YYNRULES -- Number of states. */
#define YYNSTATES  952

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   386

#define YYTRANSLATE(YYX) 						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    48,   158,     2,   156,    47,    31,   159,
     151,   152,    45,    42,     8,    43,    44,    46,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    26,   153,
      36,    13,    37,    25,    51,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    61,     2,   160,    30,     2,   157,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   154,    29,   155,    50,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     9,    10,    11,    12,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    27,    28,
      32,    33,    34,    35,    38,    39,    40,    41,    49,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150
};

//#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned short int yyprhs[] =
{
       0,     0,     3,     5,     6,    10,    11,    13,    15,    17,
      22,    28,    29,    33,    34,    36,    38,    40,    45,    47,
      51,    52,    53,    63,    64,    65,    78,    79,    80,    88,
      89,    90,   100,   101,   102,   103,   116,   117,   124,   127,
     131,   134,   138,   141,   145,   149,   153,   157,   161,   163,
     166,   170,   176,   177,   178,   179,   191,   192,   193,   194,
     206,   207,   214,   216,   217,   218,   219,   220,   221,   240,
     244,   246,   247,   249,   252,   253,   254,   265,   267,   271,
     273,   275,   279,   281,   283,   284,   286,   287,   288,   300,
     301,   310,   311,   319,   322,   323,   325,   329,   332,   343,
     349,   359,   368,   378,   379,   381,   385,   389,   393,   396,
     398,   400,   410,   423,   431,   436,   441,   448,   455,   460,
     465,   470,   473,   475,   477,   479,   481,   487,   495,   499,
     505,   513,   520,   524,   526,   529,   532,   535,   537,   539,
     541,   542,   544,   547,   550,   551,   554,   556,   557,   560,
     561,   564,   566,   570,   571,   574,   576,   579,   581,   586,
     588,   593,   595,   600,   604,   610,   614,   619,   624,   630,
     631,   632,   639,   640,   646,   648,   650,   652,   657,   658,
     659,   667,   668,   669,   678,   679,   682,   683,   687,   689,
     690,   693,   697,   703,   708,   713,   719,   727,   734,   735,
     737,   739,   741,   742,   744,   746,   749,   753,   757,   762,
     766,   768,   770,   773,   778,   782,   788,   790,   794,   797,
     798,   799,   804,   807,   816,   818,   822,   824,   826,   827,
     829,   831,   834,   836,   838,   840,   842,   844,   846,   850,
     856,   858,   862,   868,   873,   877,   879,   880,   882,   883,
     888,   890,   891,   899,   903,   908,   909,   917,   918,   923,
     926,   930,   934,   938,   942,   946,   950,   954,   958,   962,
     966,   970,   973,   976,   979,   982,   983,   988,   989,   994,
     995,  1000,  1001,  1006,  1010,  1014,  1018,  1022,  1026,  1030,
    1034,  1038,  1042,  1046,  1050,  1054,  1057,  1060,  1063,  1066,
    1070,  1074,  1078,  1082,  1086,  1090,  1094,  1098,  1102,  1106,
    1107,  1108,  1116,  1118,  1121,  1124,  1127,  1130,  1133,  1136,
    1139,  1142,  1143,  1147,  1149,  1154,  1158,  1161,  1162,  1168,
    1169,  1177,  1178,  1186,  1187,  1193,  1195,  1197,  1199,  1200,
    1201,  1208,  1210,  1213,  1214,  1217,  1218,  1221,  1225,  1226,
    1230,  1232,  1234,  1236,  1238,  1240,  1242,  1244,  1246,  1248,
    1250,  1253,  1256,  1261,  1263,  1267,  1269,  1271,  1273,  1275,
    1279,  1283,  1287,  1288,  1291,  1292,  1294,  1300,  1304,  1308,
    1310,  1312,  1314,  1316,  1317,  1320,  1321,  1324,  1325,  1326,
    1334,  1336,  1339,  1340,  1341,  1346,  1347,  1352,  1353,  1355,
    1358,  1362,  1364,  1366,  1368,  1371,  1373,  1378,  1383,  1385,
    1387,  1392,  1393,  1395,  1397,  1398,  1401,  1406,  1411,  1413,
    1415,  1419,  1421,  1424,  1428,  1430,  1432,  1433,  1439,  1440,
    1441,  1444,  1450,  1454,  1458,  1460,  1467,  1472,  1477,  1480,
    1483,  1486,  1489,  1492,  1495,  1498,  1501,  1504,  1507,  1510,
    1513,  1514,  1516,  1517,  1523,  1527,  1531,  1538,  1542,  1544,
    1546,  1548,  1553,  1558,  1561,  1564,  1569,  1572,  1575,  1577,
    1578,  1583
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short int yyrhs[] =
{
     162,     0,    -1,   163,    -1,    -1,   163,   164,   165,    -1,
      -1,   169,    -1,   203,    -1,   204,    -1,   115,   151,   152,
     153,    -1,   140,    71,   154,   212,   155,    -1,    -1,   166,
     167,   168,    -1,    -1,   169,    -1,   203,    -1,   204,    -1,
     115,   151,   152,   153,    -1,   170,    -1,   154,   166,   155,
      -1,    -1,    -1,    65,   151,   303,   152,   171,   169,   172,
     243,   247,    -1,    -1,    -1,    65,   151,   303,   152,    26,
     173,   166,   174,   245,   248,    68,   153,    -1,    -1,    -1,
      82,   151,   175,   303,   152,   176,   242,    -1,    -1,    -1,
      81,   177,   169,    82,   151,   178,   303,   152,   153,    -1,
      -1,    -1,    -1,    84,   151,   268,   153,   179,   268,   153,
     180,   268,   152,   181,   233,    -1,    -1,    91,   151,   303,
     152,   182,   237,    -1,    95,   153,    -1,    95,   303,   153,
      -1,    96,   153,    -1,    96,   303,   153,    -1,    99,   153,
      -1,    99,   271,   153,    -1,    99,   309,   153,    -1,   104,
     254,   153,    -1,   110,   256,   153,    -1,    80,   267,   153,
      -1,    75,    -1,   303,   153,    -1,   103,   202,   153,    -1,
     112,   151,   200,   152,   153,    -1,    -1,    -1,    -1,    86,
     151,   309,   183,    90,   184,   232,   231,   152,   185,   234,
      -1,    -1,    -1,    -1,    86,   151,   271,   186,    90,   187,
     309,   231,   152,   188,   234,    -1,    -1,    88,   189,   151,
     236,   152,   235,    -1,   153,    -1,    -1,    -1,    -1,    -1,
      -1,   100,   190,   154,   166,   155,   101,   151,   191,   287,
     192,    73,   152,   193,   154,   166,   155,   194,   195,    -1,
     102,   303,   153,    -1,   196,    -1,    -1,   197,    -1,   196,
     197,    -1,    -1,    -1,   101,   151,   287,   198,    73,   152,
     199,   154,   166,   155,    -1,   201,    -1,   200,     8,   201,
      -1,   309,    -1,    79,    -1,   151,    79,   152,    -1,   206,
      -1,   209,    -1,    -1,    31,    -1,    -1,    -1,    97,   207,
     205,    71,   208,   151,   249,   152,   154,   166,   155,    -1,
      -1,   225,    71,   226,   210,   229,   154,   257,   155,    -1,
      -1,   227,    71,   211,   228,   154,   257,   155,    -1,   212,
     213,    -1,    -1,   258,    -1,   261,   219,   153,    -1,   220,
     153,    -1,   262,    97,   205,   221,   139,    71,   151,   249,
     152,   260,    -1,   144,    71,    26,   215,   153,    -1,   141,
     151,   214,   152,    26,   215,   154,   166,   155,    -1,   142,
     151,   152,    26,   215,   154,   166,   155,    -1,   143,   151,
     214,   152,    26,   215,   154,   166,   155,    -1,    -1,   200,
      -1,   215,    27,   215,    -1,   215,    28,   215,    -1,   151,
     215,   152,    -1,    48,   215,    -1,   216,    -1,    71,    -1,
     146,   151,   222,   218,   223,   151,   217,   152,   152,    -1,
     145,   151,   262,   205,   223,   139,   223,   224,   151,   217,
     152,   152,    -1,    63,   151,   222,   151,   217,   152,   152,
      -1,   101,   151,   221,   152,    -1,   112,   151,   221,   152,
      -1,   147,   151,   223,   218,   223,   152,    -1,   148,   151,
     223,   218,   223,   152,    -1,   149,   151,   222,   152,    -1,
     150,   151,   222,   152,    -1,   128,   151,    79,   152,    -1,
      51,   222,    -1,    69,    -1,    45,    -1,   120,    -1,   139,
      -1,   219,     8,   221,   139,    73,    -1,   219,     8,   221,
     139,    73,    13,   297,    -1,   221,   139,    73,    -1,   221,
     139,    73,    13,   297,    -1,   220,     8,   221,   139,    71,
      13,   297,    -1,    98,   221,   139,    71,    13,   297,    -1,
     221,     8,   222,    -1,   222,    -1,   223,   224,    -1,   223,
      45,    -1,   223,    71,    -1,    45,    -1,    71,    -1,    42,
      -1,    -1,   116,    -1,   109,   116,    -1,   108,   116,    -1,
      -1,   118,   287,    -1,   117,    -1,    -1,   118,   230,    -1,
      -1,   119,   230,    -1,   287,    -1,   230,     8,   287,    -1,
      -1,   121,   232,    -1,   309,    -1,    31,   309,    -1,   169,
      -1,    26,   166,    85,   153,    -1,   169,    -1,    26,   166,
      87,   153,    -1,   169,    -1,    26,   166,    89,   153,    -1,
      71,    13,   297,    -1,   236,     8,    71,    13,   297,    -1,
     154,   238,   155,    -1,   154,   153,   238,   155,    -1,    26,
     238,    92,   153,    -1,    26,   153,   238,    92,   153,    -1,
      -1,    -1,   238,    93,   303,   241,   239,   166,    -1,    -1,
     238,    94,   241,   240,   166,    -1,    26,    -1,   153,    -1,
     169,    -1,    26,   166,    83,   153,    -1,    -1,    -1,   243,
      66,   151,   303,   152,   244,   169,    -1,    -1,    -1,   245,
      66,   151,   303,   152,    26,   246,   166,    -1,    -1,    67,
     169,    -1,    -1,    67,    26,   166,    -1,   250,    -1,    -1,
     251,    73,    -1,   251,    31,    73,    -1,   251,    31,    73,
      13,   297,    -1,   251,    73,    13,   297,    -1,   250,     8,
     251,    73,    -1,   250,     8,   251,    31,    73,    -1,   250,
       8,   251,    31,    73,    13,   297,    -1,   250,     8,   251,
      73,    13,   297,    -1,    -1,    71,    -1,   123,    -1,   253,
      -1,    -1,   271,    -1,   309,    -1,    31,   305,    -1,   253,
       8,   271,    -1,   253,     8,   309,    -1,   253,     8,    31,
     305,    -1,   254,     8,   255,    -1,   255,    -1,    73,    -1,
     156,   304,    -1,   156,   154,   303,   155,    -1,   256,     8,
      73,    -1,   256,     8,    73,    13,   297,    -1,    73,    -1,
      73,    13,   297,    -1,   257,   258,    -1,    -1,    -1,   261,
     259,   265,   153,    -1,   266,   153,    -1,   262,    97,   205,
      71,   151,   249,   152,   260,    -1,   153,    -1,   154,   166,
     155,    -1,   263,    -1,   111,    -1,    -1,   263,    -1,   264,
      -1,   263,   264,    -1,   105,    -1,   106,    -1,   107,    -1,
     110,    -1,   109,    -1,   108,    -1,   265,     8,    73,    -1,
     265,     8,    73,    13,   297,    -1,    73,    -1,    73,    13,
     297,    -1,   266,     8,    71,    13,   297,    -1,    98,    71,
      13,   297,    -1,   267,     8,   303,    -1,   303,    -1,    -1,
     269,    -1,    -1,   269,     8,   270,   303,    -1,   303,    -1,
      -1,   122,   151,   272,   329,   152,    13,   303,    -1,   309,
      13,   303,    -1,   309,    13,    31,   309,    -1,    -1,   309,
      13,    31,    63,   288,   273,   295,    -1,    -1,    63,   288,
     274,   295,    -1,    62,   303,    -1,   309,    24,   303,    -1,
     309,    23,   303,    -1,   309,    22,   303,    -1,   309,    21,
     303,    -1,   309,    20,   303,    -1,   309,    19,   303,    -1,
     309,    18,   303,    -1,   309,    17,   303,    -1,   309,    16,
     303,    -1,   309,    15,   303,    -1,   309,    14,   303,    -1,
     307,    60,    -1,    60,   307,    -1,   307,    59,    -1,    59,
     307,    -1,    -1,   303,    27,   275,   303,    -1,    -1,   303,
      28,   276,   303,    -1,    -1,   303,     9,   277,   303,    -1,
      -1,   303,    11,   278,   303,    -1,   303,    10,   303,    -1,
     303,    29,   303,    -1,   303,    31,   303,    -1,   303,    30,
     303,    -1,   303,    44,   303,    -1,   303,    42,   303,    -1,
     303,    43,   303,    -1,   303,    45,   303,    -1,   303,    46,
     303,    -1,   303,    47,   303,    -1,   303,    41,   303,    -1,
     303,    40,   303,    -1,    42,   303,    -1,    43,   303,    -1,
      48,   303,    -1,    50,   303,    -1,   303,    33,   303,    -1,
     303,    32,   303,    -1,   303,    35,   303,    -1,   303,    34,
     303,    -1,   303,    36,   303,    -1,   303,    39,   303,    -1,
     303,    37,   303,    -1,   303,    38,   303,    -1,   303,    49,
     288,    -1,   151,   303,   152,    -1,    -1,    -1,   303,    25,
     279,   303,    26,   280,   303,    -1,   338,    -1,    58,   303,
      -1,    57,   303,    -1,    56,   303,    -1,    55,   303,    -1,
      54,   303,    -1,    53,   303,    -1,    52,   303,    -1,    64,
     294,    -1,    -1,    51,   281,   303,    -1,   299,    -1,   123,
     151,   332,   152,    -1,   157,   334,   157,    -1,    12,   303,
      -1,    -1,    71,   151,   283,   252,   152,    -1,    -1,   287,
     139,    71,   151,   284,   252,   152,    -1,    -1,   287,   139,
     317,   151,   285,   252,   152,    -1,    -1,   317,   151,   286,
     252,   152,    -1,    71,    -1,    71,    -1,   289,    -1,    -1,
      -1,   320,   120,   290,   324,   291,   292,    -1,   320,    -1,
     292,   293,    -1,    -1,   120,   324,    -1,    -1,   151,   152,
      -1,   151,   303,   152,    -1,    -1,   151,   252,   152,    -1,
      69,    -1,    70,    -1,    79,    -1,   127,    -1,   128,    -1,
     124,    -1,   125,    -1,   126,    -1,   296,    -1,    71,    -1,
      42,   297,    -1,    43,   297,    -1,   123,   151,   300,   152,
      -1,   298,    -1,    71,   139,    71,    -1,    71,    -1,    72,
      -1,   341,    -1,   296,    -1,   158,   334,   158,    -1,   159,
     334,   159,    -1,   135,   334,   136,    -1,    -1,   302,   301,
      -1,    -1,     8,    -1,   302,     8,   297,   121,   297,    -1,
     302,     8,   297,    -1,   297,   121,   297,    -1,   297,    -1,
     304,    -1,   271,    -1,   309,    -1,    -1,   309,   306,    -1,
      -1,   309,   308,    -1,    -1,    -1,   319,   120,   310,   324,
     311,   315,   312,    -1,   319,    -1,   312,   313,    -1,    -1,
      -1,   120,   324,   314,   315,    -1,    -1,   151,   316,   252,
     152,    -1,    -1,   321,    -1,   328,   321,    -1,   287,   139,
     317,    -1,   320,    -1,   282,    -1,   321,    -1,   328,   321,
      -1,   318,    -1,   321,    61,   323,   160,    -1,   321,   154,
     303,   155,    -1,   322,    -1,    73,    -1,   156,   154,   303,
     155,    -1,    -1,   303,    -1,   326,    -1,    -1,   317,   325,
      -1,   326,    61,   323,   160,    -1,   326,   154,   303,   155,
      -1,   327,    -1,    71,    -1,   154,   303,   155,    -1,   156,
      -1,   328,   156,    -1,   329,     8,   330,    -1,   330,    -1,
     309,    -1,    -1,   122,   151,   331,   329,   152,    -1,    -1,
      -1,   333,   301,    -1,   333,     8,   303,   121,   303,    -1,
     333,     8,   303,    -1,   303,   121,   303,    -1,   303,    -1,
     333,     8,   303,   121,    31,   305,    -1,   333,     8,    31,
     305,    -1,   303,   121,    31,   305,    -1,    31,   305,    -1,
     334,   335,    -1,   334,    71,    -1,   334,    74,    -1,   334,
      78,    -1,   334,    76,    -1,   334,    77,    -1,   334,    61,
      -1,   334,   160,    -1,   334,   154,    -1,   334,   155,    -1,
     334,   120,    -1,    -1,    73,    -1,    -1,    73,    61,   336,
     337,   160,    -1,    73,   120,    71,    -1,   137,   303,   155,
      -1,   137,    72,    61,   303,   160,   155,    -1,   138,   309,
     155,    -1,    71,    -1,    74,    -1,    73,    -1,   113,   151,
     339,   152,    -1,   114,   151,   309,   152,    -1,     7,   303,
      -1,     6,   303,    -1,     5,   151,   303,   152,    -1,     4,
     303,    -1,     3,   303,    -1,   309,    -1,    -1,   339,     8,
     340,   309,    -1,   287,   139,    71,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short int yyrline[] =
{
       0,   158,   158,   162,   162,   163,   168,   169,   170,   171,
     173,   178,   178,   179,   184,   185,   186,   187,   192,   196,
     197,   197,   197,   198,   198,   198,   199,   199,   199,   200,
     200,   200,   204,   206,   208,   201,   210,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   225,   229,   230,   231,   229,
     233,   233,   234,   235,   236,   237,   238,   239,   235,   241,
     246,   247,   251,   252,   257,   257,   257,   262,   263,   267,
     271,   272,   277,   281,   286,   287,   292,   292,   292,   298,
     297,   304,   303,   313,   314,   319,   320,   321,   322,   323,
     324,   325,   326,   331,   333,   338,   339,   340,   341,   342,
     347,   348,   349,   351,   352,   353,   354,   355,   356,   357,
     358,   359,   364,   365,   370,   371,   376,   377,   378,   379,
     384,   385,   391,   392,   397,   400,   401,   402,   403,   408,
     409,   413,   414,   415,   419,   420,   424,   427,   429,   432,
     434,   438,   439,   443,   444,   449,   450,   454,   455,   460,
     461,   466,   467,   472,   473,   478,   479,   480,   481,   486,
     487,   487,   488,   488,   493,   494,   499,   500,   505,   507,
     507,   511,   513,   513,   517,   519,   523,   525,   530,   531,
     536,   537,   538,   539,   540,   541,   542,   543,   548,   549,
     550,   555,   556,   561,   562,   563,   564,   565,   566,   570,
     571,   576,   577,   578,   583,   584,   585,   586,   592,   593,
     598,   598,   599,   600,   606,   607,   611,   612,   616,   617,
     621,   622,   626,   627,   628,   629,   630,   631,   635,   636,
     637,   638,   642,   643,   647,   648,   653,   654,   658,   658,
     659,   663,   663,   664,   665,   666,   666,   667,   667,   668,
     669,   670,   671,   672,   673,   674,   675,   676,   677,   678,
     679,   680,   681,   682,   683,   684,   684,   685,   685,   686,
     686,   687,   687,   688,   689,   690,   691,   692,   693,   694,
     695,   696,   697,   698,   699,   700,   701,   702,   703,   704,
     705,   706,   707,   708,   709,   710,   711,   712,   713,   714,
     715,   714,   717,   718,   719,   720,   721,   722,   723,   724,
     725,   726,   726,   727,   728,   729,   730,   734,   734,   737,
     737,   740,   740,   743,   743,   749,   753,   754,   759,   760,
     759,   762,   767,   768,   773,   777,   778,   779,   784,   785,
     790,   791,   792,   793,   794,   795,   796,   797,   802,   803,
     804,   805,   806,   807,   811,   815,   816,   817,   818,   819,
     820,   821,   826,   827,   830,   832,   836,   837,   838,   839,
     843,   844,   849,   854,   854,   859,   859,   864,   865,   864,
     867,   871,   872,   877,   877,   881,   881,   885,   889,   890,
     894,   899,   900,   905,   906,   907,   911,   912,   913,   918,
     919,   923,   924,   929,   930,   930,   934,   935,   936,   940,
     941,   945,   946,   950,   951,   956,   957,   957,   958,   963,
     964,   968,   969,   970,   971,   972,   973,   974,   975,   979,
     980,   981,   982,   983,   984,   985,   986,   987,   988,   989,
     990,   997,   998,   998,   999,  1000,  1001,  1002,  1007,  1008,
    1009,  1014,  1015,  1016,  1017,  1018,  1019,  1020,  1024,  1025,
    1025,  1029
};
//#endif

//#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_REQUIRE_ONCE", "T_REQUIRE", "T_EVAL",
  "T_INCLUDE_ONCE", "T_INCLUDE", "','", "T_LOGICAL_OR", "T_LOGICAL_XOR",
  "T_LOGICAL_AND", "T_PRINT", "'='", "T_SR_EQUAL", "T_SL_EQUAL",
  "T_XOR_EQUAL", "T_OR_EQUAL", "T_AND_EQUAL", "T_MOD_EQUAL",
  "T_CONCAT_EQUAL", "T_DIV_EQUAL", "T_MUL_EQUAL", "T_MINUS_EQUAL",
  "T_PLUS_EQUAL", "'?'", "':'", "T_BOOLEAN_OR", "T_BOOLEAN_AND", "'|'",
  "'^'", "'&'", "T_IS_NOT_IDENTICAL", "T_IS_IDENTICAL", "T_IS_NOT_EQUAL",
  "T_IS_EQUAL", "'<'", "'>'", "T_IS_GREATER_OR_EQUAL",
  "T_IS_SMALLER_OR_EQUAL", "T_SR", "T_SL", "'+'", "'-'", "'.'", "'*'",
  "'/'", "'%'", "'!'", "T_INSTANCEOF", "'~'", "'@'", "T_UNSET_CAST",
  "T_BOOL_CAST", "T_OBJECT_CAST", "T_ARRAY_CAST", "T_STRING_CAST",
  "T_DOUBLE_CAST", "T_INT_CAST", "T_DEC", "T_INC", "'['", "T_CLONE",
  "T_NEW", "T_EXIT", "T_IF", "T_ELSEIF", "T_ELSE", "T_ENDIF", "T_LNUMBER",
  "T_DNUMBER", "T_STRING", "T_STRING_VARNAME", "T_VARIABLE",
  "T_NUM_STRING", "T_INLINE_HTML", "T_CHARACTER", "T_BAD_CHARACTER",
  "T_ENCAPSED_AND_WHITESPACE", "T_CONSTANT_ENCAPSED_STRING", "T_ECHO",
  "T_DO", "T_WHILE", "T_ENDWHILE", "T_FOR", "T_ENDFOR", "T_FOREACH",
  "T_ENDFOREACH", "T_DECLARE", "T_ENDDECLARE", "T_AS", "T_SWITCH",
  "T_ENDSWITCH", "T_CASE", "T_DEFAULT", "T_BREAK", "T_CONTINUE",
  "T_FUNCTION", "T_CONST", "T_RETURN", "T_TRY", "T_CATCH", "T_THROW",
  "T_USE", "T_GLOBAL", "T_PUBLIC", "T_PROTECTED", "T_PRIVATE", "T_FINAL",
  "T_ABSTRACT", "T_STATIC", "T_VAR", "T_UNSET", "T_ISSET", "T_EMPTY",
  "T_HALT_COMPILER", "T_CLASS", "T_INTERFACE", "T_EXTENDS", "T_IMPLEMENTS",
  "T_OBJECT_OPERATOR", "T_DOUBLE_ARROW", "T_LIST", "T_ARRAY", "T_CLASS_C",
  "T_METHOD_C", "T_FUNC_C", "T_LINE", "T_FILE", "T_COMMENT",
  "T_DOC_COMMENT", "T_OPEN_TAG", "T_OPEN_TAG_WITH_ECHO", "T_CLOSE_TAG",
  "T_WHITESPACE", "T_START_HEREDOC", "T_END_HEREDOC",
  "T_DOLLAR_OPEN_CURLY_BRACES", "T_CURLY_OPEN", "T_PAAMAYIM_NEKUDOTAYIM",
  "T_ASPECT", "T_BEFORE", "T_AROUND", "T_AFTER", "T_POINTCUT", "T_EXEC",
  "T_CALL", "T_SET", "T_GET", "T_THIS", "T_WITHIN", "'('", "')'", "';'",
  "'{'", "'}'", "'$'", "'`'", "'\"'", "'''", "']'", "$accept", "start",
  "top_statement_list", "@1", "top_statement", "inner_statement_list",
  "@2", "inner_statement", "statement", "unticked_statement", "@3", "@4",
  "@5", "@6", "@7", "@8", "@9", "@10", "@11", "@12", "@13", "@14", "@15",
  "@16", "@17", "@18", "@19", "@20", "@21", "@22", "@23", "@24", "@25",
  "@26", "additional_catches", "non_empty_additional_catches",
  "additional_catch", "@27", "@28", "unset_variables", "unset_variable",
  "use_filename", "function_declaration_statement",
  "class_declaration_statement", "is_reference",
  "unticked_function_declaration_statement", "@29", "@30",
  "unticked_class_declaration_statement", "@31", "@32",
  "aspect_statement_list", "aspect_statement", "aspect_advices_variables",
  "aspect_pointcut", "aspect_joinpoint", "aspect_parameters",
  "aspect_call", "aspect_variable_introduction",
  "aspect_constant_introduction", "aspect_class_signature",
  "aspect_signature_r", "aspect_signature", "aspect_subtype_or_not",
  "class_entry_type", "extends_from", "interface_entry",
  "interface_extends_list", "implements_list", "interface_list",
  "foreach_optional_arg", "foreach_variable", "for_statement",
  "foreach_statement", "declare_statement", "declare_list",
  "switch_case_list", "case_list", "@33", "@34", "case_separator",
  "while_statement", "elseif_list", "@35", "new_elseif_list", "@36",
  "else_single", "new_else_single", "parameter_list",
  "non_empty_parameter_list", "optional_class_type",
  "function_call_parameter_list", "non_empty_function_call_parameter_list",
  "global_var_list", "global_var", "static_var_list",
  "class_statement_list", "class_statement", "@37", "method_body",
  "variable_modifiers", "method_modifiers", "non_empty_member_modifiers",
  "member_modifier", "class_variable_declaration",
  "class_constant_declaration", "echo_expr_list", "for_expr",
  "non_empty_for_expr", "@38", "expr_without_variable", "@39", "@40",
  "@41", "@42", "@43", "@44", "@45", "@46", "@47", "@48", "function_call",
  "@49", "@50", "@51", "@52", "fully_qualified_class_name",
  "class_name_reference", "dynamic_class_name_reference", "@53", "@54",
  "dynamic_class_name_variable_properties",
  "dynamic_class_name_variable_property", "exit_expr", "ctor_arguments",
  "common_scalar", "static_scalar", "static_class_constant", "scalar",
  "static_array_pair_list", "possible_comma",
  "non_empty_static_array_pair_list", "expr", "r_variable", "w_variable",
  "@55", "rw_variable", "@56", "variable", "@57", "@58",
  "variable_properties", "variable_property", "@59", "method_or_not",
  "@60", "variable_without_objects", "static_member",
  "base_variable_with_function_calls", "base_variable",
  "reference_variable", "compound_variable", "dim_offset",
  "object_property", "@61", "object_dim_list", "variable_name",
  "simple_indirect_reference", "assignment_list",
  "assignment_list_element", "@62", "array_pair_list",
  "non_empty_array_pair_list", "encaps_list", "encaps_var", "@63",
  "encaps_var_offset", "internal_functions_in_yacc", "isset_variables",
  "@64", "class_constant", 0
};
//#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const unsigned short int yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,    44,   263,
     264,   265,   266,    61,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,    63,    58,   278,   279,   124,
      94,    38,   280,   281,   282,   283,    60,    62,   284,   285,
     286,   287,    43,    45,    46,    42,    47,    37,    33,   288,
     126,    64,   289,   290,   291,   292,   293,   294,   295,   296,
     297,    91,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   331,   332,   333,   334,   335,
     336,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,   364,   365,
     366,   367,   368,   369,   370,   371,   372,   373,   374,   375,
     376,   377,   378,   379,   380,   381,   382,   383,   384,   385,
     386,    40,    41,    59,   123,   125,    36,    96,    34,    39,
      93
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned short int yyr1[] =
{
       0,   161,   162,   164,   163,   163,   165,   165,   165,   165,
     165,   167,   166,   166,   168,   168,   168,   168,   169,   170,
     171,   172,   170,   173,   174,   170,   175,   176,   170,   177,
     178,   170,   179,   180,   181,   170,   182,   170,   170,   170,
     170,   170,   170,   170,   170,   170,   170,   170,   170,   170,
     170,   170,   183,   184,   185,   170,   186,   187,   188,   170,
     189,   170,   170,   190,   191,   192,   193,   194,   170,   170,
     195,   195,   196,   196,   198,   199,   197,   200,   200,   201,
     202,   202,   203,   204,   205,   205,   207,   208,   206,   210,
     209,   211,   209,   212,   212,   213,   213,   213,   213,   213,
     213,   213,   213,   214,   214,   215,   215,   215,   215,   215,
     216,   216,   216,   216,   216,   216,   216,   216,   216,   216,
     216,   216,   217,   217,   218,   218,   219,   219,   219,   219,
     220,   220,   221,   221,   222,   223,   223,   223,   223,   224,
     224,   225,   225,   225,   226,   226,   227,   228,   228,   229,
     229,   230,   230,   231,   231,   232,   232,   233,   233,   234,
     234,   235,   235,   236,   236,   237,   237,   237,   237,   238,
     239,   238,   240,   238,   241,   241,   242,   242,   243,   244,
     243,   245,   246,   245,   247,   247,   248,   248,   249,   249,
     250,   250,   250,   250,   250,   250,   250,   250,   251,   251,
     251,   252,   252,   253,   253,   253,   253,   253,   253,   254,
     254,   255,   255,   255,   256,   256,   256,   256,   257,   257,
     259,   258,   258,   258,   260,   260,   261,   261,   262,   262,
     263,   263,   264,   264,   264,   264,   264,   264,   265,   265,
     265,   265,   266,   266,   267,   267,   268,   268,   270,   269,
     269,   272,   271,   271,   271,   273,   271,   274,   271,   271,
     271,   271,   271,   271,   271,   271,   271,   271,   271,   271,
     271,   271,   271,   271,   271,   275,   271,   276,   271,   277,
     271,   278,   271,   271,   271,   271,   271,   271,   271,   271,
     271,   271,   271,   271,   271,   271,   271,   271,   271,   271,
     271,   271,   271,   271,   271,   271,   271,   271,   271,   279,
     280,   271,   271,   271,   271,   271,   271,   271,   271,   271,
     271,   281,   271,   271,   271,   271,   271,   283,   282,   284,
     282,   285,   282,   286,   282,   287,   288,   288,   290,   291,
     289,   289,   292,   292,   293,   294,   294,   294,   295,   295,
     296,   296,   296,   296,   296,   296,   296,   296,   297,   297,
     297,   297,   297,   297,   298,   299,   299,   299,   299,   299,
     299,   299,   300,   300,   301,   301,   302,   302,   302,   302,
     303,   303,   304,   306,   305,   308,   307,   310,   311,   309,
     309,   312,   312,   314,   313,   316,   315,   315,   317,   317,
     318,   319,   319,   320,   320,   320,   321,   321,   321,   322,
     322,   323,   323,   324,   325,   324,   326,   326,   326,   327,
     327,   328,   328,   329,   329,   330,   331,   330,   330,   332,
     332,   333,   333,   333,   333,   333,   333,   333,   333,   334,
     334,   334,   334,   334,   334,   334,   334,   334,   334,   334,
     334,   335,   336,   335,   335,   335,   335,   335,   337,   337,
     337,   338,   338,   338,   338,   338,   338,   338,   339,   340,
     339,   341
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     1,     0,     3,     0,     1,     1,     1,     4,
       5,     0,     3,     0,     1,     1,     1,     4,     1,     3,
       0,     0,     9,     0,     0,    12,     0,     0,     7,     0,
       0,     9,     0,     0,     0,    12,     0,     6,     2,     3,
       2,     3,     2,     3,     3,     3,     3,     3,     1,     2,
       3,     5,     0,     0,     0,    11,     0,     0,     0,    11,
       0,     6,     1,     0,     0,     0,     0,     0,    18,     3,
       1,     0,     1,     2,     0,     0,    10,     1,     3,     1,
       1,     3,     1,     1,     0,     1,     0,     0,    11,     0,
       8,     0,     7,     2,     0,     1,     3,     2,    10,     5,
       9,     8,     9,     0,     1,     3,     3,     3,     2,     1,
       1,     9,    12,     7,     4,     4,     6,     6,     4,     4,
       4,     2,     1,     1,     1,     1,     5,     7,     3,     5,
       7,     6,     3,     1,     2,     2,     2,     1,     1,     1,
       0,     1,     2,     2,     0,     2,     1,     0,     2,     0,
       2,     1,     3,     0,     2,     1,     2,     1,     4,     1,
       4,     1,     4,     3,     5,     3,     4,     4,     5,     0,
       0,     6,     0,     5,     1,     1,     1,     4,     0,     0,
       7,     0,     0,     8,     0,     2,     0,     3,     1,     0,
       2,     3,     5,     4,     4,     5,     7,     6,     0,     1,
       1,     1,     0,     1,     1,     2,     3,     3,     4,     3,
       1,     1,     2,     4,     3,     5,     1,     3,     2,     0,
       0,     4,     2,     8,     1,     3,     1,     1,     0,     1,
       1,     2,     1,     1,     1,     1,     1,     1,     3,     5,
       1,     3,     5,     4,     3,     1,     0,     1,     0,     4,
       1,     0,     7,     3,     4,     0,     7,     0,     4,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     2,     2,     2,     0,     4,     0,     4,     0,
       4,     0,     4,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     2,     2,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     0,
       0,     7,     1,     2,     2,     2,     2,     2,     2,     2,
       2,     0,     3,     1,     4,     3,     2,     0,     5,     0,
       7,     0,     7,     0,     5,     1,     1,     1,     0,     0,
       6,     1,     2,     0,     2,     0,     2,     3,     0,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     4,     1,     3,     1,     1,     1,     1,     3,
       3,     3,     0,     2,     0,     1,     5,     3,     3,     1,
       1,     1,     1,     0,     2,     0,     2,     0,     0,     7,
       1,     2,     0,     0,     4,     0,     4,     0,     1,     2,
       3,     1,     1,     1,     2,     1,     4,     4,     1,     1,
       4,     0,     1,     1,     0,     2,     4,     4,     1,     1,
       3,     1,     2,     3,     1,     1,     0,     5,     0,     0,
       2,     5,     3,     3,     1,     6,     4,     4,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       0,     1,     0,     5,     3,     3,     6,     3,     1,     1,
       1,     4,     4,     2,     2,     4,     2,     2,     1,     0,
       4,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned short int yydefact[] =
{
       5,     0,     3,     1,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   321,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   345,     0,   350,
     351,   365,   366,   409,    48,   352,     0,    29,     0,     0,
       0,    60,     0,     0,     0,    86,     0,    63,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   141,   146,
       0,     0,   355,   356,   357,   353,   354,   450,     0,     0,
      62,    13,   421,   450,   450,   450,     4,     6,    18,     7,
       8,    82,    83,     0,     0,   381,   402,     0,   368,   323,
       0,   380,     0,   382,     0,   405,   390,   401,   403,   408,
       0,   312,   367,   467,   466,     0,   464,   463,   326,   295,
     296,   297,   298,     0,   319,   318,   317,   316,   315,   314,
     313,   335,     0,   274,   385,   272,   259,   336,     0,   257,
     337,   341,   403,     0,     0,   320,     0,   327,     0,   245,
       0,    26,   246,     0,     0,     0,    38,     0,    40,     0,
      84,    42,   381,     0,   382,     0,     0,    80,     0,     0,
     211,     0,     0,   210,   143,   142,   216,     0,     0,     0,
       0,     0,   251,   429,     0,     0,     0,    11,     0,     0,
       0,     0,   144,    91,     0,   279,     0,   281,   309,   275,
     277,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    49,   273,   271,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   386,   333,   387,   411,
       0,   422,   404,     0,   322,     0,     0,   348,   338,   404,
     346,     0,     0,   202,     0,    47,     0,     0,     0,   247,
     250,   381,   382,     0,     0,    39,    41,    85,     0,    43,
      44,    13,    69,     0,    50,     0,   212,   382,     0,    45,
       0,     0,    46,     0,    77,    79,   468,     0,     0,     0,
     428,     0,   434,     0,   374,   445,   440,   451,   441,   443,
     444,   442,   449,   371,     0,     0,   447,   448,   446,   439,
      94,   308,    19,     0,     0,   325,   369,   370,     0,    89,
     147,   471,   400,   398,     0,     0,   283,     0,     0,     0,
       0,   284,   286,   285,   300,   299,   302,   301,   303,   305,
     306,   304,   294,   293,   288,   289,   287,   290,   291,   292,
     307,     0,   253,   270,   269,   268,   267,   266,   265,   264,
     263,   262,   261,   260,   202,     0,   412,     0,     0,   465,
       0,   400,   202,   258,     0,   347,    20,     0,     0,   201,
     381,   382,   244,     0,     0,    32,   248,     0,     0,     0,
       0,    36,    87,    11,    81,     0,   209,     0,     0,   359,
       0,   358,   217,   363,   214,     0,     0,   469,   461,   462,
       9,     0,   425,     0,   424,   438,   383,     0,   324,   375,
     430,   452,     0,   366,     0,     0,   228,     0,    12,    14,
      15,    16,   410,   335,   145,   149,     0,     0,   329,   331,
     399,   280,   282,     0,   276,   278,     0,   254,     0,   419,
       0,   414,   388,   413,   418,   406,   407,     0,   339,    23,
       0,   205,   328,     0,    30,    27,   246,     0,    57,    53,
       0,     0,     0,     0,     0,     0,   213,   360,   361,     0,
     372,     0,    78,    51,     0,   426,   428,     0,   384,     0,
     433,     0,   432,     0,   454,     0,   455,   457,     0,   232,
     233,   234,   237,   236,   235,   227,     0,     0,     0,     0,
      10,    93,     0,    95,   220,     0,   226,   230,     0,     0,
       0,     0,   148,   151,   219,   202,   202,   310,   255,   334,
       0,   415,   397,   411,     0,   349,   343,    13,    21,     0,
     381,   382,     0,     0,     0,   249,     0,     0,   163,     0,
      13,   161,    61,   169,   169,    37,   198,     0,   364,   379,
       0,   374,   215,   470,   428,   423,     0,   437,   436,     0,
     458,   460,   459,     0,     0,   137,   138,     0,   133,   140,
     103,     0,   103,     0,     0,    97,   138,     0,     0,     0,
      84,   231,     0,   222,     0,   150,   219,     0,   228,     0,
       0,     0,   348,   420,   395,   392,     0,     0,   340,    11,
     178,   208,     0,    13,   176,    28,    33,   153,     0,   153,
     155,     0,    11,   169,     0,   169,     0,   199,   200,     0,
     188,     0,    64,     0,   362,   375,   373,     0,   252,     0,
     431,   453,     0,     0,     0,     0,   139,   135,   136,   134,
     104,     0,     0,     0,     0,     0,     0,    96,     0,   240,
       0,     0,     0,    17,   228,   152,     0,    92,   218,   220,
       0,   330,   332,   311,   256,   202,   389,   416,   417,     0,
     342,   181,   184,     0,    11,   246,     0,     0,   156,     0,
     164,     0,     0,     0,     0,     0,     0,   165,     0,   198,
       0,   190,     0,   378,   377,   427,   435,   456,   243,   132,
       0,     0,     0,     0,     0,     0,     0,   110,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   109,
       0,     0,   128,     0,     0,   221,   138,     0,     0,    90,
       0,    84,     0,     0,   391,   344,   186,     0,     0,    22,
      31,     0,     0,   154,    58,    54,   162,     0,   167,     0,
     174,   175,   172,   166,    13,     0,   191,     0,    65,     0,
       0,     0,     0,     0,   108,   121,     0,     0,     0,     0,
     228,     0,     0,     0,     0,     0,     0,     0,     0,    99,
       0,     0,     0,   241,   238,   198,     0,   242,     0,   396,
     393,     0,     0,     0,     0,   185,   177,    34,     0,     0,
     168,   170,    13,    11,     0,   194,     0,   193,     0,   376,
     131,     0,    13,     0,     0,     0,     0,     0,    84,   229,
       0,     0,     0,     0,     0,   107,   105,   106,     0,   126,
     129,     0,     0,     0,     0,   397,     0,    13,     0,     0,
       0,    13,   159,    59,    55,    13,    11,    88,   195,     0,
     192,     0,    13,    11,    13,     0,   114,   115,   120,     0,
     124,   125,     0,     0,     0,   118,   119,   130,     0,   239,
       0,   198,   394,     0,    11,    25,   179,    13,   157,    35,
      11,    11,     0,   197,    66,    11,   101,    11,   123,   122,
       0,     0,     0,     0,     0,   127,   224,    13,   223,     0,
       0,     0,    11,     0,   196,     0,   100,   102,     0,     0,
       0,   116,   117,    11,     0,   182,   180,     0,   160,    13,
     113,   140,     0,   225,    98,    13,   158,    11,     0,     0,
      11,    67,     0,   111,    71,     0,     0,    68,    70,    72,
       0,     0,    73,   112,    74,     0,     0,    75,     0,    13,
      11,    76
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short int yydefgoto[] =
{
      -1,     1,     2,     4,    76,   177,   303,   418,   842,    78,
     450,   600,   527,   671,   247,   533,   140,   532,   456,   675,
     840,   463,   378,   537,   799,   377,   536,   798,   144,   155,
     692,   808,   905,   934,   937,   938,   939,   945,   948,   640,
     274,   159,    79,    80,   258,    81,   150,   464,    82,   425,
     310,   416,   501,   641,   718,   719,   890,   862,   577,   502,
     567,   568,   569,   639,    83,   309,    84,   427,   511,   512,
     677,   609,   879,   843,   542,   380,   545,   614,   845,   802,
     752,   605,   672,   901,   736,   925,   739,   793,   619,   620,
     621,   368,   369,   162,   163,   167,   588,   658,   579,   898,
     659,   660,   506,   507,   650,   508,   138,   248,   249,   457,
      85,   280,   592,   237,   319,   320,   315,   317,   318,   591,
     113,    86,   243,   515,   516,   354,    87,   129,   130,   364,
     526,   598,   670,   135,   363,    88,   392,   393,    89,   550,
     410,   551,    90,    91,   405,   478,    92,   226,    93,   355,
     522,   666,   734,   835,   595,   665,    94,    95,    96,    97,
      98,    99,   357,   442,   521,   443,   444,   100,   403,   404,
     554,   283,   284,   174,   299,   483,   563,   101,   277,   474,
     102
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -819
static const short int yypact[] =
{
    -819,    61,   104,  -819,   869,  3186,  3186,   -36,  3186,  3186,
    3186,  3186,  3186,  3186,  3186,  -819,  3186,  3186,  3186,  3186,
    3186,  3186,  3186,   227,   227,  3186,   228,    -7,   117,  -819,
    -819,   175,  -819,  -819,  -819,  -819,  3186,  -819,   173,   182,
     184,  -819,   192,  1751,  1877,  -819,  2003,  -819,  3186,   -15,
      -5,    53,   237,   292,   229,   265,   271,   276,  -819,  -819,
     278,   286,  -819,  -819,  -819,  -819,  -819,  -819,   367,  3186,
    -819,  -819,   287,  -819,  -819,  -819,  -819,  -819,  -819,  -819,
    -819,  -819,  -819,   369,   377,  -819,  -819,   310,  -819,  -819,
    3116,  -819,    31,  2216,   301,  -819,   334,  -819,   -12,  -819,
     231,  -819,  -819,  4090,  4090,  3186,  4090,  4090,  4153,   372,
     372,   406,  -819,  3186,  -819,  -819,  -819,  -819,  -819,  -819,
    -819,   312,   322,  -819,  -819,  -819,  -819,   344,   373,  -819,
    -819,   353,   198,   231,  2129,  -819,  3186,  -819,     5,  4090,
    1625,  -819,  3186,  3186,   364,  3186,  -819,  3243,  -819,  3447,
     489,  -819,   375,  4090,   730,   376,  3488,  -819,   442,   379,
    -819,   194,    10,  -819,  -819,  -819,   523,    13,   227,   227,
     227,   387,  -819,  2262,   513,   390,  3529,   386,  3186,   644,
     732,  3896,   427,  -819,   238,  -819,  3186,  -819,  -819,  -819,
    -819,  3186,  3186,  3186,  3186,  3186,  3186,  3186,  3186,  3186,
    3186,  3186,  3186,  3186,  3186,  3186,  3186,  3186,  3186,  3186,
     228,  -819,  -819,  -819,  2395,  3186,  3186,  3186,  3186,  3186,
    3186,  3186,  3186,  3186,  3186,  3186,  -819,  -819,  -819,  3186,
    3186,   287,   225,  3574,  -819,   239,   242,   395,  -819,   198,
    -819,  3615,  3657,  2528,  3186,  -819,   466,  3186,   397,   547,
    4090,   469,  2202,   485,  3700,  -819,  -819,  -819,   490,  -819,
    -819,  -819,  -819,   408,  -819,  3186,  -819,  -819,    -5,  -819,
     354,   492,  -819,     8,  -819,  -819,  -819,    43,   421,   423,
     203,   227,  3909,   425,   571,  -819,  -819,    11,  -819,  -819,
    -819,  -819,  -819,  -819,  3312,   227,  -819,  -819,  -819,  -819,
    -819,  -819,  -819,   995,  2059,  -819,  -819,  -819,   509,  -819,
     463,   431,   432,   198,   231,  3186,  3375,  3186,  3186,  3186,
    3186,  4239,  4258,  4276,  4294,  4294,  4294,  4294,  1602,  1602,
    1602,  1602,   772,   772,   372,   372,   372,   406,   406,   406,
    -819,   219,  4153,  4153,  4153,  4153,  4153,  4153,  4153,  4153,
    4153,  4153,  4153,  4153,  2528,   210,  4090,   433,  2318,  -819,
     431,  -819,  2528,  -819,   210,  -819,   568,   227,   443,   589,
      44,   478,  4090,   447,  3741,  -819,  -819,   510,   512,   591,
      46,  -819,  -819,   453,  -819,  2451,  -819,   354,   354,   468,
     460,  -819,  -819,  -819,   599,   227,   470,  -819,  -819,  -819,
    -819,   462,  -819,    48,  -819,  -819,  -819,  2661,  -819,  2794,
    -819,  -819,   553,   565,  2584,   472,   -25,   480,  -819,  -819,
    -819,  -819,  -819,  -819,  -819,   515,   509,   475,  -819,  -819,
     198,  4130,  4153,  4049,  4198,  4219,   228,  -819,   483,  -819,
    3186,  -819,  -819,   232,  -819,  -819,  -819,   488,  -819,  -819,
    1625,  -819,  -819,  2927,  -819,  -819,  3186,  3186,  -819,  -819,
     354,   561,  1121,   -11,   491,   543,  -819,  -819,  -819,   574,
     354,   354,  -819,  -819,   227,  -819,   203,   633,  -819,   227,
    4090,   227,  3952,   333,  -819,  3186,  -819,  -819,    34,  -819,
    -819,  -819,  -819,  -819,  -819,  -819,   503,   504,   505,   588,
    -819,  -819,    35,  -819,    55,   564,   461,  -819,    37,   519,
     509,   508,   656,  -819,  -819,  2528,  2528,  -819,  -819,  -819,
    2717,  -819,   528,  3186,  3186,  -819,  -819,  -819,  -819,   227,
      49,  1957,  3186,  1247,   527,  4090,   227,    16,  -819,   668,
    -819,  -819,  -819,   529,   530,  -819,   204,   534,  -819,   566,
     538,   684,  -819,  -819,   203,  -819,  3186,  -819,  -819,  3060,
    -819,  -819,  -819,   533,  1807,  -819,   682,     2,  -819,   343,
     227,   544,   227,   671,    55,  -819,  -819,    38,    18,   628,
     489,  -819,   631,  -819,   551,   656,  -819,   509,     1,   554,
     555,  3186,   395,  -819,  -819,  -819,   548,  2850,   590,   368,
    -819,  -819,  3783,  -819,  -819,  -819,  -819,   592,   227,   592,
    -819,   354,   620,  -819,   396,  -819,     4,  -819,  -819,   560,
     706,    62,  -819,   354,  -819,   354,  -819,    50,  4153,   227,
    4090,  -819,   569,   354,    55,   648,  -819,  -819,  -819,  -819,
     715,   573,   700,   576,   319,    42,    55,  -819,   657,   718,
      40,    77,   720,  -819,   511,  -819,   665,  -819,  -819,  -819,
     642,  -819,  -819,  4176,  -819,  2528,   621,  -819,  -819,   210,
    -819,  -819,   222,   587,   672,  3186,    16,   604,  -819,   606,
    -819,   608,   417,   609,  3186,   111,   284,  -819,   605,    -2,
     690,   752,   509,  -819,   645,  -819,  -819,  -819,  -819,  -819,
     754,   742,   319,   743,   319,    55,   624,  -819,   625,   626,
     629,   641,   643,   649,   651,   661,   673,   319,   101,  -819,
     701,    68,   766,   354,   722,  -819,   674,    70,   354,  -819,
     682,   489,   655,   210,  -819,  -819,   230,   675,  1625,  -819,
    -819,   669,   676,  -819,  -819,  -819,  -819,   670,  -819,  2983,
    -819,  -819,  -819,  -819,  -819,   248,   816,   354,  -819,   354,
     354,   319,   106,   319,  -819,  -819,    55,    55,    55,   751,
     678,    55,    55,    55,    55,    55,    32,   319,   319,  -819,
     818,   759,   354,  -819,   820,   204,   763,  -819,   764,  -819,
    -819,   685,   811,   771,  3186,  -819,  -819,  -819,  1373,  1373,
    -819,  -819,  -819,   686,   770,   831,   354,  -819,   773,  -819,
    -819,   140,  -819,   148,   696,    94,    95,   697,   489,   678,
     -19,   235,   235,   698,   699,  -819,   825,  -819,   354,   835,
    -819,   354,   702,   705,   674,   528,  3186,  -819,   704,  3826,
    1499,  -819,  -819,  -819,  -819,  -819,   316,  -819,   845,   354,
    -819,   707,  -819,   709,  -819,    26,  -819,  -819,  -819,    55,
    -819,  -819,    55,    55,    55,  -819,  -819,  -819,   354,  -819,
     187,   204,  -819,  3867,   792,  -819,  -819,  -819,  -819,  -819,
     774,   352,   354,  -819,  -819,   710,  -819,   711,  -819,  -819,
     716,   224,   206,    25,   216,  -819,  -819,  -819,  -819,   719,
     836,  1625,   782,   724,  -819,   725,  -819,  -819,   726,    55,
      26,  -819,  -819,   729,   187,  -819,  -819,   727,  -819,  -819,
    -819,   343,   733,  -819,  -819,  -819,  -819,   734,   737,   739,
     451,  -819,    26,  -819,   793,   741,   744,  -819,   793,  -819,
     745,   509,  -819,  -819,  -819,   826,   746,  -819,   748,  -819,
     749,  -819
};

/* YYPGOTO[NTERM-NUM].  */
static const short int yypgoto[] =
{
    -819,  -819,  -819,  -819,  -819,  -249,  -819,  -819,     0,  -819,
    -819,  -819,  -819,  -819,  -819,  -819,  -819,  -819,  -819,  -819,
    -819,  -819,  -819,  -819,  -819,  -819,  -819,  -819,  -819,  -819,
    -819,  -819,  -819,  -819,  -819,  -819,   -38,  -819,  -819,   735,
     514,  -819,   602,   603,  -566,  -819,  -819,  -819,  -819,  -819,
    -819,  -819,  -819,   335,  -103,  -819,  -818,  -493,  -819,  -819,
    -497,  -592,  -517,   -13,  -819,  -819,  -819,  -819,  -819,   400,
     304,   240,  -819,   115,  -819,  -819,  -819,  -222,  -819,  -819,
     166,  -819,  -819,  -819,  -819,  -819,  -819,  -819,  -719,  -819,
     241,  -345,  -819,  -819,   667,  -819,   350,   521,  -819,    29,
     531,  -408,   176,  -500,  -819,  -819,  -819,  -422,  -819,  -819,
       7,  -819,  -819,  -819,  -819,  -819,  -819,  -819,  -819,  -819,
    -819,  -819,  -819,  -819,  -819,  -819,   -23,  -191,  -819,  -819,
    -819,  -819,  -819,  -819,   360,   -71,    14,  -819,  -819,  -819,
     394,  -819,    19,   795,  -356,  -819,   388,  -819,   162,  -819,
    -819,  -819,  -819,  -819,   119,  -819,  -161,  -819,  -819,   -21,
      -6,  -819,   435,  -362,  -819,  -819,  -819,    -4,   405,   486,
    -819,  -819,  -819,   452,  -819,  -819,  -819,  -819,  -819,  -819,
    -819
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -400
static const short int yytable[] =
{
     122,   122,   448,   128,    77,   131,   581,   578,   505,   438,
     634,   451,   383,   244,   651,   543,   395,   447,   268,   340,
     132,   271,   133,   312,   103,   104,   634,   106,   107,   108,
     109,   110,   111,   112,   534,   114,   115,   116,   117,   118,
     119,   120,   699,   574,   126,   582,   646,   608,   724,   229,
     634,   397,  -203,   152,   461,   139,   476,  -206,   476,   777,
     778,     3,   147,   149,   157,   153,   832,   156,   160,   617,
     637,   888,   411,   488,   312,   361,   634,   645,   634,   565,
     489,   490,   491,   492,   493,   494,   495,   121,   176,    33,
     212,   213,   922,   690,   232,   889,   638,   684,   685,   656,
     565,   860,   634,   634,    -2,   566,   489,   490,   491,   492,
     493,   494,   495,   765,   935,   105,   496,   497,   498,   499,
     861,   618,   565,   557,   233,   558,   576,   239,   777,   778,
     500,   412,   234,   777,   778,   691,   158,   750,   122,  -398,
     246,   635,   230,   544,   134,   122,   122,   122,   726,   721,
     251,   161,   899,   241,   727,   242,   657,   648,   245,   687,
     396,   250,   153,   269,   254,   788,   272,   777,   778,   164,
     589,   590,    72,   601,   814,   777,   778,   911,   313,   820,
     314,   720,   823,   824,   825,   124,   124,   128,   575,   131,
     583,   647,   282,   725,   441,   398,  -203,   304,   462,   391,
     477,  -206,   695,   441,   132,   316,   133,   781,   154,   786,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
     331,   332,   333,   334,   335,   336,   337,   338,   339,   313,
     313,   314,   314,   342,   343,   344,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   518,   856,   857,   356,   358,
     370,   637,   859,   742,   779,   821,   822,   122,   122,   229,
     812,   637,   153,   372,   751,   121,   374,    33,   136,   637,
     815,   816,   122,   696,   121,   617,    33,   638,   599,   804,
     637,   439,   436,    33,   385,   424,   229,   638,   737,   738,
     121,   612,    33,   523,   852,   638,   791,   792,   121,   127,
      33,    33,   854,   419,    33,   252,   638,   735,   430,   311,
     360,    33,    33,   414,  -335,    33,   391,   391,   122,   581,
     732,   805,   616,   267,   141,   401,   137,   618,   863,   864,
     275,   276,   278,   142,   431,   143,   432,   433,   434,   435,
     896,   897,   891,   145,   122,   892,   893,   894,   265,   313,
      72,   314,   230,   165,   674,   860,  -189,   910,   313,    72,
     314,   370,   818,   909,   440,   166,    72,   704,   912,   370,
     705,   790,   122,   153,   861,    72,  -399,   684,   685,   230,
     168,   153,   706,    72,    72,   636,   524,   231,   637,   391,
     707,   682,   921,   686,    72,    72,   387,   388,    72,   391,
     391,   467,   468,   513,   560,   371,   561,   562,  -173,  -173,
    -173,   123,   125,   128,   638,   131,   169,   207,   208,   209,
     708,   210,   170,    29,    30,   389,   480,   171,   482,   172,
     132,   709,   133,    35,   -24,   -24,   -24,   173,   175,   753,
     182,   178,   402,   406,  -171,  -171,  -171,   710,   183,   184,
     528,   122,   227,   122,   228,   210,   122,   415,   122,   520,
     530,   235,   541,   137,   711,   712,   713,   714,   715,   716,
     717,  -173,   153,   238,   538,   250,   535,   390,    62,    63,
      64,    65,    66,  -335,   549,   552,  -204,   513,   683,   684,
     685,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   437,   564,   803,   122,  -171,   441,   747,
     684,   685,   236,   122,   122,   253,   371,  -183,  -183,  -183,
     257,   263,   370,   370,   371,   179,   180,   181,   259,   406,
     261,   122,   264,   604,   153,   153,   270,  -385,  -385,   279,
     391,   302,   356,   597,   300,   308,   362,   122,   373,   122,
     375,   602,   391,   846,   391,   376,   379,   275,  -229,   -56,
     384,   382,   391,   853,   655,   394,   489,   490,   491,   492,
     493,   494,   441,   399,   285,   628,   400,   408,   630,   409,
     423,   426,   428,   429,   286,   122,   287,   288,   874,   289,
     290,   291,   880,   445,   449,   452,   881,   453,   454,   762,
     458,   764,   459,   885,   460,   887,   122,   469,   465,   656,
     663,   470,   471,   475,   776,   531,   489,   490,   491,   492,
     493,   494,   495,   473,   484,   680,   485,   487,   902,   514,
    -204,   509,   539,   292,   510,   519,   553,   693,   402,   694,
     525,   406,   546,   406,   547,   548,   556,   698,   913,   293,
     294,   295,   391,   122,   570,   571,   572,   391,   811,   573,
     813,   580,   586,   313,   587,   314,   729,   296,   297,   758,
     927,   584,   370,   298,   826,   827,   930,   371,   371,   594,
     606,   611,   613,   615,   153,   622,   391,   623,   391,   391,
     624,   406,   625,   631,   250,   633,   642,   644,   607,   610,
     950,   649,   652,   749,   653,   285,   661,   662,   667,   681,
     669,   391,   688,   676,   689,   286,   402,   287,   288,   700,
     289,   290,   291,   395,   697,   701,   702,   313,   703,   314,
     722,   723,   275,   728,   275,   391,   730,   783,   795,   731,
     740,   733,   787,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   741,   744,   391,   745,   754,
     391,   746,   748,   756,   292,   757,   759,   760,   761,   763,
     678,   807,   780,   809,   810,   766,   767,   768,   391,   782,
     769,   294,   295,   489,   490,   491,   492,   493,   494,  -385,
    -385,   406,   770,   285,   771,   784,   830,   391,   296,   297,
     772,   305,   773,   286,   298,   287,   288,   789,   289,   290,
     291,   391,   774,   839,   204,   205,   206,   207,   208,   209,
     850,   210,   796,   800,   775,   785,   794,   371,   797,   806,
     817,   828,   829,   831,   833,   834,   836,   837,   610,   838,
     878,   847,   867,   848,   849,   869,   851,   855,   868,   858,
     865,   866,   292,   778,   870,   873,   871,   875,   882,   884,
    -187,   903,   915,   883,   886,   906,   907,   917,   908,   294,
     295,   914,     5,     6,     7,     8,     9,   918,   920,   919,
     926,    10,   895,   260,   923,   929,   296,   297,   932,   931,
     306,   933,   298,   940,   936,   941,   904,   943,   947,   946,
     942,   916,   949,   273,   951,   420,   421,   643,   928,   472,
     585,    11,    12,   679,   844,   801,   743,    13,   944,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
     755,    25,    26,    27,    28,   386,   654,   503,    29,    30,
      31,    32,    33,   924,    34,   626,   819,   504,    35,    36,
      37,    38,   664,    39,   872,    40,   266,    41,   596,   627,
      42,     0,   555,     0,    43,    44,    45,     0,    46,    47,
       0,    48,    49,    50,     0,     0,     0,    51,    52,    53,
       0,    54,    55,    56,    57,    58,    59,     0,     0,     0,
       0,    60,    61,    62,    63,    64,    65,    66,     5,     6,
       7,     8,     9,     0,    67,     0,     0,    10,     0,    68,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      69,     0,    70,    71,     0,    72,    73,    74,    75,     0,
       0,     0,     0,     0,     0,     0,     0,    11,    12,     0,
       0,     0,     0,    13,     0,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,     0,    25,    26,    27,
      28,     0,     0,     0,    29,    30,    31,    32,    33,     0,
      34,     0,     0,     0,    35,    36,    37,    38,     0,    39,
       0,    40,     0,    41,     0,     0,    42,     0,     0,     0,
      43,    44,    45,     0,    46,    47,     0,    48,    49,    50,
       0,     0,     0,    51,    52,    53,     0,    54,    55,    56,
     417,    58,    59,     0,     0,     0,     0,    60,    61,    62,
      63,    64,    65,    66,     5,     6,     7,     8,     9,     0,
      67,     0,     0,    10,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    69,   540,    70,    71,
       0,    72,    73,    74,    75,     0,     0,     0,     0,     0,
       0,     0,     0,    11,    12,     0,     0,     0,     0,    13,
       0,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,     0,    25,    26,    27,    28,     0,     0,     0,
      29,    30,    31,    32,    33,     0,    34,     0,     0,     0,
      35,    36,    37,    38,     0,    39,     0,    40,     0,    41,
       0,     0,    42,     0,     0,     0,    43,    44,     0,     0,
      46,    47,     0,    48,    49,    50,     0,     0,     0,     0,
       0,    53,     0,    54,    55,    56,     0,     0,     0,     0,
       0,     0,     0,    60,    61,    62,    63,    64,    65,    66,
       5,     6,     7,     8,     9,     0,    67,     0,     0,    10,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    69,   603,    70,    71,     0,    72,    73,    74,
      75,     0,     0,     0,     0,     0,     0,     0,     0,    11,
      12,     0,     0,     0,     0,    13,     0,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,     0,    25,
      26,    27,    28,     0,     0,     0,    29,    30,    31,    32,
      33,     0,    34,     0,     0,     0,    35,    36,    37,    38,
       0,    39,     0,    40,     0,    41,     0,     0,    42,     0,
       0,     0,    43,    44,     0,     0,    46,    47,     0,    48,
      49,    50,     0,     0,     0,     0,     0,    53,     0,    54,
      55,    56,     0,     0,     0,     0,     0,     0,     0,    60,
      61,    62,    63,    64,    65,    66,     5,     6,     7,     8,
       9,     0,    67,     0,     0,    10,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    69,   841,
      70,    71,     0,    72,    73,    74,    75,     0,     0,     0,
       0,     0,     0,     0,     0,    11,    12,     0,     0,     0,
       0,    13,     0,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,     0,    25,    26,    27,    28,     0,
       0,     0,    29,    30,    31,    32,    33,     0,    34,     0,
       0,     0,    35,    36,    37,    38,     0,    39,     0,    40,
       0,    41,     0,     0,    42,     0,     0,     0,    43,    44,
       0,     0,    46,    47,     0,    48,    49,    50,     0,     0,
       0,     0,     0,    53,     0,    54,    55,    56,     0,     0,
       0,     0,     0,     0,     0,    60,    61,    62,    63,    64,
      65,    66,     5,     6,     7,     8,     9,     0,    67,     0,
       0,    10,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    69,   877,    70,    71,     0,    72,
      73,    74,    75,     0,     0,     0,     0,     0,     0,     0,
       0,    11,    12,     0,     0,     0,     0,    13,     0,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
       0,    25,    26,    27,    28,     0,     0,     0,    29,    30,
      31,    32,    33,     0,    34,     0,     0,     0,    35,    36,
      37,    38,     0,    39,     0,    40,     0,    41,     0,     0,
      42,     0,     0,     0,    43,    44,     0,     0,    46,    47,
       0,    48,    49,    50,     0,     0,     0,     0,     0,    53,
       0,    54,    55,    56,     0,     0,     0,     0,     0,     0,
       0,    60,    61,    62,    63,    64,    65,    66,     5,     6,
       7,     8,     9,     0,    67,     0,     0,    10,  -400,  -400,
    -400,  -400,   202,   203,   204,   205,   206,   207,   208,   209,
      69,   210,    70,    71,     0,    72,    73,    74,    75,     0,
       0,     0,     0,     0,     0,     0,     0,    11,    12,     0,
       0,     0,     0,    13,     0,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,     0,    25,    26,    27,
      28,     0,     0,     0,    29,    30,    31,    32,    33,     0,
      34,     0,     0,     0,    35,    36,    37,    38,     0,    39,
       0,    40,     0,    41,     0,     0,    42,     0,     0,     0,
      43,    44,     0,     0,    46,    47,     0,    48,    49,    50,
       0,     0,     0,     0,     0,    53,     0,    54,    55,    56,
       0,     0,     0,     0,     0,     0,     0,    60,    61,    62,
      63,    64,    65,    66,     5,     6,     7,     8,     9,     0,
      67,     0,     0,    10,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    69,     0,    70,    71,
       0,    72,    73,    74,    75,     0,     0,     0,     0,     0,
       0,     0,     0,    11,    12,     0,     0,     0,     0,    13,
       0,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,     0,    25,    26,    27,   185,   186,   187,     0,
      29,    30,    31,    32,    33,     0,     0,     0,     0,     0,
      35,     0,   188,     0,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,     0,   210,     0,     0,     0,
       0,     0,     0,     0,    55,    56,     0,     0,     0,     0,
       0,     0,     0,    60,    61,    62,    63,    64,    65,    66,
       5,     6,     7,     8,     9,     0,    67,     0,     0,    10,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    69,     0,   146,     0,     0,    72,    73,    74,
      75,     0,     0,     0,     0,     0,     0,     0,     0,    11,
      12,     0,     0,     0,     0,    13,     0,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,     0,    25,
      26,    27,     0,     0,     0,     0,    29,    30,    31,    32,
      33,     0,     0,     0,     0,     0,    35,     0,     0,     0,
       0,     0,     0,     0,     0,  -207,     0,   632,     0,     0,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,     0,     0,     0,     0,     0,     0,     0,     0,
      55,    56,     0,     0,     0,     0,     0,     0,     0,    60,
      61,    62,    63,    64,    65,    66,     5,     6,     7,     8,
       9,     0,    67,     0,     0,    10,  -385,  -385,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    69,     0,
     148,     0,     0,    72,    73,    74,    75,     0,     0,     0,
       0,     0,     0,     0,     0,    11,    12,     0,     0,     0,
       0,    13,     0,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,     0,    25,    26,    27,   185,   186,
     187,     0,    29,    30,    31,    32,    33,     0,     0,     0,
       0,     0,    35,     0,   188,     0,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,     0,   210,  -207,
       0,     0,     0,     0,     0,     0,    55,    56,     0,     0,
       0,     0,     0,     0,     0,    60,    61,    62,    63,    64,
      65,    66,     5,     6,     7,     8,     9,     0,    67,     0,
       0,    10,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    69,     0,   151,     0,     0,    72,
      73,    74,    75,     0,     0,     0,     0,     0,     0,     0,
       0,    11,    12,     0,     0,     0,     0,    13,     0,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
       0,    25,    26,    27,     0,     0,     0,     0,    29,    30,
      31,    32,    33,     0,     0,     0,     0,     0,    35,     0,
       0,     0,     0,     0,   422,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,     0,     0,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,     0,    55,    56,     0,     0,     0,     0,     0,     0,
       0,    60,    61,    62,    63,    64,    65,    66,     0,     0,
       0,  -385,  -385,     0,    67,     5,     6,     7,     8,     9,
       0,     0,     0,     0,    10,  -385,  -385,     0,     0,     0,
      69,   240,     0,     0,     0,    72,    73,    74,    75,     0,
       0,     0,   -52,   281,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    11,    12,     0,     0,     0,     0,
      13,     0,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,     0,    25,    26,    27,   185,   186,   187,
       0,    29,    30,    31,    32,    33,     0,     0,     0,     0,
       0,    35,     0,   188,     0,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,     0,   210,     0,     0,
       0,     0,     0,     0,     0,    55,    56,     0,     0,     0,
       0,     0,     0,     0,    60,    61,    62,    63,    64,    65,
      66,     0,     0,     0,     0,     0,     0,    67,     5,     6,
       7,     8,     9,     0,     0,     0,     0,    10,     0,     0,
       0,     0,     0,    69,     0,     0,     0,     0,    72,    73,
      74,    75,     0,     0,     0,     0,   341,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    11,    12,     0,
       0,     0,     0,    13,     0,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,     0,    25,    26,    27,
     185,   186,   187,     0,    29,    30,    31,    32,    33,     0,
       0,     0,     0,   446,    35,     0,   188,     0,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,     0,
     210,     0,     0,     0,     0,     0,     0,     0,    55,    56,
       0,     0,     0,     0,     0,     0,     0,    60,    61,    62,
      63,    64,    65,    66,     0,     0,     0,     0,     0,     0,
      67,     5,     6,     7,     8,     9,     0,     0,     0,     0,
      10,     0,     0,     0,     0,     0,    69,     0,     0,     0,
       0,    72,    73,    74,    75,     0,     0,     0,     0,   367,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      11,    12,     0,     0,     0,     0,    13,     0,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,     0,
      25,    26,    27,   185,   186,   187,     0,    29,    30,    31,
      32,    33,     0,     0,     0,     0,   466,    35,     0,   188,
       0,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,     0,   210,     0,     0,     0,     0,     0,     0,
       0,    55,    56,     0,     0,     0,     0,     0,     0,     0,
      60,    61,    62,    63,    64,    65,    66,     0,     0,     0,
       0,     0,     0,    67,     5,     6,     7,     8,     9,     0,
       0,     0,     0,    10,     0,     0,     0,     0,     0,    69,
       0,     0,     0,     0,    72,    73,    74,    75,     0,     0,
       0,     0,   479,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    11,    12,     0,     0,     0,     0,    13,
       0,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,     0,    25,    26,    27,   185,   186,   187,     0,
      29,    30,    31,    32,    33,     0,     0,     0,     0,   486,
      35,     0,   188,     0,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,     0,   210,     0,     0,     0,
       0,     0,     0,     0,    55,    56,     0,     0,     0,     0,
       0,     0,     0,    60,    61,    62,    63,    64,    65,    66,
       0,     0,     0,     0,     0,     0,    67,     5,     6,     7,
       8,     9,     0,     0,     0,     0,    10,     0,     0,     0,
       0,     0,    69,     0,     0,     0,     0,    72,    73,    74,
      75,     0,     0,     0,     0,   481,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    11,    12,     0,     0,
       0,     0,    13,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,     0,    25,    26,    27,   185,
     186,   187,     0,    29,    30,    31,    32,    33,     0,     0,
       0,     0,   593,    35,     0,   188,     0,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,     0,   210,
       0,     0,     0,     0,     0,     0,     0,    55,    56,     0,
       0,     0,     0,     0,     0,     0,    60,    61,    62,    63,
      64,    65,    66,     0,     0,     0,     0,     0,     0,    67,
       5,     6,     7,     8,     9,     0,     0,     0,     0,    10,
       0,     0,     0,     0,     0,    69,     0,     0,     0,     0,
      72,    73,    74,    75,     0,     0,     0,     0,   529,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    11,
      12,     0,     0,     0,     0,    13,     0,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,     0,    25,
      26,    27,   185,   186,   187,     0,    29,    30,    31,    32,
      33,     0,     0,     0,     0,   668,    35,     0,   188,   750,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,     0,   210,     0,     0,     0,     0,     0,     0,     0,
      55,    56,     0,     0,     0,     0,     0,     0,     0,    60,
      61,    62,    63,    64,    65,    66,     0,     0,     0,     0,
       0,     0,    67,     5,     6,     7,     8,     9,     0,     0,
       0,     0,    10,     0,     0,     0,     0,     0,    69,     0,
       0,     0,     0,    72,    73,    74,    75,     0,     0,     0,
       0,   629,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    11,    12,     0,     0,     0,     0,    13,     0,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,     0,    25,    26,    27,   185,   186,   187,     0,    29,
      30,    31,    32,    33,     0,     0,   751,     0,     0,    35,
       0,   188,     0,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,     0,   210,     0,     0,     0,     0,
       0,     0,     0,    55,    56,     0,     0,     0,     0,     0,
       0,     0,    60,    61,    62,    63,    64,    65,    66,     5,
       6,     7,     8,     9,     0,    67,     0,     0,    10,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    69,     0,     0,     0,     0,    72,    73,    74,    75,
       0,     0,     0,     0,     0,     0,     0,     0,    11,    12,
       0,     0,     0,     0,    13,     0,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,     0,    25,    26,
      27,     0,   185,   186,   187,    29,    30,    31,    32,    33,
       0,     0,     0,     0,     0,    35,     0,     0,   188,   211,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,     0,   210,     0,     0,     0,     0,     0,     0,    55,
      56,     0,     0,     0,     0,     0,     0,     0,    60,    61,
      62,    63,    64,    65,    66,     5,     6,     7,     8,     9,
       0,    67,     0,     0,    10,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    69,     0,     0,
       0,     0,    72,    73,    74,    75,     0,     0,     0,     0,
       0,     0,     0,     0,    11,    12,     0,     0,     0,     0,
      13,     0,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,     0,    25,    26,    27,     0,     0,     0,
       0,    29,    30,    31,   413,    33,   187,     0,     0,     0,
       0,    35,     0,     0,     0,     0,   255,     0,     0,     0,
     188,     0,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,     0,   210,    55,    56,     0,     0,     0,
       0,     0,     0,     0,    60,    61,    62,    63,    64,    65,
      66,     0,     0,     0,     0,     0,     0,    67,     0,     0,
       0,     0,     0,     0,     0,     0,   185,   186,   187,     0,
       0,     0,     0,    69,     0,     0,     0,     0,    72,    73,
      74,    75,   188,     0,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,     0,   210,   185,   186,   187,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   188,     0,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,     0,   210,   185,   186,
     187,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   188,     0,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,     0,   210,     0,
       0,     0,     0,   185,   186,   187,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   188,
     256,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,     0,   210,   185,   186,   187,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     188,   262,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,     0,   210,     0,   185,   186,   187,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   301,   188,     0,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,     0,   210,     0,     0,   185,
     186,   187,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   188,   359,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,     0,   210,
     185,   186,   187,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   188,   365,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,     0,
     210,     0,   185,   186,   187,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   188,   366,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,     0,   210,     0,     0,   185,   186,   187,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   188,   381,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,     0,   210,   185,   186,   187,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   188,   455,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,     0,   210,     0,   185,   186,
     187,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   188,   673,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   285,   210,     0,
       0,   185,   186,   187,     0,     0,     0,   286,     0,   287,
     288,     0,   289,   290,   291,     0,     0,   188,   876,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
       0,   210,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   292,     0,     0,   900,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     407,     0,     0,   294,   295,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     296,   297,     0,     0,     0,   307,   298,     0,   185,   186,
     187,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   559,   188,   517,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,     0,   210,   185,
     186,   187,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   188,     0,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,     0,   210,
     186,   187,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   188,     0,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   188,   210,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,     0,   210,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,     0,   210,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,     0,   210,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,     0,   210,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,     0,   210,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,     0,   210,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,     0,   210,  -400,  -400,  -400,  -400,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,     0,   210
};

static const short int yycheck[] =
{
      23,    24,   364,    26,     4,    26,   506,   504,   416,   354,
       8,   367,   261,     8,   580,    26,     8,   362,     8,   210,
      26,     8,    26,   184,     5,     6,     8,     8,     9,    10,
      11,    12,    13,    14,   456,    16,    17,    18,    19,    20,
      21,    22,   634,     8,    25,     8,     8,    31,     8,    61,
       8,     8,     8,    46,     8,    36,     8,     8,     8,    27,
      28,     0,    43,    44,    79,    46,   785,    48,    73,    71,
      45,    45,    61,    98,   235,   236,     8,   574,     8,    45,
     105,   106,   107,   108,   109,   110,   111,    71,    69,    73,
      59,    60,   910,    31,   100,    69,    71,    93,    94,    98,
      45,   120,     8,     8,     0,    71,   105,   106,   107,   108,
     109,   110,   111,   705,   932,   151,   141,   142,   143,   144,
     139,   123,    45,   479,   105,   481,    71,   133,    27,    28,
     155,   120,   113,    27,    28,    73,   151,    26,   161,   151,
     140,   139,   154,   154,   151,   168,   169,   170,    71,   646,
     143,   156,   871,   134,   651,   136,   155,   139,   153,   155,
     152,   142,   143,   153,   145,   731,   153,    27,    28,   116,
     515,   516,   156,   529,   766,    27,    28,   152,   184,   771,
     184,   139,   774,   775,   152,    23,    24,   210,   153,   210,
     153,   153,   173,   153,   355,   152,   152,   178,   152,   270,
     152,   152,   152,   364,   210,   186,   210,   139,    46,   139,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   235,
     236,   235,   236,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   436,   152,   152,   229,   230,
     243,    45,   818,   675,   153,   772,   773,   280,   281,    61,
     154,    45,   243,   244,   153,    71,   247,    73,   151,    45,
     767,   768,   295,   629,    71,    71,    73,    71,   527,    31,
      45,    71,    63,    73,   265,   308,    61,    71,    66,    67,
      71,   540,    73,    61,   154,    71,    66,    67,    71,    71,
      73,    73,   154,   303,    73,   143,    71,   669,   314,    71,
      71,    73,    73,   294,   139,    73,   387,   388,   341,   819,
     665,    73,   544,   161,   151,   122,   151,   123,   821,   822,
     168,   169,   170,   151,   315,   151,   317,   318,   319,   320,
     153,   154,   859,   151,   367,   862,   863,   864,   154,   355,
     156,   355,   154,   116,   603,   120,   152,   151,   364,   156,
     364,   354,   770,   139,   154,    73,   156,    48,   152,   362,
      51,   733,   395,   354,   139,   156,   151,    93,    94,   154,
     151,   362,    63,   156,   156,    42,   154,   156,    45,   460,
      71,   613,   909,   615,   156,   156,    42,    43,   156,   470,
     471,   387,   388,   426,    71,   243,    73,    74,    92,    93,
      94,    23,    24,   436,    71,   436,   151,    45,    46,    47,
     101,    49,   151,    69,    70,    71,   407,   151,   409,   151,
     436,   112,   436,    79,    66,    67,    68,   151,    71,   155,
      71,   154,   280,   281,    92,    93,    94,   128,    71,   139,
     450,   474,   151,   476,   120,    49,   479,   295,   481,   440,
     453,   139,   462,   151,   145,   146,   147,   148,   149,   150,
     151,   155,   453,   120,   460,   456,   457,   123,   124,   125,
     126,   127,   128,   139,   470,   471,     8,   510,    92,    93,
      94,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,   341,   485,   754,   529,   155,   669,    92,
      93,    94,   139,   536,   537,   151,   354,    66,    67,    68,
      31,    79,   515,   516,   362,    73,    74,    75,   153,   367,
     154,   554,   153,   533,   515,   516,    13,    59,    60,   152,
     611,   155,   523,   524,   154,   118,   151,   570,    82,   572,
     153,   532,   623,   802,   625,     8,    71,   395,    97,    90,
     152,    71,   633,   812,   587,    73,   105,   106,   107,   108,
     109,   110,   733,   152,    61,   556,   153,   152,   559,     8,
      71,   118,   151,   151,    71,   608,    73,    74,   837,    76,
      77,    78,   841,   160,    26,   152,   845,     8,   151,   702,
      90,   704,    90,   852,    13,   854,   629,   139,   155,    98,
     591,   151,    13,   151,   717,   453,   105,   106,   107,   108,
     109,   110,   111,   153,    71,   611,    61,   155,   877,   154,
     152,   151,    71,   120,   119,   152,   474,   623,   476,   625,
     152,   479,   151,   481,   101,    71,    13,   633,   897,   136,
     137,   138,   723,   676,   151,   151,   151,   728,   761,    71,
     763,    97,   154,   669,     8,   669,   155,   154,   155,   692,
     919,   152,   665,   160,   777,   778,   925,   515,   516,   151,
     153,    13,   153,   153,   665,   151,   757,   121,   759,   760,
     152,   529,     8,   160,   675,    13,   152,    26,   536,   537,
     949,    73,    71,   684,   153,    61,   152,   152,   160,    89,
     120,   782,   152,   121,     8,    71,   554,    73,    74,    71,
      76,    77,    78,     8,   155,   152,    26,   733,   152,   733,
      73,    13,   570,    13,   572,   806,    71,   723,   738,    97,
     153,   120,   728,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    83,   152,   828,   152,   154,
     831,   153,   153,    73,   120,    13,   121,    13,    26,    26,
     608,   757,    71,   759,   760,   151,   151,   151,   849,    13,
     151,   137,   138,   105,   106,   107,   108,   109,   110,    59,
      60,   629,   151,    61,   151,    73,   782,   868,   154,   155,
     151,   157,   151,    71,   160,    73,    74,   152,    76,    77,
      78,   882,   151,   794,    42,    43,    44,    45,    46,    47,
     806,    49,   153,   153,   151,   151,   151,   665,   152,    13,
      79,    13,    73,    13,    71,    71,   151,    26,   676,    68,
     840,   155,   828,    73,    13,   831,    73,   151,    13,   152,
     152,   152,   120,    28,   152,   836,   151,   153,    13,   152,
      68,    87,    26,   849,   155,   155,   155,    85,   152,   137,
     138,   152,     3,     4,     5,     6,     7,   153,   152,   154,
     153,    12,   868,   153,   155,   152,   154,   155,   151,   155,
     158,   152,   160,   152,   101,   151,   882,   152,   152,    73,
     938,   901,   154,   168,   155,   303,   303,   572,   921,   395,
     510,    42,    43,   609,   799,   749,   676,    48,   941,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
     689,    62,    63,    64,    65,   268,   586,   416,    69,    70,
      71,    72,    73,   914,    75,   551,   770,   416,    79,    80,
      81,    82,   592,    84,   835,    86,   161,    88,   523,   554,
      91,    -1,   476,    -1,    95,    96,    97,    -1,    99,   100,
      -1,   102,   103,   104,    -1,    -1,    -1,   108,   109,   110,
      -1,   112,   113,   114,   115,   116,   117,    -1,    -1,    -1,
      -1,   122,   123,   124,   125,   126,   127,   128,     3,     4,
       5,     6,     7,    -1,   135,    -1,    -1,    12,    -1,   140,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     151,    -1,   153,   154,    -1,   156,   157,   158,   159,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,
      -1,    -1,    -1,    48,    -1,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    -1,    62,    63,    64,
      65,    -1,    -1,    -1,    69,    70,    71,    72,    73,    -1,
      75,    -1,    -1,    -1,    79,    80,    81,    82,    -1,    84,
      -1,    86,    -1,    88,    -1,    -1,    91,    -1,    -1,    -1,
      95,    96,    97,    -1,    99,   100,    -1,   102,   103,   104,
      -1,    -1,    -1,   108,   109,   110,    -1,   112,   113,   114,
     115,   116,   117,    -1,    -1,    -1,    -1,   122,   123,   124,
     125,   126,   127,   128,     3,     4,     5,     6,     7,    -1,
     135,    -1,    -1,    12,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   151,    26,   153,   154,
      -1,   156,   157,   158,   159,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    43,    -1,    -1,    -1,    -1,    48,
      -1,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    -1,    62,    63,    64,    65,    -1,    -1,    -1,
      69,    70,    71,    72,    73,    -1,    75,    -1,    -1,    -1,
      79,    80,    81,    82,    -1,    84,    -1,    86,    -1,    88,
      -1,    -1,    91,    -1,    -1,    -1,    95,    96,    -1,    -1,
      99,   100,    -1,   102,   103,   104,    -1,    -1,    -1,    -1,
      -1,   110,    -1,   112,   113,   114,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   122,   123,   124,   125,   126,   127,   128,
       3,     4,     5,     6,     7,    -1,   135,    -1,    -1,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   151,    26,   153,   154,    -1,   156,   157,   158,
     159,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,
      43,    -1,    -1,    -1,    -1,    48,    -1,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    -1,    62,
      63,    64,    65,    -1,    -1,    -1,    69,    70,    71,    72,
      73,    -1,    75,    -1,    -1,    -1,    79,    80,    81,    82,
      -1,    84,    -1,    86,    -1,    88,    -1,    -1,    91,    -1,
      -1,    -1,    95,    96,    -1,    -1,    99,   100,    -1,   102,
     103,   104,    -1,    -1,    -1,    -1,    -1,   110,    -1,   112,
     113,   114,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   122,
     123,   124,   125,   126,   127,   128,     3,     4,     5,     6,
       7,    -1,   135,    -1,    -1,    12,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   151,    26,
     153,   154,    -1,   156,   157,   158,   159,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,    -1,
      -1,    48,    -1,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    -1,    62,    63,    64,    65,    -1,
      -1,    -1,    69,    70,    71,    72,    73,    -1,    75,    -1,
      -1,    -1,    79,    80,    81,    82,    -1,    84,    -1,    86,
      -1,    88,    -1,    -1,    91,    -1,    -1,    -1,    95,    96,
      -1,    -1,    99,   100,    -1,   102,   103,   104,    -1,    -1,
      -1,    -1,    -1,   110,    -1,   112,   113,   114,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   122,   123,   124,   125,   126,
     127,   128,     3,     4,     5,     6,     7,    -1,   135,    -1,
      -1,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   151,    26,   153,   154,    -1,   156,
     157,   158,   159,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      -1,    62,    63,    64,    65,    -1,    -1,    -1,    69,    70,
      71,    72,    73,    -1,    75,    -1,    -1,    -1,    79,    80,
      81,    82,    -1,    84,    -1,    86,    -1,    88,    -1,    -1,
      91,    -1,    -1,    -1,    95,    96,    -1,    -1,    99,   100,
      -1,   102,   103,   104,    -1,    -1,    -1,    -1,    -1,   110,
      -1,   112,   113,   114,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   122,   123,   124,   125,   126,   127,   128,     3,     4,
       5,     6,     7,    -1,   135,    -1,    -1,    12,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
     151,    49,   153,   154,    -1,   156,   157,   158,   159,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,
      -1,    -1,    -1,    48,    -1,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    -1,    62,    63,    64,
      65,    -1,    -1,    -1,    69,    70,    71,    72,    73,    -1,
      75,    -1,    -1,    -1,    79,    80,    81,    82,    -1,    84,
      -1,    86,    -1,    88,    -1,    -1,    91,    -1,    -1,    -1,
      95,    96,    -1,    -1,    99,   100,    -1,   102,   103,   104,
      -1,    -1,    -1,    -1,    -1,   110,    -1,   112,   113,   114,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   122,   123,   124,
     125,   126,   127,   128,     3,     4,     5,     6,     7,    -1,
     135,    -1,    -1,    12,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   151,    -1,   153,   154,
      -1,   156,   157,   158,   159,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    43,    -1,    -1,    -1,    -1,    48,
      -1,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    -1,    62,    63,    64,     9,    10,    11,    -1,
      69,    70,    71,    72,    73,    -1,    -1,    -1,    -1,    -1,
      79,    -1,    25,    -1,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    -1,    49,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   113,   114,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   122,   123,   124,   125,   126,   127,   128,
       3,     4,     5,     6,     7,    -1,   135,    -1,    -1,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   151,    -1,   153,    -1,    -1,   156,   157,   158,
     159,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,
      43,    -1,    -1,    -1,    -1,    48,    -1,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    -1,    62,
      63,    64,    -1,    -1,    -1,    -1,    69,    70,    71,    72,
      73,    -1,    -1,    -1,    -1,    -1,    79,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     8,    -1,   160,    -1,    -1,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     113,   114,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   122,
     123,   124,   125,   126,   127,   128,     3,     4,     5,     6,
       7,    -1,   135,    -1,    -1,    12,    59,    60,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   151,    -1,
     153,    -1,    -1,   156,   157,   158,   159,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,    -1,
      -1,    48,    -1,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    -1,    62,    63,    64,     9,    10,
      11,    -1,    69,    70,    71,    72,    73,    -1,    -1,    -1,
      -1,    -1,    79,    -1,    25,    -1,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    -1,    49,   152,
      -1,    -1,    -1,    -1,    -1,    -1,   113,   114,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   122,   123,   124,   125,   126,
     127,   128,     3,     4,     5,     6,     7,    -1,   135,    -1,
      -1,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   151,    -1,   153,    -1,    -1,   156,
     157,   158,   159,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      -1,    62,    63,    64,    -1,    -1,    -1,    -1,    69,    70,
      71,    72,    73,    -1,    -1,    -1,    -1,    -1,    79,    -1,
      -1,    -1,    -1,    -1,   155,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    -1,    -1,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    -1,   113,   114,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   122,   123,   124,   125,   126,   127,   128,    -1,    -1,
      -1,    59,    60,    -1,   135,     3,     4,     5,     6,     7,
      -1,    -1,    -1,    -1,    12,    59,    60,    -1,    -1,    -1,
     151,   152,    -1,    -1,    -1,   156,   157,   158,   159,    -1,
      -1,    -1,    90,    31,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    42,    43,    -1,    -1,    -1,    -1,
      48,    -1,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    -1,    62,    63,    64,     9,    10,    11,
      -1,    69,    70,    71,    72,    73,    -1,    -1,    -1,    -1,
      -1,    79,    -1,    25,    -1,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    -1,    49,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   113,   114,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   122,   123,   124,   125,   126,   127,
     128,    -1,    -1,    -1,    -1,    -1,    -1,   135,     3,     4,
       5,     6,     7,    -1,    -1,    -1,    -1,    12,    -1,    -1,
      -1,    -1,    -1,   151,    -1,    -1,    -1,    -1,   156,   157,
     158,   159,    -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,
      -1,    -1,    -1,    48,    -1,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    -1,    62,    63,    64,
       9,    10,    11,    -1,    69,    70,    71,    72,    73,    -1,
      -1,    -1,    -1,   155,    79,    -1,    25,    -1,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    -1,
      49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,   114,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   122,   123,   124,
     125,   126,   127,   128,    -1,    -1,    -1,    -1,    -1,    -1,
     135,     3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,
      12,    -1,    -1,    -1,    -1,    -1,   151,    -1,    -1,    -1,
      -1,   156,   157,   158,   159,    -1,    -1,    -1,    -1,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      42,    43,    -1,    -1,    -1,    -1,    48,    -1,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    -1,
      62,    63,    64,     9,    10,    11,    -1,    69,    70,    71,
      72,    73,    -1,    -1,    -1,    -1,   155,    79,    -1,    25,
      -1,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   113,   114,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     122,   123,   124,   125,   126,   127,   128,    -1,    -1,    -1,
      -1,    -1,    -1,   135,     3,     4,     5,     6,     7,    -1,
      -1,    -1,    -1,    12,    -1,    -1,    -1,    -1,    -1,   151,
      -1,    -1,    -1,    -1,   156,   157,   158,   159,    -1,    -1,
      -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    43,    -1,    -1,    -1,    -1,    48,
      -1,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    -1,    62,    63,    64,     9,    10,    11,    -1,
      69,    70,    71,    72,    73,    -1,    -1,    -1,    -1,   155,
      79,    -1,    25,    -1,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    -1,    49,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   113,   114,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   122,   123,   124,   125,   126,   127,   128,
      -1,    -1,    -1,    -1,    -1,    -1,   135,     3,     4,     5,
       6,     7,    -1,    -1,    -1,    -1,    12,    -1,    -1,    -1,
      -1,    -1,   151,    -1,    -1,    -1,    -1,   156,   157,   158,
     159,    -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,
      -1,    -1,    48,    -1,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    -1,    62,    63,    64,     9,
      10,    11,    -1,    69,    70,    71,    72,    73,    -1,    -1,
      -1,    -1,   155,    79,    -1,    25,    -1,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    -1,    49,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,   114,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   122,   123,   124,   125,
     126,   127,   128,    -1,    -1,    -1,    -1,    -1,    -1,   135,
       3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,    12,
      -1,    -1,    -1,    -1,    -1,   151,    -1,    -1,    -1,    -1,
     156,   157,   158,   159,    -1,    -1,    -1,    -1,    31,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,
      43,    -1,    -1,    -1,    -1,    48,    -1,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    -1,    62,
      63,    64,     9,    10,    11,    -1,    69,    70,    71,    72,
      73,    -1,    -1,    -1,    -1,   155,    79,    -1,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     113,   114,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   122,
     123,   124,   125,   126,   127,   128,    -1,    -1,    -1,    -1,
      -1,    -1,   135,     3,     4,     5,     6,     7,    -1,    -1,
      -1,    -1,    12,    -1,    -1,    -1,    -1,    -1,   151,    -1,
      -1,    -1,    -1,   156,   157,   158,   159,    -1,    -1,    -1,
      -1,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    42,    43,    -1,    -1,    -1,    -1,    48,    -1,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    -1,    62,    63,    64,     9,    10,    11,    -1,    69,
      70,    71,    72,    73,    -1,    -1,   153,    -1,    -1,    79,
      -1,    25,    -1,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    -1,    49,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   113,   114,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   122,   123,   124,   125,   126,   127,   128,     3,
       4,     5,     6,     7,    -1,   135,    -1,    -1,    12,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   151,    -1,    -1,    -1,    -1,   156,   157,   158,   159,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,
      -1,    -1,    -1,    -1,    48,    -1,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    -1,    62,    63,
      64,    -1,     9,    10,    11,    69,    70,    71,    72,    73,
      -1,    -1,    -1,    -1,    -1,    79,    -1,    -1,    25,   153,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,   113,
     114,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   122,   123,
     124,   125,   126,   127,   128,     3,     4,     5,     6,     7,
      -1,   135,    -1,    -1,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   151,    -1,    -1,
      -1,    -1,   156,   157,   158,   159,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    42,    43,    -1,    -1,    -1,    -1,
      48,    -1,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    -1,    62,    63,    64,    -1,    -1,    -1,
      -1,    69,    70,    71,    72,    73,    11,    -1,    -1,    -1,
      -1,    79,    -1,    -1,    -1,    -1,   153,    -1,    -1,    -1,
      25,    -1,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    -1,    49,   113,   114,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   122,   123,   124,   125,   126,   127,
     128,    -1,    -1,    -1,    -1,    -1,    -1,   135,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     9,    10,    11,    -1,
      -1,    -1,    -1,   151,    -1,    -1,    -1,    -1,   156,   157,
     158,   159,    25,    -1,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    -1,    49,     9,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    25,    -1,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    -1,    49,     9,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    25,    -1,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    -1,    49,    -1,
      -1,    -1,    -1,     9,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,
     153,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    -1,    49,     9,    10,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      25,   153,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    -1,    49,    -1,     9,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   152,    25,    -1,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    -1,    49,    -1,    -1,     9,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    25,   152,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    -1,    49,
       9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    25,   152,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    -1,
      49,    -1,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,   152,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    -1,    49,    -1,    -1,     9,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    25,   152,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    -1,    49,     9,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    25,   152,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    -1,    49,    -1,     9,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    25,   152,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    61,    49,    -1,
      -1,     9,    10,    11,    -1,    -1,    -1,    71,    -1,    73,
      74,    -1,    76,    77,    78,    -1,    -1,    25,   152,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   120,    -1,    -1,   152,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     121,    -1,    -1,   137,   138,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     154,   155,    -1,    -1,    -1,   159,   160,    -1,     9,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   121,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    -1,    49,     9,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    25,    -1,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    -1,    49,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    25,    -1,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    25,    49,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    -1,    49,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    -1,    49,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    -1,    49,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    -1,    49,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    -1,    49,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    -1,    49,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    -1,    49,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    -1,    49
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned short int yystos[] =
{
       0,   162,   163,     0,   164,     3,     4,     5,     6,     7,
      12,    42,    43,    48,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    62,    63,    64,    65,    69,
      70,    71,    72,    73,    75,    79,    80,    81,    82,    84,
      86,    88,    91,    95,    96,    97,    99,   100,   102,   103,
     104,   108,   109,   110,   112,   113,   114,   115,   116,   117,
     122,   123,   124,   125,   126,   127,   128,   135,   140,   151,
     153,   154,   156,   157,   158,   159,   165,   169,   170,   203,
     204,   206,   209,   225,   227,   271,   282,   287,   296,   299,
     303,   304,   307,   309,   317,   318,   319,   320,   321,   322,
     328,   338,   341,   303,   303,   151,   303,   303,   303,   303,
     303,   303,   303,   281,   303,   303,   303,   303,   303,   303,
     303,    71,   287,   307,   309,   307,   303,    71,   287,   288,
     289,   320,   321,   328,   151,   294,   151,   151,   267,   303,
     177,   151,   151,   151,   189,   151,   153,   303,   153,   303,
     207,   153,   271,   303,   309,   190,   303,    79,   151,   202,
      73,   156,   254,   255,   116,   116,    73,   256,   151,   151,
     151,   151,   151,   151,   334,    71,   303,   166,   154,   334,
     334,   334,    71,    71,   139,     9,    10,    11,    25,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      49,   153,    59,    60,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,   308,   151,   120,    61,
     154,   156,   321,   303,   303,   139,   139,   274,   120,   321,
     152,   303,   303,   283,     8,   153,   169,   175,   268,   269,
     303,   271,   309,   151,   303,   153,   153,    31,   205,   153,
     153,   154,   153,    79,   153,   154,   304,   309,     8,   153,
      13,     8,   153,   200,   201,   309,   309,   339,   309,   152,
     272,    31,   303,   332,   333,    61,    71,    73,    74,    76,
      77,    78,   120,   136,   137,   138,   154,   155,   160,   335,
     154,   152,   155,   167,   303,   157,   158,   159,   118,   226,
     211,    71,   317,   321,   328,   277,   303,   278,   279,   275,
     276,   303,   303,   303,   303,   303,   303,   303,   303,   303,
     303,   303,   303,   303,   303,   303,   303,   303,   303,   303,
     288,    31,   303,   303,   303,   303,   303,   303,   303,   303,
     303,   303,   303,   303,   286,   310,   303,   323,   303,   152,
      71,   317,   151,   295,   290,   152,   152,    31,   252,   253,
     271,   309,   303,    82,   303,   153,     8,   186,   183,    71,
     236,   152,    71,   166,   152,   303,   255,    42,    43,    71,
     123,   296,   297,   298,    73,     8,   152,     8,   152,   152,
     153,   122,   309,   329,   330,   305,   309,   121,   152,     8,
     301,    61,   120,    72,   303,   309,   212,   115,   168,   169,
     203,   204,   155,    71,   287,   210,   118,   228,   151,   151,
     321,   303,   303,   303,   303,   303,    63,   309,   252,    71,
     154,   317,   324,   326,   327,   160,   155,   252,   324,    26,
     171,   305,   152,     8,   151,   152,   179,   270,    90,    90,
      13,     8,   152,   182,   208,   155,   155,   297,   297,   139,
     151,    13,   201,   153,   340,   151,     8,   152,   306,    31,
     303,    31,   303,   336,    71,    61,   155,   155,    98,   105,
     106,   107,   108,   109,   110,   111,   141,   142,   143,   144,
     155,   213,   220,   258,   261,   262,   263,   264,   266,   151,
     119,   229,   230,   287,   154,   284,   285,    26,   288,   152,
     303,   325,   311,    61,   154,   152,   291,   173,   169,    31,
     271,   309,   178,   176,   268,   303,   187,   184,   297,    71,
      26,   169,   235,    26,   154,   237,   151,   101,    71,   297,
     300,   302,   297,   309,   331,   330,    13,   305,   305,   121,
      71,    73,    74,   337,   303,    45,    71,   221,   222,   223,
     151,   151,   151,    71,     8,   153,    71,   219,   221,   259,
      97,   264,     8,   153,   152,   230,   154,     8,   257,   252,
     252,   280,   273,   155,   151,   315,   323,   303,   292,   166,
     172,   305,   303,    26,   169,   242,   153,   309,    31,   232,
     309,    13,   166,   153,   238,   153,   238,    71,   123,   249,
     250,   251,   151,   121,   152,     8,   301,   329,   303,    31,
     303,   160,   160,    13,     8,   139,    42,    45,    71,   224,
     200,   214,   152,   214,    26,   221,     8,   153,   139,    73,
     265,   205,    71,   153,   257,   287,    98,   155,   258,   261,
     262,   152,   152,   303,   295,   316,   312,   160,   155,   120,
     293,   174,   243,   152,   166,   180,   121,   231,   309,   231,
     297,    89,   238,    92,    93,    94,   238,   155,   152,     8,
      31,    73,   191,   297,   297,   152,   305,   155,   297,   222,
      71,   152,    26,   152,    48,    51,    63,    71,   101,   112,
     128,   145,   146,   147,   148,   149,   150,   151,   215,   216,
     139,   221,    73,    13,     8,   153,    71,   221,    13,   155,
      71,    97,   252,   120,   313,   324,   245,    66,    67,   247,
     153,    83,   268,   232,   152,   152,   153,    92,   153,   303,
      26,   153,   241,   155,   154,   251,    73,    13,   287,   121,
      13,    26,   215,    26,   215,   222,   151,   151,   151,   151,
     151,   151,   151,   151,   151,   151,   215,    27,    28,   153,
      71,   139,    13,   297,    73,   151,   139,   297,   205,   152,
     324,    66,    67,   248,   151,   169,   153,   152,   188,   185,
     153,   241,   240,   166,    31,    73,    13,   297,   192,   297,
     297,   215,   154,   215,   222,   221,   221,    79,   262,   263,
     222,   223,   223,   222,   222,   152,   215,   215,    13,    73,
     297,    13,   249,    71,    71,   314,   151,    26,    68,   303,
     181,    26,   169,   234,   234,   239,   166,   155,    73,    13,
     297,    73,   154,   166,   154,   151,   152,   152,   152,   205,
     120,   139,   218,   218,   218,   152,   152,   297,    13,   297,
     152,   151,   315,   303,   166,   153,   152,    26,   169,   233,
     166,   166,    13,   297,   152,   166,   155,   166,    45,    69,
     217,   223,   223,   223,   223,   297,   153,   154,   260,   249,
     152,   244,   166,    87,   297,   193,   155,   155,   152,   139,
     151,   152,   152,   166,   152,    26,   169,    85,   153,   154,
     152,   223,   217,   155,   260,   246,   153,   166,   224,   152,
     166,   155,   151,   152,   194,   217,   101,   195,   196,   197,
     152,   151,   197,   152,   287,   198,    73,   152,   199,   154,
     166,   155
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { 								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (0)


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)         \
    do									\
      if (N)								\
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (0)
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
              (Loc).first_line, (Loc).first_column,	\
              (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (&yylval, YYLEX_PARAM)
#else
# define YYLEX yylex (&yylval)
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

#  include <stdio.h> 
# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (0)

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)		\
do {								\
  if (yydebug)							\
    {								\
      YYFPRINTF (stderr, "%s ", Title);				\
      yysymprint (stderr,					\
                  Type, Value);	\
      YYFPRINTF (stderr, "\n");					\
    }								\
} while (0)

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_stack_print (short int *bottom, short int *top)
#else
static void
yy_stack_print (bottom, top)
    short int *bottom;
    short int *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (/* Nothing. */; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_reduce_print (int yyrule)
#else
static void
yy_reduce_print (yyrule)
    int yyrule;
#endif
{
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu), ",
             yyrule - 1, yylno);
  /* Print the symbols being reduced, and their result.  */
  for (yyi = yyprhs[yyrule]; 0 <= yyrhs[yyi]; yyi++)
    YYFPRINTF (stderr, "%s ", yytname[yyrhs[yyi]]);
  YYFPRINTF (stderr, "-> %s\n", yytname[yyr1[yyrule]]);
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (Rule);		\
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined (__GLIBC__) && defined (_STRING_H)
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
#   if defined (__STDC__) || defined (__cplusplus)
yystrlen (const char *yystr)
#   else
yystrlen (yystr)
     const char *yystr;
#   endif
{
  const char *yys = yystr;

  while (*yys++ != '\0')
    continue;

  return yys - yystr - 1;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined (__GLIBC__) && defined (_STRING_H) && defined (_GNU_SOURCE)
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
#   if defined (__STDC__) || defined (__cplusplus)
yystpcpy (char *yydest, const char *yysrc)
#   else
yystpcpy (yydest, yysrc)
     char *yydest;
     const char *yysrc;
#   endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

#endif /* YYERROR_VERBOSE */



#if YYDEBUG
/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yysymprint (FILE *yyoutput, int yytype, YYSTYPE *yyvaluep)
#else
static void
yysymprint (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);


# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  switch (yytype)
    {
      default:
        break;
    }
  YYFPRINTF (yyoutput, ")");
}

#endif /* ! YYDEBUG */
/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM);
# else
int yyparse ();
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */






// Yijun Yu: utility functions -----------------------------------------------
#include <stdio.h>
/// replace character terminals into symbolic terminals
static char *YYTNAME(int r)
{
  static char yytname_buf[8];
  if (strlen(yytname[r])==3 && yytname[r][0] == '\'' && yytname[r][2] == '\'') 
  { 
        sprintf(yytname_buf, "CHAR%d", (int)yytname[r][1]);
        return yytname_buf;
  } 
  else if (strlen(yytname[r])>=2 && yytname[r][0] == 64 )
  {
    strcpy(yytname_buf,"ACTION");
    strcat(yytname_buf,&(yytname[r][1]));
    return yytname_buf;
  }

  return (char *)yytname[r];
}
#include <stdio.h>
static char *yytext_buf = NULL;

/// replace a special character in the text into an entity
static
void replace_entity(char c, char *s)
{
    char *buf;
    char *i;
    int len, l;
    i = yytext_buf;
    do {
        i =  (char *)index(i, c);
        if (i) {
            l = i - yytext_buf;
            len = strlen(yytext_buf) + strlen(s) - 1;
            //buf = (char*)YYSTACK_ALLOC(1000000);
            buf = (char*)YYSTACK_ALLOC(len + 1); // Myo M Thein
            if (l>0) {
#if 1 // Myo M Thein
		strncpy(buf, yytext_buf, l);
#else
		int t = 0;
		while (t < l) {
			buf[t] = yytext_buf[t]; 
			t++;
		}
                buf[t] = 0;
#endif
            } else {
                buf[0] = 0;
            }
            strcat(buf, s); 
            strncat(buf, yytext_buf + l + 1, strlen(yytext_buf) - l); 
            buf[len] = 0;
            YYSTACK_FREE(yytext_buf); 
            //yytext_buf = buf;
	    memcpy(yytext_buf,buf,len+1);
        i++;
        if (*i=='\0')
            i=NULL;
        }
    } while (i);
}

/// replace the special characters in the text into entities 
static
char* xml_encode( char ch)
{
  static char text[2];
    switch(ch)
    {
    case '&':
        return ( "&amp;");
        break;
    case '>':
        return ( "&gt;");
        break;
    case '<' :
        return ( "&lt;" );
        break;
    case  '\"':
        return ( "&quot;");
        break;
    case '\'':
        return ( "&apos;");
        break;
    default:
        text[0]=ch;
        text[1]=0;
        return text;
        break;
    }
}

static
void replace_special_entities(char *text,char *text_out)
{
  int i,lg;
    if (!text) { strcpy(text_out,"??");return ; }
    lg = strlen(text);
    strcpy(text_out,"");
    for (i=0;i<lg;i++)
    {
       strcat(text_out,xml_encode(text[i]));
    }
}
static
void generate_xml_output(char **yyxsp,char **yyxs)
{
#ifndef YYYAXX_XML 
#define YYYAXX_XML  "yaxx.xml"
#endif
#ifndef YYYAXX_DTD
#define YYYAXX_DTD "yaxx.dtd"
#endif
       int r, i, j;
       char buf[65536];
       int old_rule = 0;
       char *p = *yyxsp + 6;
#if 0
       char *v = strsep(&p, ">");
       strcpy(buf, v);
#else
	   i = 0;
	   while (p[i]!='>') {
		buf[i] = p[i];
		i++;
	   }
	   buf[i]  = 0;
#endif
	/// Generating the XML document 
	char out[strlen(yyxs[1]+i+6)+strlen(buf)+69];
	sprintf(out, "<?xml version=\"1.0\" encoding=\"UTF-8\" ?>\n<php:start xmlns:php=\"http://php.net/xsl\"%s\n", yyxs[1]+i+6);
	_xml_output = out;
}

//------------------------------------------------------------------------
/*----------.
| yyparse.  |
`----------*/
// Yijun Yu
#include <stdio.h>
char *yytext=NULL;

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM)
# else
int yyparse (YYPARSE_PARAM)
  void *YYPARSE_PARAM;
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int
yyparse (void)
#else
int
yyparse ()
    ;
#endif
#endif
{
  /* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;

  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyxs': related to xml tags,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  short	int yyssa[YYINITDEPTH];
  short int *yyss = yyssa;
  short int *yyssp;

  // Yijun Yu: for XML
  /* The tags stack. */
  char *yyxsa[YYINITDEPTH];
  char **yyxs = yyxsa;
  char **yyxsp;
  //-----------------------------------------------

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;


// Yijun Yu: don't forget yyxsp--
#define YYPOPSTACK   (yyvsp--, yyxsp--, yyssp--)
static char * yyxml_string=NULL; // for XML
// for id attribute generation (by William Candillon)
int _id = 0; 
char string[512];

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* When reducing, the number of symbols on the RHS of the reduced
     rule.  */
  int yylen;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  // Yijun Yu: don't forget yyxsp
  yyxsp = yyxs;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed. so pushing a state here evens the stacks.
     */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack. Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	// Yijun Yu: don't forget yyxs
    char **yyxs1 = yyxs;
	short int *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    // Yijun Yu: don't forget yyxsl
		    &yyxs1, yysize * sizeof (*yyxsp),
		    &yyvs1, yysize * sizeof (*yyvsp),
 &yystacksize);
    yyxs = yyxs1;

	yyss = yyss1;
	// Yijun Yu: don't forget yyxsl
    yyxs = yyxs1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	short int *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
    char **yyxs1 = yyxs;
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
		// Yijun Yu: yyxsp
      yyxsp = yyxs + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

/* Do appropriate processing given the current state.  */
/* Read a look-ahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to look-ahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
    { // Yijun Yu: process the terminal
      yyxml_string = (char *) XML_ALLOC(1024 + strlen(string));
      strcpy(yyxml_string, "<php:");
      strcat(yyxml_string, YYTNAME(yytoken));      
#if 1 //William Candillon
      strcat(yyxml_string, " id=\"");
      sprintf(string, "%d", _id);
      strcat(yyxml_string, string);
      strcat(yyxml_string, "\"");
      _id++;
	  //printf ("%d: %s\n", yyvsp->u.opline_num, YYTNAME(yytoken));
#endif
      strcat(yyxml_string, ">");
      if (yytoken < YYNTOKENS) {
	  if (yytext) {
		  char *tmp;
		  tmp=(char *)YYSTACK_ALLOC(6*strlen(yytext)+1); 
		  replace_special_entities(yytext,tmp);
		  strcat(yyxml_string, tmp);
		  YYSTACK_FREE(tmp);
	  }
      }
      strcat(yyxml_string, "</php:");
      strcat(yyxml_string, YYTNAME(yytoken));
      strcat(yyxml_string, ">\n");
    }
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

	// Yijun Yu: update yyxsp
  *++yyxsp = yyxml_string;
  yyxml_string = 0;
  *++yyvsp = yylval;


  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  yystate = yyn;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
    {
      int len = 0;
      int alloc_len=0;
      int n = 0;
      int yyi;
      int i;
      for (yyi = yyprhs[yyn]; yyrhs[yyi] > 0 ; yyi++, n++) {
          int l;
          char * yyxml_str = yyxsp[-n];
          if (yyxml_str==NULL) {
            l = 0;
          } else
              l = strlen(yyxml_str);
          len += l;
      }
      alloc_len =len+100+2*strlen(YYTNAME(yyr1[yyn]));
      yyxml_string = (char *) XML_ALLOC(alloc_len);
      strcpy(yyxml_string, "<php:");
      strcat(yyxml_string, YYTNAME(yyr1[yyn]));
#if 1 //William Candillon
      strcat(yyxml_string, " id=\"");
      sprintf(string, "%d", _id);
      strcat(yyxml_string, string);
      strcat(yyxml_string, "\"");
      _id++;
#endif
      strcat(yyxml_string, ">\n");
      i = n;
      for (yyi = yyprhs[yyn]; yyrhs[yyi] > 0; yyi++, i--) 
      {
          char * yyxml_str = yyxsp[1-i];
          if (yyxml_str) {
              strcat(yyxml_string, yyxml_str); 
              XML_FREE(yyxml_str);
              yyxsp[1-i] = NULL;
          } else {
            fprintf(stderr, "Warning! the %d-th argument is empty", n-i+1);
          }
      }
      strcat(yyxml_string, "</php:");
      strcat(yyxml_string, YYTNAME(yyr1[yyn]));
      strcat(yyxml_string, ">\n");
      yyxsp -= n;
      *++yyxsp = yyxml_string;
      yyxml_string = NULL;
    }
  switch (yyn)
    {
      /*  case 3:
#line 162 "php_parser.y"
    { zend_do_extended_info(TSRMLS_C); ;}
    break;

  case 4:
#line 162 "php_parser.y"
    { HANDLE_INTERACTIVE(); ;}
    break;

  case 7:
#line 169 "php_parser.y"
    { zend_do_early_binding(TSRMLS_C); ;}
    break;

  case 8:
#line 170 "php_parser.y"
    { zend_do_early_binding(TSRMLS_C); ;}
    break;

  case 9:
#line 171 "php_parser.y"
    { REGISTER_MAIN_LONG_CONSTANT("__COMPILER_HALT_OFFSET__", zend_get_scanned_file_offset(TSRMLS_C), CONST_CS); YYACCEPT; ;}
    break;

  case 11:
#line 178 "php_parser.y"
    { zend_do_extended_info(TSRMLS_C); ;}
    break;

  case 12:
#line 178 "php_parser.y"
    { HANDLE_INTERACTIVE(); ;}
    break;

  case 17:
#line 187 "php_parser.y"
    { zend_error(E_COMPILE_ERROR, "__HALT_COMPILER() can only be used from the outermost scope"); ;}
    break;

  case 18:
#line 192 "php_parser.y"
    { zend_do_ticks(TSRMLS_C); ;}
    break;

  case 20:
#line 197 "php_parser.y"
    { zend_do_if_cond(&(yyvsp[-1]), &(yyvsp[0]) TSRMLS_CC); ;}
    break;

  case 21:
#line 197 "php_parser.y"
    { zend_do_if_after_statement(&(yyvsp[-2]), 1 TSRMLS_CC); ;}
    break;

  case 22:
#line 197 "php_parser.y"
    { zend_do_if_end(TSRMLS_C); ;}
    break;

  case 23:
#line 198 "php_parser.y"
    { zend_do_if_cond(&(yyvsp[-2]), &(yyvsp[-1]) TSRMLS_CC); ;}
    break;

  case 24:
#line 198 "php_parser.y"
    { zend_do_if_after_statement(&(yyvsp[-3]), 1 TSRMLS_CC); ;}
    break;

  case 25:
#line 198 "php_parser.y"
    { zend_do_if_end(TSRMLS_C); ;}
    break;

  case 26:
#line 199 "php_parser.y"
    { (yyvsp[-1]).u.opline_num = get_next_op_number(CG(active_op_array));  ;}
    break;

  case 27:
#line 199 "php_parser.y"
    { zend_do_while_cond(&(yyvsp[-1]), &(yyvsp[0]) TSRMLS_CC); ;}
    break;

  case 28:
#line 199 "php_parser.y"
    { zend_do_while_end(&(yyvsp[-6]), &(yyvsp[-2]) TSRMLS_CC); ;}
    break;

  case 29:
#line 200 "php_parser.y"
    { (yyvsp[0]).u.opline_num = get_next_op_number(CG(active_op_array));  zend_do_do_while_begin(TSRMLS_C); ;}
    break;

  case 30:
#line 200 "php_parser.y"
    { (yyvsp[0]).u.opline_num = get_next_op_number(CG(active_op_array)); ;}
    break;

  case 31:
#line 200 "php_parser.y"
    { zend_do_do_while_end(&(yyvsp[-8]), &(yyvsp[-4]), &(yyvsp[-2]) TSRMLS_CC); ;}
    break;

  case 32:
#line 204 "php_parser.y"
    { zend_do_free(&(yyvsp[-1]) TSRMLS_CC); (yyvsp[0]).u.opline_num = get_next_op_number(CG(active_op_array)); ;}
    break;

  case 33:
#line 206 "php_parser.y"
    { zend_do_extended_info(TSRMLS_C); zend_do_for_cond(&(yyvsp[-1]), &(yyvsp[0]) TSRMLS_CC); ;}
    break;

  case 34:
#line 208 "php_parser.y"
    { zend_do_free(&(yyvsp[-1]) TSRMLS_CC); zend_do_for_before_statement(&(yyvsp[-6]), &(yyvsp[-3]) TSRMLS_CC); ;}
    break;

  case 35:
#line 209 "php_parser.y"
    { zend_do_for_end(&(yyvsp[-5]) TSRMLS_CC); ;}
    break;

  case 36:
#line 210 "php_parser.y"
    { zend_do_switch_cond(&(yyvsp[-1]) TSRMLS_CC); ;}
    break;

  case 37:
#line 210 "php_parser.y"
    { zend_do_switch_end(&(yyvsp[0]) TSRMLS_CC); ;}
    break;

  case 38:
#line 211 "php_parser.y"
    { zend_do_brk_cont(ZEND_BRK, NULL TSRMLS_CC); ;}
    break;

  case 39:
#line 212 "php_parser.y"
    { zend_do_brk_cont(ZEND_BRK, &(yyvsp[-1]) TSRMLS_CC); ;}
    break;

  case 40:
#line 213 "php_parser.y"
    { zend_do_brk_cont(ZEND_CONT, NULL TSRMLS_CC); ;}
    break;

  case 41:
#line 214 "php_parser.y"
    { zend_do_brk_cont(ZEND_CONT, &(yyvsp[-1]) TSRMLS_CC); ;}
    break;

  case 42:
#line 215 "php_parser.y"
    { zend_do_return(NULL, 0 TSRMLS_CC); ;}
    break;

  case 43:
#line 216 "php_parser.y"
    { zend_do_return(&(yyvsp[-1]), 0 TSRMLS_CC); ;}
    break;

  case 44:
#line 217 "php_parser.y"
    { zend_do_return(&(yyvsp[-1]), 1 TSRMLS_CC); ;}
    break;

  case 48:
#line 221 "php_parser.y"
    { zend_do_echo(&(yyvsp[0]) TSRMLS_CC); ;}
    break;

  case 49:
#line 222 "php_parser.y"
    { zend_do_free(&(yyvsp[-1]) TSRMLS_CC); ;}
    break;

  case 50:
#line 223 "php_parser.y"
    { zend_error(E_COMPILE_ERROR,"use: Not yet supported. Please use include_once() or require_once()");  zval_dtor(&(yyvsp[-1]).u.constant); ;}
    break;

  case 52:
#line 225 "php_parser.y"
    { zend_do_foreach_begin(&(yyvsp[-2]), &(yyvsp[-1]), &(yyvsp[0]), 1 TSRMLS_CC); ;}
    break;

  case 53:
#line 226 "php_parser.y"
    { zend_do_foreach_fetch(&(yyvsp[-4]), &(yyvsp[-3]), &(yyvsp[0]) TSRMLS_CC); ;}
    break;

  case 54:
#line 227 "php_parser.y"
    { zend_do_foreach_cont(&(yyvsp[-8]), &(yyvsp[-4]), &(yyvsp[-2]), &(yyvsp[-1]) TSRMLS_CC); ;}
    break;

  case 55:
#line 228 "php_parser.y"
    { zend_do_foreach_end(&(yyvsp[-10]), &(yyvsp[-6]) TSRMLS_CC); ;}
    break;

  case 56:
#line 229 "php_parser.y"
    { zend_do_foreach_begin(&(yyvsp[-2]), &(yyvsp[-1]), &(yyvsp[0]), 0 TSRMLS_CC); ;}
    break;

  case 57:
#line 230 "php_parser.y"
    { zend_do_foreach_fetch(&(yyvsp[-4]), &(yyvsp[-3]), &(yyvsp[0]) TSRMLS_CC); ;}
    break;

  case 58:
#line 231 "php_parser.y"
    { zend_check_writable_variable(&(yyvsp[-2])); zend_do_foreach_cont(&(yyvsp[-8]), &(yyvsp[-4]), &(yyvsp[-2]), &(yyvsp[-1]) TSRMLS_CC); ;}
    break;

  case 59:
#line 232 "php_parser.y"
    { zend_do_foreach_end(&(yyvsp[-10]), &(yyvsp[-6]) TSRMLS_CC); ;}
    break;

  case 60:
#line 233 "php_parser.y"
    { (yyvsp[0]).u.opline_num = get_next_op_number(CG(active_op_array)); zend_do_declare_begin(TSRMLS_C); ;}
    break;

  case 61:
#line 233 "php_parser.y"
    { zend_do_declare_end(&(yyvsp[-5]) TSRMLS_CC); ;}
    break;

  case 63:
#line 235 "php_parser.y"
    { zend_do_try(&(yyvsp[0]) TSRMLS_CC); ;}
    break;

  case 64:
#line 236 "php_parser.y"
    { zend_initialize_try_catch_element(&(yyvsp[-6]) TSRMLS_CC); ;}
    break;

  case 65:
#line 237 "php_parser.y"
    { zend_do_first_catch(&(yyvsp[-2]) TSRMLS_CC); ;}
    break;

  case 66:
#line 238 "php_parser.y"
    { zend_do_begin_catch(&(yyvsp[-11]), &(yyvsp[-3]), &(yyvsp[-1]), 1 TSRMLS_CC); ;}
    break;

  case 67:
#line 239 "php_parser.y"
    { zend_do_end_catch(&(yyvsp[-15]) TSRMLS_CC); ;}
    break;

  case 68:
#line 240 "php_parser.y"
    { zend_do_mark_last_catch(&(yyvsp[-11]), &(yyvsp[0]) TSRMLS_CC); ;}
    break;

  case 69:
#line 241 "php_parser.y"
    { zend_do_throw(&(yyvsp[-1]) TSRMLS_CC); ;}
    break;

  case 70:
#line 246 "php_parser.y"
    { (yyval) = (yyvsp[0]); ;}
    break;

  case 71:
#line 247 "php_parser.y"
    { (yyval).u.opline_num = -1; ;}
    break;

  case 72:
#line 251 "php_parser.y"
    { (yyval) = (yyvsp[0]); ;}
    break;

  case 73:
#line 252 "php_parser.y"
    { (yyval) = (yyvsp[0]); ;}
    break;

  case 74:
#line 257 "php_parser.y"
    { (yyval).u.opline_num = get_next_op_number(CG(active_op_array)); ;}
    break;

  case 75:
#line 257 "php_parser.y"
    { zend_do_begin_catch(&(yyvsp[-5]), &(yyvsp[-3]), &(yyvsp[-1]), 0 TSRMLS_CC); ;}
    break;

  case 76:
#line 257 "php_parser.y"
    { zend_do_end_catch(&(yyvsp[-9]) TSRMLS_CC); ;}
    break;

  case 79:
#line 267 "php_parser.y"
    { zend_do_end_variable_parse(BP_VAR_UNSET, 0 TSRMLS_CC); zend_do_unset(&(yyvsp[0]) TSRMLS_CC); ;}
    break;

  case 80:
#line 271 "php_parser.y"
    { (yyval) = (yyvsp[0]); ;}
    break;

  case 81:
#line 272 "php_parser.y"
    { (yyval) = (yyvsp[-1]); ;}
    break;

  case 82:
#line 277 "php_parser.y"
    { zend_do_ticks(TSRMLS_C); ;}
    break;

  case 83:
#line 281 "php_parser.y"
    { zend_do_ticks(TSRMLS_C); ;}
    break;

  case 84:
#line 286 "php_parser.y"
    { (yyval).op_type = ZEND_RETURN_VAL; ;}
    break;

  case 85:
#line 287 "php_parser.y"
    { (yyval).op_type = ZEND_RETURN_REF; ;}
    break;

  case 86:
#line 292 "php_parser.y"
    { (yyvsp[0]).u.opline_num = CG(zend_lineno); ;}
    break;

  case 87:
#line 292 "php_parser.y"
    { zend_do_begin_function_declaration(&(yyvsp[-3]), &(yyvsp[0]), 0, (yyvsp[-1]).op_type, NULL TSRMLS_CC); ;}
    break;

  case 88:
#line 293 "php_parser.y"
    { zend_do_end_function_declaration(&(yyvsp[-10]) TSRMLS_CC); ;}
    break;

  case 89:
#line 298 "php_parser.y"
    { zend_do_begin_class_declaration(&(yyvsp[-2]), &(yyvsp[-1]), &(yyvsp[0]) TSRMLS_CC); ;}
    break;

  case 90:
#line 302 "php_parser.y"
    { zend_do_end_class_declaration(&(yyvsp[-7]), &(yyvsp[-6]) TSRMLS_CC); ;}
    break;

  case 91:
#line 304 "php_parser.y"
    { zend_do_begin_class_declaration(&(yyvsp[-1]), &(yyvsp[0]), NULL TSRMLS_CC); ;}
    break;

  case 92:
#line 308 "php_parser.y"
    { zend_do_end_class_declaration(&(yyvsp[-6]), &(yyvsp[-5]) TSRMLS_CC); ;}
    break;

  case 141:
#line 413 "php_parser.y"
    { (yyval).u.opline_num = CG(zend_lineno); (yyval).u.EA.type = 0; ;}
    break;

  case 142:
#line 414 "php_parser.y"
    { (yyval).u.opline_num = CG(zend_lineno); (yyval).u.EA.type = ZEND_ACC_EXPLICIT_ABSTRACT_CLASS; ;}
    break;

  case 143:
#line 415 "php_parser.y"
    { (yyval).u.opline_num = CG(zend_lineno); (yyval).u.EA.type = ZEND_ACC_FINAL_CLASS; ;}
    break;

  case 144:
#line 419 "php_parser.y"
    { (yyval).op_type = IS_UNUSED; ;}
    break;

  case 145:
#line 420 "php_parser.y"
    { (yyval) = (yyvsp[0]); ;}
    break;

  case 146:
#line 424 "php_parser.y"
    { (yyval).u.opline_num = CG(zend_lineno); (yyval).u.EA.type = ZEND_ACC_INTERFACE; ;}
    break;

  case 151:
#line 438 "php_parser.y"
    { zend_do_implements_interface(&(yyvsp[0]) TSRMLS_CC); ;}
    break;

  case 152:
#line 439 "php_parser.y"
    { zend_do_implements_interface(&(yyvsp[0]) TSRMLS_CC); ;}
    break;

  case 153:
#line 443 "php_parser.y"
    { (yyval).op_type = IS_UNUSED; ;}
    break;

  case 154:
#line 444 "php_parser.y"
    { (yyval) = (yyvsp[0]); ;}
    break;

  case 155:
#line 449 "php_parser.y"
    { zend_check_writable_variable(&(yyvsp[0])); (yyval) = (yyvsp[0]); ;}
    break;

  case 156:
#line 450 "php_parser.y"
    { zend_check_writable_variable(&(yyvsp[0])); (yyval) = (yyvsp[0]);  (yyval).u.EA.type |= ZEND_PARSED_REFERENCE_VARIABLE; ;}
    break;

  case 163:
#line 472 "php_parser.y"
    { zend_do_declare_stmt(&(yyvsp[-2]), &(yyvsp[0]) TSRMLS_CC); ;}
    break;

  case 164:
#line 473 "php_parser.y"
    { zend_do_declare_stmt(&(yyvsp[-2]), &(yyvsp[0]) TSRMLS_CC); ;}
    break;

  case 165:
#line 478 "php_parser.y"
    { (yyval) = (yyvsp[-1]); ;}
    break;

  case 166:
#line 479 "php_parser.y"
    { (yyval) = (yyvsp[-1]); ;}
    break;

  case 167:
#line 480 "php_parser.y"
    { (yyval) = (yyvsp[-2]); ;}
    break;

  case 168:
#line 481 "php_parser.y"
    { (yyval) = (yyvsp[-2]); ;}
    break;

  case 169:
#line 486 "php_parser.y"
    { (yyval).op_type = IS_UNUSED; ;}
    break;

  case 170:
#line 487 "php_parser.y"
    { zend_do_extended_info(TSRMLS_C);  zend_do_case_before_statement(&(yyvsp[-3]), &(yyvsp[-2]), &(yyvsp[-1]) TSRMLS_CC); ;}
    break;

  case 171:
#line 487 "php_parser.y"
    { zend_do_case_after_statement(&(yyval), &(yyvsp[-4]) TSRMLS_CC); (yyval).op_type = IS_CONST; ;}
    break;

  case 172:
#line 488 "php_parser.y"
    { zend_do_extended_info(TSRMLS_C);  zend_do_default_before_statement(&(yyvsp[-2]), &(yyvsp[-1]) TSRMLS_CC); ;}
    break;

  case 173:
#line 488 "php_parser.y"
    { zend_do_case_after_statement(&(yyval), &(yyvsp[-3]) TSRMLS_CC); (yyval).op_type = IS_CONST; ;}
    break;

  case 179:
#line 507 "php_parser.y"
    { zend_do_if_cond(&(yyvsp[-1]), &(yyvsp[0]) TSRMLS_CC); ;}
    break;

  case 180:
#line 507 "php_parser.y"
    { zend_do_if_after_statement(&(yyvsp[-2]), 0 TSRMLS_CC); ;}
    break;

  case 182:
#line 513 "php_parser.y"
    { zend_do_if_cond(&(yyvsp[-2]), &(yyvsp[-1]) TSRMLS_CC); ;}
    break;

  case 183:
#line 513 "php_parser.y"
    { zend_do_if_after_statement(&(yyvsp[-3]), 0 TSRMLS_CC); ;}
    break;

  case 190:
#line 536 "php_parser.y"
    { znode tmp;  fetch_simple_variable(&tmp, &(yyvsp[0]), 0 TSRMLS_CC); (yyval).op_type = IS_CONST; (yyval).u.constant.value.lval=1; (yyval).u.constant.type=IS_LONG; INIT_PZVAL(&(yyval).u.constant); zend_do_receive_arg(ZEND_RECV, &tmp, &(yyval), NULL, &(yyvsp[-1]), &(yyvsp[0]), 0 TSRMLS_CC); ;}
    break;

  case 191:
#line 537 "php_parser.y"
    { znode tmp;  fetch_simple_variable(&tmp, &(yyvsp[0]), 0 TSRMLS_CC); (yyval).op_type = IS_CONST; (yyval).u.constant.value.lval=1; (yyval).u.constant.type=IS_LONG; INIT_PZVAL(&(yyval).u.constant); zend_do_receive_arg(ZEND_RECV, &tmp, &(yyval), NULL, &(yyvsp[-2]), &(yyvsp[0]), 1 TSRMLS_CC); ;}
    break;

  case 192:
#line 538 "php_parser.y"
    { znode tmp;  fetch_simple_variable(&tmp, &(yyvsp[-2]), 0 TSRMLS_CC); (yyval).op_type = IS_CONST; (yyval).u.constant.value.lval=1; (yyval).u.constant.type=IS_LONG; INIT_PZVAL(&(yyval).u.constant); zend_do_receive_arg(ZEND_RECV_INIT, &tmp, &(yyval), &(yyvsp[0]), &(yyvsp[-4]), &(yyvsp[-2]), 1 TSRMLS_CC); ;}
    break;

  case 193:
#line 539 "php_parser.y"
    { znode tmp;  fetch_simple_variable(&tmp, &(yyvsp[-2]), 0 TSRMLS_CC); (yyval).op_type = IS_CONST; (yyval).u.constant.value.lval=1; (yyval).u.constant.type=IS_LONG; INIT_PZVAL(&(yyval).u.constant); zend_do_receive_arg(ZEND_RECV_INIT, &tmp, &(yyval), &(yyvsp[0]), &(yyvsp[-3]), &(yyvsp[-2]), 0 TSRMLS_CC); ;}
    break;

  case 194:
#line 540 "php_parser.y"
    { znode tmp;  fetch_simple_variable(&tmp, &(yyvsp[0]), 0 TSRMLS_CC); (yyval)=(yyvsp[-3]); (yyval).u.constant.value.lval++; zend_do_receive_arg(ZEND_RECV, &tmp, &(yyval), NULL, &(yyvsp[-1]), &(yyvsp[0]), 0 TSRMLS_CC); ;}
    break;

  case 195:
#line 541 "php_parser.y"
    { znode tmp;  fetch_simple_variable(&tmp, &(yyvsp[0]), 0 TSRMLS_CC); (yyval)=(yyvsp[-4]); (yyval).u.constant.value.lval++; zend_do_receive_arg(ZEND_RECV, &tmp, &(yyval), NULL, &(yyvsp[-2]), &(yyvsp[0]), 1 TSRMLS_CC); ;}
    break;

  case 196:
#line 542 "php_parser.y"
    { znode tmp;  fetch_simple_variable(&tmp, &(yyvsp[-2]), 0 TSRMLS_CC); (yyval)=(yyvsp[-6]); (yyval).u.constant.value.lval++; zend_do_receive_arg(ZEND_RECV_INIT, &tmp, &(yyval), &(yyvsp[0]), &(yyvsp[-4]), &(yyvsp[-2]), 1 TSRMLS_CC); ;}
    break;

  case 197:
#line 543 "php_parser.y"
    { znode tmp;  fetch_simple_variable(&tmp, &(yyvsp[-2]), 0 TSRMLS_CC); (yyval)=(yyvsp[-5]); (yyval).u.constant.value.lval++; zend_do_receive_arg(ZEND_RECV_INIT, &tmp, &(yyval), &(yyvsp[0]), &(yyvsp[-3]), &(yyvsp[-2]), 0 TSRMLS_CC); ;}
    break;

  case 198:
#line 548 "php_parser.y"
    { (yyval).op_type = IS_UNUSED; ;}
    break;

  case 199:
#line 549 "php_parser.y"
    { (yyval) = (yyvsp[0]); ;}
    break;

  case 200:
#line 550 "php_parser.y"
    { (yyval).op_type = IS_CONST; (yyval).u.constant.type=IS_NULL;;}
    break;

  case 201:
#line 555 "php_parser.y"
    { (yyval) = (yyvsp[0]); ;}
    break;

  case 202:
#line 556 "php_parser.y"
    { (yyval).u.constant.value.lval = 0; ;}
    break;

  case 203:
#line 561 "php_parser.y"
    { (yyval).u.constant.value.lval = 1;  zend_do_pass_param(&(yyvsp[0]), ZEND_SEND_VAL, (yyval).u.constant.value.lval TSRMLS_CC); ;}
    break;

  case 204:
#line 562 "php_parser.y"
    { (yyval).u.constant.value.lval = 1;  zend_do_pass_param(&(yyvsp[0]), ZEND_SEND_VAR, (yyval).u.constant.value.lval TSRMLS_CC); ;}
    break;

  case 205:
#line 563 "php_parser.y"
    { (yyval).u.constant.value.lval = 1;  zend_do_pass_param(&(yyvsp[0]), ZEND_SEND_REF, (yyval).u.constant.value.lval TSRMLS_CC); ;}
    break;

  case 206:
#line 564 "php_parser.y"
    { (yyval).u.constant.value.lval=(yyvsp[-2]).u.constant.value.lval+1;  zend_do_pass_param(&(yyvsp[0]), ZEND_SEND_VAL, (yyval).u.constant.value.lval TSRMLS_CC); ;}
    break;

  case 207:
#line 565 "php_parser.y"
    { (yyval).u.constant.value.lval=(yyvsp[-2]).u.constant.value.lval+1;  zend_do_pass_param(&(yyvsp[0]), ZEND_SEND_VAR, (yyval).u.constant.value.lval TSRMLS_CC); ;}
    break;

  case 208:
#line 566 "php_parser.y"
    { (yyval).u.constant.value.lval=(yyvsp[-3]).u.constant.value.lval+1;  zend_do_pass_param(&(yyvsp[0]), ZEND_SEND_REF, (yyval).u.constant.value.lval TSRMLS_CC); ;}
    break;

  case 209:
#line 570 "php_parser.y"
    { zend_do_fetch_global_variable(&(yyvsp[0]), NULL, ZEND_FETCH_GLOBAL_LOCK TSRMLS_CC); ;}
    break;

  case 210:
#line 571 "php_parser.y"
    { zend_do_fetch_global_variable(&(yyvsp[0]), NULL, ZEND_FETCH_GLOBAL_LOCK TSRMLS_CC); ;}
    break;

  case 211:
#line 576 "php_parser.y"
    { (yyval) = (yyvsp[0]); ;}
    break;

  case 212:
#line 577 "php_parser.y"
    { (yyval) = (yyvsp[0]); ;}
    break;

  case 213:
#line 578 "php_parser.y"
    { (yyval) = (yyvsp[-1]); ;}
    break;

  case 214:
#line 583 "php_parser.y"
    { zend_do_fetch_static_variable(&(yyvsp[0]), NULL, ZEND_FETCH_STATIC TSRMLS_CC); ;}
    break;

  case 215:
#line 584 "php_parser.y"
    { zend_do_fetch_static_variable(&(yyvsp[-2]), &(yyvsp[0]), ZEND_FETCH_STATIC TSRMLS_CC); ;}
    break;

  case 216:
#line 585 "php_parser.y"
    { zend_do_fetch_static_variable(&(yyvsp[0]), NULL, ZEND_FETCH_STATIC TSRMLS_CC); ;}
    break;

  case 217:
#line 586 "php_parser.y"
    { zend_do_fetch_static_variable(&(yyvsp[-2]), &(yyvsp[0]), ZEND_FETCH_STATIC TSRMLS_CC); ;}
    break;

  case 220:
#line 598 "php_parser.y"
    { CG(access_type) = (yyvsp[0]).u.constant.value.lval; ;}
    break;

  case 224:
#line 606 "php_parser.y"
    { (yyval).u.constant.value.lval = ZEND_ACC_ABSTRACT; ;}
    break;

  case 225:
#line 607 "php_parser.y"
    { (yyval).u.constant.value.lval = 0;	;}
    break;

  case 226:
#line 611 "php_parser.y"
    { (yyval) = (yyvsp[0]); ;}
    break;

  case 227:
#line 612 "php_parser.y"
    { (yyval).u.constant.value.lval = ZEND_ACC_PUBLIC; ;}
    break;

  case 228:
#line 616 "php_parser.y"
    { (yyval).u.constant.value.lval = ZEND_ACC_PUBLIC; ;}
    break;

  case 229:
#line 617 "php_parser.y"
    { (yyval) = (yyvsp[0]);  if (!((yyval).u.constant.value.lval & ZEND_ACC_PPP_MASK)) { (yyval).u.constant.value.lval |= ZEND_ACC_PUBLIC; } ;}
    break;

  case 230:
#line 621 "php_parser.y"
    { (yyval) = (yyvsp[0]); ;}
    break;

  case 231:
#line 622 "php_parser.y"
    { (yyval).u.constant.value.lval = zend_do_verify_access_types(&(yyvsp[-1]), &(yyvsp[0])); ;}
    break;

  case 232:
#line 626 "php_parser.y"
    { (yyval).u.constant.value.lval = ZEND_ACC_PUBLIC; ;}
    break;

  case 233:
#line 627 "php_parser.y"
    { (yyval).u.constant.value.lval = ZEND_ACC_PROTECTED; ;}
    break;

  case 234:
#line 628 "php_parser.y"
    { (yyval).u.constant.value.lval = ZEND_ACC_PRIVATE; ;}
    break;

  case 235:
#line 629 "php_parser.y"
    { (yyval).u.constant.value.lval = ZEND_ACC_STATIC; ;}
    break;

  case 236:
#line 630 "php_parser.y"
    { (yyval).u.constant.value.lval = ZEND_ACC_ABSTRACT; ;}
    break;

  case 237:
#line 631 "php_parser.y"
    { (yyval).u.constant.value.lval = ZEND_ACC_FINAL; ;}
    break;

  case 238:
#line 635 "php_parser.y"
    { zend_do_declare_property(&(yyvsp[0]), NULL, CG(access_type) TSRMLS_CC); ;}
    break;

  case 239:
#line 636 "php_parser.y"
    { zend_do_declare_property(&(yyvsp[-2]), &(yyvsp[0]), CG(access_type) TSRMLS_CC); ;}
    break;

  case 240:
#line 637 "php_parser.y"
    { zend_do_declare_property(&(yyvsp[0]), NULL, CG(access_type) TSRMLS_CC); ;}
    break;

  case 241:
#line 638 "php_parser.y"
    { zend_do_declare_property(&(yyvsp[-2]), &(yyvsp[0]), CG(access_type) TSRMLS_CC); ;}
    break;

  case 242:
#line 642 "php_parser.y"
    { zend_do_declare_class_constant(&(yyvsp[-2]), &(yyvsp[0]) TSRMLS_CC); ;}
    break;

  case 243:
#line 643 "php_parser.y"
    { zend_do_declare_class_constant(&(yyvsp[-2]), &(yyvsp[0]) TSRMLS_CC); ;}
    break;

  case 244:
#line 647 "php_parser.y"
    { zend_do_echo(&(yyvsp[0]) TSRMLS_CC); ;}
    break;

  case 245:
#line 648 "php_parser.y"
    { zend_do_echo(&(yyvsp[0]) TSRMLS_CC); ;}
    break;

  case 246:
#line 653 "php_parser.y"
    { (yyval).op_type = IS_CONST;  (yyval).u.constant.type = IS_BOOL;  (yyval).u.constant.value.lval = 1; ;}
    break;

  case 247:
#line 654 "php_parser.y"
    { (yyval) = (yyvsp[0]); ;}
    break;

  case 248:
#line 658 "php_parser.y"
    { zend_do_free(&(yyvsp[-1]) TSRMLS_CC); ;}
    break;

  case 249:
#line 658 "php_parser.y"
    { (yyval) = (yyvsp[0]); ;}
    break;

  case 250:
#line 659 "php_parser.y"
    { (yyval) = (yyvsp[0]); ;}
    break;

  case 251:
#line 663 "php_parser.y"
    { zend_do_list_init(TSRMLS_C); ;}
    break;

  case 252:
#line 663 "php_parser.y"
    { zend_do_list_end(&(yyval), &(yyvsp[0]) TSRMLS_CC); ;}
    break;

  case 253:
#line 664 "php_parser.y"
    { zend_check_writable_variable(&(yyvsp[-2])); zend_do_end_variable_parse(BP_VAR_W, 0 TSRMLS_CC); zend_do_assign(&(yyval), &(yyvsp[-2]), &(yyvsp[0]) TSRMLS_CC); ;}
    break;

  case 254:
#line 665 "php_parser.y"
    { zend_check_writable_variable(&(yyvsp[-3])); zend_do_end_variable_parse(BP_VAR_W, 0 TSRMLS_CC); zend_do_end_variable_parse(BP_VAR_W, 0 TSRMLS_CC); zend_do_assign_ref(&(yyval), &(yyvsp[-3]), &(yyvsp[0]) TSRMLS_CC); ;}
    break;

  case 255:
#line 666 "php_parser.y"
    { zend_error(E_STRICT, "Assigning the return value of new by reference is deprecated");  zend_check_writable_variable(&(yyvsp[-4])); zend_do_extended_fcall_begin(TSRMLS_C); zend_do_begin_new_object(&(yyvsp[-1]), &(yyvsp[0]) TSRMLS_CC); ;}
    break;

  case 256:
#line 666 "php_parser.y"
    { zend_do_end_new_object(&(yyvsp[-4]), &(yyvsp[-3]), &(yyvsp[0]) TSRMLS_CC); zend_do_extended_fcall_end(TSRMLS_C); zend_do_end_variable_parse(BP_VAR_W, 0 TSRMLS_CC); zend_do_assign_ref(&(yyval), &(yyvsp[-6]), &(yyvsp[-4]) TSRMLS_CC); ;}
    break;

  case 257:
#line 667 "php_parser.y"
    { zend_do_extended_fcall_begin(TSRMLS_C); zend_do_begin_new_object(&(yyvsp[-1]), &(yyvsp[0]) TSRMLS_CC); ;}
    break;

  case 258:
#line 667 "php_parser.y"
    { zend_do_end_new_object(&(yyval), &(yyvsp[-3]), &(yyvsp[0]) TSRMLS_CC); zend_do_extended_fcall_end(TSRMLS_C);;}
    break;

  case 259:
#line 668 "php_parser.y"
    { zend_do_clone(&(yyval), &(yyvsp[0]) TSRMLS_CC); ;}
    break;

  case 260:
#line 669 "php_parser.y"
    { zend_check_writable_variable(&(yyvsp[-2])); zend_do_end_variable_parse(BP_VAR_RW, 0 TSRMLS_CC); zend_do_binary_assign_op(ZEND_ASSIGN_ADD, &(yyval), &(yyvsp[-2]), &(yyvsp[0]) TSRMLS_CC); ;}
    break;

  case 261:
#line 670 "php_parser.y"
    { zend_check_writable_variable(&(yyvsp[-2])); zend_do_end_variable_parse(BP_VAR_RW, 0 TSRMLS_CC); zend_do_binary_assign_op(ZEND_ASSIGN_SUB, &(yyval), &(yyvsp[-2]), &(yyvsp[0]) TSRMLS_CC); ;}
    break;

  case 262:
#line 671 "php_parser.y"
    { zend_check_writable_variable(&(yyvsp[-2])); zend_do_end_variable_parse(BP_VAR_RW, 0 TSRMLS_CC); zend_do_binary_assign_op(ZEND_ASSIGN_MUL, &(yyval), &(yyvsp[-2]), &(yyvsp[0]) TSRMLS_CC); ;}
    break;

  case 263:
#line 672 "php_parser.y"
    { zend_check_writable_variable(&(yyvsp[-2])); zend_do_end_variable_parse(BP_VAR_RW, 0 TSRMLS_CC); zend_do_binary_assign_op(ZEND_ASSIGN_DIV, &(yyval), &(yyvsp[-2]), &(yyvsp[0]) TSRMLS_CC); ;}
    break;

  case 264:
#line 673 "php_parser.y"
    { zend_check_writable_variable(&(yyvsp[-2])); zend_do_end_variable_parse(BP_VAR_RW, 0 TSRMLS_CC); zend_do_binary_assign_op(ZEND_ASSIGN_CONCAT, &(yyval), &(yyvsp[-2]), &(yyvsp[0]) TSRMLS_CC); ;}
    break;

  case 265:
#line 674 "php_parser.y"
    { zend_check_writable_variable(&(yyvsp[-2])); zend_do_end_variable_parse(BP_VAR_RW, 0 TSRMLS_CC); zend_do_binary_assign_op(ZEND_ASSIGN_MOD, &(yyval), &(yyvsp[-2]), &(yyvsp[0]) TSRMLS_CC); ;}
    break;

  case 266:
#line 675 "php_parser.y"
    { zend_check_writable_variable(&(yyvsp[-2])); zend_do_end_variable_parse(BP_VAR_RW, 0 TSRMLS_CC); zend_do_binary_assign_op(ZEND_ASSIGN_BW_AND, &(yyval), &(yyvsp[-2]), &(yyvsp[0]) TSRMLS_CC); ;}
    break;

  case 267:
#line 676 "php_parser.y"
    { zend_check_writable_variable(&(yyvsp[-2])); zend_do_end_variable_parse(BP_VAR_RW, 0 TSRMLS_CC); zend_do_binary_assign_op(ZEND_ASSIGN_BW_OR, &(yyval), &(yyvsp[-2]), &(yyvsp[0]) TSRMLS_CC); ;}
    break;

  case 268:
#line 677 "php_parser.y"
    { zend_check_writable_variable(&(yyvsp[-2])); zend_do_end_variable_parse(BP_VAR_RW, 0 TSRMLS_CC); zend_do_binary_assign_op(ZEND_ASSIGN_BW_XOR, &(yyval), &(yyvsp[-2]), &(yyvsp[0]) TSRMLS_CC); ;}
    break;

  case 269:
#line 678 "php_parser.y"
    { zend_check_writable_variable(&(yyvsp[-2])); zend_do_end_variable_parse(BP_VAR_RW, 0 TSRMLS_CC); zend_do_binary_assign_op(ZEND_ASSIGN_SL, &(yyval), &(yyvsp[-2]), &(yyvsp[0]) TSRMLS_CC); ;}
    break;

  case 270:
#line 679 "php_parser.y"
    { zend_check_writable_variable(&(yyvsp[-2])); zend_do_end_variable_parse(BP_VAR_RW, 0 TSRMLS_CC); zend_do_binary_assign_op(ZEND_ASSIGN_SR, &(yyval), &(yyvsp[-2]), &(yyvsp[0]) TSRMLS_CC); ;}
    break;

  case 271:
#line 680 "php_parser.y"
    { zend_do_post_incdec(&(yyval), &(yyvsp[-1]), ZEND_POST_INC TSRMLS_CC); ;}
    break;

  case 272:
#line 681 "php_parser.y"
    { zend_do_pre_incdec(&(yyval), &(yyvsp[0]), ZEND_PRE_INC TSRMLS_CC); ;}
    break;

  case 273:
#line 682 "php_parser.y"
    { zend_do_post_incdec(&(yyval), &(yyvsp[-1]), ZEND_POST_DEC TSRMLS_CC); ;}
    break;

  case 274:
#line 683 "php_parser.y"
    { zend_do_pre_incdec(&(yyval), &(yyvsp[0]), ZEND_PRE_DEC TSRMLS_CC); ;}
    break;

  case 275:
#line 684 "php_parser.y"
    { zend_do_boolean_or_begin(&(yyvsp[-1]), &(yyvsp[0]) TSRMLS_CC); ;}
    break;

  case 276:
#line 684 "php_parser.y"
    { zend_do_boolean_or_end(&(yyval), &(yyvsp[-3]), &(yyvsp[0]), &(yyvsp[-2]) TSRMLS_CC); ;}
    break;

  case 277:
#line 685 "php_parser.y"
    { zend_do_boolean_and_begin(&(yyvsp[-1]), &(yyvsp[0]) TSRMLS_CC); ;}
    break;

  case 278:
#line 685 "php_parser.y"
    { zend_do_boolean_and_end(&(yyval), &(yyvsp[-3]), &(yyvsp[0]), &(yyvsp[-2]) TSRMLS_CC); ;}
    break;

  case 279:
#line 686 "php_parser.y"
    { zend_do_boolean_or_begin(&(yyvsp[-1]), &(yyvsp[0]) TSRMLS_CC); ;}
    break;

  case 280:
#line 686 "php_parser.y"
    { zend_do_boolean_or_end(&(yyval), &(yyvsp[-3]), &(yyvsp[0]), &(yyvsp[-2]) TSRMLS_CC); ;}
    break;

  case 281:
#line 687 "php_parser.y"
    { zend_do_boolean_and_begin(&(yyvsp[-1]), &(yyvsp[0]) TSRMLS_CC); ;}
    break;

  case 282:
#line 687 "php_parser.y"
    { zend_do_boolean_and_end(&(yyval), &(yyvsp[-3]), &(yyvsp[0]), &(yyvsp[-2]) TSRMLS_CC); ;}
    break;

  case 283:
#line 688 "php_parser.y"
    { zend_do_binary_op(ZEND_BOOL_XOR, &(yyval), &(yyvsp[-2]), &(yyvsp[0]) TSRMLS_CC); ;}
    break;

  case 284:
#line 689 "php_parser.y"
    { zend_do_binary_op(ZEND_BW_OR, &(yyval), &(yyvsp[-2]), &(yyvsp[0]) TSRMLS_CC); ;}
    break;

  case 285:
#line 690 "php_parser.y"
    { zend_do_binary_op(ZEND_BW_AND, &(yyval), &(yyvsp[-2]), &(yyvsp[0]) TSRMLS_CC); ;}
    break;

  case 286:
#line 691 "php_parser.y"
    { zend_do_binary_op(ZEND_BW_XOR, &(yyval), &(yyvsp[-2]), &(yyvsp[0]) TSRMLS_CC); ;}
    break;

  case 287:
#line 692 "php_parser.y"
    { zend_do_binary_op(ZEND_CONCAT, &(yyval), &(yyvsp[-2]), &(yyvsp[0]) TSRMLS_CC); ;}
    break;

  case 288:
#line 693 "php_parser.y"
    { zend_do_binary_op(ZEND_ADD, &(yyval), &(yyvsp[-2]), &(yyvsp[0]) TSRMLS_CC); ;}
    break;

  case 289:
#line 694 "php_parser.y"
    { zend_do_binary_op(ZEND_SUB, &(yyval), &(yyvsp[-2]), &(yyvsp[0]) TSRMLS_CC); ;}
    break;

  case 290:
#line 695 "php_parser.y"
    { zend_do_binary_op(ZEND_MUL, &(yyval), &(yyvsp[-2]), &(yyvsp[0]) TSRMLS_CC); ;}
    break;

  case 291:
#line 696 "php_parser.y"
    { zend_do_binary_op(ZEND_DIV, &(yyval), &(yyvsp[-2]), &(yyvsp[0]) TSRMLS_CC); ;}
    break;

  case 292:
#line 697 "php_parser.y"
    { zend_do_binary_op(ZEND_MOD, &(yyval), &(yyvsp[-2]), &(yyvsp[0]) TSRMLS_CC); ;}
    break;

  case 293:
#line 698 "php_parser.y"
    { zend_do_binary_op(ZEND_SL, &(yyval), &(yyvsp[-2]), &(yyvsp[0]) TSRMLS_CC); ;}
    break;

  case 294:
#line 699 "php_parser.y"
    { zend_do_binary_op(ZEND_SR, &(yyval), &(yyvsp[-2]), &(yyvsp[0]) TSRMLS_CC); ;}
    break;

  case 295:
#line 700 "php_parser.y"
    { (yyvsp[-1]).u.constant.value.lval=0; (yyvsp[-1]).u.constant.type=IS_LONG; (yyvsp[-1]).op_type = IS_CONST; INIT_PZVAL(&(yyvsp[-1]).u.constant); zend_do_binary_op(ZEND_ADD, &(yyval), &(yyvsp[-1]), &(yyvsp[0]) TSRMLS_CC); ;}
    break;

  case 296:
#line 701 "php_parser.y"
    { (yyvsp[-1]).u.constant.value.lval=0; (yyvsp[-1]).u.constant.type=IS_LONG; (yyvsp[-1]).op_type = IS_CONST; INIT_PZVAL(&(yyvsp[-1]).u.constant); zend_do_binary_op(ZEND_SUB, &(yyval), &(yyvsp[-1]), &(yyvsp[0]) TSRMLS_CC); ;}
    break;

  case 297:
#line 702 "php_parser.y"
    { zend_do_unary_op(ZEND_BOOL_NOT, &(yyval), &(yyvsp[0]) TSRMLS_CC); ;}
    break;

  case 298:
#line 703 "php_parser.y"
    { zend_do_unary_op(ZEND_BW_NOT, &(yyval), &(yyvsp[0]) TSRMLS_CC); ;}
    break;

  case 299:
#line 704 "php_parser.y"
    { zend_do_binary_op(ZEND_IS_IDENTICAL, &(yyval), &(yyvsp[-2]), &(yyvsp[0]) TSRMLS_CC); ;}
    break;

  case 300:
#line 705 "php_parser.y"
    { zend_do_binary_op(ZEND_IS_NOT_IDENTICAL, &(yyval), &(yyvsp[-2]), &(yyvsp[0]) TSRMLS_CC); ;}
    break;

  case 301:
#line 706 "php_parser.y"
    { zend_do_binary_op(ZEND_IS_EQUAL, &(yyval), &(yyvsp[-2]), &(yyvsp[0]) TSRMLS_CC); ;}
    break;

  case 302:
#line 707 "php_parser.y"
    { zend_do_binary_op(ZEND_IS_NOT_EQUAL, &(yyval), &(yyvsp[-2]), &(yyvsp[0]) TSRMLS_CC); ;}
    break;

  case 303:
#line 708 "php_parser.y"
    { zend_do_binary_op(ZEND_IS_SMALLER, &(yyval), &(yyvsp[-2]), &(yyvsp[0]) TSRMLS_CC); ;}
    break;

  case 304:
#line 709 "php_parser.y"
    { zend_do_binary_op(ZEND_IS_SMALLER_OR_EQUAL, &(yyval), &(yyvsp[-2]), &(yyvsp[0]) TSRMLS_CC); ;}
    break;

  case 305:
#line 710 "php_parser.y"
    { zend_do_binary_op(ZEND_IS_SMALLER, &(yyval), &(yyvsp[0]), &(yyvsp[-2]) TSRMLS_CC); ;}
    break;

  case 306:
#line 711 "php_parser.y"
    { zend_do_binary_op(ZEND_IS_SMALLER_OR_EQUAL, &(yyval), &(yyvsp[0]), &(yyvsp[-2]) TSRMLS_CC); ;}
    break;

  case 307:
#line 712 "php_parser.y"
    { zend_do_instanceof(&(yyval), &(yyvsp[-2]), &(yyvsp[0]), 0 TSRMLS_CC); ;}
    break;

  case 308:
#line 713 "php_parser.y"
    { (yyval) = (yyvsp[-1]); ;}
    break;

  case 309:
#line 714 "php_parser.y"
    { zend_do_begin_qm_op(&(yyvsp[-1]), &(yyvsp[0]) TSRMLS_CC); ;}
    break;

  case 310:
#line 715 "php_parser.y"
    { zend_do_qm_true(&(yyvsp[-1]), &(yyvsp[-3]), &(yyvsp[0]) TSRMLS_CC); ;}
    break;

  case 311:
#line 716 "php_parser.y"
    { zend_do_qm_false(&(yyval), &(yyvsp[0]), &(yyvsp[-5]), &(yyvsp[-2]) TSRMLS_CC); ;}
    break;

  case 312:
#line 717 "php_parser.y"
    { (yyval) = (yyvsp[0]); ;}
    break;

  case 313:
#line 718 "php_parser.y"
    { zend_do_cast(&(yyval), &(yyvsp[0]), IS_LONG TSRMLS_CC); ;}
    break;

  case 314:
#line 719 "php_parser.y"
    { zend_do_cast(&(yyval), &(yyvsp[0]), IS_DOUBLE TSRMLS_CC); ;}
    break;

  case 315:
#line 720 "php_parser.y"
    { zend_do_cast(&(yyval), &(yyvsp[0]), IS_STRING TSRMLS_CC); ;}
    break;

  case 316:
#line 721 "php_parser.y"
    { zend_do_cast(&(yyval), &(yyvsp[0]), IS_ARRAY TSRMLS_CC); ;}
    break;

  case 317:
#line 722 "php_parser.y"
    { zend_do_cast(&(yyval), &(yyvsp[0]), IS_OBJECT TSRMLS_CC); ;}
    break;

  case 318:
#line 723 "php_parser.y"
    { zend_do_cast(&(yyval), &(yyvsp[0]), IS_BOOL TSRMLS_CC); ;}
    break;

  case 319:
#line 724 "php_parser.y"
    { zend_do_cast(&(yyval), &(yyvsp[0]), IS_NULL TSRMLS_CC); ;}
    break;

  case 320:
#line 725 "php_parser.y"
    { zend_do_exit(&(yyval), &(yyvsp[0]) TSRMLS_CC); ;}
    break;

  case 321:
#line 726 "php_parser.y"
    { zend_do_begin_silence(&(yyvsp[0]) TSRMLS_CC); ;}
    break;

  case 322:
#line 726 "php_parser.y"
    { zend_do_end_silence(&(yyvsp[-2]) TSRMLS_CC); (yyval) = (yyvsp[0]); ;}
    break;

  case 323:
#line 727 "php_parser.y"
    { (yyval) = (yyvsp[0]); ;}
    break;

  case 324:
#line 728 "php_parser.y"
    { (yyval) = (yyvsp[-1]); ;}
    break;

  case 325:
#line 729 "php_parser.y"
    { zend_do_shell_exec(&(yyval), &(yyvsp[-1]) TSRMLS_CC); ;}
    break;

  case 326:
#line 730 "php_parser.y"
    { zend_do_print(&(yyval), &(yyvsp[0]) TSRMLS_CC); ;}
    break;

  case 327:
#line 734 "php_parser.y"
    { (yyvsp[0]).u.opline_num = zend_do_begin_function_call(&(yyvsp[-1]) TSRMLS_CC); ;}
    break;

  case 328:
#line 736 "php_parser.y"
    { zend_do_end_function_call(&(yyvsp[-4]), &(yyval), &(yyvsp[-1]), 0, (yyvsp[-3]).u.opline_num TSRMLS_CC); zend_do_extended_fcall_end(TSRMLS_C); ;}
    break;

  case 329:
#line 737 "php_parser.y"
    { zend_do_begin_class_member_function_call(&(yyvsp[-3]), &(yyvsp[-1]) TSRMLS_CC); ;}
    break;

  case 330:
#line 739 "php_parser.y"
    { zend_do_end_function_call(NULL, &(yyval), &(yyvsp[-1]), 1, 1 TSRMLS_CC); zend_do_extended_fcall_end(TSRMLS_C);;}
    break;

  case 331:
#line 740 "php_parser.y"
    { zend_do_end_variable_parse(BP_VAR_R, 0 TSRMLS_CC); zend_do_begin_class_member_function_call(&(yyvsp[-3]), &(yyvsp[-1]) TSRMLS_CC); ;}
    break;

  case 332:
#line 742 "php_parser.y"
    { zend_do_end_function_call(NULL, &(yyval), &(yyvsp[-1]), 1, 1 TSRMLS_CC); zend_do_extended_fcall_end(TSRMLS_C);;}
    break;

  case 333:
#line 743 "php_parser.y"
    { zend_do_end_variable_parse(BP_VAR_R, 0 TSRMLS_CC); zend_do_begin_dynamic_function_call(&(yyvsp[-1]) TSRMLS_CC); ;}
    break;

  case 334:
#line 745 "php_parser.y"
    { zend_do_end_function_call(&(yyvsp[-4]), &(yyval), &(yyvsp[-1]), 0, 1 TSRMLS_CC); zend_do_extended_fcall_end(TSRMLS_C);;}
    break;

  case 335:
#line 749 "php_parser.y"
    { zend_do_fetch_class(&(yyval), &(yyvsp[0]) TSRMLS_CC); ;}
    break;

  case 336:
#line 753 "php_parser.y"
    { zend_do_fetch_class(&(yyval), &(yyvsp[0]) TSRMLS_CC); ;}
    break;

  case 337:
#line 754 "php_parser.y"
    { zend_do_end_variable_parse(BP_VAR_R, 0 TSRMLS_CC); zend_do_fetch_class(&(yyval), &(yyvsp[0]) TSRMLS_CC); ;}
    break;

  case 338:
#line 759 "php_parser.y"
    { zend_do_push_object(&(yyvsp[-1]) TSRMLS_CC); ;}
    break;

  case 339:
#line 760 "php_parser.y"
    { zend_do_push_object(&(yyvsp[0]) TSRMLS_CC); zend_do_declare_implicit_property(TSRMLS_C); ;}
    break;

  case 340:
#line 761 "php_parser.y"
    { zend_do_pop_object(&(yyval) TSRMLS_CC); (yyval).u.EA.type = ZEND_PARSED_MEMBER; ;}
    break;

  case 341:
#line 762 "php_parser.y"
    { (yyval) = (yyvsp[0]); ;}
    break;

  case 344:
#line 773 "php_parser.y"
    { zend_do_push_object(&(yyvsp[0]) TSRMLS_CC); zend_do_declare_implicit_property(TSRMLS_C); ;}
    break;

  case 345:
#line 777 "php_parser.y"
    { memset(&(yyval), 0, sizeof(znode)); (yyval).op_type = IS_UNUSED; ;}
    break;

  case 346:
#line 778 "php_parser.y"
    { memset(&(yyval), 0, sizeof(znode)); (yyval).op_type = IS_UNUSED; ;}
    break;

  case 347:
#line 779 "php_parser.y"
    { (yyval) = (yyvsp[-1]); ;}
    break;

  case 348:
#line 784 "php_parser.y"
    { (yyval).u.constant.value.lval=0; ;}
    break;

  case 349:
#line 785 "php_parser.y"
    { (yyval) = (yyvsp[-1]); ;}
    break;

  case 350:
#line 790 "php_parser.y"
    { (yyval) = (yyvsp[0]); ;}
    break;

  case 351:
#line 791 "php_parser.y"
    { (yyval) = (yyvsp[0]); ;}
    break;

  case 352:
#line 792 "php_parser.y"
    { (yyval) = (yyvsp[0]); ;}
    break;

  case 353:
#line 793 "php_parser.y"
    { (yyval) = (yyvsp[0]); ;}
    break;

  case 354:
#line 794 "php_parser.y"
    { (yyval) = (yyvsp[0]); ;}
    break;

  case 355:
#line 795 "php_parser.y"
    { (yyval) = (yyvsp[0]); ;}
    break;

  case 356:
#line 796 "php_parser.y"
    { (yyval) = (yyvsp[0]); ;}
    break;

  case 357:
#line 797 "php_parser.y"
    { (yyval) = (yyvsp[0]); ;}
    break;

  case 358:
#line 802 "php_parser.y"
    { (yyval) = (yyvsp[0]); ;}
    break;

  case 359:
#line 803 "php_parser.y"
    { zend_do_fetch_constant(&(yyval), NULL, &(yyvsp[0]), ZEND_CT TSRMLS_CC); ;}
    break;

  case 360:
#line 804 "php_parser.y"
    { (yyval) = (yyvsp[0]); ;}
    break;

  case 361:
#line 805 "php_parser.y"
    { zval minus_one;  minus_one.type = IS_LONG; minus_one.value.lval = -1;  mul_function(&(yyvsp[0]).u.constant, &(yyvsp[0]).u.constant, &minus_one TSRMLS_CC);  (yyval) = (yyvsp[0]); ;}
    break;

  case 362:
#line 806 "php_parser.y"
    { (yyval) = (yyvsp[-1]); (yyval).u.constant.type = IS_CONSTANT_ARRAY; ;}
    break;

  case 363:
#line 807 "php_parser.y"
    { (yyval) = (yyvsp[0]); ;}
    break;

  case 364:
#line 811 "php_parser.y"
    { zend_do_fetch_constant(&(yyval), &(yyvsp[-2]), &(yyvsp[0]), ZEND_CT TSRMLS_CC); ;}
    break;

  case 365:
#line 815 "php_parser.y"
    { zend_do_fetch_constant(&(yyval), NULL, &(yyvsp[0]), ZEND_RT TSRMLS_CC); ;}
    break;

  case 366:
#line 816 "php_parser.y"
    { (yyval) = (yyvsp[0]); ;}
    break;

  case 367:
#line 817 "php_parser.y"
    { (yyval) = (yyvsp[0]); ;}
    break;

  case 368:
#line 818 "php_parser.y"
    { (yyval) = (yyvsp[0]); ;}
    break;

  case 369:
#line 819 "php_parser.y"
    { (yyval) = (yyvsp[-1]); ;}
    break;

  case 370:
#line 820 "php_parser.y"
    { (yyval) = (yyvsp[-1]); ;}
    break;

  case 371:
#line 821 "php_parser.y"
    { (yyval) = (yyvsp[-1]); zend_do_end_heredoc(TSRMLS_C); ;}
    break;

  case 372:
#line 826 "php_parser.y"
    { (yyval).op_type = IS_CONST; INIT_PZVAL(&(yyval).u.constant); array_init(&(yyval).u.constant); ;}
    break;

  case 373:
#line 827 "php_parser.y"
    { (yyval) = (yyvsp[-1]); ;}
    break;

  case 376:
#line 836 "php_parser.y"
    { zend_do_add_static_array_element(&(yyval), &(yyvsp[-2]), &(yyvsp[0])); ;}
    break;

  case 377:
#line 837 "php_parser.y"
    { zend_do_add_static_array_element(&(yyval), NULL, &(yyvsp[0])); ;}
    break;

  case 378:
#line 838 "php_parser.y"
    { (yyval).op_type = IS_CONST; INIT_PZVAL(&(yyval).u.constant); array_init(&(yyval).u.constant); zend_do_add_static_array_element(&(yyval), &(yyvsp[-2]), &(yyvsp[0])); ;}
    break;

  case 379:
#line 839 "php_parser.y"
    { (yyval).op_type = IS_CONST; INIT_PZVAL(&(yyval).u.constant); array_init(&(yyval).u.constant); zend_do_add_static_array_element(&(yyval), NULL, &(yyvsp[0])); ;}
    break;

  case 380:
#line 843 "php_parser.y"
    { (yyval) = (yyvsp[0]); ;}
    break;

  case 381:
#line 844 "php_parser.y"
    { (yyval) = (yyvsp[0]); ;}
    break;

  case 382:
#line 849 "php_parser.y"
    { zend_do_end_variable_parse(BP_VAR_R, 0 TSRMLS_CC); (yyval) = (yyvsp[0]); ;}
    break;

  case 383:
#line 854 "php_parser.y"
    { zend_do_end_variable_parse(BP_VAR_W, 0 TSRMLS_CC); (yyval) = (yyvsp[0]); ;}
    break;

  case 384:
#line 855 "php_parser.y"
    { zend_check_writable_variable(&(yyvsp[-1])); ;}
    break;

  case 385:
#line 859 "php_parser.y"
    { zend_do_end_variable_parse(BP_VAR_RW, 0 TSRMLS_CC); (yyval) = (yyvsp[0]); ;}
    break;

  case 386:
#line 860 "php_parser.y"
    { zend_check_writable_variable(&(yyvsp[-1])); ;}
    break;

  case 387:
#line 864 "php_parser.y"
    { zend_do_push_object(&(yyvsp[-1]) TSRMLS_CC); ;}
    break;

  case 388:
#line 865 "php_parser.y"
    { zend_do_push_object(&(yyvsp[0]) TSRMLS_CC); ;}
    break;

  case 389:
#line 866 "php_parser.y"
    { zend_do_pop_object(&(yyval) TSRMLS_CC); (yyval).u.EA.type = (yyvsp[-6]).u.EA.type | ((yyvsp[0]).u.EA.type ? (yyvsp[0]).u.EA.type : (yyvsp[-1]).u.EA.type); ;}
    break;

  case 390:
#line 867 "php_parser.y"
    { (yyval) = (yyvsp[0]); ;}
    break;

  case 391:
#line 871 "php_parser.y"
    { (yyval).u.EA.type = (yyvsp[0]).u.EA.type; ;}
    break;

  case 392:
#line 872 "php_parser.y"
    { (yyval).u.EA.type = 0; ;}
    break;

  case 393:
#line 877 "php_parser.y"
    { zend_do_push_object(&(yyvsp[0]) TSRMLS_CC); ;}
    break;

  case 394:
#line 877 "php_parser.y"
    { (yyval).u.EA.type = (yyvsp[0]).u.EA.type; ;}
    break;

  case 395:
#line 881 "php_parser.y"
    { zend_do_pop_object(&(yyvsp[0]) TSRMLS_CC); zend_do_begin_method_call(&(yyvsp[0]) TSRMLS_CC); ;}
    break;

  case 396:
#line 883 "php_parser.y"
    { zend_do_end_function_call(&(yyvsp[-3]), &(yyval), &(yyvsp[-1]), 1, 1 TSRMLS_CC); zend_do_extended_fcall_end(TSRMLS_C);
			  zend_do_push_object(&(yyval) TSRMLS_CC); (yyval).u.EA.type = ZEND_PARSED_METHOD_CALL; ;}
    break;

  case 397:
#line 885 "php_parser.y"
    { zend_do_declare_implicit_property(TSRMLS_C); (yyval).u.EA.type = ZEND_PARSED_MEMBER; ;}
    break;

  case 398:
#line 889 "php_parser.y"
    { (yyval) = (yyvsp[0]); ;}
    break;

  case 399:
#line 890 "php_parser.y"
    { zend_do_indirect_references(&(yyval), &(yyvsp[-1]), &(yyvsp[0]) TSRMLS_CC); ;}
    break;

  case 400:
#line 894 "php_parser.y"
    { (yyval) = (yyvsp[0]); zend_do_fetch_static_member(&(yyval), &(yyvsp[-2]) TSRMLS_CC); ;}
    break;

  case 401:
#line 899 "php_parser.y"
    { (yyval) = (yyvsp[0]); ;}
    break;

  case 402:
#line 900 "php_parser.y"
    { zend_do_begin_variable_parse(TSRMLS_C); (yyval) = (yyvsp[0]); (yyval).u.EA.type = ZEND_PARSED_FUNCTION_CALL; ;}
    break;

  case 403:
#line 905 "php_parser.y"
    { (yyval) = (yyvsp[0]); (yyval).u.EA.type = ZEND_PARSED_VARIABLE; ;}
    break;

  case 404:
#line 906 "php_parser.y"
    { zend_do_indirect_references(&(yyval), &(yyvsp[-1]), &(yyvsp[0]) TSRMLS_CC); (yyval).u.EA.type = ZEND_PARSED_VARIABLE; ;}
    break;

  case 405:
#line 907 "php_parser.y"
    { (yyval) = (yyvsp[0]); (yyval).u.EA.type = ZEND_PARSED_STATIC_MEMBER; ;}
    break;

  case 406:
#line 911 "php_parser.y"
    { fetch_array_dim(&(yyval), &(yyvsp[-3]), &(yyvsp[-1]) TSRMLS_CC); ;}
    break;

  case 407:
#line 912 "php_parser.y"
    { fetch_string_offset(&(yyval), &(yyvsp[-3]), &(yyvsp[-1]) TSRMLS_CC); ;}
    break;

  case 408:
#line 913 "php_parser.y"
    { zend_do_begin_variable_parse(TSRMLS_C); fetch_simple_variable(&(yyval), &(yyvsp[0]), 1 TSRMLS_CC); ;}
    break;

  case 409:
#line 918 "php_parser.y"
    { (yyval) = (yyvsp[0]); ;}
    break;

  case 410:
#line 919 "php_parser.y"
    { (yyval) = (yyvsp[-1]); ;}
    break;

  case 411:
#line 923 "php_parser.y"
    { (yyval).op_type = IS_UNUSED; ;}
    break;

  case 412:
#line 924 "php_parser.y"
    { (yyval) = (yyvsp[0]); ;}
    break;

  case 413:
#line 929 "php_parser.y"
    { (yyval) = (yyvsp[0]); ;}
    break;

  case 414:
#line 930 "php_parser.y"
    { zend_do_end_variable_parse(BP_VAR_R, 0 TSRMLS_CC); ;}
    break;

  case 415:
#line 930 "php_parser.y"
    { znode tmp_znode;  zend_do_pop_object(&tmp_znode TSRMLS_CC);  zend_do_fetch_property(&(yyval), &tmp_znode, &(yyvsp[-1]) TSRMLS_CC);;}
    break;

  case 416:
#line 934 "php_parser.y"
    { fetch_array_dim(&(yyval), &(yyvsp[-3]), &(yyvsp[-1]) TSRMLS_CC); ;}
    break;

  case 417:
#line 935 "php_parser.y"
    { fetch_string_offset(&(yyval), &(yyvsp[-3]), &(yyvsp[-1]) TSRMLS_CC); ;}
    break;

  case 418:
#line 936 "php_parser.y"
    { znode tmp_znode;  zend_do_pop_object(&tmp_znode TSRMLS_CC);  zend_do_fetch_property(&(yyval), &tmp_znode, &(yyvsp[0]) TSRMLS_CC);;}
    break;

  case 419:
#line 940 "php_parser.y"
    { (yyval) = (yyvsp[0]); ;}
    break;

  case 420:
#line 941 "php_parser.y"
    { (yyval) = (yyvsp[-1]); ;}
    break;

  case 421:
#line 945 "php_parser.y"
    { (yyval).u.constant.value.lval = 1; ;}
    break;

  case 422:
#line 946 "php_parser.y"
    { (yyval).u.constant.value.lval++; ;}
    break;

  case 425:
#line 956 "php_parser.y"
    { zend_do_add_list_element(&(yyvsp[0]) TSRMLS_CC); ;}
    break;

  case 426:
#line 957 "php_parser.y"
    { zend_do_new_list_begin(TSRMLS_C); ;}
    break;

  case 427:
#line 957 "php_parser.y"
    { zend_do_new_list_end(TSRMLS_C); ;}
    break;

  case 428:
#line 958 "php_parser.y"
    { zend_do_add_list_element(NULL TSRMLS_CC); ;}
    break;

  case 429:
#line 963 "php_parser.y"
    { zend_do_init_array(&(yyval), NULL, NULL, 0 TSRMLS_CC); ;}
    break;

  case 430:
#line 964 "php_parser.y"
    { (yyval) = (yyvsp[-1]); ;}
    break;

  case 431:
#line 968 "php_parser.y"
    { zend_do_add_array_element(&(yyval), &(yyvsp[0]), &(yyvsp[-2]), 0 TSRMLS_CC); ;}
    break;

  case 432:
#line 969 "php_parser.y"
    { zend_do_add_array_element(&(yyval), &(yyvsp[0]), NULL, 0 TSRMLS_CC); ;}
    break;

  case 433:
#line 970 "php_parser.y"
    { zend_do_init_array(&(yyval), &(yyvsp[0]), &(yyvsp[-2]), 0 TSRMLS_CC); ;}
    break;

  case 434:
#line 971 "php_parser.y"
    { zend_do_init_array(&(yyval), &(yyvsp[0]), NULL, 0 TSRMLS_CC); ;}
    break;

  case 435:
#line 972 "php_parser.y"
    { zend_do_add_array_element(&(yyval), &(yyvsp[0]), &(yyvsp[-3]), 1 TSRMLS_CC); ;}
    break;

  case 436:
#line 973 "php_parser.y"
    { zend_do_add_array_element(&(yyval), &(yyvsp[0]), NULL, 1 TSRMLS_CC); ;}
    break;

  case 437:
#line 974 "php_parser.y"
    { zend_do_init_array(&(yyval), &(yyvsp[0]), &(yyvsp[-3]), 1 TSRMLS_CC); ;}
    break;

  case 438:
#line 975 "php_parser.y"
    { zend_do_init_array(&(yyval), &(yyvsp[0]), NULL, 1 TSRMLS_CC); ;}
    break;

  case 439:
#line 979 "php_parser.y"
    { zend_do_end_variable_parse(BP_VAR_R, 0 TSRMLS_CC);  zend_do_add_variable(&(yyval), &(yyvsp[-1]), &(yyvsp[0]) TSRMLS_CC); ;}
    break;

  case 440:
#line 980 "php_parser.y"
    { zend_do_add_string(&(yyval), &(yyvsp[-1]), &(yyvsp[0]) TSRMLS_CC); ;}
    break;

  case 441:
#line 981 "php_parser.y"
    { zend_do_add_string(&(yyval), &(yyvsp[-1]), &(yyvsp[0]) TSRMLS_CC); ;}
    break;

  case 442:
#line 982 "php_parser.y"
    { zend_do_add_string(&(yyval), &(yyvsp[-1]), &(yyvsp[0]) TSRMLS_CC); ;}
    break;

  case 443:
#line 983 "php_parser.y"
    { zend_do_add_char(&(yyval), &(yyvsp[-1]), &(yyvsp[0]) TSRMLS_CC); ;}
    break;

  case 444:
#line 984 "php_parser.y"
    { zend_do_add_string(&(yyval), &(yyvsp[-1]), &(yyvsp[0]) TSRMLS_CC); ;}
    break;

  case 445:
#line 985 "php_parser.y"
    { (yyvsp[0]).u.constant.value.lval = (long) '['; zend_do_add_char(&(yyval), &(yyvsp[-1]), &(yyvsp[0]) TSRMLS_CC); ;}
    break;

  case 446:
#line 986 "php_parser.y"
    { (yyvsp[0]).u.constant.value.lval = (long) ']'; zend_do_add_char(&(yyval), &(yyvsp[-1]), &(yyvsp[0]) TSRMLS_CC); ;}
    break;

  case 447:
#line 987 "php_parser.y"
    { (yyvsp[0]).u.constant.value.lval = (long) '{'; zend_do_add_char(&(yyval), &(yyvsp[-1]), &(yyvsp[0]) TSRMLS_CC); ;}
    break;

  case 448:
#line 988 "php_parser.y"
    { (yyvsp[0]).u.constant.value.lval = (long) '}'; zend_do_add_char(&(yyval), &(yyvsp[-1]), &(yyvsp[0]) TSRMLS_CC); ;}
    break;

  case 449:
#line 989 "php_parser.y"
    { znode tmp;  (yyvsp[0]).u.constant.value.lval = (long) '-';  zend_do_add_char(&tmp, &(yyvsp[-1]), &(yyvsp[0]) TSRMLS_CC);  (yyvsp[0]).u.constant.value.lval = (long) '>'; zend_do_add_char(&(yyval), &tmp, &(yyvsp[0]) TSRMLS_CC); ;}
    break;

  case 450:
#line 990 "php_parser.y"
    { zend_do_init_string(&(yyval) TSRMLS_CC); ;}
    break;

  case 451:
#line 997 "php_parser.y"
    { zend_do_begin_variable_parse(TSRMLS_C); fetch_simple_variable(&(yyval), &(yyvsp[0]), 1 TSRMLS_CC); ;}
    break;

  case 452:
#line 998 "php_parser.y"
    { zend_do_begin_variable_parse(TSRMLS_C); ;}
    break;

  case 453:
#line 998 "php_parser.y"
    { fetch_array_begin(&(yyval), &(yyvsp[-4]), &(yyvsp[-1]) TSRMLS_CC); ;}
    break;

  case 454:
#line 999 "php_parser.y"
    { zend_do_begin_variable_parse(TSRMLS_C); fetch_simple_variable(&(yyvsp[-1]), &(yyvsp[-2]), 1 TSRMLS_CC); zend_do_fetch_property(&(yyval), &(yyvsp[-1]), &(yyvsp[0]) TSRMLS_CC); ;}
    break;

  case 455:
#line 1000 "php_parser.y"
    { zend_do_begin_variable_parse(TSRMLS_C);  fetch_simple_variable(&(yyval), &(yyvsp[-1]), 1 TSRMLS_CC); ;}
    break;

  case 456:
#line 1001 "php_parser.y"
    { zend_do_begin_variable_parse(TSRMLS_C);  fetch_array_begin(&(yyval), &(yyvsp[-4]), &(yyvsp[-2]) TSRMLS_CC); ;}
    break;

  case 457:
#line 1002 "php_parser.y"
    { (yyval) = (yyvsp[-1]); ;}
    break;

  case 458:
#line 1007 "php_parser.y"
    { (yyval) = (yyvsp[0]); ;}
    break;

  case 459:
#line 1008 "php_parser.y"
    { (yyval) = (yyvsp[0]); ;}
    break;

  case 460:
#line 1009 "php_parser.y"
    { fetch_simple_variable(&(yyval), &(yyvsp[0]), 1 TSRMLS_CC); ;}
    break;

  case 461:
#line 1014 "php_parser.y"
    { (yyval) = (yyvsp[-1]); ;}
    break;

  case 462:
#line 1015 "php_parser.y"
    { zend_do_isset_or_isempty(ZEND_ISEMPTY, &(yyval), &(yyvsp[-1]) TSRMLS_CC); ;}
    break;

  case 463:
#line 1016 "php_parser.y"
    { zend_do_include_or_eval(ZEND_INCLUDE, &(yyval), &(yyvsp[0]) TSRMLS_CC); ;}
    break;

  case 464:
#line 1017 "php_parser.y"
    { zend_do_include_or_eval(ZEND_INCLUDE_ONCE, &(yyval), &(yyvsp[0]) TSRMLS_CC); ;}
    break;

  case 465:
#line 1018 "php_parser.y"
    { zend_do_include_or_eval(ZEND_EVAL, &(yyval), &(yyvsp[-1]) TSRMLS_CC); ;}
    break;

  case 466:
#line 1019 "php_parser.y"
    { zend_do_include_or_eval(ZEND_REQUIRE, &(yyval), &(yyvsp[0]) TSRMLS_CC); ;}
    break;

  case 467:
#line 1020 "php_parser.y"
    { zend_do_include_or_eval(ZEND_REQUIRE_ONCE, &(yyval), &(yyvsp[0]) TSRMLS_CC); ;}
    break;

  case 468:
#line 1024 "php_parser.y"
    { zend_do_isset_or_isempty(ZEND_ISSET, &(yyval), &(yyvsp[0]) TSRMLS_CC); ;}
    break;

  case 469:
#line 1025 "php_parser.y"
    { zend_do_boolean_and_begin(&(yyvsp[-1]), &(yyvsp[0]) TSRMLS_CC); ;}
    break;

  case 470:
#line 1025 "php_parser.y"
    { znode tmp; zend_do_isset_or_isempty(ZEND_ISSET, &tmp, &(yyvsp[0]) TSRMLS_CC); zend_do_boolean_and_end(&(yyval), &(yyvsp[-3]), &tmp, &(yyvsp[-2]) TSRMLS_CC); ;}
    break;

  case 471:
#line 1029 "php_parser.y"
    { zend_do_fetch_constant(&(yyval), &(yyvsp[-2]), &(yyvsp[0]), ZEND_RT TSRMLS_CC); ;}
    break;

*/
      default: break;
    }

/* Line 1422 of yacc.c.  */
#line 5174 "php_parser.c"

  yyvsp -= yylen;
  yyssp -= yylen;


  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (YYPACT_NINF < yyn && yyn < YYLAST)
	{
	  int yytype = YYTRANSLATE (yychar);
	  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
	  YYSIZE_T yysize = yysize0;
	  YYSIZE_T yysize1;
	  int yysize_overflow = 0;
	  char *yymsg = 0;
#	  define YYERROR_VERBOSE_ARGS_MAXIMUM 5
	  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
	  int yyx;

#if 0
	  /* This is so xgettext sees the translatable formats that are
	     constructed on the fly.  */
	  YY_("syntax error, unexpected %s");
	  YY_("syntax error, unexpected %s, expecting %s");
	  YY_("syntax error, unexpected %s, expecting %s or %s");
	  YY_("syntax error, unexpected %s, expecting %s or %s or %s");
	  YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
#endif
	  char *yyfmt;
	  char const *yyf;
	  static char const yyunexpected[] = "syntax error, unexpected %s";
	  static char const yyexpecting[] = ", expecting %s";
	  static char const yyor[] = " or %s";
	  char yyformat[sizeof yyunexpected
			+ sizeof yyexpecting - 1
			+ ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
			   * (sizeof yyor - 1))];
	  char const *yyprefix = yyexpecting;

	  /* Start YYX at -YYN if negative to avoid negative indexes in
	     YYCHECK.  */
	  int yyxbegin = yyn < 0 ? -yyn : 0;
  
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn;
	  int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
	  int yycount = 1;

	  yyarg[0] = yytname[yytype];
	  yyfmt = yystpcpy (yyformat, yyunexpected);

	  for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
              {
		if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
		  {
		    yycount = 1;
		    yysize = yysize0;
		    yyformat[sizeof yyunexpected - 1] = '\0';
		    break;
		  }
		yyarg[yycount++] = yytname[yyx];
		yysize1 = yysize + yytnamerr (0, yytname[yyx]);
		yysize_overflow |= yysize1 < yysize;
		yysize = yysize1;
		yyfmt = yystpcpy (yyfmt, yyprefix);
		yyprefix = yyor;
	      }

	  yyf = YY_(yyformat);
	  yysize1 = yysize + yystrlen (yyf);
	  yysize_overflow |= yysize1 < yysize;
	  yysize = yysize1;

	  if (!yysize_overflow && yysize <= YYSTACK_ALLOC_MAXIMUM)
	    yymsg = (char *) YYSTACK_ALLOC (yysize);
	  if (yymsg)
	    {
	      /* Avoid sprintf, as that infringes on the user's name space.
		 Don't have undefined behavior even if the translation
		 produced a string with the wrong number of "%s"s.  */
	      char *yyp = yymsg;
	      int yyi = 0;
	      while ((*yyp = *yyf))
		{
		  if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		    {
		      yyp += yytnamerr (yyp, yyarg[yyi++]);
		      yyf += 2;
		    }
		  else
		    {
		      yyp++;
		      yyf++;
		    }
		}
	      yyerror (yymsg);
	      YYSTACK_FREE (yymsg);
	    }
	  else
	    {
	      yyerror (YY_("syntax error"));
	      goto yyexhaustedlab;
	    }
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror (YY_("syntax error"));
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */
      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
        }
      else
	{
	  yydestruct ("Error: discarding", yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (0)
     goto yyerrorlab;

yyvsp -= yylen;
  yyssp -= yylen;
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping", yystos[yystate], yyvsp);
      YYPOPSTACK;
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  YYDPRINTF ((stderr, "Shifting error token, "));

	// Yijun Yu: yyxsp
  *++yyxsp = yyxml_string;
  yyxml_string = NULL;
  *++yyvsp = yylval;


  /* Shift the error token. */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  generate_xml_output(yyxsp,yyxs);
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK;
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  return yyresult;
}


#line 1032 "php_parser.y"

void yyerror(char* s){
	_error = 1;
	printf("%s line: %d in %s\n", s, getLineno(), file_name);
}
