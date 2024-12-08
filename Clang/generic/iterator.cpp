#include<iostream>
#include<vector>

template<class InputIterator, class T> // std::find, reference: linear search algorithm
InputIterator Find(InputIterator first, InputIterator last, const T& value) {
    while (first != last) {
        if (*first == value) {
            return first;
        }
        ++first;
    }
    return last;
};

int main() {
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

    return 0;
};