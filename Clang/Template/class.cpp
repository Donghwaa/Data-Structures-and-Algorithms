#include<iostream>

// Class template definition
template<typename T>
class ArrayProcessor {
private:
    const T* arr; // pointer to the array
    int size;     // size of the array

public:
    ArrayProcessor(const T* array, int arraySize) : arr(array), size(arraySize) {}

    // Find minimum value in the array
    T finMin() const {
        T min = arr[0];
        for (int i = 1; i < size; i++) {
            if (arr[i] < min) {
                min = arr[i];
            }
        }
        return min;
    }

    // calculate the sum of the array elements
    T sumArray() const {
        T sum = 0;
        for (int i = 0; i < size; i++) {
            sum += arr[i];
        }
        return sum;
    }

    // Return maxmum of two value
    static T maxValue(T a, T b) {
        return (a > b) ? a: b;
    }

    // Swap two value
    static void Swap(T& a, T& b) {
        T temp = a;
        a = b;
        b = temp;
    }

};

//Explicit  specialization : Swap Method for double type
template<> void ArrayProcessor<double>::Swap(double& a, double& b) { 
    std::cout << "Swap not supported for double type.\n";
    }

int main() {
    int arr[] = {1,2,3,4,5};
    int size = sizeof(arr) / sizeof(arr[0]);

    // ArrayProcessor instance for int type
    ArrayProcessor<int> intProcessor(arr,size);

    std::cout << "Minimum Value of Array: " << intProcessor.finMin() << std::endl; 
    std::cout << "Sum of Array: " << intProcessor.sumArray() << std::endl;
    
    int a = 10 , b = 20;
    ArrayProcessor<int>::Swap(a,b); 
    std::cout << "Swap results for int type values: " << a << ' ' << b << '\n';

    double x = 1.5, y = 2.0; 
    ArrayProcessor<double>::Swap(x,y);

    return 0;
};