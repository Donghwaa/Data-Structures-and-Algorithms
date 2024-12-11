#include<iostream>
#include<vector>


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

int main() {
    randomAcessIteratorExample();
    return 0;
}