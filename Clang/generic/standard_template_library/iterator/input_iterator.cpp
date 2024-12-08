#include<iostream>
#include<vector>
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

    std::cout << "You Enterd: ";
    for (const auto& num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

};