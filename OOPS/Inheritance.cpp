#include <iostream>
using namespace std;

class Animal {
public:
    void sound() { cout << "Animal makes sound\n"; }
};

class Dog : public Animal {};

int main() {
    Dog d;
    d.sound();
    return 0;
}
