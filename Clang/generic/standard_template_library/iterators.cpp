#include<iostream>
#include<vector>
#include <list>
#include<iterator>

void istreamIteratorExample() {
    std::cout << "숫자를 입력하세요";
    // Input stream iterator for reading numbers from std::cin
    std::istream_iterator<int> input_iter(std::cin);
    std::istream_iterator<int> end_iter; // int형이 아닌 데이터 입력시 종료

    std::vector<int> numbers(input_iter, end_iter);

    for (const auto& num : numbers) {std::cout << num << " ";}
};

void ostreamIteratorExample() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // 범위 기반의 for문을 사용하여 벡터 요소 출력
    for (int num : numbers) {std::cout << num << " ";}

    std::cout << std::endl;

    // 출력 스트림 반복자를 이용해 std::cout 객체에 벡터 요소 write
    std::ostream_iterator<int> output_iter(std::cout, " ");

    // std::cout 객체로 벡터데이터 복사
    std::copy(numbers.begin(), numbers.end(), output_iter);
}

void frontInserIteratorExample() {
    // list 컨테이너 선언 (std::list or std::deque)
    std::list<int> numbers;

    // front_insert_iterator 사용하여 list 컨테이너에 데이터 입력
    std::front_insert_iterator<std::list<int>> front_inserter(numbers);

    *front_inserter = 1;

    std::list<int> more_numbers = {3,4,5};
    std::copy(more_numbers.begin(), more_numbers.end(), front_inserter);

    *front_inserter = 2;

    for(int num : numbers) {std::cout << num << " ";} // 2 5 4 3 1

    std::list<int> num_list = {10};
    num_list.push_front(20);
    num_list.push_front(30);

    for(int num : num_list) {std::cout << num << " ";} // 30 20 10
}

void backInserIteratorExample() {
    // vector 컨테이너 선언((std::vector or std::list or std::deque))
    std::vector<int> numbers; 

    // back_insert_iterator 사용하여 vector 컨테이너에 데이터 입력
    std::back_insert_iterator<std::vector<int>> back_inserter(numbers);

    *back_inserter = 1;

    std::vector<int> more_numbers = {3,4,5};
    std::copy(more_numbers.begin(), more_numbers.end(), back_inserter);

    *back_inserter = 2;

    for(int num : numbers) {std::cout << num << " ";} // 1 3 4 5 2

    std::list<int> num_list = {10};
    num_list.push_back(20);
    num_list.push_back(30);
    for(int num : num_list) {std::cout << num << " ";} // 10 20 30
}


void bidirectionalIteratorExample() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    std::list<int> numbers2 = {10,  20, 30, 40, 50};

    // Declare a forward iterator for the vector
    std::vector<int>::iterator iter;

    // Declare a bidirectional iterator for the list
    std::list<int>::iterator iter2;

    // Forward traversal using the iterator
    for (iter = numbers.begin(); iter != numbers.end(); ++iter) {
        std::cout << *iter << " ";
    }

    std::cout << std::endl;

    // Reverse travesal usubbg the iterator
    for (iter2 = --numbers2.end(); iter2 != --numbers2.begin(); --iter2) {
        std::cout << *iter2 << " ";
    }

    std::cout << std::endl;

    //modify elements of vector
    for (iter = numbers.begin(); iter != numbers.end(); ++iter) {
        *iter *= 2;
    }

    // read and print modified elements of vector
    for (iter = numbers.begin(); iter != numbers.end(); ++iter) {
        std::cout << *iter << " ";
    }
};

void randomAcessIteratorExample() {
    // Create and initialize a vector container
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // Declare a random access iterator
    std::vector<int>::iterator it = numbers.begin();

    // 1. Access elements using iterator increment and decrement
    std::cout << "First element: " << *it << std::endl; // Access the first element
    ++it; // Move to the second element
    std::cout << "Second element: " << *it << std::endl;
    --it; // Move back to the first element
    std::cout << "First element: " << *it << std::endl;

    it = numbers.begin() + 3; // Point to the fourth element
    std::cout << "Point to the fourth element: " << *it << std::endl;

    it -= 2; // Move iterator back by two positions
    std::cout << "Point to the first element: " << *it << std::endl;


    // 2. Access elements using the subscript operator
    std::cout << "Element at index 2: " << it[2] << std::endl; // Directly access the third element (index 2)

    // 3. Use relational operators to compare iterators
    auto it_end = numbers.end(); // pointing to the position just after the last element of the container
    if (it < it_end - 1) {
        std::cout << "Iterator points to an element before the last element.\n";
    }
}