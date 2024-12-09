#include<iostream>
#include<vector>
#include <list>
#include<iterator>

void vectorIteratorExample() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // Declare an iterator and point it to the first element
    std::vector<int>::iterator iter = numbers.begin();

    // Access the value of the element
    std::cout << "First element: " << *iter << "\n";

    *iter = 6;
    std::cout << "First element after update: " << *iter <<"\n";

    // iterator assignment
    std::vector<int>::iterator iter1 = numbers.begin();
    std::vector<int>::iterator iter2 = numbers.end();

    iter1 = iter;
    if (iter == iter1) {
        std::cout << "iter and iter1 point to the same element.\n";
    }

    if (iter != iter2) {
        std::cout << "iter and iter1 point to the different element.\n";
    }

    ++iter;
    std::cout << "After pre-increment: " << *iter << "\n";

    iter++;
    std::cout << "After post-increment: " << *iter << "\n";

};


void istreamIteratorExample() {
    std::cout << "Enter Numbers\n";

    // Input stream iterator for reading numbers from std::cin
    std::istream_iterator<int> input_iter(std::cin);
    std::istream_iterator<int> end_iter;

    std::vector<int> numbers(input_iter, end_iter);

    for (const auto& num : numbers) {
        std::cout << num << " ";
    }

};

void ostreamIteratorExample() {
    std::vector<int> numbers = {10, 20, 30, 40, 50};

    // Create output stream iterator to write data to std::cout
    std::ostream_iterator<int> output_iter(std::cout, " ");

    // Copy data from the vector to std::cout
    std::copy(numbers.begin(), numbers.end(), output_iter);
}


void frontInserIteratorExample() {
    // A container to store data (std::list or std::deque)
    std::list<int> numbers;

    // Create a front_insert_iterator to insert data at the front of the container
    std::front_insert_iterator<std::list<int>> front_inserter(numbers);

    *front_inserter = 1;

    std::list<int> more_numbers = {3,4,5};
    std::copy(more_numbers.begin(), more_numbers.end(), front_inserter);

    *front_inserter = 2;

    for(int num:numbers) { std::cout << num << " ";} // 2 5 4 3 1
}

void backInserIteratorExample() {
    std::vector<int> numbers; 

    // Create a front_insert_iterator to insert data at the front of the container
    std::back_insert_iterator<std::vector<int>> back_inserter(numbers);

    *back_inserter = 1;

    std::vector<int> more_numbers = {3,4,5};
    std::copy(more_numbers.begin(), more_numbers.end(), back_inserter);

    *back_inserter = 2;

    for(int num:numbers) { std::cout << num << " ";} // 1 3 4 5 2
}