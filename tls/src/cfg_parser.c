/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "cfg_parser.y"

#include "config.h"

#include <stdio.h>
#include <stdlib.h>

#include "configuration.h"
#include "foreign/vas.h"
#include "foreign/miniobj.h"
#include "foreign/uthash.h"

extern int yylex (void);
extern int yyparse(hitch_config *);
extern FILE *yyin;
int yyget_lineno(void);

void config_error_set(char *, ...);
int config_param_validate(char *k, char *v, hitch_config *cfg,
    char *file, int line);
int front_arg_add(hitch_config *cfg, struct front_arg *fa);
struct front_arg *front_arg_new(void);
void front_arg_destroy(struct front_arg *fa);
struct cfg_cert_file *
cfg_cert_file_new(void);
void cfg_cert_file_free(struct cfg_cert_file **cfptr);
int cfg_cert_vfy(struct cfg_cert_file *cf);
void yyerror(hitch_config *, const char *);
void cfg_cert_add(struct cfg_cert_file *cf, struct cfg_cert_file **dst);

static struct front_arg *cur_fa;
static struct cfg_cert_file *cur_pem;
extern char input_line[512];


#line 106 "cfg_parser.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_CFG_PARSER_H_INCLUDED
# define YY_YY_CFG_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    INT = 258,                     /* INT  */
    UINT = 259,                    /* UINT  */
    BOOL = 260,                    /* BOOL  */
    STRING = 261,                  /* STRING  */
    TOK_CIPHERS = 262,             /* TOK_CIPHERS  */
    TOK_SSL_ENGINE = 263,          /* TOK_SSL_ENGINE  */
    TOK_PREFER_SERVER_CIPHERS = 264, /* TOK_PREFER_SERVER_CIPHERS  */
    TOK_BACKEND = 265,             /* TOK_BACKEND  */
    TOK_FRONTEND = 266,            /* TOK_FRONTEND  */
    TOK_WORKERS = 267,             /* TOK_WORKERS  */
    TOK_BACKLOG = 268,             /* TOK_BACKLOG  */
    TOK_KEEPALIVE = 269,           /* TOK_KEEPALIVE  */
    TOK_CHROOT = 270,              /* TOK_CHROOT  */
    TOK_USER = 271,                /* TOK_USER  */
    TOK_GROUP = 272,               /* TOK_GROUP  */
    TOK_QUIET = 273,               /* TOK_QUIET  */
    TOK_SYSLOG = 274,              /* TOK_SYSLOG  */
    TOK_SYSLOG_FACILITY = 275,     /* TOK_SYSLOG_FACILITY  */
    TOK_PARAM_SYSLOG_FACILITY = 276, /* TOK_PARAM_SYSLOG_FACILITY  */
    TOK_DAEMON = 277,              /* TOK_DAEMON  */
    TOK_WRITE_IP = 278,            /* TOK_WRITE_IP  */
    TOK_WRITE_PROXY = 279,         /* TOK_WRITE_PROXY  */
    TOK_WRITE_PROXY_V1 = 280,      /* TOK_WRITE_PROXY_V1  */
    TOK_WRITE_PROXY_V2 = 281,      /* TOK_WRITE_PROXY_V2  */
    TOK_PEM_FILE = 282,            /* TOK_PEM_FILE  */
    TOK_PROXY_PROXY = 283,         /* TOK_PROXY_PROXY  */
    TOK_BACKEND_CONNECT_TIMEOUT = 284, /* TOK_BACKEND_CONNECT_TIMEOUT  */
    TOK_SSL_HANDSHAKE_TIMEOUT = 285, /* TOK_SSL_HANDSHAKE_TIMEOUT  */
    TOK_RECV_BUFSIZE = 286,        /* TOK_RECV_BUFSIZE  */
    TOK_SEND_BUFSIZE = 287,        /* TOK_SEND_BUFSIZE  */
    TOK_LOG_FILENAME = 288,        /* TOK_LOG_FILENAME  */
    TOK_RING_SLOTS = 289,          /* TOK_RING_SLOTS  */
    TOK_RING_DATA_LEN = 290,       /* TOK_RING_DATA_LEN  */
    TOK_PIDFILE = 291,             /* TOK_PIDFILE  */
    TOK_SNI_NOMATCH_ABORT = 292,   /* TOK_SNI_NOMATCH_ABORT  */
    TOK_SSL = 293,                 /* TOK_SSL  */
    TOK_TLS = 294,                 /* TOK_TLS  */
    TOK_HOST = 295,                /* TOK_HOST  */
    TOK_PORT = 296,                /* TOK_PORT  */
    TOK_MATCH_GLOBAL = 297,        /* TOK_MATCH_GLOBAL  */
    TOK_PB_CERT = 298,             /* TOK_PB_CERT  */
    TOK_PB_OCSP_FILE = 299,        /* TOK_PB_OCSP_FILE  */
    TOK_OCSP_VERIFY = 300,         /* TOK_OCSP_VERIFY  */
    TOK_OCSP_DIR = 301,            /* TOK_OCSP_DIR  */
    TOK_OCSP_RESP_TMO = 302,       /* TOK_OCSP_RESP_TMO  */
    TOK_OCSP_CONN_TMO = 303,       /* TOK_OCSP_CONN_TMO  */
    TOK_ALPN_PROTOS = 304,         /* TOK_ALPN_PROTOS  */
    TOK_TLS_PROTOS = 305,          /* TOK_TLS_PROTOS  */
    TOK_SSLv3 = 306,               /* TOK_SSLv3  */
    TOK_TLSv1_0 = 307,             /* TOK_TLSv1_0  */
    TOK_TLSv1_1 = 308,             /* TOK_TLSv1_1  */
    TOK_TLSv1_2 = 309,             /* TOK_TLSv1_2  */
    TOK_TLSv1_3 = 310,             /* TOK_TLSv1_3  */
    TOK_CIPHERSUITES = 311,        /* TOK_CIPHERSUITES  */
    TOK_ECDH_CURVE = 312,          /* TOK_ECDH_CURVE  */
    TOK_SESSION_CACHE = 313,       /* TOK_SESSION_CACHE  */
    TOK_SHARED_CACHE_LISTEN = 314, /* TOK_SHARED_CACHE_LISTEN  */
    TOK_SHARED_CACHE_PEER = 315,   /* TOK_SHARED_CACHE_PEER  */
    TOK_SHARED_CACHE_IF = 316,     /* TOK_SHARED_CACHE_IF  */
    TOK_PRIVATE_KEY = 317,         /* TOK_PRIVATE_KEY  */
    TOK_BACKEND_REFRESH = 318,     /* TOK_BACKEND_REFRESH  */
    TOK_OCSP_REFRESH_INTERVAL = 319, /* TOK_OCSP_REFRESH_INTERVAL  */
    TOK_PEM_DIR = 320,             /* TOK_PEM_DIR  */
    TOK_PEM_DIR_GLOB = 321,        /* TOK_PEM_DIR_GLOB  */
    TOK_LOG_LEVEL = 322,           /* TOK_LOG_LEVEL  */
    TOK_PROXY_TLV = 323,           /* TOK_PROXY_TLV  */
    TOK_PROXY_AUTHORITY = 324,     /* TOK_PROXY_AUTHORITY  */
    TOK_TFO = 325,                 /* TOK_TFO  */
    TOK_CLIENT_VERIFY = 326,       /* TOK_CLIENT_VERIFY  */
    TOK_VERIFY_NONE = 327,         /* TOK_VERIFY_NONE  */
    TOK_VERIFY_OPT = 328,          /* TOK_VERIFY_OPT  */
    TOK_VERIFY_REQ = 329,          /* TOK_VERIFY_REQ  */
    TOK_CLIENT_VERIFY_CA = 330,    /* TOK_CLIENT_VERIFY_CA  */
    TOK_PROXY_CCERT = 331,         /* TOK_PROXY_CCERT  */
    TOK_AUTO = 332                 /* TOK_AUTO  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define INT 258
#define UINT 259
#define BOOL 260
#define STRING 261
#define TOK_CIPHERS 262
#define TOK_SSL_ENGINE 263
#define TOK_PREFER_SERVER_CIPHERS 264
#define TOK_BACKEND 265
#define TOK_FRONTEND 266
#define TOK_WORKERS 267
#define TOK_BACKLOG 268
#define TOK_KEEPALIVE 269
#define TOK_CHROOT 270
#define TOK_USER 271
#define TOK_GROUP 272
#define TOK_QUIET 273
#define TOK_SYSLOG 274
#define TOK_SYSLOG_FACILITY 275
#define TOK_PARAM_SYSLOG_FACILITY 276
#define TOK_DAEMON 277
#define TOK_WRITE_IP 278
#define TOK_WRITE_PROXY 279
#define TOK_WRITE_PROXY_V1 280
#define TOK_WRITE_PROXY_V2 281
#define TOK_PEM_FILE 282
#define TOK_PROXY_PROXY 283
#define TOK_BACKEND_CONNECT_TIMEOUT 284
#define TOK_SSL_HANDSHAKE_TIMEOUT 285
#define TOK_RECV_BUFSIZE 286
#define TOK_SEND_BUFSIZE 287
#define TOK_LOG_FILENAME 288
#define TOK_RING_SLOTS 289
#define TOK_RING_DATA_LEN 290
#define TOK_PIDFILE 291
#define TOK_SNI_NOMATCH_ABORT 292
#define TOK_SSL 293
#define TOK_TLS 294
#define TOK_HOST 295
#define TOK_PORT 296
#define TOK_MATCH_GLOBAL 297
#define TOK_PB_CERT 298
#define TOK_PB_OCSP_FILE 299
#define TOK_OCSP_VERIFY 300
#define TOK_OCSP_DIR 301
#define TOK_OCSP_RESP_TMO 302
#define TOK_OCSP_CONN_TMO 303
#define TOK_ALPN_PROTOS 304
#define TOK_TLS_PROTOS 305
#define TOK_SSLv3 306
#define TOK_TLSv1_0 307
#define TOK_TLSv1_1 308
#define TOK_TLSv1_2 309
#define TOK_TLSv1_3 310
#define TOK_CIPHERSUITES 311
#define TOK_ECDH_CURVE 312
#define TOK_SESSION_CACHE 313
#define TOK_SHARED_CACHE_LISTEN 314
#define TOK_SHARED_CACHE_PEER 315
#define TOK_SHARED_CACHE_IF 316
#define TOK_PRIVATE_KEY 317
#define TOK_BACKEND_REFRESH 318
#define TOK_OCSP_REFRESH_INTERVAL 319
#define TOK_PEM_DIR 320
#define TOK_PEM_DIR_GLOB 321
#define TOK_LOG_LEVEL 322
#define TOK_PROXY_TLV 323
#define TOK_PROXY_AUTHORITY 324
#define TOK_TFO 325
#define TOK_CLIENT_VERIFY 326
#define TOK_VERIFY_NONE 327
#define TOK_VERIFY_OPT 328
#define TOK_VERIFY_REQ 329
#define TOK_CLIENT_VERIFY_CA 330
#define TOK_PROXY_CCERT 331
#define TOK_AUTO 332

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 36 "cfg_parser.y"

	int	i;
	char	*s;

#line 318 "cfg_parser.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (hitch_config *cfg);


#endif /* !YY_YY_CFG_PARSER_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INT = 3,                        /* INT  */
  YYSYMBOL_UINT = 4,                       /* UINT  */
  YYSYMBOL_BOOL = 5,                       /* BOOL  */
  YYSYMBOL_STRING = 6,                     /* STRING  */
  YYSYMBOL_TOK_CIPHERS = 7,                /* TOK_CIPHERS  */
  YYSYMBOL_TOK_SSL_ENGINE = 8,             /* TOK_SSL_ENGINE  */
  YYSYMBOL_TOK_PREFER_SERVER_CIPHERS = 9,  /* TOK_PREFER_SERVER_CIPHERS  */
  YYSYMBOL_TOK_BACKEND = 10,               /* TOK_BACKEND  */
  YYSYMBOL_TOK_FRONTEND = 11,              /* TOK_FRONTEND  */
  YYSYMBOL_TOK_WORKERS = 12,               /* TOK_WORKERS  */
  YYSYMBOL_TOK_BACKLOG = 13,               /* TOK_BACKLOG  */
  YYSYMBOL_TOK_KEEPALIVE = 14,             /* TOK_KEEPALIVE  */
  YYSYMBOL_TOK_CHROOT = 15,                /* TOK_CHROOT  */
  YYSYMBOL_TOK_USER = 16,                  /* TOK_USER  */
  YYSYMBOL_TOK_GROUP = 17,                 /* TOK_GROUP  */
  YYSYMBOL_TOK_QUIET = 18,                 /* TOK_QUIET  */
  YYSYMBOL_TOK_SYSLOG = 19,                /* TOK_SYSLOG  */
  YYSYMBOL_TOK_SYSLOG_FACILITY = 20,       /* TOK_SYSLOG_FACILITY  */
  YYSYMBOL_TOK_PARAM_SYSLOG_FACILITY = 21, /* TOK_PARAM_SYSLOG_FACILITY  */
  YYSYMBOL_TOK_DAEMON = 22,                /* TOK_DAEMON  */
  YYSYMBOL_TOK_WRITE_IP = 23,              /* TOK_WRITE_IP  */
  YYSYMBOL_TOK_WRITE_PROXY = 24,           /* TOK_WRITE_PROXY  */
  YYSYMBOL_TOK_WRITE_PROXY_V1 = 25,        /* TOK_WRITE_PROXY_V1  */
  YYSYMBOL_TOK_WRITE_PROXY_V2 = 26,        /* TOK_WRITE_PROXY_V2  */
  YYSYMBOL_TOK_PEM_FILE = 27,              /* TOK_PEM_FILE  */
  YYSYMBOL_TOK_PROXY_PROXY = 28,           /* TOK_PROXY_PROXY  */
  YYSYMBOL_TOK_BACKEND_CONNECT_TIMEOUT = 29, /* TOK_BACKEND_CONNECT_TIMEOUT  */
  YYSYMBOL_TOK_SSL_HANDSHAKE_TIMEOUT = 30, /* TOK_SSL_HANDSHAKE_TIMEOUT  */
  YYSYMBOL_TOK_RECV_BUFSIZE = 31,          /* TOK_RECV_BUFSIZE  */
  YYSYMBOL_TOK_SEND_BUFSIZE = 32,          /* TOK_SEND_BUFSIZE  */
  YYSYMBOL_TOK_LOG_FILENAME = 33,          /* TOK_LOG_FILENAME  */
  YYSYMBOL_TOK_RING_SLOTS = 34,            /* TOK_RING_SLOTS  */
  YYSYMBOL_TOK_RING_DATA_LEN = 35,         /* TOK_RING_DATA_LEN  */
  YYSYMBOL_TOK_PIDFILE = 36,               /* TOK_PIDFILE  */
  YYSYMBOL_TOK_SNI_NOMATCH_ABORT = 37,     /* TOK_SNI_NOMATCH_ABORT  */
  YYSYMBOL_TOK_SSL = 38,                   /* TOK_SSL  */
  YYSYMBOL_TOK_TLS = 39,                   /* TOK_TLS  */
  YYSYMBOL_TOK_HOST = 40,                  /* TOK_HOST  */
  YYSYMBOL_TOK_PORT = 41,                  /* TOK_PORT  */
  YYSYMBOL_TOK_MATCH_GLOBAL = 42,          /* TOK_MATCH_GLOBAL  */
  YYSYMBOL_TOK_PB_CERT = 43,               /* TOK_PB_CERT  */
  YYSYMBOL_TOK_PB_OCSP_FILE = 44,          /* TOK_PB_OCSP_FILE  */
  YYSYMBOL_TOK_OCSP_VERIFY = 45,           /* TOK_OCSP_VERIFY  */
  YYSYMBOL_TOK_OCSP_DIR = 46,              /* TOK_OCSP_DIR  */
  YYSYMBOL_TOK_OCSP_RESP_TMO = 47,         /* TOK_OCSP_RESP_TMO  */
  YYSYMBOL_TOK_OCSP_CONN_TMO = 48,         /* TOK_OCSP_CONN_TMO  */
  YYSYMBOL_TOK_ALPN_PROTOS = 49,           /* TOK_ALPN_PROTOS  */
  YYSYMBOL_TOK_TLS_PROTOS = 50,            /* TOK_TLS_PROTOS  */
  YYSYMBOL_TOK_SSLv3 = 51,                 /* TOK_SSLv3  */
  YYSYMBOL_TOK_TLSv1_0 = 52,               /* TOK_TLSv1_0  */
  YYSYMBOL_TOK_TLSv1_1 = 53,               /* TOK_TLSv1_1  */
  YYSYMBOL_TOK_TLSv1_2 = 54,               /* TOK_TLSv1_2  */
  YYSYMBOL_TOK_TLSv1_3 = 55,               /* TOK_TLSv1_3  */
  YYSYMBOL_TOK_CIPHERSUITES = 56,          /* TOK_CIPHERSUITES  */
  YYSYMBOL_TOK_ECDH_CURVE = 57,            /* TOK_ECDH_CURVE  */
  YYSYMBOL_TOK_SESSION_CACHE = 58,         /* TOK_SESSION_CACHE  */
  YYSYMBOL_TOK_SHARED_CACHE_LISTEN = 59,   /* TOK_SHARED_CACHE_LISTEN  */
  YYSYMBOL_TOK_SHARED_CACHE_PEER = 60,     /* TOK_SHARED_CACHE_PEER  */
  YYSYMBOL_TOK_SHARED_CACHE_IF = 61,       /* TOK_SHARED_CACHE_IF  */
  YYSYMBOL_TOK_PRIVATE_KEY = 62,           /* TOK_PRIVATE_KEY  */
  YYSYMBOL_TOK_BACKEND_REFRESH = 63,       /* TOK_BACKEND_REFRESH  */
  YYSYMBOL_TOK_OCSP_REFRESH_INTERVAL = 64, /* TOK_OCSP_REFRESH_INTERVAL  */
  YYSYMBOL_TOK_PEM_DIR = 65,               /* TOK_PEM_DIR  */
  YYSYMBOL_TOK_PEM_DIR_GLOB = 66,          /* TOK_PEM_DIR_GLOB  */
  YYSYMBOL_TOK_LOG_LEVEL = 67,             /* TOK_LOG_LEVEL  */
  YYSYMBOL_TOK_PROXY_TLV = 68,             /* TOK_PROXY_TLV  */
  YYSYMBOL_TOK_PROXY_AUTHORITY = 69,       /* TOK_PROXY_AUTHORITY  */
  YYSYMBOL_TOK_TFO = 70,                   /* TOK_TFO  */
  YYSYMBOL_TOK_CLIENT_VERIFY = 71,         /* TOK_CLIENT_VERIFY  */
  YYSYMBOL_TOK_VERIFY_NONE = 72,           /* TOK_VERIFY_NONE  */
  YYSYMBOL_TOK_VERIFY_OPT = 73,            /* TOK_VERIFY_OPT  */
  YYSYMBOL_TOK_VERIFY_REQ = 74,            /* TOK_VERIFY_REQ  */
  YYSYMBOL_TOK_CLIENT_VERIFY_CA = 75,      /* TOK_CLIENT_VERIFY_CA  */
  YYSYMBOL_TOK_PROXY_CCERT = 76,           /* TOK_PROXY_CCERT  */
  YYSYMBOL_TOK_AUTO = 77,                  /* TOK_AUTO  */
  YYSYMBOL_78_ = 78,                       /* '='  */
  YYSYMBOL_79_ = 79,                       /* '{'  */
  YYSYMBOL_80_ = 80,                       /* '}'  */
  YYSYMBOL_YYACCEPT = 81,                  /* $accept  */
  YYSYMBOL_CFG = 82,                       /* CFG  */
  YYSYMBOL_CFG_RECORDS = 83,               /* CFG_RECORDS  */
  YYSYMBOL_CFG_RECORD = 84,                /* CFG_RECORD  */
  YYSYMBOL_FRONTEND_REC = 85,              /* FRONTEND_REC  */
  YYSYMBOL_86_1 = 86,                      /* $@1  */
  YYSYMBOL_FRONTEND_BLK = 87,              /* FRONTEND_BLK  */
  YYSYMBOL_FB_RECS = 88,                   /* FB_RECS  */
  YYSYMBOL_FB_REC = 89,                    /* FB_REC  */
  YYSYMBOL_FB_HOST = 90,                   /* FB_HOST  */
  YYSYMBOL_FB_PORT = 91,                   /* FB_PORT  */
  YYSYMBOL_PEM_BLK = 92,                   /* PEM_BLK  */
  YYSYMBOL_PB_RECS = 93,                   /* PB_RECS  */
  YYSYMBOL_PB_REC = 94,                    /* PB_REC  */
  YYSYMBOL_PB_CERT = 95,                   /* PB_CERT  */
  YYSYMBOL_PB_OCSP_RESP_FILE = 96,         /* PB_OCSP_RESP_FILE  */
  YYSYMBOL_OCSP_VERIFY = 97,               /* OCSP_VERIFY  */
  YYSYMBOL_PRIVATE_KEY = 98,               /* PRIVATE_KEY  */
  YYSYMBOL_PB_CLIENT_VERIFY = 99,          /* PB_CLIENT_VERIFY  */
  YYSYMBOL_PB_CLIENT_VERIFY_CA = 100,      /* PB_CLIENT_VERIFY_CA  */
  YYSYMBOL_PEM_DIR = 101,                  /* PEM_DIR  */
  YYSYMBOL_PEM_DIR_GLOB = 102,             /* PEM_DIR_GLOB  */
  YYSYMBOL_OCSP_DIR = 103,                 /* OCSP_DIR  */
  YYSYMBOL_OCSP_RESP_TMO = 104,            /* OCSP_RESP_TMO  */
  YYSYMBOL_OCSP_CONN_TMO = 105,            /* OCSP_CONN_TMO  */
  YYSYMBOL_OCSP_REFRESH_INTERVAL = 106,    /* OCSP_REFRESH_INTERVAL  */
  YYSYMBOL_FB_CERT = 107,                  /* FB_CERT  */
  YYSYMBOL_108_2 = 108,                    /* $@2  */
  YYSYMBOL_FB_CLIENT_VERIFY = 109,         /* FB_CLIENT_VERIFY  */
  YYSYMBOL_FB_CLIENT_VERIFY_CA = 110,      /* FB_CLIENT_VERIFY_CA  */
  YYSYMBOL_FB_MATCH_GLOBAL = 111,          /* FB_MATCH_GLOBAL  */
  YYSYMBOL_FB_SNI_NOMATCH_ABORT = 112,     /* FB_SNI_NOMATCH_ABORT  */
  YYSYMBOL_FB_TLS = 113,                   /* FB_TLS  */
  YYSYMBOL_FB_SSL = 114,                   /* FB_SSL  */
  YYSYMBOL_FB_TLS_PROTOS = 115,            /* FB_TLS_PROTOS  */
  YYSYMBOL_116_3 = 116,                    /* $@3  */
  YYSYMBOL_FB_TLS_PROTOS_LIST = 117,       /* FB_TLS_PROTOS_LIST  */
  YYSYMBOL_FB_TLS_PROTO = 118,             /* FB_TLS_PROTO  */
  YYSYMBOL_FB_CIPHERS = 119,               /* FB_CIPHERS  */
  YYSYMBOL_FB_CIPHERSUITES = 120,          /* FB_CIPHERSUITES  */
  YYSYMBOL_FB_PREF_SRV_CIPH = 121,         /* FB_PREF_SRV_CIPH  */
  YYSYMBOL_QUIET_REC = 122,                /* QUIET_REC  */
  YYSYMBOL_WORKERS_REC = 123,              /* WORKERS_REC  */
  YYSYMBOL_BACKLOG_REC = 124,              /* BACKLOG_REC  */
  YYSYMBOL_KEEPALIVE_REC = 125,            /* KEEPALIVE_REC  */
  YYSYMBOL_TLS_REC = 126,                  /* TLS_REC  */
  YYSYMBOL_SSL_REC = 127,                  /* SSL_REC  */
  YYSYMBOL_TLS_PROTOS_REC = 128,           /* TLS_PROTOS_REC  */
  YYSYMBOL_129_4 = 129,                    /* $@4  */
  YYSYMBOL_TLS_PROTOS_LIST = 130,          /* TLS_PROTOS_LIST  */
  YYSYMBOL_TLS_PROTO = 131,                /* TLS_PROTO  */
  YYSYMBOL_SSL_ENGINE_REC = 132,           /* SSL_ENGINE_REC  */
  YYSYMBOL_PREFER_SERVER_CIPHERS_REC = 133, /* PREFER_SERVER_CIPHERS_REC  */
  YYSYMBOL_CHROOT_REC = 134,               /* CHROOT_REC  */
  YYSYMBOL_BACKEND_REC = 135,              /* BACKEND_REC  */
  YYSYMBOL_PEM_FILE_REC = 136,             /* PEM_FILE_REC  */
  YYSYMBOL_137_5 = 137,                    /* $@5  */
  YYSYMBOL_SYSLOG_REC = 138,               /* SYSLOG_REC  */
  YYSYMBOL_DAEMON_REC = 139,               /* DAEMON_REC  */
  YYSYMBOL_SNI_NOMATCH_ABORT_REC = 140,    /* SNI_NOMATCH_ABORT_REC  */
  YYSYMBOL_CIPHERS_REC = 141,              /* CIPHERS_REC  */
  YYSYMBOL_CIPHERSUITES_REC = 142,         /* CIPHERSUITES_REC  */
  YYSYMBOL_USER_REC = 143,                 /* USER_REC  */
  YYSYMBOL_GROUP_REC = 144,                /* GROUP_REC  */
  YYSYMBOL_WRITE_IP_REC = 145,             /* WRITE_IP_REC  */
  YYSYMBOL_WRITE_PROXY_REC = 146,          /* WRITE_PROXY_REC  */
  YYSYMBOL_WRITE_PROXY_V1_REC = 147,       /* WRITE_PROXY_V1_REC  */
  YYSYMBOL_WRITE_PROXY_V2_REC = 148,       /* WRITE_PROXY_V2_REC  */
  YYSYMBOL_PROXY_TLV_REC = 149,            /* PROXY_TLV_REC  */
  YYSYMBOL_PROXY_CCRT_REC = 150,           /* PROXY_CCRT_REC  */
  YYSYMBOL_PROXY_PROXY_REC = 151,          /* PROXY_PROXY_REC  */
  YYSYMBOL_ALPN_PROTOS_REC = 152,          /* ALPN_PROTOS_REC  */
  YYSYMBOL_SYSLOG_FACILITY_REC = 153,      /* SYSLOG_FACILITY_REC  */
  YYSYMBOL_SEND_BUFSIZE_REC = 154,         /* SEND_BUFSIZE_REC  */
  YYSYMBOL_RECV_BUFSIZE_REC = 155,         /* RECV_BUFSIZE_REC  */
  YYSYMBOL_LOG_FILENAME_REC = 156,         /* LOG_FILENAME_REC  */
  YYSYMBOL_LOG_LEVEL_REC = 157,            /* LOG_LEVEL_REC  */
  YYSYMBOL_SESSION_CACHE_REC = 158,        /* SESSION_CACHE_REC  */
  YYSYMBOL_SHARED_CACHE_LISTEN_REC = 159,  /* SHARED_CACHE_LISTEN_REC  */
  YYSYMBOL_SHARED_CACHE_PEER_REC = 160,    /* SHARED_CACHE_PEER_REC  */
  YYSYMBOL_SHARED_CACHE_IF_REC = 161,      /* SHARED_CACHE_IF_REC  */
  YYSYMBOL_TFO = 162,                      /* TFO  */
  YYSYMBOL_BACKEND_REFRESH_REC = 163,      /* BACKEND_REFRESH_REC  */
  YYSYMBOL_ECDH_CURVE_REC = 164,           /* ECDH_CURVE_REC  */
  YYSYMBOL_CLIENT_VERIFY_REC = 165,        /* CLIENT_VERIFY_REC  */
  YYSYMBOL_CLIENT_VERIFY_OPT = 166,        /* CLIENT_VERIFY_OPT  */
  YYSYMBOL_CLIENT_VERIFY_CA_REC = 167,     /* CLIENT_VERIFY_CA_REC  */
  YYSYMBOL_BACKEND_CONNECT_TIMEOUT_REC = 168, /* BACKEND_CONNECT_TIMEOUT_REC  */
  YYSYMBOL_SSL_HANDSHAKE_TIMEOUT_REC = 169 /* SSL_HANDSHAKE_TIMEOUT_REC  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  159
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   236

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  81
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  89
/* YYNRULES -- Number of rules.  */
#define YYNRULES  176
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  324

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   332


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    78,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    79,     2,    80,     2,     2,     2,     2,
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
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    69,    69,    73,    74,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   132,   138,   138,   149,
     151,   152,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   171,   180,   182,   185,   186,
     190,   191,   192,   193,   194,   195,   198,   200,   205,   212,
     216,   217,   221,   234,   242,   250,   254,   258,   263,   277,
     277,   292,   294,   299,   301,   306,   323,   340,   340,   352,
     352,   354,   355,   356,   357,   358,   360,   364,   371,   375,
     382,   383,   389,   391,   393,   408,   423,   423,   433,   433,
     435,   436,   437,   438,   439,   441,   443,   447,   454,   462,
     468,   468,   487,   488,   489,   493,   500,   508,   515,   522,
     524,   526,   530,   534,   536,   538,   540,   542,   549,   557,
     559,   561,   569,   571,   581,   594,   607,   620,   630,   634,
     641,   644,   652,   660,   672,   677,   681
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "INT", "UINT", "BOOL",
  "STRING", "TOK_CIPHERS", "TOK_SSL_ENGINE", "TOK_PREFER_SERVER_CIPHERS",
  "TOK_BACKEND", "TOK_FRONTEND", "TOK_WORKERS", "TOK_BACKLOG",
  "TOK_KEEPALIVE", "TOK_CHROOT", "TOK_USER", "TOK_GROUP", "TOK_QUIET",
  "TOK_SYSLOG", "TOK_SYSLOG_FACILITY", "TOK_PARAM_SYSLOG_FACILITY",
  "TOK_DAEMON", "TOK_WRITE_IP", "TOK_WRITE_PROXY", "TOK_WRITE_PROXY_V1",
  "TOK_WRITE_PROXY_V2", "TOK_PEM_FILE", "TOK_PROXY_PROXY",
  "TOK_BACKEND_CONNECT_TIMEOUT", "TOK_SSL_HANDSHAKE_TIMEOUT",
  "TOK_RECV_BUFSIZE", "TOK_SEND_BUFSIZE", "TOK_LOG_FILENAME",
  "TOK_RING_SLOTS", "TOK_RING_DATA_LEN", "TOK_PIDFILE",
  "TOK_SNI_NOMATCH_ABORT", "TOK_SSL", "TOK_TLS", "TOK_HOST", "TOK_PORT",
  "TOK_MATCH_GLOBAL", "TOK_PB_CERT", "TOK_PB_OCSP_FILE", "TOK_OCSP_VERIFY",
  "TOK_OCSP_DIR", "TOK_OCSP_RESP_TMO", "TOK_OCSP_CONN_TMO",
  "TOK_ALPN_PROTOS", "TOK_TLS_PROTOS", "TOK_SSLv3", "TOK_TLSv1_0",
  "TOK_TLSv1_1", "TOK_TLSv1_2", "TOK_TLSv1_3", "TOK_CIPHERSUITES",
  "TOK_ECDH_CURVE", "TOK_SESSION_CACHE", "TOK_SHARED_CACHE_LISTEN",
  "TOK_SHARED_CACHE_PEER", "TOK_SHARED_CACHE_IF", "TOK_PRIVATE_KEY",
  "TOK_BACKEND_REFRESH", "TOK_OCSP_REFRESH_INTERVAL", "TOK_PEM_DIR",
  "TOK_PEM_DIR_GLOB", "TOK_LOG_LEVEL", "TOK_PROXY_TLV",
  "TOK_PROXY_AUTHORITY", "TOK_TFO", "TOK_CLIENT_VERIFY", "TOK_VERIFY_NONE",
  "TOK_VERIFY_OPT", "TOK_VERIFY_REQ", "TOK_CLIENT_VERIFY_CA",
  "TOK_PROXY_CCERT", "TOK_AUTO", "'='", "'{'", "'}'", "$accept", "CFG",
  "CFG_RECORDS", "CFG_RECORD", "FRONTEND_REC", "$@1", "FRONTEND_BLK",
  "FB_RECS", "FB_REC", "FB_HOST", "FB_PORT", "PEM_BLK", "PB_RECS",
  "PB_REC", "PB_CERT", "PB_OCSP_RESP_FILE", "OCSP_VERIFY", "PRIVATE_KEY",
  "PB_CLIENT_VERIFY", "PB_CLIENT_VERIFY_CA", "PEM_DIR", "PEM_DIR_GLOB",
  "OCSP_DIR", "OCSP_RESP_TMO", "OCSP_CONN_TMO", "OCSP_REFRESH_INTERVAL",
  "FB_CERT", "$@2", "FB_CLIENT_VERIFY", "FB_CLIENT_VERIFY_CA",
  "FB_MATCH_GLOBAL", "FB_SNI_NOMATCH_ABORT", "FB_TLS", "FB_SSL",
  "FB_TLS_PROTOS", "$@3", "FB_TLS_PROTOS_LIST", "FB_TLS_PROTO",
  "FB_CIPHERS", "FB_CIPHERSUITES", "FB_PREF_SRV_CIPH", "QUIET_REC",
  "WORKERS_REC", "BACKLOG_REC", "KEEPALIVE_REC", "TLS_REC", "SSL_REC",
  "TLS_PROTOS_REC", "$@4", "TLS_PROTOS_LIST", "TLS_PROTO",
  "SSL_ENGINE_REC", "PREFER_SERVER_CIPHERS_REC", "CHROOT_REC",
  "BACKEND_REC", "PEM_FILE_REC", "$@5", "SYSLOG_REC", "DAEMON_REC",
  "SNI_NOMATCH_ABORT_REC", "CIPHERS_REC", "CIPHERSUITES_REC", "USER_REC",
  "GROUP_REC", "WRITE_IP_REC", "WRITE_PROXY_REC", "WRITE_PROXY_V1_REC",
  "WRITE_PROXY_V2_REC", "PROXY_TLV_REC", "PROXY_CCRT_REC",
  "PROXY_PROXY_REC", "ALPN_PROTOS_REC", "SYSLOG_FACILITY_REC",
  "SEND_BUFSIZE_REC", "RECV_BUFSIZE_REC", "LOG_FILENAME_REC",
  "LOG_LEVEL_REC", "SESSION_CACHE_REC", "SHARED_CACHE_LISTEN_REC",
  "SHARED_CACHE_PEER_REC", "SHARED_CACHE_IF_REC", "TFO",
  "BACKEND_REFRESH_REC", "ECDH_CURVE_REC", "CLIENT_VERIFY_REC",
  "CLIENT_VERIFY_OPT", "CLIENT_VERIFY_CA_REC",
  "BACKEND_CONNECT_TIMEOUT_REC", "SSL_HANDSHAKE_TIMEOUT_REC", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-279)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      22,   -67,   -57,   -56,   -55,   -53,   -52,   -51,   -50,   -35,
     -22,   -20,   -16,   -15,   -14,   -13,   -12,     6,    17,    21,
      23,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      37,    38,    39,    40,    41,  -279,    42,    44,    45,    53,
      54,    55,    57,    58,    60,    61,    62,    63,    64,    66,
      67,    68,    69,    24,    22,  -279,  -279,  -279,  -279,  -279,
    -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,
    -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,
    -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,
    -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,
    -279,  -279,  -279,  -279,  -279,  -279,  -279,    70,    94,   143,
     144,    -6,    -3,   145,   147,   146,   148,   149,   151,   152,
     153,   155,   156,   158,   159,   160,    -4,   161,   163,   164,
     165,   166,   167,   169,   170,   171,   172,   173,   168,   174,
     175,    75,   176,   177,   180,   179,   181,   182,   185,   186,
     187,   188,   191,   192,   193,   194,   -54,   190,   195,  -279,
    -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,
    -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,
    -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,
    -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,   -45,  -279,
    -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,
    -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,    87,
      59,  -279,  -279,  -279,  -279,  -279,   -45,  -279,    93,   102,
     108,   113,   114,   123,   124,   125,   126,  -279,   127,   128,
     129,   130,    87,  -279,  -279,  -279,  -279,  -279,  -279,  -279,
    -279,  -279,  -279,  -279,  -279,  -279,  -279,   131,   133,   134,
     135,   136,   137,    59,  -279,  -279,  -279,  -279,  -279,  -279,
    -279,  -279,   202,   210,    -2,   211,   213,   214,   215,   216,
     218,   142,   219,   -54,   220,  -279,  -279,   221,   222,   223,
     -54,   224,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,
    -279,  -279,  -279,  -279,   -38,  -279,  -279,  -279,  -279,  -279,
    -279,  -279,  -279,    59,  -279,  -279,  -279,  -279,  -279,   -38,
    -279,   154,  -279,  -279
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   126,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     2,     3,     5,    34,    39,    40,
      38,    35,    36,    37,    21,    15,    16,    17,    10,    11,
      12,    14,    13,    18,     6,     7,    22,    24,    33,     8,
       9,    19,    20,    25,    26,    27,    28,    31,    32,    29,
      30,    23,    47,    48,    45,    46,    41,    42,    43,    44,
      52,    49,    53,    54,    55,    50,    51,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     1,
       4,   145,   135,   136,   138,    56,    57,   120,   121,   122,
     123,   137,   147,   148,   119,   142,   158,   143,   149,   150,
     151,   152,   139,   140,   156,   175,   176,   160,   159,   161,
     144,   125,   124,    88,    94,    95,    96,   157,     0,   146,
     169,   163,   164,   165,   166,   168,    97,    92,    93,   162,
     153,   154,   167,   171,   172,   173,   170,   174,   155,     0,
       0,   130,   131,   132,   133,   134,   127,   128,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   107,     0,     0,
       0,     0,    59,    60,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,     0,     0,     0,
       0,     0,     0,    77,    78,    80,    81,    82,    83,    84,
      85,   129,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    58,    61,     0,     0,     0,
       0,     0,   141,    79,   116,   118,    98,    99,   104,   106,
     105,    75,    76,   103,     0,   117,   101,   102,    86,    87,
      89,    90,    91,     0,   111,   112,   113,   114,   115,   108,
     109,     0,   110,   100
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -279,  -279,  -279,   178,  -279,  -279,  -279,  -279,   -18,  -279,
    -279,   -82,  -279,   -30,  -279,  -279,     3,  -279,  -279,  -279,
    -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,
    -279,  -279,  -279,  -279,  -279,  -279,  -279,   -84,  -279,  -279,
    -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,
      10,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,
    -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,
    -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,
    -279,  -279,  -279,  -279,  -279,  -278,  -279,  -279,  -279
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    53,    54,    55,    56,   219,   241,   242,   243,   244,
     245,   262,   263,   264,   265,   266,   267,   268,   269,   270,
      58,    59,    60,    61,    62,    63,   246,   313,   247,   248,
     249,   250,   251,   252,   253,   281,   319,   320,   254,   255,
     256,    64,    65,    66,    67,    68,    69,    70,   141,   226,
     227,    71,    72,    73,    74,    75,   220,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   216,   104,   105,   106
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     165,   167,   182,    57,   296,   306,   221,   222,   223,   224,
     225,   107,   311,   314,   315,   316,   317,   318,   213,   214,
     215,   108,   109,   110,   159,   111,   112,   113,   114,     1,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,   115,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,   116,    57,   117,    27,
      28,    29,   118,   119,   120,   121,   122,    30,    31,    32,
      33,    34,    35,   166,   168,   183,   161,   297,    36,    37,
      38,    39,    40,    41,   123,    42,    43,    44,    45,    46,
      47,    48,    49,    50,   228,   124,   229,    51,    52,   125,
     162,   126,   257,   258,    30,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   230,   136,   137,   138,   139,   140,
     142,   259,   143,   144,   231,   232,   233,   234,   235,   236,
     260,   145,   146,   147,   261,   148,   149,   237,   150,   151,
     152,   153,   154,   238,   155,   156,   157,   158,   163,   169,
     164,   170,   171,   198,   172,   173,   174,   175,   239,   176,
     177,   178,   240,   179,   180,   181,   184,   185,   186,   187,
     188,   272,   195,   189,   190,   191,   192,   193,   196,   194,
     273,   197,   199,   200,   201,   202,   274,   203,   204,   205,
     206,   275,   276,   207,   208,   209,   217,   210,   211,   212,
     218,   277,   278,   279,   280,   282,   283,   284,   294,   287,
     285,   288,   289,   290,   291,   295,   298,   292,   299,   300,
     304,   301,   302,   303,   286,   305,   307,   308,   309,   310,
     312,   321,   160,   293,   323,   322,   271
};

static const yytype_int16 yycheck[] =
{
       6,     4,     6,     0,     6,   283,    51,    52,    53,    54,
      55,    78,   290,    51,    52,    53,    54,    55,    72,    73,
      74,    78,    78,    78,     0,    78,    78,    78,    78,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    78,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    78,    54,    78,    37,
      38,    39,    78,    78,    78,    78,    78,    45,    46,    47,
      48,    49,    50,    79,    77,    79,     6,    79,    56,    57,
      58,    59,    60,    61,    78,    63,    64,    65,    66,    67,
      68,    69,    70,    71,     7,    78,     9,    75,    76,    78,
       6,    78,    43,    44,    45,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    27,    78,    78,    78,    78,    78,
      78,    62,    78,    78,    37,    38,    39,    40,    41,    42,
      71,    78,    78,    78,    75,    78,    78,    50,    78,    78,
      78,    78,    78,    56,    78,    78,    78,    78,     5,     4,
       6,     4,     6,    78,     6,     6,     5,     5,    71,     6,
       5,     5,    75,     5,     5,     5,     5,     4,     4,     4,
       4,    78,     4,     6,     5,     5,     5,     5,     4,     6,
      78,     6,     6,     6,     4,     6,    78,     6,     6,     4,
       4,    78,    78,     6,     6,     4,     6,     5,     5,     5,
       5,    78,    78,    78,    78,    78,    78,    78,     6,    78,
      80,    78,    78,    78,    78,     5,     5,    80,     5,     5,
      78,     6,     6,     5,   242,     6,     6,     6,     6,     6,
       6,   313,    54,   263,    80,   319,   226
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    37,    38,    39,
      45,    46,    47,    48,    49,    50,    56,    57,    58,    59,
      60,    61,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    75,    76,    82,    83,    84,    85,    97,   101,   102,
     103,   104,   105,   106,   122,   123,   124,   125,   126,   127,
     128,   132,   133,   134,   135,   136,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   167,   168,   169,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,   129,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,     0,
      84,     6,     6,     5,     6,     6,    79,     4,    77,     4,
       4,     6,     6,     6,     5,     5,     6,     5,     5,     5,
       5,     5,     6,    79,     5,     4,     4,     4,     4,     6,
       5,     5,     5,     5,     6,     4,     4,     6,    78,     6,
       6,     4,     6,     6,     6,     4,     4,     6,     6,     4,
       5,     5,     5,    72,    73,    74,   166,     6,     5,    86,
     137,    51,    52,    53,    54,    55,   130,   131,     7,     9,
      27,    37,    38,    39,    40,    41,    42,    50,    56,    71,
      75,    87,    88,    89,    90,    91,   107,   109,   110,   111,
     112,   113,   114,   115,   119,   120,   121,    43,    44,    62,
      71,    75,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   131,    78,    78,    78,    78,    78,    78,    78,    78,
      78,   116,    78,    78,    78,    80,    89,    78,    78,    78,
      78,    78,    80,    94,     6,     5,     6,    79,     5,     5,
       5,     6,     6,     5,    78,     6,   166,     6,     6,     6,
       6,   166,     6,   108,    51,    52,    53,    54,    55,   117,
     118,    92,   118,    80
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    81,    82,    83,    83,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    85,    86,    85,    87,
      88,    88,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    90,    91,    92,    93,    93,
      94,    94,    94,    94,    94,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     107,   109,   110,   111,   112,   113,   114,   116,   115,   117,
     117,   118,   118,   118,   118,   118,   119,   120,   121,   122,
     123,   123,   124,   125,   126,   127,   129,   128,   130,   130,
     131,   131,   131,   131,   131,   132,   133,   134,   135,   136,
     137,   136,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   166,   166,   167,   168,   169
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     0,     6,     1,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     1,     1,     2,
       1,     1,     1,     1,     1,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     0,
       6,     3,     3,     3,     3,     3,     3,     0,     4,     1,
       2,     1,     1,     1,     1,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     0,     4,     1,     2,
       1,     1,     1,     1,     1,     3,     3,     3,     3,     3,
       0,     6,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     1,     1,     3,     3,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (cfg, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, cfg); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, hitch_config *cfg)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (cfg);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, hitch_config *cfg)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep, cfg);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule, hitch_config *cfg)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)], cfg);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, cfg); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, hitch_config *cfg)
{
  YY_USE (yyvaluep);
  YY_USE (cfg);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (hitch_config *cfg)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
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
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 56: /* FRONTEND_REC: TOK_FRONTEND '=' STRING  */
#line 132 "cfg_parser.y"
                                  {
		/* XXX: passing an empty string for file */
		if ((yyvsp[0].s) && config_param_validate("frontend", (yyvsp[0].s), cfg, "",
		    yyget_lineno()) != 0)
			YYABORT;
	}
#line 1719 "cfg_parser.c"
    break;

  case 57: /* $@1: %empty  */
#line 138 "cfg_parser.y"
                               {
		/* NB: Mid-rule action */
		AZ(cur_fa);
		cur_fa = front_arg_new();
	}
#line 1729 "cfg_parser.c"
    break;

  case 58: /* FRONTEND_REC: TOK_FRONTEND '=' '{' $@1 FRONTEND_BLK '}'  */
#line 143 "cfg_parser.y"
                         {
		if (front_arg_add(cfg, cur_fa) != 1)
			YYABORT;
		cur_fa = NULL;
	}
#line 1739 "cfg_parser.c"
    break;

  case 75: /* FB_HOST: TOK_HOST '=' STRING  */
#line 171 "cfg_parser.y"
                             {
	if ((yyvsp[0].s)) {
		if (strcmp((yyvsp[0].s), "*") == 0)
			cur_fa->ip = NULL;
		else
			cur_fa->ip = strdup((yyvsp[0].s));
	}
}
#line 1752 "cfg_parser.c"
    break;

  case 76: /* FB_PORT: TOK_PORT '=' STRING  */
#line 180 "cfg_parser.y"
                             { if ((yyvsp[0].s)) cur_fa->port = strdup((yyvsp[0].s)); }
#line 1758 "cfg_parser.c"
    break;

  case 86: /* PB_CERT: TOK_PB_CERT '=' STRING  */
#line 198 "cfg_parser.y"
                                { if ((yyvsp[0].s)) cur_pem->filename = strdup((yyvsp[0].s)); }
#line 1764 "cfg_parser.c"
    break;

  case 87: /* PB_OCSP_RESP_FILE: TOK_PB_OCSP_FILE '=' STRING  */
#line 200 "cfg_parser.y"
                                               {
	if ((yyvsp[0].s))
		cur_pem->ocspfn = strdup((yyvsp[0].s));
}
#line 1773 "cfg_parser.c"
    break;

  case 88: /* OCSP_VERIFY: TOK_OCSP_VERIFY '=' BOOL  */
#line 205 "cfg_parser.y"
                                      {
	if (cur_pem != NULL)
		cur_pem->ocsp_vfy = (yyvsp[0].i);
	else
		cfg->OCSP_VFY = (yyvsp[0].i);
}
#line 1784 "cfg_parser.c"
    break;

  case 89: /* PRIVATE_KEY: TOK_PRIVATE_KEY '=' STRING  */
#line 212 "cfg_parser.y"
                                        {
	if ((yyvsp[0].s)) cur_pem->priv_key_filename = strdup((yyvsp[0].s));
}
#line 1792 "cfg_parser.c"
    break;

  case 91: /* PB_CLIENT_VERIFY_CA: TOK_CLIENT_VERIFY_CA '=' STRING  */
#line 217 "cfg_parser.y"
                                                     {
	cur_pem->client_verify_ca = strdup((yyvsp[0].s));
}
#line 1800 "cfg_parser.c"
    break;

  case 92: /* PEM_DIR: TOK_PEM_DIR '=' STRING  */
#line 221 "cfg_parser.y"
                                {
	if ((yyvsp[0].s)) {
		size_t l;
		l = strlen((yyvsp[0].s));
		cfg->PEM_DIR = malloc(l + 2);
		strcpy(cfg->PEM_DIR, (yyvsp[0].s));
		if (cfg->PEM_DIR[l-1] != '/')
			strcat(cfg->PEM_DIR, "/");
	}
	else
		cfg->PEM_DIR = NULL;
}
#line 1817 "cfg_parser.c"
    break;

  case 93: /* PEM_DIR_GLOB: TOK_PEM_DIR_GLOB '=' STRING  */
#line 234 "cfg_parser.y"
                                          {
	if ((yyvsp[0].s))
		cfg->PEM_DIR_GLOB = strdup((yyvsp[0].s));
	else
		cfg->PEM_DIR_GLOB = NULL;

}
#line 1829 "cfg_parser.c"
    break;

  case 94: /* OCSP_DIR: TOK_OCSP_DIR '=' STRING  */
#line 242 "cfg_parser.y"
                                  {
	free(cfg->OCSP_DIR);
	if ((yyvsp[0].s))
		cfg->OCSP_DIR = strdup((yyvsp[0].s));
	else
		cfg->OCSP_DIR = NULL;
}
#line 1841 "cfg_parser.c"
    break;

  case 95: /* OCSP_RESP_TMO: TOK_OCSP_RESP_TMO '=' UINT  */
#line 250 "cfg_parser.y"
                                          {
	cfg->OCSP_RESP_TMO = (yyvsp[0].i);
}
#line 1849 "cfg_parser.c"
    break;

  case 96: /* OCSP_CONN_TMO: TOK_OCSP_CONN_TMO '=' UINT  */
#line 254 "cfg_parser.y"
                                          {
	cfg->OCSP_CONN_TMO = (yyvsp[0].i);
}
#line 1857 "cfg_parser.c"
    break;

  case 97: /* OCSP_REFRESH_INTERVAL: TOK_OCSP_REFRESH_INTERVAL '=' UINT  */
#line 258 "cfg_parser.y"
                                                          {
	cfg->OCSP_REFRESH_INTERVAL = (yyvsp[0].i);
}
#line 1865 "cfg_parser.c"
    break;

  case 98: /* FB_CERT: TOK_PEM_FILE '=' STRING  */
#line 263 "cfg_parser.y"
                                  {
		if ((yyvsp[0].s) != NULL) {
			int r;
			struct cfg_cert_file *cert;
			cert = cfg_cert_file_new();
			cert->filename = strdup((yyvsp[0].s));
			r = cfg_cert_vfy(cert);
			if (r == 0) {
				cfg_cert_file_free(&cert);
				YYABORT;
			}
			cfg_cert_add(cert, &cur_fa->certs);
		}
	}
#line 1884 "cfg_parser.c"
    break;

  case 99: /* $@2: %empty  */
#line 277 "cfg_parser.y"
                               {
		/* NB: Mid-rule action */
		AZ(cur_pem);
		cur_pem = cfg_cert_file_new();
	}
#line 1894 "cfg_parser.c"
    break;

  case 100: /* FB_CERT: TOK_PEM_FILE '=' '{' $@2 PEM_BLK '}'  */
#line 282 "cfg_parser.y"
                    {
		if (cfg_cert_vfy(cur_pem) != 0)
			cfg_cert_add(cur_pem, &cur_fa->certs);
		else {
			cfg_cert_file_free(&cur_pem);
			YYABORT;
		}
		cur_pem = NULL;
	}
#line 1908 "cfg_parser.c"
    break;

  case 102: /* FB_CLIENT_VERIFY_CA: TOK_CLIENT_VERIFY_CA '=' STRING  */
#line 294 "cfg_parser.y"
                                                     {
	cur_fa->client_verify_ca = strdup((yyvsp[0].s));
}
#line 1916 "cfg_parser.c"
    break;

  case 103: /* FB_MATCH_GLOBAL: TOK_MATCH_GLOBAL '=' BOOL  */
#line 299 "cfg_parser.y"
                                           { cur_fa->match_global_certs = (yyvsp[0].i); }
#line 1922 "cfg_parser.c"
    break;

  case 104: /* FB_SNI_NOMATCH_ABORT: TOK_SNI_NOMATCH_ABORT '=' BOOL  */
#line 301 "cfg_parser.y"
                                                    {
		cur_fa->sni_nomatch_abort = (yyvsp[0].i);
}
#line 1930 "cfg_parser.c"
    break;

  case 105: /* FB_TLS: TOK_TLS '=' BOOL  */
#line 306 "cfg_parser.y"
                         {
	if (cur_fa->selected_protos != 0) {
		fprintf(stderr, "%s (%s, line %d):"
		    " It is illegal to specify tls after ssl,"
		    " tls or tls-protos.\n",
		    __func__, __FILE__, __LINE__);
		front_arg_destroy(cur_fa);
		cur_fa = NULL;
		YYABORT;
	}
	if ((yyvsp[0].i))
		cur_fa->selected_protos = TLS_OPTION_PROTOS;
	else
		fprintf(stderr,
		    "Warning: tls = off is deprecated and has no effect.\n");
}
#line 1951 "cfg_parser.c"
    break;

  case 106: /* FB_SSL: TOK_SSL '=' BOOL  */
#line 323 "cfg_parser.y"
                         {
	if (cur_fa->selected_protos != 0) {
		fprintf(stderr, "%s (%s, line %d):"
		    " It is illegal to specify ssl after ssl,"
		    " tls or tls-protos.\n",
		    __func__, __FILE__, __LINE__);
		front_arg_destroy(cur_fa);
		cur_fa = NULL;
		YYABORT;
	}
	if ((yyvsp[0].i))
		cur_fa->selected_protos = SSL_OPTION_PROTOS;
	else
		fprintf(stderr,
		    "Warning: ssl = off is deprecated and has no effect.\n");
}
#line 1972 "cfg_parser.c"
    break;

  case 107: /* $@3: %empty  */
#line 340 "cfg_parser.y"
                              {
	if (cur_fa->selected_protos != 0) {
		fprintf(stderr, "%s (%s, line %d):"
		    " It is illegal to specify tls-protos after"
		    " ssl, tls or tls-protos\nSelected before was %d\n",
		    __func__, __FILE__, __LINE__, cur_fa->selected_protos);
		front_arg_destroy(cur_fa);
		cur_fa = NULL;
		YYABORT;
	}
}
#line 1988 "cfg_parser.c"
    break;

  case 111: /* FB_TLS_PROTO: TOK_SSLv3  */
#line 354 "cfg_parser.y"
                    { cur_fa->selected_protos |= SSLv3_PROTO; }
#line 1994 "cfg_parser.c"
    break;

  case 112: /* FB_TLS_PROTO: TOK_TLSv1_0  */
#line 355 "cfg_parser.y"
                      { cur_fa->selected_protos |= TLSv1_0_PROTO; }
#line 2000 "cfg_parser.c"
    break;

  case 113: /* FB_TLS_PROTO: TOK_TLSv1_1  */
#line 356 "cfg_parser.y"
                      { cur_fa->selected_protos |= TLSv1_1_PROTO; }
#line 2006 "cfg_parser.c"
    break;

  case 114: /* FB_TLS_PROTO: TOK_TLSv1_2  */
#line 357 "cfg_parser.y"
                      { cur_fa->selected_protos |= TLSv1_2_PROTO; }
#line 2012 "cfg_parser.c"
    break;

  case 115: /* FB_TLS_PROTO: TOK_TLSv1_3  */
#line 358 "cfg_parser.y"
                      { cur_fa->selected_protos |= TLSv1_3_PROTO; }
#line 2018 "cfg_parser.c"
    break;

  case 116: /* FB_CIPHERS: TOK_CIPHERS '=' STRING  */
#line 360 "cfg_parser.y"
                                   {
	if ((yyvsp[0].s)) cur_fa->ciphers_tlsv12 = strdup((yyvsp[0].s));
}
#line 2026 "cfg_parser.c"
    break;

  case 117: /* FB_CIPHERSUITES: TOK_CIPHERSUITES '=' STRING  */
#line 364 "cfg_parser.y"
                                             {
	if ((yyvsp[0].s)) {
		CHECK_OBJ_NOTNULL(cur_fa, FRONT_ARG_MAGIC);
		cur_fa->ciphersuites_tlsv13 = strdup((yyvsp[0].s));
	}
}
#line 2037 "cfg_parser.c"
    break;

  case 118: /* FB_PREF_SRV_CIPH: TOK_PREFER_SERVER_CIPHERS '=' BOOL  */
#line 371 "cfg_parser.y"
                                                     {
	cur_fa->prefer_server_ciphers = (yyvsp[0].i);
}
#line 2045 "cfg_parser.c"
    break;

  case 119: /* QUIET_REC: TOK_QUIET '=' BOOL  */
#line 375 "cfg_parser.y"
                              {
	if ((yyvsp[0].i))
		cfg->LOG_LEVEL = 0;
	else
		cfg->LOG_LEVEL = 1;
}
#line 2056 "cfg_parser.c"
    break;

  case 120: /* WORKERS_REC: TOK_WORKERS '=' UINT  */
#line 382 "cfg_parser.y"
                                  { cfg->NCORES = (yyvsp[0].i); }
#line 2062 "cfg_parser.c"
    break;

  case 121: /* WORKERS_REC: TOK_WORKERS '=' TOK_AUTO  */
#line 383 "cfg_parser.y"
                                   {
	if (config_param_validate("workers", "auto", cfg, "",
		yyget_lineno()) != 0)
		YYABORT;
}
#line 2072 "cfg_parser.c"
    break;

  case 122: /* BACKLOG_REC: TOK_BACKLOG '=' UINT  */
#line 389 "cfg_parser.y"
                                  { cfg->BACKLOG = (yyvsp[0].i); }
#line 2078 "cfg_parser.c"
    break;

  case 123: /* KEEPALIVE_REC: TOK_KEEPALIVE '=' UINT  */
#line 391 "cfg_parser.y"
                                      { cfg->TCP_KEEPALIVE_TIME = (yyvsp[0].i); }
#line 2084 "cfg_parser.c"
    break;

  case 124: /* TLS_REC: TOK_TLS '=' BOOL  */
#line 393 "cfg_parser.y"
                          {
	if (cfg->SELECTED_TLS_PROTOS != 0) {
		fprintf(stderr, "%s (%s, line %d):"
		    " It is illegal to specify tls after ssl,"
		    " tls or tls-protos\n",
		    __func__, __FILE__, __LINE__);
		YYABORT;
	}
	if ((yyvsp[0].i))
		cfg->SELECTED_TLS_PROTOS = TLS_OPTION_PROTOS;
	else
		fprintf(stderr,
		    "Warning: tls = off is deprecated and has no effect.\n");
}
#line 2103 "cfg_parser.c"
    break;

  case 125: /* SSL_REC: TOK_SSL '=' BOOL  */
#line 408 "cfg_parser.y"
                          {
	if (cfg->SELECTED_TLS_PROTOS != 0) {
		fprintf(stderr, "%s (%s, line %d):"
		    " It is illegal to specify ssl after ssl,"
		    " tls or tls-protos.\n",
		    __func__, __FILE__, __LINE__);
		YYABORT;
	}
	if ((yyvsp[0].i))
		cfg->SELECTED_TLS_PROTOS = SSL_OPTION_PROTOS;
	else
		fprintf(stderr,
		    "Warning: ssl = off is deprecated and has no effect.\n");
}
#line 2122 "cfg_parser.c"
    break;

  case 126: /* $@4: %empty  */
#line 423 "cfg_parser.y"
                               {
	if (cfg->SELECTED_TLS_PROTOS != 0) {
		fprintf(stderr, "%s (%s, line %d):"
		    " It is illegal to specify tls-protos after"
		    " ssl, tls or tls-protos\n",
		    __func__, __FILE__, __LINE__);
		YYABORT;
	}
}
#line 2136 "cfg_parser.c"
    break;

  case 130: /* TLS_PROTO: TOK_SSLv3  */
#line 435 "cfg_parser.y"
                    { cfg->SELECTED_TLS_PROTOS |= SSLv3_PROTO; }
#line 2142 "cfg_parser.c"
    break;

  case 131: /* TLS_PROTO: TOK_TLSv1_0  */
#line 436 "cfg_parser.y"
                      { cfg->SELECTED_TLS_PROTOS |= TLSv1_0_PROTO; }
#line 2148 "cfg_parser.c"
    break;

  case 132: /* TLS_PROTO: TOK_TLSv1_1  */
#line 437 "cfg_parser.y"
                      { cfg->SELECTED_TLS_PROTOS |= TLSv1_1_PROTO; }
#line 2154 "cfg_parser.c"
    break;

  case 133: /* TLS_PROTO: TOK_TLSv1_2  */
#line 438 "cfg_parser.y"
                      { cfg->SELECTED_TLS_PROTOS |= TLSv1_2_PROTO; }
#line 2160 "cfg_parser.c"
    break;

  case 134: /* TLS_PROTO: TOK_TLSv1_3  */
#line 439 "cfg_parser.y"
                      { cfg->SELECTED_TLS_PROTOS |= TLSv1_3_PROTO; }
#line 2166 "cfg_parser.c"
    break;

  case 135: /* SSL_ENGINE_REC: TOK_SSL_ENGINE '=' STRING  */
#line 441 "cfg_parser.y"
                                          { if ((yyvsp[0].s)) cfg->ENGINE = strdup((yyvsp[0].s)); }
#line 2172 "cfg_parser.c"
    break;

  case 136: /* PREFER_SERVER_CIPHERS_REC: TOK_PREFER_SERVER_CIPHERS '=' BOOL  */
#line 443 "cfg_parser.y"
                                                              {
	cfg->PREFER_SERVER_CIPHERS = (yyvsp[0].i);
}
#line 2180 "cfg_parser.c"
    break;

  case 137: /* CHROOT_REC: TOK_CHROOT '=' STRING  */
#line 447 "cfg_parser.y"
                                  {
	/* XXX: passing an empty string for file */
	if ((yyvsp[0].s) && config_param_validate("chroot", (yyvsp[0].s), cfg, "",
	    yyget_lineno()) != 0)
		YYABORT;
}
#line 2191 "cfg_parser.c"
    break;

  case 138: /* BACKEND_REC: TOK_BACKEND '=' STRING  */
#line 454 "cfg_parser.y"
                                    {
	/* XXX: passing an empty string for file */
	if ((yyvsp[0].s) && config_param_validate("backend", (yyvsp[0].s), cfg, "",
	    yyget_lineno()) != 0)
		YYABORT;
}
#line 2202 "cfg_parser.c"
    break;

  case 139: /* PEM_FILE_REC: TOK_PEM_FILE '=' STRING  */
#line 462 "cfg_parser.y"
                                  {
		/* XXX: passing an empty string for file */
		if ((yyvsp[0].s) && config_param_validate("pem-file", (yyvsp[0].s), cfg, "",
		    yyget_lineno()) != 0)
			YYABORT;
	}
#line 2213 "cfg_parser.c"
    break;

  case 140: /* $@5: %empty  */
#line 468 "cfg_parser.y"
                               {
		/* NB: Mid-rule action */
		AZ(cur_pem);
		cur_pem = cfg_cert_file_new();
	}
#line 2223 "cfg_parser.c"
    break;

  case 141: /* PEM_FILE_REC: TOK_PEM_FILE '=' '{' $@5 PEM_BLK '}'  */
#line 473 "cfg_parser.y"
                    {
		if (cfg_cert_vfy(cur_pem) != 0) {
			if (cfg->CERT_DEFAULT != NULL) {
				struct cfg_cert_file *tmp = cfg->CERT_DEFAULT;
				cfg_cert_add(tmp, &cfg->CERT_FILES);
			}
			cfg->CERT_DEFAULT = cur_pem;
		} else {
			cfg_cert_file_free(&cur_pem);
			YYABORT;
		}
		cur_pem = NULL;
	}
#line 2241 "cfg_parser.c"
    break;

  case 142: /* SYSLOG_REC: TOK_SYSLOG '=' BOOL  */
#line 487 "cfg_parser.y"
                                { cfg->SYSLOG = (yyvsp[0].i); }
#line 2247 "cfg_parser.c"
    break;

  case 143: /* DAEMON_REC: TOK_DAEMON '=' BOOL  */
#line 488 "cfg_parser.y"
                                { cfg->DAEMONIZE = (yyvsp[0].i); }
#line 2253 "cfg_parser.c"
    break;

  case 144: /* SNI_NOMATCH_ABORT_REC: TOK_SNI_NOMATCH_ABORT '=' BOOL  */
#line 489 "cfg_parser.y"
                                                       {
	cfg->SNI_NOMATCH_ABORT = (yyvsp[0].i);
}
#line 2261 "cfg_parser.c"
    break;

  case 145: /* CIPHERS_REC: TOK_CIPHERS '=' STRING  */
#line 493 "cfg_parser.y"
                                    {
	if ((yyvsp[0].s)) {
		free(cfg->CIPHERS_TLSv12);
		cfg->CIPHERS_TLSv12 = strdup((yyvsp[0].s));
	}
}
#line 2272 "cfg_parser.c"
    break;

  case 146: /* CIPHERSUITES_REC: TOK_CIPHERSUITES '=' STRING  */
#line 500 "cfg_parser.y"
                                              {
	if ((yyvsp[0].s)) {
		free(cfg->CIPHERSUITES_TLSv13);
		cfg->CIPHERSUITES_TLSv13 = strdup((yyvsp[0].s));
	}
}
#line 2283 "cfg_parser.c"
    break;

  case 147: /* USER_REC: TOK_USER '=' STRING  */
#line 508 "cfg_parser.y"
                              {
	/* XXX: passing an empty string for file */
	if ((yyvsp[0].s) && config_param_validate("user", (yyvsp[0].s), cfg, "",
	    yyget_lineno()) != 0)
		YYABORT;
}
#line 2294 "cfg_parser.c"
    break;

  case 148: /* GROUP_REC: TOK_GROUP '=' STRING  */
#line 515 "cfg_parser.y"
                                {
	/* XXX: passing an empty string for file */
	if ((yyvsp[0].s) && config_param_validate("group", (yyvsp[0].s), cfg, "",
	    yyget_lineno()) != 0)
		YYABORT;
}
#line 2305 "cfg_parser.c"
    break;

  case 149: /* WRITE_IP_REC: TOK_WRITE_IP '=' BOOL  */
#line 522 "cfg_parser.y"
                                    { cfg->WRITE_IP_OCTET = (yyvsp[0].i); }
#line 2311 "cfg_parser.c"
    break;

  case 150: /* WRITE_PROXY_REC: TOK_WRITE_PROXY '=' BOOL  */
#line 524 "cfg_parser.y"
                                          { cfg->WRITE_PROXY_LINE_V2 = (yyvsp[0].i); }
#line 2317 "cfg_parser.c"
    break;

  case 151: /* WRITE_PROXY_V1_REC: TOK_WRITE_PROXY_V1 '=' BOOL  */
#line 526 "cfg_parser.y"
                                                {
	cfg->WRITE_PROXY_LINE_V1 = (yyvsp[0].i);
}
#line 2325 "cfg_parser.c"
    break;

  case 152: /* WRITE_PROXY_V2_REC: TOK_WRITE_PROXY_V2 '=' BOOL  */
#line 530 "cfg_parser.y"
                                                {
	cfg->WRITE_PROXY_LINE_V2 = (yyvsp[0].i);
}
#line 2333 "cfg_parser.c"
    break;

  case 153: /* PROXY_TLV_REC: TOK_PROXY_TLV '=' BOOL  */
#line 534 "cfg_parser.y"
                                      { cfg->PROXY_TLV = (yyvsp[0].i); }
#line 2339 "cfg_parser.c"
    break;

  case 154: /* PROXY_TLV_REC: TOK_PROXY_AUTHORITY '=' BOOL  */
#line 536 "cfg_parser.y"
                                            { cfg->PROXY_AUTHORITY = (yyvsp[0].i); }
#line 2345 "cfg_parser.c"
    break;

  case 155: /* PROXY_CCRT_REC: TOK_PROXY_CCERT '=' BOOL  */
#line 538 "cfg_parser.y"
                                         { cfg->PROXY_CLIENT_CERT = (yyvsp[0].i); }
#line 2351 "cfg_parser.c"
    break;

  case 156: /* PROXY_PROXY_REC: TOK_PROXY_PROXY '=' BOOL  */
#line 540 "cfg_parser.y"
                                          { cfg->PROXY_PROXY_LINE = (yyvsp[0].i); }
#line 2357 "cfg_parser.c"
    break;

  case 157: /* ALPN_PROTOS_REC: TOK_ALPN_PROTOS '=' STRING  */
#line 542 "cfg_parser.y"
                                            {
	/* XXX: passing an empty string for file */
	if ((yyvsp[0].s) && config_param_validate("alpn-protos", (yyvsp[0].s), cfg, "",
	    yyget_lineno()) != 0)
		YYABORT;
}
#line 2368 "cfg_parser.c"
    break;

  case 158: /* SYSLOG_FACILITY_REC: TOK_SYSLOG_FACILITY '=' STRING  */
#line 549 "cfg_parser.y"
                                                    {
	/* XXX: passing an empty string for file */
	if ((yyvsp[0].s) &&
	    config_param_validate("syslog-facility", (yyvsp[0].s), cfg, "",
	    yyget_lineno()) != 0)
		YYABORT;
}
#line 2380 "cfg_parser.c"
    break;

  case 159: /* SEND_BUFSIZE_REC: TOK_SEND_BUFSIZE '=' UINT  */
#line 557 "cfg_parser.y"
                                            { cfg->SEND_BUFSIZE = (yyvsp[0].i); }
#line 2386 "cfg_parser.c"
    break;

  case 160: /* RECV_BUFSIZE_REC: TOK_RECV_BUFSIZE '=' UINT  */
#line 559 "cfg_parser.y"
                                            { cfg->RECV_BUFSIZE = (yyvsp[0].i); }
#line 2392 "cfg_parser.c"
    break;

  case 161: /* LOG_FILENAME_REC: TOK_LOG_FILENAME '=' STRING  */
#line 561 "cfg_parser.y"
                                              {
	/* XXX: passing an empty string for file */
	if ((yyvsp[0].s) &&
	    config_param_validate("log-filename", (yyvsp[0].s), cfg, "",
	    yyget_lineno()) != 0)
		YYABORT;
}
#line 2404 "cfg_parser.c"
    break;

  case 162: /* LOG_LEVEL_REC: TOK_LOG_LEVEL '=' UINT  */
#line 569 "cfg_parser.y"
                                      { cfg->LOG_LEVEL = (yyvsp[0].i); }
#line 2410 "cfg_parser.c"
    break;

  case 163: /* SESSION_CACHE_REC: TOK_SESSION_CACHE '=' UINT  */
#line 571 "cfg_parser.y"
                                              {
#ifdef USE_SHARED_CACHE
	cfg->SHARED_CACHE = (yyvsp[0].i);
#else
	fprintf(stderr, "Hitch needs to be compiled with --enable-sessioncache "
			"for '%s'", input_line);
	YYABORT;
#endif
}
#line 2424 "cfg_parser.c"
    break;

  case 164: /* SHARED_CACHE_LISTEN_REC: TOK_SHARED_CACHE_LISTEN '=' STRING  */
#line 581 "cfg_parser.y"
                                                            {
#ifdef USE_SHARED_CACHE
	/* XXX: passing an empty string for file */
	if ((yyvsp[0].s) && config_param_validate("shared-cache-listen", (yyvsp[0].s), cfg,
		"", yyget_lineno()) != 0)
		YYABORT;
#else
	fprintf(stderr, "Hitch needs to be compiled with --enable-sessioncache "
			"for '%s'", input_line);
	YYABORT;
#endif
}
#line 2441 "cfg_parser.c"
    break;

  case 165: /* SHARED_CACHE_PEER_REC: TOK_SHARED_CACHE_PEER '=' STRING  */
#line 594 "cfg_parser.y"
                                                         {
#ifdef USE_SHARED_CACHE
	/* XXX: passing an empty string for file */
	if ((yyvsp[0].s) && config_param_validate("shared-cache-peer", (yyvsp[0].s), cfg,
		"", yyget_lineno()) != 0)
		YYABORT;
#else
	fprintf(stderr, "Hitch needs to be compiled with --enable-sessioncache "
			"for '%s'", input_line);
	YYABORT;
#endif
}
#line 2458 "cfg_parser.c"
    break;

  case 166: /* SHARED_CACHE_IF_REC: TOK_SHARED_CACHE_IF '=' STRING  */
#line 607 "cfg_parser.y"
                                                    {
#ifdef USE_SHARED_CACHE
	/* XXX: passing an empty string for file */
	if ((yyvsp[0].s) && config_param_validate("shared-cache-if", (yyvsp[0].s), cfg,
		"", yyget_lineno()) != 0)
		YYABORT;
#else
	fprintf(stderr, "Hitch needs to be compiled with --enable-sessioncache "
			"for '%s'", input_line);
	YYABORT;
#endif
}
#line 2475 "cfg_parser.c"
    break;

  case 167: /* TFO: TOK_TFO '=' BOOL  */
#line 620 "cfg_parser.y"
                      {
#ifdef TCP_FASTOPEN_WORKS
	{ cfg->TFO = (yyvsp[0].i); };
#else
	fprintf(stderr, "Hitch needs to be compiled with --enable-tfo"
			"for '%s'", input_line);
	YYABORT;
#endif
}
#line 2489 "cfg_parser.c"
    break;

  case 168: /* BACKEND_REFRESH_REC: TOK_BACKEND_REFRESH '=' UINT  */
#line 630 "cfg_parser.y"
                                                  {
	cfg->BACKEND_REFRESH_TIME = (yyvsp[0].i);
}
#line 2497 "cfg_parser.c"
    break;

  case 169: /* ECDH_CURVE_REC: TOK_ECDH_CURVE '=' STRING  */
#line 634 "cfg_parser.y"
                                          {
	if ((yyvsp[0].s)) {
		free(cfg->ECDH_CURVE);
		cfg->ECDH_CURVE = strdup((yyvsp[0].s));
	}
}
#line 2508 "cfg_parser.c"
    break;

  case 171: /* CLIENT_VERIFY_OPT: TOK_VERIFY_NONE  */
#line 644 "cfg_parser.y"
                          {
		if (cur_pem)
			cur_pem->client_verify = SSL_VERIFY_NONE;
		else if (cur_fa)
			cur_fa->client_verify = SSL_VERIFY_NONE;
		else
			cfg->CLIENT_VERIFY = SSL_VERIFY_NONE;
	}
#line 2521 "cfg_parser.c"
    break;

  case 172: /* CLIENT_VERIFY_OPT: TOK_VERIFY_OPT  */
#line 652 "cfg_parser.y"
                         {
		if (cur_pem)
			cur_pem->client_verify = SSL_VERIFY_PEER;
		else if (cur_fa)
			cur_fa->client_verify = SSL_VERIFY_PEER;
		else
			cfg->CLIENT_VERIFY = SSL_VERIFY_PEER;
	}
#line 2534 "cfg_parser.c"
    break;

  case 173: /* CLIENT_VERIFY_OPT: TOK_VERIFY_REQ  */
#line 660 "cfg_parser.y"
                         {
		if (cur_pem)
			cur_pem->client_verify =
			    SSL_VERIFY_PEER | SSL_VERIFY_FAIL_IF_NO_PEER_CERT;
		else if (cur_fa)
			cur_fa->client_verify =
			    SSL_VERIFY_PEER | SSL_VERIFY_FAIL_IF_NO_PEER_CERT;
		else
			cfg->CLIENT_VERIFY =
			    SSL_VERIFY_PEER | SSL_VERIFY_FAIL_IF_NO_PEER_CERT;
	}
#line 2550 "cfg_parser.c"
    break;

  case 174: /* CLIENT_VERIFY_CA_REC: TOK_CLIENT_VERIFY_CA '=' STRING  */
#line 672 "cfg_parser.y"
                                                      {
	free(cfg->CLIENT_VERIFY_CA);
	cfg->CLIENT_VERIFY_CA = strdup((yyvsp[0].s));
}
#line 2559 "cfg_parser.c"
    break;

  case 175: /* BACKEND_CONNECT_TIMEOUT_REC: TOK_BACKEND_CONNECT_TIMEOUT '=' UINT  */
#line 677 "cfg_parser.y"
                                                                  {
	cfg->BACKEND_CONNECT_TIMEOUT = (yyvsp[0].i);
}
#line 2567 "cfg_parser.c"
    break;

  case 176: /* SSL_HANDSHAKE_TIMEOUT_REC: TOK_SSL_HANDSHAKE_TIMEOUT '=' UINT  */
#line 681 "cfg_parser.y"
                                                              {
	cfg->SSL_HANDSHAKE_TIMEOUT = (yyvsp[0].i);
}
#line 2575 "cfg_parser.c"
    break;


#line 2579 "cfg_parser.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (cfg, YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, cfg);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, cfg);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (cfg, YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, cfg);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, cfg);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 685 "cfg_parser.y"


void
yyerror(hitch_config *cfg, const char *s)
{
	(void) cfg;

	/* Clean up if FRONTEND_BLK parsing failed */
	if (cur_fa != NULL)
		FREE_OBJ(cur_fa);

	config_error_set("Parsing error in line %d: %s: '%s'",
	    yyget_lineno(), s, strlen(input_line) > 0 ? input_line : "");
}
