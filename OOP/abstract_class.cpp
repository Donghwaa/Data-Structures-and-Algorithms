#include<iostream>

class Account { // 추상 클래스
protected:
    double balance_; 
public:
    Account(double initial_balance) : balance_(initial_balance) {}

    virtual void withdraw(double amount) = 0; // 슨수 가상 함수
    virtual ~Account() {} // 가상 소멸자: 메모리 누수 방지
};

class SavingsAccount : public Account {
public:
    SavingsAccount(double initial_balance) : Account(initial_balance) {}

    void withdraw(double amount) override {
        if (amount > 1000) {
            std::cout << "1000원을 초과하여 출금할 수 없습니다" << std::endl;
        } else {
            balance_ -= amount;
            std::cout << "출금 금액" << amount << std::endl;
            std::cout << "계좌 잔액" << balance_ << std::endl;
        }
    }
};

int main() {
    Account* accountPtr;
    SavingsAccount savingsAccount(5000);

    accountPtr = &savingsAccount;
    accountPtr->withdraw(200);  
    accountPtr->withdraw(2000); 

    return 0;
}