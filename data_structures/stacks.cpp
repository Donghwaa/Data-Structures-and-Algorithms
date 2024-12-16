#include<iostream>
#include<stack>
#define MAX 100 // 스택의 최대 크기

class Stack {
    private:
        int arr[MAX]; // 스택 데이터를 저장할 배열
        int top;      // 스택의 최상단을 나타내는 인덱스

    public:
        Stack() : top(-1) {}; // 초기화

        //요소 Insert
        void push(int data) {
            if (top >= MAX - 1) {
                std::cout << "스택 오버플로우!" << std::endl;
                return; 
            }
            arr[++top] = data; // 데이터 추가 후 top 증가
        }

        // 최상단 요소 반환
        int peek() {
            if (isEmpty()) {
                std::cout << "스택이 비어 있습니다" << std::endl;
                return -1;
            }
            return arr[top];
        }

        // 최상단 요소 제거(LIFO 구현)
        void pop() {
            if (isEmpty()) {
                std::cout << "스택이 비어 있습니다" << std::endl;
                return;
            }
            --top; // top 변수를 1 감소 시켜 최상단 데이터를 제거하지 않고 논리적으로 제거
        }

        //스택이 비어 있는지 확인. 비어 있으면 -1로 초기화
        bool isEmpty() {
            return top == -1;
        }

        // 스택 크기 반환
        int size() {
            return top + 1; // 요소가 한개가 추가되면 index=0으로 되어 크기는 1이 된다.
        }

};

int main() {
    Stack myStack;

    // 데이터 저장
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);

    std::cout << "스택 크기: " << myStack.size() << std::endl;
    std::cout << "스택 최상단: " << myStack.peek() << std::endl;

    //데이터 제거
    myStack.pop();
    std::cout << "(데이터 제거후)스택 최상단: " << myStack.peek() << std::endl;

    //스택 비우기
    while (!myStack.isEmpty()) {
        std::cout << "스택에서 제거: " << myStack.peek() << std::endl;
        myStack.pop();
    }

    return 0;
}