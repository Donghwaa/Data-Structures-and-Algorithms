// Clang/Template/smart_pointer.cpp 예제와 비교
// Account에 대한 unique_ptr 생성
// 특징:
// 동적 메모리 할당: 객체는 스택(Stack)에 동적으로 생성.

#include<iostream>

class Account {
protected:
    double balance_; // 계좌 잔고
public:
    Account(double initial_balance) : balance_(initial_balance) {}

    virtual ~Account() {} // 가상 소멸자

    // void withdraw(double amount) {
    virtual void withdraw(double amount) {
        balance_ -= amount;
        std::cout << "출금 금액: " << amount << std::endl;
        std::cout << "남은 잔액: " << balance_ << std::endl;
    }
};

class SavingAccount : public Account {
public:
    SavingAccount(double initial_balance) : Account(initial_balance) {}
    
    // void withdraw(double amount) { // 재정의
    void withdraw(double amount) override {
        if(amount > 1000) {
            std::cout << "1000원을 초과하여 출금할 수 없습니다." << std::endl;
        } else {
            Account::withdraw(amount);
        }
    }
};

int main() {
    Account* accountPtr; // 기본 클래스(Account)의 포인터
    // 이 포인터는 실행 시간(run time)에 어떤 객체(basicAccount 또는 savingsAccount)를 가리키는지 결정

    Account basicAccount(5000); 
    SavingAccount savingsAccount(5000); 

    // 포인터가 기본 클래스 객체를 가리키는 경우
    accountPtr = &basicAccount;
    accountPtr->withdraw(500); // Account::withdraw 호출

    // 포인터가 파생 클래스 객체를 가리키는 경우
    accountPtr = &savingsAccount;
    accountPtr->withdraw(2000);  // SavingAccount::withdraw 호출, 출금 한도 확인

    return 0;
}
