#include<iostream>
#include<string>


class ATM
{
public:
    static int totalWithdrawals; // 정적 멤버 변수 선언


    // 정적 멤버 함수 선언
    static void incrementWithdrawals() {
        totalWithdrawals++;
    }

    static int getTotalWithdrawals() {
        return totalWithdrawals;
    }

    // Account의 private 멤버에 직접 접근 불가
    void withdraw(double amount)
    {
        if (amount > 0) {
            incrementWithdrawals(); // 출금 횟수 증가
            std::cout << "출금 완료. 총 출금 횟수: " << getTotalWithdrawals() << std::endl; 
        } else {
            std::cout << "출금 실패" << std:: endl;
        }
    }
};

/* 
정적 멤버 변수의 정의 및 초기화
객체를 선언하지 않아도 클래스 이름을 통해 접근 가능
클래스에서 선언하고 파일 스코프에서 정의 및 초기화
외부 연결성(external linkage) 때문에 정의는 단 한 번만 진행
메모리의 데이터 영역에 할당
*/
int ATM::totalWithdrawals = 0;

int main() {
    ATM atm1, atm2;

    atm1.withdraw(100); // 총 출금 횟수: 1
    atm2.withdraw(50); // 총 출금 횟수: 2

    std::cout << "현재 총 출금 횟수: " << ATM::getTotalWithdrawals() << std::endl; 
    // (atm1, atm2 객체를 생성하지 않고) 클래스의 이름만으로 호출 가능

    return 0;
}
