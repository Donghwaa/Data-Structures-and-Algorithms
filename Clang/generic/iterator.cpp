#include<iostream>
#include<vector>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // 반복자 선언 및 첫 번째 요소를 가리킴
    std::vector<int>::iterator iter = numbers.begin();

    // 반복자를 통해 요소 값에 접근
    std::cout << "첫 번째 요소:" << *iter << "\n";

    // 반복자가 가리키는 요소 값을 수정
    *iter = 6;

    std::cout << "첫 번째 요소 수정: " << *iter <<"\n";

    // 반복자 대입 연산
    std::vector<int>::iterator iter1 = numbers.begin();
    std::vector<int>::iterator iter2 = numbers.end();

    iter1 = iter;
    if (iter == iter1) {
        std::cout << "iter와 iter1은 같은 요소 입니다." << "\n";
    }

    if (iter != iter2) {
        std::cout << "iter와 iter2는 다른 요소 입니다."<< "\n";
    }

    // 전위 증가 연산자
    ++iter;
    std::cout << "전위 증가: " << *iter << "\n";

    // 후위 증가 연산자
    iter++;
    std::cout << "후위 증가: " << *iter << "\n";

    return 0;
};