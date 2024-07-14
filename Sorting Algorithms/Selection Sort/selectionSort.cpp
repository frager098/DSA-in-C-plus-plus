#include <iostream>
using namespace std;
int main()
{
  int arr[] = {3, 2, 1,5,40,-2,-43};
  int size = sizeof(arr)/sizeof(arr[0]);
  for (int i = 0; i < size; i++) //loop to hold each element one by one to swap it with min or max value in array
  {
    int min_index = i; //Variable to hold index of minimum value in array
    for (int j = i + 1; j < size; j++)//loop for comparing holded value with the whole array 
    {
      if (arr[min_index] > arr[j])
      {
        min_index = j;
      }
    }
    int min = arr[min_index]; // local variable for swapping
    arr[min_index] = arr[i];
    arr[i] = min ;
  }
  for (int i = 0; i < size; i++)
  {
    cout << arr[i] << endl;
  }
}