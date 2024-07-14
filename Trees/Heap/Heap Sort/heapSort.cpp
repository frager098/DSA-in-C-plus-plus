#include <iostream>
using namespace std;

const int MAX_SIZE = 10;
int heapArray[MAX_SIZE];
int heapSize = 0;

void minHeapify(int currentIndex) {
    int parentIndex = (currentIndex - 1) / 2;
    while (parentIndex >= 0 && heapArray[parentIndex] > heapArray[currentIndex]) {
        int temp = heapArray[currentIndex]; 
        heapArray[currentIndex] = heapArray[parentIndex];
        heapArray[parentIndex] = temp;
        currentIndex = parentIndex;
        parentIndex = (currentIndex - 1) / 2;
    }
}

void insert(int data) {
    if (heapSize == MAX_SIZE - 1) {
        cout << "Heap is full" << endl;
        return;
    }
    else {
        heapArray[heapSize] = data;
        minHeapify(heapSize);
        heapSize++;
    }
}

int deleteMin() {
    if (heapSize == 0) {
        cout << "Heap is empty" << endl;
        return -1; // Indicating failure
    }

    int minValue = heapArray[0];
    heapArray[0] = heapArray[heapSize - 1];
    heapSize--;

    int currentIndex = 0;
    while (true) {
        int leftChild = (2 * currentIndex) + 1;
        int rightChild = (2 * currentIndex) + 2;
        int smallest = currentIndex;

        if (leftChild < heapSize && heapArray[leftChild] < heapArray[smallest]) {
            smallest = leftChild;
        }
        if (rightChild < heapSize && heapArray[rightChild] < heapArray[smallest]) {
            smallest = rightChild;
        }
        if (smallest != currentIndex) {
            int temp = heapArray[currentIndex];
            heapArray[currentIndex] = heapArray[smallest];
            heapArray[smallest] = temp;
            currentIndex = smallest;
        } 
        else {
            break;
        }
    }
    return minValue;
}

void heapSort() {
    while (heapSize > 0) {
        cout << deleteMin() << " ";
    }
}

int main() {

    insert(5);
    insert(10);
    insert(3);
    insert(7);
    insert(1);

    heapSort();
    return 0;
}