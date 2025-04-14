#include <iostream>
#include <vector>
#include <algorithm>

struct Student { 
    std::string id; 
    std::string name; 
    double gpa; 

    void print(const std::vector<Student>& student_list); 
    int find(const std::vector<Student>& student_list, std::string id);
    std::vector<Student> top3(const std::vector<Student>& student_list);
};

void printStudent(const Student& stu) {
    std::cout << stu.id << " " << stu.name << " " << stu.gpa << std::endl;
}

void print(const std::vector<Student>& student_list) {
    for (int i=0; i<(int)student_list.size(); i++) {
        printStudent(student_list[i]);
    }
}

bool custom_order(Student& a, Student& b) {
    return a.gpa >= b.gpa;
}

std::vector<Student> top3(const std::vector<Student>& student_list) {
    std::vector<Student> tmplist;
    std::copy(student_list.begin(), student_list.end(), back_inserter(tmplist));
    sort(tmplist.begin(), tmplist.end(), custom_order);
    tmplist.resize(3);
    return tmplist;
}

int find(const std::vector<Student>& student_list, std::string id) {
    for (int i=0; i<(int)student_list.size(); i++) {
        if (student_list[i].id == id) {
            return i;
        }
    }
    return -1;
}

int main() {
    std::vector<Student> students = {
        {"1", "Le Quang Duy", 5.5},
        {"2", "Nguyen Tan Dat", 6},
        {"10", "Cao Duy Manh", 3},
        {"4", "Nguyen Van Ngoc", 4.5},
        {"3", "Trieu Dinh Nguyen", 4}
    };
    std::vector<Student> top_students = top3(students);
    print(top_students);
    std::cout << find(students, "10") << std::endl;
    std::cout << find(students, "11") << std::endl;
}