#include<iostream>
#include<string>

class Account
{
private:
    const std::string accountHolder_; // 상수 멤버 변수
    double balance_;
    std::string pin_;

public:
    Account(std::string holder, double balance, std::string pin)
    : accountHolder_(holder), balance_(balance), pin_(pin) {}

    std::string getAccountHolder() const { return accountHolder_; } // 상수 메서드
    double getBalance() const { return balance_; } // 상수 메서드
    bool verifyPin(const std::string &inputPin) const { return pin_ == inputPin; } // 상수 메서드

    void withdraw(double amount) { balance_ -= amount; } // 상태를 변경하므로 상수 메서드 아님

};