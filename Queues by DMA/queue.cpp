#include <iostream>
#include <cstdlib>
using namespace std;
struct queue{
    int num;
    queue* next;
};
void enQueue(queue** front,queue** rear){
    queue* ptr=(queue*)malloc(sizeof(queue));
    int num;
    cout<<"Enter value: ";
    cin>>num;
    // queue* curr=*front;
    ptr->num=num;
    ptr->next=NULL;
    if(*front==NULL && *rear==NULL){
        *front=ptr;
        *rear=*front;
    }
    else{
        while((*rear)->next!=NULL){
            *rear=(*rear)->next;
            //  cout<<"ok";
            
        }
        (*rear)->next=ptr;
        *rear=(*rear)->next;
    }
}
void deQueue(queue** front,queue** rear){
        cout<<"g";
    queue* curr=(*front);
    (*front)=curr->next;
    free(curr);
        cout<<"hi";
}
void print(queue** front,queue** rear){
    if(*front==NULL){
        cout<<"Queue is empty";
    }
    else{
    queue* curr=*front;
    while(curr!=NULL){
        cout<<"Queue: "<<curr->num<<"--->";
        curr=curr->next;
        // if(*rear=)
    }
    }
    cout<<endl;
}
int main(){
    int i =0;
    queue* front=NULL;
    queue* rear=NULL;
    while(i!=4){
        cout<<"Press 1 to add value in a Queue: "<<endl;
        cout<<"Press 2 to delete value in a Queue: "<<endl;
        cout<<"Press 3 to print a Queue: "<<endl;
        cout<<"Press 4 to exit"<<endl;
        cin>>i;
        if(i==1){
            enQueue(&front,&rear);
        }
        else if(i==2){
            deQueue(&front,&rear);
        }
        else if(i==3){
            print(&front,&rear);
        }
    }
    if(i==4){
        cout<<"exit";
    }
}