/*연산자 오버로딩을 이용한 벡터의 내적 계산*/
#include<iostream>
#include<vector>

class Vector {
private:
    std::vector<double> elements;

public:
    // 생성자 : 벡터 초기화
    // initializer_list<double> list : 벡터의 초기 값들을 받는 리스트
    Vector(std::initializer_list<double> list) : elements(list) {}

    // 벡터의 크기 반환
    size_t size() const {
        return elements.size();
    }

    // 벡터 간 내적 계산 연산자 오버로딩
    // 매개변수 other : 내적을 계산할 다른 벡터
    double operator*(const Vector& other) const {
        // 유효성 검사
        if (this->size() != other.size()) {
            throw std::invalid_argument("Vectors must have the same size for dot product.");
        }

        // 내적 계산
        double result = 0;
        for (size_t i =0; i < this->size(); ++i) {
            result += this->elements[i] * other.elements[i];
        }
        return result;
    }


    // 벡터 및 각 요소 출력 함수
    void display() const {
        for (double val : elements) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

};

int main() {
    Vector v1 = {1.0, 2.0, 3.0};
    Vector v2 = {4.0, 5.0, 6.0};

    // 벡터 요소 출력
    std::cout << "Vector 1:" << std::endl;
    v1.display();
    std::cout << "Vector 2:" << std::endl;
    v2.display();

    // 벡터의 내적 계산
    double dotProduct = v1 * v2; // operator* 사용
    std::cout << "Dot Product:" << dotProduct << std::endl;

    return 0;
};