// Clang/OOP/virtual.cpp 예제와 비교
// Account에 대한 스마트 포인터 생성 생성
// 특징:
// 동적 메모리 할당: 객체는 힙(Heap)에 동적으로 생성.
// 메모리는 스마트 포인터에 의해 관리되며, 스코프가 종료될 때 자동으로 해제.

#include<iostream>
#include<memory> // std::unique_ptr, std::unique_ptr std::weak_ptr 를 사용하기 위해 필요

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
    // unique_ptr 사용 예시
    // Account에 대한 unique_ptr 생성
    std::unique_ptr<Account> account = std::make_unique<Account>(5000.0);

    std::unique_ptr<Account> another_account = std::move(account); // 소유권 이전
    another_account->withdraw(500); 

    // SavingAccount에 대한 unique_ptr 생성
    std::unique_ptr<Account> savingAccount = std::make_unique<SavingAccount>(3000.0);
    savingAccount->withdraw(1500);
    savingAccount->withdraw(500);  

    // unique_ptr가 스코프를 벗어나면 메모리가 자동으로 해제.

    // shared_ptr 사용 예시
    // 특징: shared_ptr는 참조 횟수(reference count)를 통해 메모리를 공유 관리합니다.
    std::shared_ptr<Account> account1 = std::make_shared<Account>(5000.0);

    std::shared_ptr<Account> account2 = account1; // 소유권 공유

    // account1과 account2 모두 동일 객체를 참조
    account1->withdraw(500);
    account2->withdraw(300);

    // 참조 횟수가 관리되며, 마지막 shared_ptr가 소멸될 때 메모리 해제
    return 0;
}
