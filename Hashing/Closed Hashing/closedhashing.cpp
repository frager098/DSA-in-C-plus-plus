#include <iostream>
using namespace std;
void insert(int size , int *arr){
    int key;
    cout<<"Enter value:"<<endl;
    cin>>key;
    int ind;
    ind = key % (size ) ;
    if(arr[ind] == -1 ){
        arr[ind] = key ;
    }
    else{
        int pro;
        cout<<"You want to do linear probing or quadratic???"<<endl;
        cout<<"Press 1 for linear and 2 for quadratic and 0 to exit"<<endl;
        cin>>pro;
        if(pro==1){
            int start = ind;
            while(arr[ind] != -1){
                ind = (ind + 1) % size;
                if(ind == start){
                    cout<<"Hash Table is Full"<<endl;
                    return;
                }
        }
            arr[ind] = key ;
        }
        else if(pro==2){
            int n =1;
            int quad = ind;
            int attempts = 0;
            while(arr[quad] != -1 && attempts < size  ){
                quad = ( ind + (n*n) ) % size ;
                n++ ;
                attempts++ ;
            }
            if(arr[quad] == -1) {
                arr[quad] = key ;
                
            }
            else{
                cout<<"Not possible with quadratic probabing now"<<endl<<"collision at "<<ind<<" index."<<endl;
            }                   
                
        }
        else{
            cout<<"exit";
        }
    }
}

void  print(int size ,int *arr){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<"   ";
    }
    cout<<endl;
}
int main(){
    int size;
    cout<<"Enter size of an array"<<endl;
    cin>>size;
    // int arr[size];
    int *arr = new int[size];
    for(int i=0;i<size;i++){
        arr[i] = -1;
    }
    int inp;
    while(true){
    cout<<"Enter 0 to exit"<<endl;
    cout<<"Enter 1 to insert value"<<endl;
    cout<<"Enter 2 to print"<<endl;
    cin>>inp;
        if(inp==0){
            cout<<"Exit!"<<endl;
            delete(arr);
            return 0;
        }
        if(inp==1){    
            insert(size , arr);
        }
        if(inp==2){
            print(size , arr);
        }
    }
}