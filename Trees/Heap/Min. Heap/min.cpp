#include <iostream>
using namespace std;

// ARRAY DECLARATION
const int MAX_SIZE = 10;
int elements[MAX_SIZE];
int heapSize = 0;

// HEAPIFY FUNCTION
void minHeapify(int index){
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int smallest = index;

    if (left < heapSize && elements[left] < elements[smallest]){
        smallest = left;
    }
    if (right < heapSize && elements[right] < elements[smallest]){
        smallest = right;
    }
    if (smallest != index){
        swap(elements[index], elements[smallest]);
        minHeapify(smallest);
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
        int current = heapSize;
        while (current > 0 && elements[current] < elements[(current - 1) / 2]){
            swap(elements[current], elements[(current - 1) / 2]);
            current = (current - 1) / 2;
        }
        heapSize++;
    }
}

// DELETE FUNCTION
void deleteValue(){
    if (heapSize == 0){
        cout << "Heap is empty";
        return;
    }

    elements[0] = elements[heapSize - 1];
    heapSize--;

    minHeapify(0);
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