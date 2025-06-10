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
void linearSearch(int *arr,int size,int num){
    int i = 0 ;
    for( i ; i < size ; i++){
        if(num==arr[i]){
            cout<<num<<" Found at "<<i<<" index"<<endl;
            return ;
        }
    }   
    if(i == size){
        cout<<"Not Found!"<<endl;
        return;
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
    for(int i = 0 ; i < size ; i++){
        arr[i] = -1 ;
    }
   while(true){
    cout<<"Press 0 to Exit"<<endl;
    cout<<"Press 1 to Insert Number in an Array"<<endl;
    cout<<"Press 2 to Search Number in an Array"<<endl;
    cout<<"Press 3 to print an Array"<<endl;
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
    else if(inp == 2 ){
        cout<<"Enter Number You want to Search:";
        cin>>num;   
        linearSearch(arr,size,num);
    }
    else if(inp == 3 ){
        print(arr,size);
    }
    else{
        cout<<"Wrong Input,Try Again!"<<endl;
    }
   }
}
