# Student Performance Analytics System – Design Document

## 1. Problem Statement

Colleges often store student marks but lack a simple system to analyze academic performance. Faculty and administrators need quick insights such as average scores, rankings, and identification of weak students or subjects.

The goal of this project is to build a **backend-focused system** that stores student performance data and generates useful analytics using **C++ and SQL**, without relying on any frontend framework.

This system is designed to demonstrate backend logic, database design, and analytical thinking suitable for a **Software Engineering Intern** role.

---

## 2. Objectives

* Store student, course, and marks data in a relational database
* Perform analytical queries on stored data
* Generate insights such as averages, rankings, and thresholds
* Design a clean, normalized database schema
* Optimize queries for performance

---

## 3. Scope of the Project

### In Scope

* Command-line based interaction (CLI)
* Relational database (MySQL)
* Backend logic written in C++
* SQL-based analytics

### Out of Scope

* Web or mobile UI
* Authentication / login system
* Cloud deployment

---

## 4. Entities and Attributes

### 4.1 Student

* student_id (INT, Primary Key)
* name (VARCHAR)
* branch (VARCHAR)

### 4.2 Course

* course_id (INT, Primary Key)
* course_name (VARCHAR)

### 4.3 Marks

* student_id (INT, Foreign Key → Student)
* course_id (INT, Foreign Key → Course)
* marks (INT)

Composite Primary Key:

* (student_id, course_id)

---

## 5. Database Relationships

* One student can have marks in multiple courses
* One course can have marks for multiple students
* Relationship between Student and Course is **many-to-many**, resolved using the Marks table

---

## 6. Use Cases

### Core Operations

* Add a new student
* Add a new course
* Assign marks to a student for a course
* View all students
* View all courses

### Analytics Operations

* Calculate average marks per student
* Rank students based on average marks
* Identify students below a performance threshold
* Calculate subject-wise average marks

---

## 7. Functional Requirements

* System must allow insertion of student, course, and marks data
* System must prevent duplicate entries using primary keys
* System must validate input data (e.g., marks between 0–100)
* System must support analytical SQL queries

---

## 8. Non-Functional Requirements

* Queries should execute efficiently for large datasets
* Code should be modular and readable
* Database schema should follow normalization principles (3NF)

---

## 9. High-Level System Flow

1. User selects an operation from CLI menu
2. C++ application processes input
3. SQL query is executed on MySQL database
4. Result is fetched and displayed to the user

---

## 10. Example Analytics Queries (Conceptual)

* Average marks per student
* Top N students by average score
* Students scoring below a given threshold
* Course-wise performance analysis

---

## 11. Future Enhancements (Optional)

* Export analytics results to CSV
* Add semester-wise performance tracking
* Integrate visualization layer

---

## 12. Learning Outcomes

* Hands-on experience with backend system design
* Strong understanding of SQL joins and aggregations
* Practice with performance optimization using indexing
* Improved problem-solving and system thinking
