#include <iostream>
#include <stdexcept>

#include "db_connector.h"

using namespace std;

#if SPA_HAS_MYSQL_HEADERS

mysql_conn_t get_connection() {
    MYSQL* con = mysql_init(nullptr);
    if (con == nullptr) {
        throw runtime_error("mysql_init failed");
    }

    if (mysql_real_connect(
            con,
            "127.0.0.1",
            "root",
            "root",
            "student_analytics",
            3306,
            nullptr,
            0) == nullptr) {
        string err = mysql_error(con);
        mysql_close(con);
        throw runtime_error("MySQL connection failed: " + err);
    }

    return con;
}

void close_connection(mysql_conn_t con) {
    mysql_close(con);
}

#else

mysql_conn_t get_connection() {
    throw runtime_error(
        "MySQL headers not found (mysql.h). Install MySQL/MariaDB Connector/C development headers, "
        "or configure your compiler include path so it can find mysql.h.");
}

void close_connection(mysql_conn_t) {
    // no-op when MySQL headers are unavailable
}

#endif