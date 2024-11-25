#include<iostream>

template <typename T>
T finMin(const T arr[], int size){
    T min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    return min
}

template<typename T>
T sumArray(const T arr[], int size) {
    T sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i]
    }
    return sum;
}

template<typename T>
T maxValue(T a, T b) {
    return (a > b) ? a : b
}

template<typename T> void Swap(T& a, T& b) { T temp; temp = a; a = b; b = temp; }

//explicit specialization
template<> void Swap<double>(double& a, double& b) {} 