#include <iostream>
#include <stdexcept>
#include <string>

#include "student.h"

using namespace std;

static string escape_sql_string(mysql_conn_t con, const string& input) {
    if (con == nullptr) {
        return input;
    }

    string out;
    out.resize(input.size() * 2 + 1);
    unsigned long escaped_len = mysql_real_escape_string(con, &out[0], input.c_str(), (unsigned long)input.size());
    out.resize(escaped_len);
    return out;
}

static void print_result(mysql_conn_t con) {
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

void getallstudents(mysql_conn_t con) {

    if(con == nullptr) {
        throw std::runtime_error("Invalid MySQL connection.");
    }

    if (mysql_query(con, "SELECT student_id, name, branch FROM students")) {
        cout << "Query failed because :" << mysql_error(con) << endl;
        return;
    }

    print_result(con);

}

void addstudent(mysql_conn_t con, int student_id, const std::string& name, const std::string& branch) {
    if (con == nullptr) {
        throw std::runtime_error("Invalid MySQL connection.");
    }

    string esc_name = escape_sql_string(con, name);
    string esc_branch = escape_sql_string(con, branch);

    string query =
        "INSERT INTO students (student_id, name, branch) VALUES (" +
        to_string(student_id) + ", '" + esc_name + "', '" + esc_branch + "')";

    if (mysql_query(con, query.c_str())) {
        cout << "Insert Query failed because :" << mysql_error(con) << endl;
        return;
    }

    cout << "Student added." << endl;
}

void viewstudent(mysql_conn_t con, int id) {
    if (con == nullptr) {
        throw std::runtime_error("Invalid MySQL connection.");
    }

    string query = "SELECT student_id, name, branch FROM students WHERE student_id = " + to_string(id);

    if (mysql_query(con, query.c_str())) {
        cout << "Select Query failed because :" << mysql_error(con) << endl;
        return;
    }

    print_result(con);
}

void updatestudent(mysql_conn_t con, int student_id, const std::string& name, const std::string& branch) {
    if (con == nullptr) {
        throw std::runtime_error("Invalid MySQL connection.");
    }

    string esc_name = escape_sql_string(con, name);
    string esc_branch = escape_sql_string(con, branch);

    string query =
        "UPDATE students SET name = '" + esc_name + "', branch = '" + esc_branch +
        "' WHERE student_id = " + to_string(student_id);

    if (mysql_query(con, query.c_str())) {
        cout << "Update Query failed because :" << mysql_error(con) << endl;
        return;
    }

    cout << "Student updated. Rows affected: " << mysql_affected_rows(con) << endl;
}

void executequery(mysql_conn_t con, const std::string& query){
    if (con == nullptr) {
        throw std::runtime_error("Invalid MySQL connection.");
    }

    if (mysql_query(con, query.c_str())) {
        cout << "Query failed because :" << mysql_error(con) << endl;
        return;
    }

    if (mysql_field_count(con) == 0) {
        cout << "Query OK. Rows affected: " << mysql_affected_rows(con) << endl;
        return;
    }

    print_result(con);
    //void 
}