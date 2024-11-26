#include<iostream>
#include<string>

class ATM; // ATM클래스 전방 선언

// 계좌 데이터 캡슐화 & 보안 
class Account
{
private:
    std::string accountHolder_;
    double balance_;
    std::string pin_;

public:
    Account(std::string holder, double balance, std::string pin)
    : accountHolder_(holder), balance_(balance), pin_(pin) {}

    std::string getAccountHolder() const { return accountHolder_; }
    double getBalance() const { return getBalance(); }
    bool verifyPin(const std::string &inputPin) const { return pin_ == inputPin; }
    void withdraw(double amount) { balance_ -= amount; }

    // ATM 클래스의 showBalance 함수만 friend 멤버 함수로 선언
    friend void ATM::showBalance(const Account &account, const std::string &inputPin) const;
};

class ATM
{
public:
    // Account의 private 멤버에 접근 가능
    void showBalance(const Account &account, const std::string &inputPin) const
    {
        if (account.verifyPin(inputPin)) {
            std::cout << "계좌 소유주" << account.getAccountHolder() << std::endl;
            std::cout << "잔액" << account.getBalance() << std::endl;
        }
        else 
        {
            std::cout << "Pin 번호가 일치 하지 않습니다." << std::endl;
        }
    }

    // Account의 private 멤버에 직접 접근 불가
    void withdraw(Account &account, const std::string &inputPin, double amount)
    {
        if (account.verifyPin(inputPin)){
            if (amount > account.getBalance()) {
                std::cout << "계좌 잔액이 부족합니다" << std::endl;
            }
            else
            {
                account.withdraw(amount);
                std::cout << "출금이 완료 되었습니다. 남은 잔액은" << account.getBalance() << "원 입니다" << std::endl;
            }
        }
        else{
            std::cout << "pin 번호가 일치하지 않습니다" << std::endl;
        }
    }
};
