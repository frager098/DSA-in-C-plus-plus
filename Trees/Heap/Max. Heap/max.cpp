#include <iostream>
using namespace std;

// ARRAY DECLARATION
const int MAX_SIZE = 10;
int elements[MAX_SIZE];
int heapSize = 0;

// HEAPIFY FUNCTION
void maxHeapify(int index){
    int parent = (index - 1) / 2;
    while (index > 0 && elements[index] > elements[parent]){
        int temp = elements[index];
        elements[index] = elements[parent];
        elements[parent] = temp;
        index = parent;
        parent = (index - 1) / 2;
    }
}

// INSERT FUNCTION
void insert(int data){
    if (heapSize == MAX_SIZE - 1){
        cout << "Heap is full";
        return;
    }
    else{
        elements[heapSize] = data;
        maxHeapify(heapSize);
        heapSize++;
    }
}

// DELETE FUNCTION
void deleteValue(){
    elements[0] = elements[heapSize - 1];
    heapSize--;
    
    int index = 0;
    while (true){
        int left = (2 * index) + 1;
        int right = (2 * index) + 2;
        int largest = index;

        if (left < heapSize && elements[left] > elements[largest]){
            largest = left;
        }
        if (right < heapSize && elements[right] > elements[largest]){
            largest = right;
        }
        if (largest != index){
            int temp = elements[index];
            elements[index] = elements[largest];
            elements[largest] = temp;
            index = largest;
        }
        else{
            break;
        }
    }
}

// PRINT FUNCTION
void print(){
    for (int i = 0; i < heapSize; i++){
        cout << elements[i] << " ";
    }
}

// MAIN FUNCTION
int main(){
    insert(5);
    insert(10);
    insert(3);
    insert(7);
    insert(1);
    deleteValue();
    print();
    return 0;
}