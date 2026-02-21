#include <iostream>
#include <stdexcept>
#include "student.h"

#include "db_connector.h"


using namespace std;

// int main() {
//     try {
//         mysql_conn_t con = get_connection();
//         cout << "MySQL connection established successfully." << endl;

//         int choice;

//         while(true){
//             cout<<"1. View all Students"<<endl;
//             cout<<"2. Add Student"<<endl;
//             cout<<"3. Update Student"<<endl;
//             cout<<"4. View Student (individual)"<<endl;
//             cout<<"5. Execute Query"<<endl;
//             cout<<"6. Exit"<<endl;
//             cout<<"Enter your choice: ";
//             cin>>choice;

//             if(choice == 1){
//                 getallstudents(con);
//             }
//             else if(choice == 2){
//                 int id;
//                 string name;
//                 string branch;
//                 cout<<"Enter Student ID: ";
//                 cin>>id;
//                 cout<<"Enter Student Name: ";
//                 cin.ignore();
//                 getline(cin, name);
//                 cout<<"Enter Student Branch: ";
//                 getline(cin, branch);
//                 addstudent(con, id, name, branch);
//             }
//             else if(choice == 3){
//                 int id;
//                 string name;
//                 string branch;
//                 cout<<"Enter Student ID to update: ";
//                 cin>>id;
//                 cout<<"Enter new Student Name: ";
//                 cin.ignore();
//                 getline(cin, name);
//                 cout<<"Enter new Student Branch: ";
//                 getline(cin, branch);
//                 updatestudent(con, id, name, branch);
//             }
//             else if(choice == 4){
//                 int id;
//                 cout<<"Enter student ID"<<endl;
//                 cin>>id;
//                 viewstudent(con , id);
//             }
//             else if(choice == 5){
//                 string query;
//                 cout<<"Enter your SQL query: ";
//                 cin.ignore(); 
//                 getline(cin, query);
//                 executequery(con, query);

               
//             }
//             else if(choice == 6){
//                 cout<<"Exiting..."<<endl;
//                 break;
//             }
//             else{
//                 cout<<"Invalid choice. Please try again."<<endl;
//             }
//         }

//         close_connection(con);
//         return 0;
//     } catch (const exception& ex) {
//         cerr << ex.what() << endl;
//         return 1;
//     }
// }

int main(){
    APIClient client("http://localhost:5000");

    while(true) {
        string input;
        cout<< " Enter what you want to do"<<endl;
        getline(cin, input);
        if(input == "exit"){
            break;
        }
        QueryResult result = client.executeNLQuery(input);
        client.printQueryResult(result);
    }
    return 0;
}