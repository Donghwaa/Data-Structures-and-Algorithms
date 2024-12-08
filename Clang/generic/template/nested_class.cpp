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
        Y(T oValue, U iValue);

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

// class template with two template arguments
template<typename T = double, int i =3>
class Example {
public:
    T data[i]; // Array size is degermined by the template argument

    void display() {
        for (int j=0; j<i; ++j)
            std::cout << data[j] << " ";
        std::cout << "\n";
    }
};

template<typename T>
class Base {
public:
    T value;
    Base(T v) : value(v) {} // constructor initialize value
    void show() { std::cout << "Base value: " << value << "\n"}
};

template<typename T>
class Derieved : public Base<T> {
public:
    Derieved(T v) : Base<T>(v) {} // constuctor passes value to the base class
    void display() { std::cout << "Derived value (via Base): " << this->value << "\n"; }
};

// define general template
template<typename T>
class A {
public:
    void display() { std::cout << "Generla template type for T\n"; }
};

// define specialized template for double type
template<>
class A<double> {
public:
    void display() { std::cout << "Specialized template for type double\n"; }
};

// define gerenal template
template<typename T, typename U>
class B {
public: void display() { std::cout << "General template for T and U\n"; }
};

// define partial specialization template
template<typename U>
class B<int ,U> {
public: void display() { std::cout << "Partial specialization: T is int\n"}
};

// define partial specialization template
template<typename T>
class B<T, double> {
public: void display() { std::cout << "Partial specialtiztion: U is double\n"; }
};