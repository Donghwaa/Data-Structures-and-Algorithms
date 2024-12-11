#include<iostream>
#include<vector>
#include <list>
#include<iterator>

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