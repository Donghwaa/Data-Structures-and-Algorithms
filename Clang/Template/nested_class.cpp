#include <iostream>

// Outer template class
template <typename T>
class X {
public:
    // Nested template class
    template <typename U>
    class Y {
    private:
        T outerValue; // Value from the outer class
        U innerValue; // Value specific to the inner class
    public:
        // Constructor
        Y(T oValue, U iValue) : outerValue(oValue), innerValue(iValue) {}

        // Member function to display values
        void display() const;
    };

    // Outer class member function
    void outerFunction() {
        std::cout << "This is X<T>'s function.\n";
    }
};


// Constructor definition (outside the class)
template <typename T>
template <typename U>
X<T>::Y<U>::Y(T oValue, U iValue) : outerValue(oValue), innerValue(iValue) {}


// Definition of the nested class member function(outside the class)
template <typename T>
template <typename U>
void X<T>::Y<U>::display() const {
    std::cout << "Outer value (T): " << outerValue << "\n";
    std::cout << "Inner value (U): " << innerValue << "\n";
}