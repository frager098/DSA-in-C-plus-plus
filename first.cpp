// // int main(){
// //     cout<<"hi";

// //     return 0;
// // }
// int main(){
// int arr[]={1,2,3};
// cout arr[];
// }
// #include<iostream>
// using namespace std;
// int main(){
// int arr[9]={1,3,4,5,6,7,8,9};
// }
// void insertionsort(arr){
//     int i=1;
//     int size=9;
//     for(i,i<size;i++){
//         if(arr[i]<arr[i-1]){

//         }
//     }
// }

// void insertionSort(int arr[], int n) {
//     for (int i = 1; i < n; i++) {
//         int key = arr[i];
//         int j = i - 1;

//         // Move elements greater than key one position ahead
//         while (j >= 0 && arr[j] > key) {
//             arr[j + 1] = arr[j];
//             j--;
//         }

//         arr[j + 1] = key;
//     }
// }

// int main() {
//     int arr[] = {64, 25, 12, 22, 11};
//     int n = sizeof(arr) / sizeof(arr[0]);

//     insertionSort(arr, n);

//     cout << "Sorted array: ";
//     for (int i = 0; i < n; i++) {
//         cout << arr[i] << " ";
//     }

//     return 0;
// }
// int arr[5]={1,2,3,4,5};
// void insertionSort(int size){
//     int i=1;
//     while (i-1>=0 && i<=size){
//         if(arr[i]<arr[i-1]){
//             arr[i-1]=arr[i]
//         ;}
//     }
// }
// int main(){
//         int arr[5]={1,2,3,4,5};
//     insertionSort(5);
//     cout<<arr[5];
// }
// int main(){
//     int arr[5]={23,32,50,60,19};
// }
// void selectionSort(){
//     int i=0;
//     int size=5;
//     for (i;i<size;i++){
//         if (int arr[i]<arr[i+1]){
            
//         }
//     }
// }
// #include <iostream>
// using namespace std;
// int main(){
//     cout<<"Hello";
//     return 0;
// }
#include<iostream>
#include<conio.h>
using namespace std;
int main(){
    int size;
    int arr[]={};
    cout<<"Enter size:";
    cin>>size;
    for (int i=0;i<size;++i){
        cout<<"Enter elem:";
        cin>>arr[i];
        // arr[i]=elem;
        // cout<<arr[i]<<" ";
    }
    for(int i=0;i<size;i++){
        cout<<arr[i];
    }
    
}
// int main(){
//     cout<<"Enter Size of an Array";
//     int size,elem;
//     cin>>size;
//     int arr[5];
//     for (int i=0; i < size; i++)
//     {
//         cout<<"Enter Element";
//         cin>>elem;
//         arr[5]={elem};
//         cout<<arr[i]<<" ";
//         /* code */
//     }
    
// }
 // namespace std;

// int main(){
//     // clrscr(); old code
//    std::cout<<"Welcome";
//     getch();
//     return 0;
// }
// int main(){
//     string name;
    // char arr[]="Welcome to DSA";
    // std::cout<<"Value of array is:"<<arr<<std::endl;
    // cout<<"Enter your Name:";
    // cin>>name;
    // cout<<"Your Name is :"<<name;
    // cout<<endl<<"HI";
    
    
    //Program for linear Search 
//     int arr[10]={3,1,2,29,9,75,15,11,43,78};
//     cout<<"Enter number";
//     int num;
//     cin>>num;
//     int size=10;
//     bool r;
//     for(int i=0;i<size;i++){
//         cout<<i<<" "<<r<<endl;
//         if(num==arr[i]){
//             cout<<"Number found on:"<<i<<" index"<<endl;
//              r=true;
//              cout<<r;
//             break;
//         }
//     }
//     if(r==false){
//         cout<<"Number Not found";
//     }
// }
// int main(){
//     int arr[10]={3,1,2,29,9,75,15,11,43,78};
//     cout<<"Enter number";
//     int num;
//     int result;
//     cin>>num;
//     int size=10;
//     // bool r;
//     for(int i=0;i<size;i++){
//         // cout<<i<<" "<<endl;
//         if(num==arr[i]){
//             result=arr[i];
//             cout<<result<<"found";
//         }
//     }
//     cout<<result;
// }
// int main(){
    
//     int arr[5]={2,1,5,4,3};
//     int i,size,num,result;
//     i=0;size=5;
//     cout<<"Enter Number:";
//     cin>>num;
//     for(i;i<=size;i++){
//         if(num==arr[i]){
//             result=arr[i];
//             cout<<result<<" Found at "<<i<<" index";
//             break;
//         }
        
//     }
// if(num!=arr[i]){
//     cout<<"Not Found!";
// }

// }
