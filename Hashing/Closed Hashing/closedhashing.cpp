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
        int pro=10;
            cout<<"You want to do linear probabbing or quadratic???"<<endl;
            cout<<"Press 1 for linear and 2 for quadratic and 0 to exit"<<endl;
            cin>>pro;
            if(pro==1){
                while(arr[ind] != -1){
                    ind++;
                    if(ind >= size){
                    ind = 0 ;
                    break;
                }
                if(arr[ind]== -1 ){
                    arr[ind] = key ;
                    break;
                }
                }
            }
            else if(pro==2){
                int n =1;
                int quad = ind;
                int stop =0;
                while(arr[quad] != -1 && stop != 3  ){
                    quad = ( ind + (n*n) ) % size ;
                    n++ ;
                    if(arr[quad] == -1) {
                        arr[quad] = key ;
                        break;
                    }
                    if( ind == quad  ){
                        stop++ ;
                        cout<<stop;
                    }
                    if(stop==3){
                        cout<<"Not possible with quadratic probabing now"<<endl<<"collision at "<<ind<<" index."<<endl;
                    }
                    
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
        }cout<<endl;
    }
int main(){
    int size;
    cout<<"Enter size of an array"<<endl;
    cin>>size;
    int arr[size];
    for(int i=0;i<=size;i++){
        arr[i] = -1;
    }cout<<endl;

    int inp=10;
    while(inp!=0){
    cout<<"Enter 0 to exit"<<endl;
    cout<<"Enter 1 to print"<<endl;
    cout<<"Enter 2 to insert value";
    cin>>inp;
        if(inp==0){
            cout<<"exit"<<endl;
        }
        if(inp==1){    
            print(size , arr);
        }
        if(inp==2){
            insert(size , arr);
        }
    }
}