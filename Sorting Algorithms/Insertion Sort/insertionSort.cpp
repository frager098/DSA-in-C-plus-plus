#include <iostream>
#include <iomanip>
using namespace std;
// Function for creating array 
int* initializingArray(int* arr , int size)
{
    for ( int i = 0 ; i < size ; i++)
    {
        cout<<"Enter element for an array"<<endl; int key ;
        cin>>key; arr[i] = key ;
    }
    return arr;
}
int* insertionSorting(int* unSortedArray ,int size)
{
    for ( int i = 1 ; i < size ; i++ )
    {
        int current = unSortedArray[i];
        int j = i - 1 ;
        while( j >= 0 && current < unSortedArray[j] )
        {
                unSortedArray[j+1] = unSortedArray[j];
                j-- ;
        }
        //Reason of j + 1 is coz after termination of while loop j will be lesser than 0 
                unSortedArray[j+1] = current ;
    }
    return unSortedArray ;
}
void printingArray(int* array , int size)
{
    for ( int i = 0 ; i < size ; i++ )
    {
        cout<<array[i]<<endl;
    }
}
int main()
{
    cout<<"Enter size of an Array"<<endl;
    int size ; cin>>size;
    int array[size];
    int* unSortedArray = initializingArray(array , size);
    int* sortedArray = insertionSorting(unSortedArray , size);
    printingArray(sortedArray , size );
   
}
