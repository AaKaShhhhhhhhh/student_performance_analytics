#ifndef STUDENT_H
#define STUDENT_H

#include "db_connector.h"
#include <string>

void getallstudents(mysql_conn_t con);
void addstudent(mysql_conn_t con, int student_id, const std::string& name, const std::string& branch);
void viewstudent(mysql_conn_t con , int id);
void updatestudent(mysql_conn_t con, int student_id, const std::string& name, const std::string& branch);
void executequery(mysql_conn_t con, const std::string& query);

#endif
