#include <iostream>
using namespace std;
// int swap(int *a,int *b){
//     int t=*a;
//     *a=*b;
//     *b=t;
//     }
int main(){
    // int a=3;
    
    // int b=9;
    // int *ptr1,*ptr2;
    // ptr1=&a;ptr2=&b;
    // cout<<ptr1<<endl;
    // cout<<ptr2<<endl;
    // cout<<*ptr1<<endl<<*ptr2<<endl;
    // cout<<ptr1+4<<endl;
    // float c,d;
    // c=1.3;d=1.4;
    // float *ptr3;
    // float *ptr4;
    // ptr3=&c;
    // ptr4=&d;
    // cout<<ptr3<<endl<<ptr4<<endl;
    // cout<<*ptr3;
//     int x,y;
//     cout<<"Enter x and y";
//     cin>>x;cin>>y;
//     swap(&x,&y);
//     cout<<x<<endl<<y;
// }
// return type +function name(arguments){
// cout<<arr<<endl;

// cout<<arr[2]<<endl;
// arr[2]=5;
// cout<<&(arr[2])<<endl;
cout<<"Enter size";
int size;
cin>>size;
int arr[size];
int elem;
for (int i=0;i<size;i++){
    cout<<"Enter element:";
    cin>>elem;
    arr[i]=elem;
    arr[size]=arr[i];
    cout<<arr[size];
}
}