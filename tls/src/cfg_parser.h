/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

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

#line 226 "cfg_parser.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (hitch_config *cfg);


#endif /* !YY_YY_CFG_PARSER_H_INCLUDED  */
