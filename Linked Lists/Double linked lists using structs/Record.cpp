#include <iostream>
#include <cstdlib>
using namespace std;
struct Record{
    int rollno;
    float GPA;
    Record *next;
    Record* pre;
    Record(int r , float g):rollno(r),GPA(g),next(NULL),pre(NULL){}
};
void insert(Record**head){
    int rollno;
    float GPA;
    cout<<"Enter roll no: ";
    cin>>rollno;
    cout<<"Enter GPA: ";
    cin>>GPA;
    Record*ptr= new Record(rollno,GPA);
    Record*curr=*head;
    if(*head==NULL){
        *head=ptr;
    }
    else{
        while(curr->next!=NULL){
            curr=curr->next;
        }
        ptr->pre= curr;
        curr->next=ptr;
    }
    cout<<"Record inserted Successfully"<<endl;
}
void search(Record**head){
    if(*head == NULL){
        cout<<"Records are empty"<<endl;
        return;
    }
    Record* curr=*head;
    int rollno;
    cout<<"Enter roll no. that you wanna search : ";
    cin>>rollno;
    if(curr->rollno==rollno){
        cout<<"Your GPA is:"<<curr->GPA<<endl;
    }
    else{
        while(curr!=NULL){
            curr=curr->next;
            if(curr != NULL && curr->rollno==rollno){
                cout<<"Your GPA is:"<<curr->GPA<<endl;
                return;
            }
        }      
        cout<<"Record Not Found!"<<endl;
    }   
}
void deleteSingleRecord(Record**head){
    if(*head == NULL){
        cout<<"Records are empty"<<endl;
        return;
    }
    Record* curr=*head;cout<<"Enter roll no. you wanna delete:";
    int rollno;cin>>rollno;
    if(curr->rollno==rollno){
        if(curr -> next != NULL){
            (*head)=curr->next;
            (*head)->pre=NULL;
            delete(curr);
            cout<<"Record deleted Successfully"<<endl;
            return;
        }
        else{
            delete(*head);
            *head = NULL ;
            return;

        }
    }
    else{ 
        while(curr ->next !=NULL){
            curr=curr->next;
            if(curr->rollno == rollno){
                if(curr -> next != NULL){
                    (curr->pre)->next=curr->next;
                    delete(curr);
                    cout<<"Record deleted Successfully"<<endl;
                    return;
                }
                else{
                    cout<<"Hi";
                    (curr -> pre) -> next = NULL;
                    delete(curr); 
                    return;
                }
            }
        }
    }
    cout<<"Record Not Found!"<<endl;

}
void print(Record**head){
    if(*head == NULL){
        cout<<"Records are empty"<<endl;
        return;
    }
    Record * curr = *head;
    while(curr!=NULL){
        cout<<"Address is:"<<" "<<curr<<endl;
        cout<<"Your Roll No. is:"<<" "<<curr->rollno<<"   ";
        cout<<"And your GPA is:"<<" "<<curr->GPA<<endl;
        curr=curr->next;
    }
    cout<<"All Records are printed successfully!"<<endl;

}
void deleteAllRecords(Record**head){
    if(*head == NULL){
        cout<<"Records are empty"<<endl;
        return;
    }
    Record* curr=*head;
    while((curr)!=NULL){
        *head = curr -> next;
        delete(curr);
        curr = (*head);
    }
    delete(*head);
    cout<<"All Records are deleted Successfully"<<endl;
}
int main(){
    Record *head=NULL; int i ;
    while(true){
        cout<<"Press 0 to exit"<<endl;
        cout<<"Press 1 to insert record"<<endl;
        cout<<"Press 2 to search value"<<endl;
        cout<<"Press 3 to print value"<<endl;
        cout<<"Press 4 to delete a Single Record"<<endl;
        cout<<"Press 5 To Delete Whole Record"<<endl;
        cin>>i;
        if(i==1){
            insert(&head);
        }
        else if(i==2){
            search(&head);
        }
        else if(i==3){
            print(&head);
        }
        else if(i==4){
            deleteSingleRecord(&head);
        }
        else if(i==5){
            deleteAllRecords(&head);
        }   
        else if(i ==  0 ){
            cout<<"exit";
            break;
        }    
        else{
            cout<<"Wrong Input, Try Again!"<<endl;
        }        
    }
}