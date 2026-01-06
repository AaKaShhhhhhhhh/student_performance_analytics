#include <iostream>
#include <stdexcept>

#include "db_connector.h"

using namespace std;

extern void getStudents(mysql_conn_t con);

int main() {
    try {
        mysql_conn_t con = get_connection();
        cout << "MySQL connection established successfully." << endl;

        getStudents(con);

        close_connection(con);
        return 0;
    } catch (const exception& ex) {
        cerr << ex.what() << endl;
        return 1;
    }
}