#include <iostream>
#include <cstdlib>
using namespace std;
struct Record{
    int rollno;
    float GPA;
    Record *next = NULL;
};

void insert(Record*(&head),int inp1,float inp2){
    Record * ptr = new Record;
    Record *curr=head;
    if(head==NULL){
        ptr->rollno=inp1;
        ptr->GPA=inp2;
        ptr->next=NULL;
        head=ptr;

    }
    else{
        while(curr->next!=NULL){
            curr=curr->next;
        }
            ptr->rollno=inp1;
            ptr->GPA=inp2;
            ptr->next=NULL;
            curr->next=ptr;
    }
}  

// Search Function

void search(Record*(&head),int rollno){
    if (head == NULL){
        cout<<"Record is Empty!"<<endl;
        return ;
    }
    Record *curr=head;
    while(curr!=NULL){
        if(curr->rollno==rollno){
            cout<<"Your CGPA is: "<<curr->GPA<<endl;
            return;
        }
        curr=curr->next;
    }
    cout<<"Record Not Found!"<<endl;
        
}
void print(Record*(&head)){
    if (head == NULL){
        cout<<"Record is Empty!"<<endl;
        return ;
    }
    Record* curr=head;
        while(curr!=NULL){
            cout<<"Your Roll No. is: "<<curr->rollno<<" And your GPA is: "<<curr->GPA<<endl;
            curr=curr->next;
        }   
}
// Delete Function

void deleteRecord(Record*(&head),int rollno){
    if (head == NULL){
        cout<<"Record is Empty!"<<endl;
        return ;
    }
    Record *curr=head;
    Record* pre = NULL ;
    if(head->rollno==rollno){
    head= head -> next;
    free(curr);
    }
    else if( (curr-> next) != NULL && (curr->next)->rollno == rollno ){
        curr=curr->next;
        head -> next = curr -> next;
        free(curr);
    }
    else{
        while((curr )!= NULL && (curr )->rollno!=rollno){
            pre=curr;
            curr=curr->next;
        }
        if(curr == NULL){
            cout<<"Record Not Found!"<<endl;
            return;
        }
        pre->next=curr->next;
        free(curr);
    }
}

// Delete Record
void deleteAllRecords(Record*(&head)){
    if (head == NULL){
        cout<<"Record is Empty!"<<endl;
        return ;
    }
    Record*curr=head;
    while(head!=NULL){
        free(head);
        curr=curr->next;
        head=curr;
        }
}
int main(){
    Record *head=NULL;
        // i=10;
        while(true){
        int i;
        cout<<"Press 0 to exit"<<endl;
        cout<<"Press 1 to insert value"<<endl;
        cout<<"Press 2 to search value"<<endl;
        cout<<"Press 3 to print value"<<endl;
        cout<<"Press 4 to delete a Single Record"<<endl;
        cout<<"Press 5 To Delete Whole Record"<<endl;
        cin>>i;
        if(i==1){
            int inp1;
            float inp2;
            cout<<"Enter Roll NO:";
            cin>>inp1;           
            cout<<"Enter CGPA:";
            cin>>inp2;
            insert(head,inp1,inp2);           
        }
        else if(i==2){
            cout<<"Enter Roll No:";
            int rollno;
            cin>>rollno;
            search(head,rollno);
        }
        else if(i==3){
            print(head);
        }
        else if(i==4){
            cout<<"Enter Roll No:";
            int rollno;
            cin>>rollno;
            deleteRecord(head,rollno);
        }
        else if(i==5){
            deleteAllRecords(head);
        }
        else if( i == 0 ) {
            cout<<"Exit";
            break;
        }
        else{
            cout<<"Wrong Input!"<<endl;
        }
    }
}