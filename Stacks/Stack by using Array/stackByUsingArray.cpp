#include <iostream>
#include <cstdlib>
using namespace std;
struct staticStack{
    int data;
};
void printStaticStack(staticStack* staticStackarray , int size){

    for ( int i = 0 ; i < size ; i++){
        cout<<staticStackarray[i].data<<"-->";
    }
    cout<<endl;
}
staticStack* push(staticStack* staticStackarray ,int size , int top){
    cout<<"Enter Value"<<endl;
    int value ;
    cin>>value ;
    int ind = 0 ;
    if(staticStackarray[0].data == -1){
        staticStackarray[ind].data = value ;
        staticStackarray[ind + 1].data = -1 ;
    return staticStackarray ;
    }
    else{
        while(staticStackarray[ind + 1 ].data != -1 && ind < size){
            ind++ ;
        }
        if( ind == size - 1 ){
            cout<<"Stack is full!"<<endl;
            return staticStackarray;
        }
        staticStackarray[ind + 2].data = -1 ;
        for(ind ; ind >= 0 ; ind--){

            staticStackarray [ind + 1] = staticStackarray[ind] ;
        }
        staticStackarray[top].data = value ;
    }
    return staticStackarray ;

}
staticStack* pop(staticStack* staticStackarray ,int size , int top){
    if (staticStackarray[top].data == -1){
        cout<<"array's top is already empty!"<<endl;
        return staticStackarray ;
    }
        staticStackarray[top].data = -1 ;
        return staticStackarray ;

}
int main(){
    cout<<"Enter size of static stack:";
    int size ; cin >> size;
    staticStack staticStackarray[size] ;
    int top = 0 ;
    staticStackarray[top].data  = -1 ;
    cout<<"Static stack created of size:"<<size<<endl;
    int i = 10 ;
    while ( i != 0){
    cout<<"Enter 0 to exit" <<endl;
    cout<<"Enter 1 to push value in Stack" <<endl;
    cout<<"Enter 2 to pop  Stack" <<endl;
    cout<<"Enter 3 to print Stack" <<endl;
        cin >> i ;
        if ( i == 1){
        staticStack* staticStack =  push(staticStackarray , size , top);
        }
        else if (i == 2){
            pop(staticStackarray  , size , top );
        }       
        else if (i == 3){
            printStaticStack(staticStackarray  , size);
        }       
    }
}