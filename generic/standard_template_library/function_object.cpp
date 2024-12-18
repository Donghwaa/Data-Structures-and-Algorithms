#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>

// 함수 객체를 이용해 내림차순 정렬
void sortExample() {
    std::vector<int> numbers = {1,4,2,8,5,7};

    std::sort(numbers.begin(), numbers.end(), std::greater<int>());

    for( int num : numbers) {
        std::cout << num << " ";
    }
}

// 일반 함수
int multiply(int x, int y) {
    return x * y;
}

// 함수 객체
class Multiplier {
private:
    int factor_; // 상태를 저장하는 변수
public:
    Multiplier(int factor) : factor_(factor) {}

    // 호출 연산자 오버로딩
    int operator()(int x) {
        return x * factor_; // 내부 상태를 사용하여 동작
    }
};


int main() {
    sortExample();

    // 일반 함수는 상태를 가지지 않음.
    std::cout << "Function multiply: " << multiply(3,5) << std::endl;

    // 함수 객체는 상태를 유지.
    Multiplier multiplier(10); // 상태로 factor_ = 10 설정
    std::cout << "Multiplier with state: " << multiplier(3) << std::endl;

    return 0;
}
