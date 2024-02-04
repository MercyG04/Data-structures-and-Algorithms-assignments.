#include <iostream>
#include <vector>

class Course {
public:
    std::string course_code;
    std::string course_name;

    // Constructor for Course
    Course(const std::string& code, const std::string& name)
        : course_code(code), course_name(name) {}
};

class Grade {
public:
    int mark;
    char the_grade;

    // Constructor for Grade
    Grade(int m) : mark(m) {
        calculateGrade();
    }

    // Function to calculate the grade based on the mark
    void calculateGrade() {
        if (mark > 69) {
            the_grade = 'A';
        } else if (mark > 59) {
            the_grade = 'B';
        } else if (mark > 49) {
            the_grade = 'C';
        } else if (mark > 39) {
            the_grade = 'D';
        } else {
            the_grade = 'E';
        }
    }
};

class Student {
public:
    std::string registration_number;
    std::string name;
    int age;
    Course course;
    Grade grades;
    bool grades_calculated;

    // Constructor for Student
    Student(const std::string& reg_num, const std::string& student_name, int student_age,
            const std::string& course_code, const std::string& course_name)
        : registration_number(reg_num),
          name(student_name),
          age(student_age),
          course(course_code, course_name),
          grades(0),  // Initialize grades with default mark of 0
          grades_calculated(false) {}

    // Function to edit student details
    void editDetails(int new_age) {
        age = new_age;
        std::cout << "Student details updated successfully.\n";
    }

    // Function to add marks and calculate grades
    void addMarksAndCalculateGrades(int new_mark) {
        if (!grades_calculated) {
            grades.mark = new_mark;
            grades.calculateGrade();
            grades_calculated = true;
            std::cout << "Grade calculated and added successfully.\n";
        } else {
            std::cout << "Grades for " << name << " already calculated.\n";
        }
    }
};

int main() {
    std::vector<Student> students;
    int numStudents = 0;

    // Example usage
    students.emplace_back("S001", "John Kamau", 20, "ICSI101", "Introduction to Programming");
    students[numStudents].addMarksAndCalculateGrades(75);
    students[numStudents].editDetails(21);

    return 0;
}
