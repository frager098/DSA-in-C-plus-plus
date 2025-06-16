// #include <iostream>
// #include <iomanip>
// using namespace std;
// // Function for creating array 
// int* initializingArray(int* arr , int size)
// {
//     for ( int i = 0 ; i < size ; i++)
//     {
//         cout<<"Enter element for an array"<<endl; int key ;
//         cin>>key; arr[i] = key ;
//     }
//     return arr;
// }
// int* insertionSorting(int* unSortedArray ,int size)
// {
//     for ( int i = 1 ; i < size ; i++ )
//     {
//         int current = unSortedArray[i];
//         int j = i - 1 ;
//         while( j >= 0 && current < unSortedArray[j] )
//         {
//                 unSortedArray[j+1] = unSortedArray[j];
//                 j-- ;
//         }
//         //Reason of j + 1 is coz after termination of while loop j will be lesser than 0 
//                 unSortedArray[j+1] = current ;
//     }
//     return unSortedArray ;
// }
// void printingArray(int* array , int size)
// {
//     for ( int i = 0 ; i < size ; i++ )
//     {
//         cout<<array[i]<<endl;
//     }
// }
// int main()
// {
//     cout<<"Enter size of an Array"<<endl;
//     int size ; cin>>size;
//     int array[size];
//     int* unSortedArray = initializingArray(array , size);
//     int* sortedArray = insertionSorting(unSortedArray , size);
//     printingArray(sortedArray , size );
   
// }

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
void insertionSort(int * arr ,int size){
  for(int i = 1 ; i < size  ; i++){
    // int start = i ;
        for(int j = i - 1 ; j >= 0 ; j--){
            for(int k = j-1 ; k > 0 ;k--){
                if(arr[k] < arr[j]){
                    int temp = arr[k];
                    arr[k] = arr[j];
                    arr[j] = temp ;
                }     

            }
            // for(int k = j - 1 ; )
          }
    // i = start ;
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
    // cout<<"Enter Size of An Array:";
    // cin>>size;
    // int * arr = new int[size];
    // for(int i = 0 ; i < size ; i++ ){
    //     arr[i] = -1 ;
    // } 
    int arr[10] = {100,-9,-34,40,3,1,2,12,42,23};
    size = 10;
   while(true){
    cout<<"Press 0 to Exit"<<endl;
    cout<<"Press 1 to Insert Number in an Array"<<endl;
    cout<<"Press 3 to Sort An array using Bubble Sort"<<endl;
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
