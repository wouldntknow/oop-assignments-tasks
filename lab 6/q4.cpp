#include <iostream>
#include <string>

using namespace std;

class Course {
  public:
    string course_code;
    string course_name;

  
    int credit_hours;
    Course(string code, string name, int hours) : course_code(code), course_name(name), credit_hours(hours) {}
};

class Student {

    string id;
    string name;
    Course** courses;
    int num;
    int max_courses=5;
public:
    Student(string id, string name, int max_courses) : id(id), name(name), max_courses(max_courses) {
    courses = new Course*[max_courses];
    num = 0;
}


    ~Student() {
        delete[] courses;
    }

    void enroll(Course* course) {
        if (max_courses < 6) {
            courses[num] = course;
            num++;
        } else {
            cout << "Cannot enroll in more courses. Maximum limit reached." << endl;
        }
    }

    void drop(Course* course) {
        for (int i = 0; i < max_courses; ++i) {
            if (courses[i] == course) {
                for (int j = i; j < max_courses - 1; ++j) {
                    courses[j] = courses[j + 1];
                }
                num--;
                break;
            }
        }
    }


    void printEnrolledCourses() {
        cout << "Enrolled Courses:" << endl;
        for (int i = 0; i < num; ++i) {
            cout << "Course Code: " << courses[i]->course_code << endl;
            cout << "Course Name: " << courses[i]->course_name << endl;
            cout << "Credit Hours: " << courses[i]->credit_hours << endl;
        }
    }
   void stdData()
{
    cout<<"Student name: "<<name<<endl;
    cout<<"Student Id: "<<id<<endl;
    cout<<"Number of courses enrolled: "<<num<<endl;
    
}
};

int main() {
    Course* course1 = new Course("CS1001", "Introduction to Programming Fundamentals", 4);
    Course* course2 = new Course("MATH201", "Calculus", 3);
    Course* course3 =new Course("LA1002","Linear Algebra",3);
 Course* course4 =new Course("TA6003","Thoery of Automata",3);
  Course* course5 =new Course("NC1002","Numeical Computing",3);

    Student* student1 = new Student("5112", "Alice", 5);
     student1->stdData();
    student1->enroll(course1);
    student1->enroll(course2);
    student1->enroll(course3);
    student1->enroll(course4);
    student1->enroll(course5);
       
    student1->printEnrolledCourses();
student1->drop(course3); 
cout<<"Updated Course list after dropping one course: "<<endl;
student1->printEnrolledCourses();
    delete course1;
    delete course2;
    delete course3;
    delete course4;
    delete course5;
    delete student1;

    return 0;
}
