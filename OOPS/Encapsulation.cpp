#include <iostream>
using namespace std;

class BankAccount {
private:
    int balance;

public:
    void setBalance(int b) { balance = b; }
    int getBalance() { return balance; }
};

int main() {
    BankAccount acc;
    acc.setBalance(1000);
    cout << "Balance: " << acc.getBalance() << endl;
    return 0;
}
