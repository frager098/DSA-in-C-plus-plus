

#include <iostream>
using namespace std;
void insert(int * arr , int size , int num){
    for(int i = 0 ; i < size ; i++ ){
        if(arr[i] == -1){
            arr[i] = num;
            return;
        }
    }
}

int* initializingArray(int* arr , int size)
{
    for ( int i = 0 ; i < size ; i++)
    {
        cout<<"Enter element for an array"<<endl; int key ;
        cin>>key; arr[i] = key ;
    }
    return arr;
}
void insertionSort(int * arr ,int size){
  for(int i = 1 ; i < size  ; i++){
    int key = arr[i];
    int j = i -1  ;
    while(j >= 0 && arr[j] > key ){
        arr[j+1] = arr[j] ;//Right Shift
        j--;
    }
    arr[j+1] = key;
    cout<<endl;
  }  
}

void print(int * arr,int size){
    cout<<"[";
    for(int i = 0 ; i < size ; i++ ){
        cout<<arr[i]<<" ";
    } cout<<"]"<<endl;
}
int main(){
    int size , num , inp;
    cout<<"Enter Size of An Array:";
    cin>>size;
    int * arr = new int[size];
    arr = initializingArray(arr , size);
    // int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    // size = 10;
   while(true){
    cout<<"Press 0 to Exit"<<endl;
    cout<<"Press 1 to Insert Number in an Array"<<endl;
    cout<<"Press 3 to Sort An array using Insertion Sort"<<endl;
    cout<<"Press 4 to print an Array"<<endl;
    cin>>inp;
    if(inp == 0){
        cout<<"Exit"<<endl;
        return 0;
    }
    else if(inp == 1){
        cout<<"Enter Number You want to Insert:";
        cin>>num;
        insert(arr,size,num);
    }
    else if(inp == 3 ){
        insertionSort(arr,size);
    }
    else if(inp == 4 ){
        print(arr,size);
    }
    else{
        cout<<"Wrong Input,Try Again!"<<endl;
    }
   }
}
