#include <iostream>
using namespace std ;
void insert(int * arr , int size , int num){
    for(int i = 0 ; i < size ; i++ ){
        if(arr[i] == -1){
            arr[i] = num;
            return;
        }
    }
}

void binarySearch(int arr[] ,int size, int num){
    int i1 = 0  ;
    int mid;
    bool flag = false;
    while( i1 <= size){
        mid = (i1 + size ) / 2;
        cout<<"i1 "<<i1<<" mid:"<<mid<<" size:"<<size<<endl;
        if(arr[mid]==num){
            cout<<num<<" Found at Index:"<<mid<<endl;
            return;
        }
        else{
            if(num < arr[mid])size = mid - 1 ;
            else i1 = mid + 1;
        }
    }
    cout<<"Number Not Found!"<<endl;

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
    for(int i = 0 ; i < size ; i++ ){
        arr[i] = -1;
    } 
   while(true){
    cout<<"Press 0 to Exit"<<endl;
    cout<<"Press 1 to Insert Number in an Array"<<endl;
    cout<<"Press 3 to Search Number in an Array By Using Binary Search"<<endl;
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
        cout<<"Enter Number You want to Search:";
        cin>>num;   
        binarySearch(arr,size - 1 ,num);
    }
    else if(inp == 4 ){
        print(arr,size);
    }
    else{
        cout<<"Wrong Input,Try Again!"<<endl;
    }
   }
}
