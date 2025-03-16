#include <iostream>
using namespace std;

class Person {
public:
    string name;
    Person(string n) { name = n; }
    void display() { cout << "Name: " << name << endl; }
};

int main() {
    Person p("John");
    p.display();
    return 0;
}
