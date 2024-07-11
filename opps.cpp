#include<iostream>
#include<string>
using namespace std;

class Teacher {
    public:
        string name;
        string dept;
        string subject;
        double salary;
};

int main() {
    Teacher t1;
    t1.name = "Bibek Joshi";
    t1.subject = "C++";
    t1.dept = "Computer Science";
    t1.salary = 25000;

    cout << t1.dept << endl;
    return 0;
}

