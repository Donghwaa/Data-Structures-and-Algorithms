#include<iostream>
#include<vector>
#include <list> // std::list uses bidirectional iterators
#include<iterator>


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
