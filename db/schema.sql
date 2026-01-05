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