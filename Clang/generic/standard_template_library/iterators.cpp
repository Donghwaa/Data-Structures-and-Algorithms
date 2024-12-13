#include<iostream>
#include<vector>
#include <list>
#include<iterator>

void istreamIteratorExample() {
    std::cout << "숫자를 입력하세요";
    // Input stream iterator for reading num_vector from std::cin
    std::istream_iterator<int> input_iter(std::cin);
    std::istream_iterator<int> end_iter; // int형이 아닌 데이터 입력시 종료

    std::vector<int> num_vector(input_iter, end_iter);

    for (const auto& num : num_vector) {std::cout << num << " ";}
};

void ostreamIteratorExample() {
    std::vector<int> num_vector = {1, 2, 3, 4, 5};

    // 범위 기반의 for문을 사용하여 벡터 요소 출력
    for (int num : num_vector) {std::cout << num << " ";}

    std::cout << std::endl;

    // 출력 스트림 반복자를 이용해 std::cout 객체에 벡터 요소 write
    std::ostream_iterator<int> output_iter(std::cout, " ");

    // std::cout 객체로 벡터데이터 복사
    std::copy(num_vector.begin(), num_vector.end(), output_iter);
}

void frontInserIteratorExample() {
    // list 컨테이너 선언 (std::list or std::deque)
    std::list<int> num_vector;

    // front_insert_iterator 사용하여 list 컨테이너에 데이터 입력
    std::front_insert_iterator<std::list<int>> front_inserter(num_vector);

    *front_inserter = 1;

    std::list<int> more_num_vector = {3,4,5};
    std::copy(more_num_vector.begin(), more_num_vector.end(), front_inserter);

    *front_inserter = 2;

    for(int num : num_vector) {std::cout << num << " ";} // 2 5 4 3 1

    std::list<int> num_list = {10};
    num_list.push_front(20);
    num_list.push_front(30);

    for(int num : num_list) {std::cout << num << " ";} // 30 20 10
}

void backInserIteratorExample() {
    // vector 컨테이너 선언((std::vector or std::list or std::deque))
    std::vector<int> num_vector; 

    // back_insert_iterator 사용하여 vector 컨테이너에 데이터 입력
    std::back_insert_iterator<std::vector<int>> back_inserter(num_vector);

    *back_inserter = 1;

    std::vector<int> more_num_vector = {3,4,5};
    std::copy(more_num_vector.begin(), more_num_vector.end(), back_inserter);

    *back_inserter = 2;

    for(int num : num_vector) {std::cout << num << " ";} // 1 3 4 5 2

    std::list<int> num_list = {10};
    num_list.push_back(20);
    num_list.push_back(30);
    for(int num : num_list) {std::cout << num << " ";} // 10 20 30
}


void bidirectionalIteratorExample() {
    std::vector<int> num_vector = {1, 2, 3, 4, 5};
    std::list<int> num_list = {10, 20, 30, 40, 50};
    
    std::vector<int>::iterator iter; // 순방향 반복자 선언
    std::list<int>::iterator list_iter; // 역방향 반복자 선언

    // 순방향 반복자 출력
    for (iter = num_vector.begin(); iter != num_vector.end(); ++iter) {
        std::cout << *iter << " ";
    }

    std::cout << std::endl;

    // 반복자를 이용한 벡터 요소 수정
    for (iter = num_vector.begin(); iter != num_vector.end(); ++iter) {*iter *= 2;}

    // 수정된 요소 출력
    for (iter = num_vector.begin(); iter != num_vector.end(); ++iter) {
        std::cout << *iter << " ";
    }

    std::cout << std::endl;

    // 역순으로 출력
    for (list_iter = --num_list.end(); list_iter != --num_list.begin(); --list_iter) {
        std::cout << *list_iter << " ";
    }

    // rbegin()과 rend() 멤버함수를 사용해서 역순으로 출력
    std::copy(num_vector.rbegin(), num_vector.rend(), std::ostream_iterator<int>(std::cout, " "));
};

void randomAcessIteratorExample() {
    std::vector<int> num_vector = {1, 2, 3, 4, 5};
    std::vector<int>::iterator it = num_vector.begin();

    // iterator 증감을 통해 요소에 접근
    std::cout << "첫 번째 요소: " << *it << std::endl;
    ++it; std::cout << "두 번째 요소: " << *it << std::endl;
    --it; std::cout << "첫 번째 요소: " << *it << std::endl;

    it = num_vector.begin() + 3; std::cout << "네 번째 요소: "<< *it << std::endl;
    it -= 2; std::cout << "두 번째 요소: " << *it << std::endl;

    // []연산자를 이용한 요소에 접근
    std::cout << "index = 2 인 요소값 접근: " << it[2] << std::endl;

    // 관계 연산자를 이용한 요소의 접근 
    auto it_end = num_vector.end();
    if (it < it_end - 1) {std::cout << "마지막 요소에 접근하지 않았습니다.\n";}
}

void constantIteratorExample() {
    std::list<int> num_list = {1,2,3};
    std::list<int>::iterator iter;
    std::list<int>::const_iterator citer;

    iter = num_list.begin();
    *iter = 10;
    citer = num_list.end();
    // *citer = 30; // 컴파일 에러

    for (int num: num_list) {std::cout << num << " ";}
}