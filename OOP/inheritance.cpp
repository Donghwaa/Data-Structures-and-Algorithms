#include<iostream>
#include<string>

class Account
{
private:
    std::string accountHolder_;
    double balance_;
    std::string pin_;

public:
    Account(std::string holder, double balance, std::string pin)
    : accountHolder_(holder), balance_(balance), pin_(pin) {}

    ~Account() {
        std::cout << "Account 소멸자 호출" << std::endl;
    }

    std::string getAccountHolder() const { return accountHolder_; }
    double getBalance() const { return getBalance(); }
    bool verifyPin(const std::string &inputPin) const { return pin_ == inputPin; }
    void withdraw(double amount) { balance_ -= amount; }

};

// 기록 기능 제공 클래스
class Logger {
public:
    Logger() {
        std::cout << "Logger 생성자 호출" << std::endl;
    }

    ~Logger() {
        std::cout << "Logger 소멸자 호출" << std::endl;
    }


    void log(const std::string &message) const {
        std::cout << "[Log]: " << message << std::endl;
    }
};

// 저축 계좌 : 이자를 제공하고 특정 조건에서만 출금 가능
// Account의 모든 멤버가 private로 상속. SavingsAccountWithLogger에서만 기초 클래스 멤버 접근 가능
class SavingsAccountWithLogger : private Account, public Logger {
private:
    double interestRate_; // 이자율

public:
    // 파생 클래스는 기초 클래스의 멤버를 사용하기 떄문에 객체 생성 순서가 중요
    // 생성 순서 : Account -> Logger -> SavingsAccountWithLogger
    // 소멸 순서 : SavingsAccountWithLogger -> Logger -> Account
    SavingsAccountWithLogger(std::string holder, double balance, std::string pin, double interestRate)
    : Account(holder, balance, pin), interestRate_(interestRate) {}

    ~SavingsAccountWithLogger() {
        std::cout << "SavingsAccountWithLogger 소멸자 호출" << std::endl;
    }

    // 이자 계산 메서드
    double calculateInterest() const {
        log("이자를 계산합니다"); // 비-const 함수 호출시 오류 발생하므로, log 메서드도 const 선언해야한다.
        return getBalance() * interestRate_;
    }

    // 출금 조건을 오버라이드
    void withdraw(double amount) {
        if (amount > 1000) { // 예 : 1000원 이상 출금 불가
            std::cout << "저축 계좌에서 한 번에 1000원을 초과하여 출금할 수 없습니다." << std::endl;
        } else {
            Account::withdraw(amount); // 기본 출금 로직
        }
    }

    // Account 클래스를 private로 상속하였기 때문에 외부에서 접근할 수 있는 메서드 추가
    std::string getAccountHolder() const {
        return Account::getAccountHolder(); 
    }

    // Account 클래스를 private로 상속하였기 때문에 외부에서 접근할 수 있는 메서드 추가
    double getBalance() const {
        return Account::getBalance();
    }

};