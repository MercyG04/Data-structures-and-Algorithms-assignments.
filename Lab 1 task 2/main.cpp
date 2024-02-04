#include <iostream>
#include <cstring>

const int MAX_STUDENTS = 40;
const int MAX_REGISTRATION_LENGTH = 20;
const int MAX_NAME_LENGTH = 50;

struct Course {
    std::string course_code;
    std::string course_name;
};

struct Grade {
    int mark;
    char the_grade;
};

struct Student {
    std::string registration_number;
    std::string name;
    int age;
    Course course;
    Grade grades;
    bool grades_calculated;  // To track whether grades are already calculated
};

// Function prototypes
void addStudent(Student students[], int& numStudents);
void editStudentDetails(Student students[], int numStudents);
void addMarksAndCalculateGrades(Student students[], int numStudents);

int main() {
    Student students[MAX_STUDENTS];
    int numStudents = 0;

    // Example usage
    addStudent(students, numStudents);
    addMarksAndCalculateGrades(students, numStudents);
    editStudentDetails(students, numStudents);

    return 0;
}

void addStudent(Student students[], int& numStudents) {
    if (numStudents < MAX_STUDENTS) {
        Student newStudent;
        std::cout << "Enter registration number: ";
        std::cin >> newStudent.registration_number;

        std::cout << "Enter name: ";
        std::cin.ignore();  // Clear the newline character from the buffer
        std::getline(std::cin, newStudent.name);

        std::cout << "Enter age: ";
        std::cin >> newStudent.age;

        std::cout << "Enter course code: ";
        std::cin >> newStudent.course.course_code;

        std::cout << "Enter course name: ";
        std::cin.ignore();  // Clear the newline character from the buffer
        std::getline(std::cin, newStudent.course.course_name);

        students[numStudents] = newStudent;
        numStudents++;

        std::cout << "Student added successfully.\n";
    } else {
        std::cout << "Maximum number of students reached.\n";
    }
}

void editStudentDetails(Student students[], int numStudents) {
    if (numStudents == 0) {
        std::cout << "No students to edit.\n";
        return;
    }

    std::string regNumber;
    std::cout << "Enter the registration number of the student to edit: ";
    std::cin >> regNumber;

    bool found = false;
    for (int i = 0; i < numStudents; ++i) {
        if (students[i].registration_number == regNumber) {
            std::cout << "Enter new age: ";
            std::cin >> students[i].age;

            std::cout << "Student details updated successfully.\n";
            found = true;
            break;
        }
    }

    if (!found) {
        std::cout << "Student not found.\n";
    }
}

void addMarksAndCalculateGrades(Student students[], int numStudents) {
    if (numStudents == 0) {
        std::cout << "No students to add marks and calculate grades.\n";
        return;
    }

    std::string regNumber;
    std::cout << "Enter the registration number of the student: ";
    std::cin >> regNumber;

    for (int i = 0; i < numStudents; ++i) {
        if (students[i].registration_number == regNumber) {
            if (!students[i].grades_calculated) {
                std::cout << "Enter mark for " << students[i].name << ": ";
                std::cin >> students[i].grades.mark;

                // Calculate the grade based on the mark
                if (students[i].grades.mark > 69) {
                    students[i].grades.the_grade = 'A';
                } else if (students[i].grades.mark > 59) {
                    students[i].grades.the_grade = 'B';
                } else if (students[i].grades.mark > 49) {
                    students[i].grades.the_grade = 'C';
                } else if (students[i].grades.mark > 39) {
                    students[i].grades.the_grade = 'D';
                } else {
                    students[i].grades.the_grade = 'E';
                }

                students[i].grades_calculated = true;
                std::cout << "Grade calculated and added successfully.\n";
            } else {
                std::cout << "Grades for " << students[i].name << " already calculated.\n";
            }
            return;
        }
    }

    std::cout << "Student not found.\n";
}
