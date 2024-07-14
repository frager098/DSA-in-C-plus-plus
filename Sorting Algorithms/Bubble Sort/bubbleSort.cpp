#include <iostream>
using namespace std;

int main(){
  int arr[] = {6,10,2,1,0,3,5,100,30,55,-3};
  int size = sizeof(arr)/sizeof(arr[0]);
  for ( int i = 0 ; i  < size - 1 ; i++ ) //loop to iterate an array size - 1 number of times
  {
    for ( int j = 0 ; j < size - 1  ; j++) // loop to compare adjacent elements 
    {
      if(arr[j]>arr[j+1])
      {
        int temp = arr[j+1];
        arr[j+1]=arr[j];
        arr[j] = temp ;
      }
    }
  }
  for ( int i = 0 ; i < size ; i++)
  {
    cout<<arr[i]<<endl;
  }
}