#include<iostream>
#include<vector>
#include<algorithm> //std::find

template<class InputIterator, class T>
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

    int value_to_find = 4;

    //auto result = Find(numbers.begin(), numbers.end(), value_to_find);
    auto result = std::find(numbers.begin(), numbers.end(), value_to_find);

    if (result != numbers.end()) {
        std::cout << "Value " << value_to_find << " found at position:"
                  << std::distance(numbers.begin(), result) << std::endl;
    }   else {
        std::cout << "Value " << value_to_find << " not found in container" << std::endl;
    }

    return 0;
}
