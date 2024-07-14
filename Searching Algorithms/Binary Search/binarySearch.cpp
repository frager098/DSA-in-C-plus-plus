#include <iostream>
using namespace std;
int main(){
    int arr[5]={1,2,3,4,5};
    int inp,size,i1,mid;
    i1=0;
    cout<<"Enter NUmber";
    size=5;
    cin>>inp;
    mid=(i1+size)/2;
    while (i1!=size){
        if (inp<arr[mid]){
            mid=(i1+size)/2;
            continue;
        }
        else if(inp>arr[mid]){
            mid=(mid+size)/2;
            continue;
        }
        else{
            cout<<"Number found on:"<<mid<<" index";
            break;
        }
    }
}
    // int arr[5]={1,2,3,4,5};
    // int inp;
    // cout<<"Enter Number:";
    // cin>>inp;
    // int i1,size,mid;i1=0;size=5;
    // mid=(i1+size)/2;
    // while(mid!=i1 || mid!=size || mid<size){
    // if(inp<arr[mid]){
    //     cout<<"Required number is between "<<i1+1<<" and "<<mid+1<<" value"<<endl;
    //     mid=(i1+mid)/2;
    // }
    // else if (inp>arr[mid]){
    //     cout<<"Required number is between "<<mid+1 <<" and "<<size<<"value";
    //     mid=(mid+size)/2;
    // }
    // else if(inp==arr[mid]){
    //     cout<<"Number Found!";
    //     cout<<arr[mid];
    //     break;
    //     }
    // }
    // int arr[5]={1,2,3,4,5};
    // int i1,size,mid,num,result;
    // i1=0;size=5;mid=(i1+size)/2;
    // cout<<"Enter Number";cin>>num;
    // while(mid>=i1 || mid<=size-1){
    //     if(num<arr[mid]){
    //         mid=(i1+mid)/2;
    //         // cout<<mid," ",i1;
    //         // cout<<"g";
    //       if(mid==i1 || mid==size-1){
    //         if (num==arr[mid]){
    //         result=arr[mid];
    //         cout<<result<<" found";
    //         break;
    //         }
    //         else if(num!=arr[mid]){
    //         cout<<"Number Not Found!";
    //         break;
    //         }
    //     }
    //     }
    //     else if(num>arr[mid]){
    //         mid=(mid+size)/2;
    //         //  cout<<mid," ",i1;
    //         // cout<<"h";
    //      if(mid==i1 || mid==size-1){
    //         if (num==arr[mid]){
    //         result=arr[mid];
    //         cout<<result<<" found";
    //         break;
    //         }
    //         else if(num!=arr[mid]){
    //         cout<<"Number Not Found!";
    //         break;
    //         }
    //     }
    //     }
    //     else if(num==arr[mid]){
    //         result=arr[mid];
    //         cout<<result<<" found";
    //         break;
    //     }
    // }
// }
// #include <iostream>
// using namespace std;
// void printArr(int arr[]){

// }
// int main(){
//     int size,inp;
//     // size=1;
//     cout<<"Enter size:";
//     cin>>size;
//    int arr[size];
//     cout<<"Enter Element of an Array";
//     for(int i=0; i<size;i++){
//         cout<<"Enter element of an array";
//         cin>>inp;
//         arr[i]=inp;
//     }
//     cout<<arr[size-1]<<" ";
// int arr[0]={};
    // cout<<*(arr+5)<<" ";
    // cout<<*(arr+9)<<" ";
    // cout<<*(arr+13)<<" ";
    // cout<<*(arr+17)<<" ";
//     int arr[5]={1};
//     // cout<<arr[2]<<endl;
//     // cout<<*(&arr[2]);
//     cout<<arr[4];
// }