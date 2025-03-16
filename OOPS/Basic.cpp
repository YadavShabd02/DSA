#include <iostream>
using namespace std;

class Car {
public:
    string brand;
    void print() {
        cout << "Brand: " << brand << endl;
    }
};

int main() {
    Car c;
    c.brand = "Toyota";
    c.print();
    return 0;
}
