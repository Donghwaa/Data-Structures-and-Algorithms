// Clang/OOP/virtual.cpp 예제와 비교
// Account에 대한 unique_ptr 생성
// 특징:
// 동적 메모리 할당: 객체는 힙(Heap)에 동적으로 생성.
// 메모리는 스마트 포인터에 의해 관리되며, 스코프가 종료될 때 자동으로 해제.

#include<iostream>
#include<memory> // std::unique_ptr를 사용하기 위해 필요

class Account {
protected:
    double balance_; // 계좌 잔고
public:
    Account(double initial_balance) : balance_(initial_balance) {}

    virtual ~Account() {} // 가상 소멸자

    virtual void withdraw(double amount) {
        balance_ -= amount;
        std::cout << "출금 금액: " << amount << std::endl;
        std::cout << "남은 잔액: " << balance_ << std::endl;
    }
};

class SavingAccount : public Account {
public:
    SavingAccount(double initial_balance) : Account(initial_balance) {}

    void withdraw(double amount) override {
        if (amount > 1000) {
            std::cout << "1000원을 초과하여 출금할 수 없습니다." << std::endl;
        } else {
            Account::withdraw(amount);
        }
    }
};

int main() {
    // Account에 대한 unique_ptr 생성
    std::unique_ptr<Account> account = std::make_unique<Account>(5000.0);
    account->withdraw(500); // Account::withdraw 호출

    // SavingAccount에 대한 unique_ptr 생성
    std::unique_ptr<Account> savingAccount = std::make_unique<SavingAccount>(3000.0);
    savingAccount->withdraw(1500); // SavingAccount::withdraw 호출, 출금 한도 초과
    savingAccount->withdraw(500);  // SavingAccount::withdraw 호출, 정상 출금

    // unique_ptr가 스코프를 벗어나면 메모리가 자동으로 해제.
    return 0;
}
