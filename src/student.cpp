#include<iostream>
#include<stdexcept>

#include "db_connector.h"

using namespace std;

void getStudents(mysql_conn_t con) {

    if(con == nullptr) {
        throw std::runtime_error("Invalid MySQL connection.");
    }

    if(mysql_query(con, "SELECT * FROM students")){
        cout<<"Query failed because :" << mysql_error(con) << endl;
        return ;

    }

    MYSQL_RES* res = mysql_store_result(con);
    if (res == nullptr) {
        if (mysql_field_count(con) != 0) {
            cout << "Failed to fetch result: " << mysql_error(con) << endl;
        }
        return;
    }

    unsigned int num_fields = mysql_num_fields(res);
    MYSQL_FIELD* fields = mysql_fetch_fields(res);

    for (unsigned int i = 0; i < num_fields; i++) {
        cout << fields[i].name;
        if (i + 1 < num_fields) cout << "\t";
    }
    cout << endl;

    MYSQL_ROW row;
    while ((row = mysql_fetch_row(res)) != nullptr) {
        for (unsigned int i = 0; i < num_fields; i++) {
            cout << (row[i] ? row[i] : "NULL");
            if (i + 1 < num_fields) cout << "\t";
        }
        cout << endl;
    }

    mysql_free_result(res);

}
