#pragma once

#if defined(__has_include)
#  if __has_include(<mysql.h>)
#    include <mysql.h>
#    define SPA_HAS_MYSQL_HEADERS 1
#  elif __has_include(<mysql/mysql.h>)
#    include <mysql/mysql.h>
#    define SPA_HAS_MYSQL_HEADERS 1
#  else
#    define SPA_HAS_MYSQL_HEADERS 0
#  endif
#else
#  define SPA_HAS_MYSQL_HEADERS 0
#endif

#if SPA_HAS_MYSQL_HEADERS
using mysql_conn_t = MYSQL*;
#else
using mysql_conn_t = void*;
#endif

mysql_conn_t get_connection();
void close_connection(mysql_conn_t con);
