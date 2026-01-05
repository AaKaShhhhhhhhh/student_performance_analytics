create table students(
    student_id int primary key,
    name varchar(100),
    branch varchar(100)
);

create table courses(
    course_id int primary key,
    course_name varchar(100)
    
);

create table marks(
    student_id int,
    course_id int,
    marks int,
    primary key (student_id, course_id),
    foreign key (student_id) references students(student_id),
    foreign key (course_id) references courses(course_id)
);

INSERT INTO STUDENT(student_id, name, branch)
VALUES
(1, 'Aakash Kamal', 'CSE'),
(2, 'Riya Sharma', 'IT'),
(3, 'Rahul Mehta', 'CSE'),
(4, 'Priya Singh', 'AI'),
(5, 'Vikram Patel', 'IT');

INSERT INTO COURSE(course_id, course_name)
VALUES
(1, 'Mathematics'),
(2, 'Data Structures'),
(3, 'Database Systems'),
(4, 'Operating Systems');


INSERT INTO MARKS(student_id, course_id, marks)
VALUES
(1, 1, 85),
(1, 2, 90),
(1, 3, 78),
(1, 4, 88),

(2, 1, 75),
(2, 2, 80),
(2, 3, 82),
(2, 4, 70),

(3, 1, 65),
(3, 2, 60),
(3, 3, 72),
(3, 4, 68),

(4, 1, 95),
(4, 2, 92),
(4, 3, 88),
(4, 4, 90),

(5, 1, 55),
(5, 2, 60),
(5, 3, 58),
(5, 4, 62);
