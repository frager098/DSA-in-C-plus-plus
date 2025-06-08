#include <iostream>
#include <cstdlib>
using namespace std;
struct Record{
    int rollno;
    float GPA;
    Record *next;
    Record(int r,float g):rollno(r),GPA(g),next(NULL){}
};
void insert(Record*(&head),int rollno,float GPA){
    Record * ptr = new Record(rollno,GPA);
    if(head == NULL){
        head = ptr ;
        head -> next = head ;
        return;
    }
    else{
        Record * curr = head;
        while( curr -> rollno != rollno && curr -> next != head ){
            curr = curr -> next ;
        }
        if(curr -> rollno == rollno){
            cout<<"Record Already Exists!"<<endl;
            delete(ptr);
            return;
        }
        curr -> next = ptr ;
        ptr -> next = head ;
    }
}
// Search Function
void search(Record*(&head),int rollno){
        if(head==NULL){
            cout<<"Record is empty";
            return;
        }
        else{
            Record *curr=head;
            while(curr -> rollno != rollno && curr -> next != head ){
                curr = curr -> next ;
            }
            if(curr -> rollno == rollno){
                cout<<"Your CGPA is: "<<curr->GPA<<endl;
                return;
            }
            cout<<"Record Not Found!"<<endl;

        }
}
void print(Record*(&head)){
    if(head==NULL){
        cout<<"Record is empty"<<endl;
        return;
    }
    else{
        Record* curr=head;
        while(curr->next!=head){
            cout<<"Your Roll No. is: "<<curr->rollno<<" And your GPA is: "<<curr->GPA<<endl;
            curr=curr->next;
        }
        cout<<"Your Roll No. is: "<<curr->rollno<<" And your GPA is: "<<curr->GPA<<endl;
    }
}// Delete Function

void deleteSingleRecord(Record*(&head),int rollno){
        if(head==NULL){
            cout<<"Record is empty"<<endl;
            return;
        }
        Record *curr=head;
        Record* pre = NULL;
        while(curr -> rollno != rollno && curr -> next != head ){
            pre = curr ;
            curr = curr -> next ;
        }
        if(curr -> rollno == rollno && curr -> next == head){
            if(curr == head){
                delete(curr);
                head = NULL;
                cout<<"Record deleted successfully!"<<endl;
                return;
            }
            pre -> next = curr -> next;
            delete(curr);
            cout<<"Record deleted successfully!"<<endl;
        }
        else if(curr -> rollno == rollno && curr -> next != head){
            Record * lastNode = head;
            while(lastNode->next!=head){
            lastNode=lastNode->next;
            } 
            if(curr == head){
                head = head -> next;
                lastNode -> next = head;
                delete(curr);
                cout<<"Record deleted successfully!"<<endl;
                return;
            }
            pre -> next = curr -> next;
            delete(curr);
            cout<<"Record deleted successfully!"<<endl;
        }
        else{
            cout<<"Record Not Found!"<<endl;
        }
}
void deleteAllRecords(Record*(&head)){
     if(head==NULL){
        cout<<"Record is empty"<<endl;
        return;
    }
    Record*curr=head -> next;
    head -> next = NULL;
    Record *temp=curr;
    while(curr != head ){
        curr = curr -> next ;
        delete(temp);
        temp = curr;
    }
    delete(head);
    head = NULL ;
    cout<<"Records deleted successfully!"<<endl;

}
int main(){
    Record *head=NULL;int i;
        while( true ){      
        cout<<"Press 0 to exit"<<endl;
        cout<<"Press 1 to insert value"<<endl;
        cout<<"Press 2 to search value"<<endl;
        cout<<"Press 3 to print value"<<endl;
        cout<<"Press 4 to delete a Single Record"<<endl;
        cout<<"Press 5 To Delete Whole Record"<<endl;
        cin>>i;
        if(i==0){
            cout<<"Exit";
            return 0;
        }
        else if(i==1){
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
            deleteSingleRecord(head,rollno);
        }
        else if(i==5){
            deleteAllRecords(head);      
        }
        else{
            cout<<"Wrong Input!"<<endl;
        }
    }
}
