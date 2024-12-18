#include<iostream>
#include<queue>
#include<vector>

void fibonacciQue(int n) {
    if (n <= 0) {
        std::cout << "n은 1 이상이어야 합니다." << std::endl;
        return;
    }

    std::queue<int> fibonacci;

    fibonacci.push(0);
    fibonacci.push(1);
    std::cout << "피보나치 수열: ";

    for (int i=0;i <n;++i) {
        // 큐의 앞 2개 값을 더하여 다음 값을 계산
        int first = fibonacci.front();
        fibonacci.pop();
        int second = fibonacci.front();

        std::cout << first << " ";

        fibonacci.push(first+second);
    }
    std::cout << std::endl;
}

void maxHeap() {
    // 우선순위 큐 (최대 힙 자료구조 구현)
    std::priority_queue<int> maxheap;

    // 데이터 삽입
    maxheap.push(10);
    maxheap.push(5);
    maxheap.push(20);
    maxheap.push(25);

    std::cout << "우선순위 큐 (최대 힙): " << std::endl;
    while(!maxheap.empty()) {
        std::cout << maxheap.top() << " "; // 가장 큰 값을 출력
        maxheap.pop();                     // 가장 큰 값을 제거
    }
    std::cout << std::endl;

}

void minHeap() {
    std::priority_queue< int, std::vector<int>, std::greater<int> > minheap;

    minheap.push(10);
    minheap.push(5);
    minheap.push(20);
    minheap.push(25);

    std::cout << "우선순위 큐(최소 힙):" << std::endl;
    while (!minheap.empty()) {
        std::cout << minheap.top() << " ";       // 가장 작은값 출력
        minheap.pop();                           // 가장 작은값 제거
    }
    std::cout << std::endl;
}