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
    int i =0;
    while(i!=4){
        cout<<"Press 1 to push value in stack: "<<endl;
        cout<<"Press 2 to pop value in a stack: "<<endl;
        cout<<"Press 3 to print a stack: "<<endl;
        cout<<"Press 4 to exit"<<endl;
        cin>>i;
        if(i==1){
            push(&top);
        }
        else if(i==2){
            pop(&top);
        }
        else if(i==3){
          print(&top);
        }
    }
    if(i==4){
        cout<<"exit";
    }
}