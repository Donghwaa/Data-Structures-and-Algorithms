#include<iostream>
#include<vector>
#include <list>
#include<iterator>


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
