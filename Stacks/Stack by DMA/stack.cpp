#include <iostream>
#include <cstdlib>
using namespace std;
struct stack{
    int num;
    stack* next;
};
void push(stack** top){
    stack* ptr = (stack*)malloc(sizeof(stack));
    cout<<"Enter Number:";
    int num;
    cin>>num;
    ptr->num = num;
    ptr->next = NULL;
    if(*top == NULL){
        *top = ptr;
        cout<<"NULL";
    }
    else{
        ptr->next = *top;
        *top = ptr;
    }
}

void pop(stack** top){
    stack* curr = *top;
    *top=curr->next;
    free(curr);
    }

void print(stack** top){
    stack* curr=*top;
    while(curr!=NULL){
        cout<<"Stack: "<<curr->num<<"--->";
        curr=curr->next;
    }
    cout<<endl;
}
int main(){
    stack* top=NULL;
    int i ;
    while(true){
        cout<<"Press 0 to exit"<<endl;
        cout<<"Press 1 to push data in stack: "<<endl;
        cout<<"Press 2 to pop data in a stack: "<<endl;
        cout<<"Press 3 to print data in a stack: "<<endl;
        cout<<"Enter:";
        cin>>i;
        if(i == 0 ){
            cout<<"Exit!";
            return 0 ;
        }
        else if(i==1){
            push(&top);
        }
        else if(i==2){
            pop(&top);
        }
        else if(i==3){
          print(&top);
        }
        else{
            cout<<"Wrong Input,Try Again!"<<endl;
        }
    }
}