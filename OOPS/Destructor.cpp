#include <iostream>
using namespace std;

class Sample {
public:
    Sample() { cout << "Constructor called\n"; }
    ~Sample() { cout << "Destructor called\n"; }
};

int main() {
    Sample s;
    return 0;
}
