#include <iostream>
using namespace std ;
int main(){
    
    int arr[5]={2,1,5,4,3};
    int i,size,num,result;
    i=0;size=5;
    cout<<"Enter Number:";
    cin>>num;
    for(i;i<=size;i++){
        if(num==arr[i]){
            result=arr[i];
            cout<<result<<" Found at "<<i<<" index";
            break;
        }
        
    }
if(num!=arr[i]){
    cout<<"Not Found!";
}

}
