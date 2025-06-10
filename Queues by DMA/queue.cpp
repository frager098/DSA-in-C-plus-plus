#include <iostream>
#include <cstdlib>
using namespace std;
struct queue{
    int num;
    queue* next;
    queue(int n):num(n),next(NULL){}
};
void enQueue(queue** front,queue** rear){
    int num;
    cout<<"Enter data: ";
    cin>>num;
    queue * ptr = new queue(num);
    if(*front==NULL && *rear==NULL){
        *front=ptr;
        *rear=*front;
    }
    else{
        (*rear) -> next = ptr;
        (*rear) = ptr;
    }
}
void deQueue(queue** front,queue** rear){
    if(*front==NULL){
        cout<<"Queue is empty!"<<endl;
    }
    else if(*front == *rear){
        delete(*front);
        *front = NULL;
        *rear = NULL ;
    }
    else{
        queue* curr=(*front);
        (*front)=curr->next;
        delete(curr);
    }
}
void print(queue** front){
    if(*front==NULL){
        cout<<"Queue is empty";
    }
    else{
    queue* curr=*front;
    while(curr!=NULL){
        cout<<"Queue: "<<curr->num<<"--->";
        curr=curr->next;
        }
    }
    cout<<endl;
}
int main(){
    int i;
    queue* front=NULL;
    queue* rear=NULL;
    while(true){
        cout<<"Press 0 to exit"<<endl;
        cout<<"Press 1 to add value in a Queue: "<<endl;
        cout<<"Press 2 to delete value in a Queue: "<<endl;
        cout<<"Press 3 to print a Queue: "<<endl;
        cin>>i;
        if(i == 0 ){
            cout<<"Exit!";
            return 0 ;
        }
        else if(i==1){
            enQueue(&front,&rear);
        }
        else if(i==2){
            deQueue(&front,&rear);
        }
        else if(i==3){
            print(&front);
        }
        else{
            cout<<"Wrong Input,Try Again!"<<endl;
        }
    }
}