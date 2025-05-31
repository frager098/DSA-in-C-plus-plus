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










// #include<iostream>
// #include <cstdlib>
// using namespace std;

// struct Node{
//   int rollNo;
//   float gpa;
//   int index=0;
//   Node* next;  
// };

// Node* head=NULL;
// int counter=0;

// void insertValue(){
//     int set=1;
//     while (set==1){
//     Node* ptr=(Node*) malloc(sizeof(Node));
//     cout<<"Enter roll no of the student: "<<endl;
//     cin>>ptr->rollNo;
//     cout<<"Enter cgpa of the student: "<<endl;
//     cin>>ptr->gpa;
//      ptr->next=NULL;
//         ptr->index=++counter;
        
//     if (head==NULL){
//         head=ptr;
//         ptr->index=0;
//     }
//     else if (head->next==NULL){
//         if(head->rollNo<ptr->rollNo){
//             head->next=ptr;
//         }
        
//         else{
//             Node* current=head;
//             head=ptr;
//             ptr->next=current;
//             head->index=0;
//             current->index=1;
//         }
//     }
//      else{
//          Node* previous=NULL;
//          Node* current=head;
//          while(current!=NULL and current->rollNo<ptr->rollNo){
//              previous=current;
//              current=current->next;
//          }
//          int index;
//          if(previous==NULL){
//              ptr->next=current;
//              head=ptr;
//              ptr->index=0;
//               index=1;
//          }
//          else{
//          previous->next=ptr;
//          ptr->next=current;
//          ptr->index=previous->index+1;
//           index=ptr->index+1;
//          }
//          while(current!=NULL){
//              current->index=index;
//              current=current->next;
//              index++;
//          }
//      }    
        
//         cout<<"Enter 1 if you want to insert further! "<<endl;
//         cin>>set;
//     }
// } 

    
// void searchValue(){
//     if (head==NULL){
//         cout<<"The linked list is empty right now!"<<endl<<endl;
//         return;
//     }
//     int tosearch;
//     cout<<"Enter roll no to find the relevant gpa of that student!"<<endl;
//     cin>>tosearch;
    
//     Node* current=head;
//     while(current!=NULL){
//         if (current->rollNo==tosearch){
//             cout<<"the gpa of that student is: "<<current->gpa<<endl<<endl;
//             return;
//         }
//         current=current->next;
//     }
//     cout<<"given roll no was not found! probably that student didn't appear in the exam!"<<endl<<endl;
// }
    


// void printList(){
//     //cout<<"print list function was called!"<<endl;
//     if (head==NULL){
//         cout<<"The list is empty right now!"<<endl<<endl;
//         return;
//     }
//     Node* current=head;
//     while (current!=NULL){
//         cout<<"index: "<<current->index<<" ,Roll no: "<<current->rollNo<<" and gpa: "<<current->gpa<<" ---> ";
//         current=current->next;
//     }
//     cout<<"NULL"<<endl<<endl;
// }


// void deleteElement(){
//     //cout<<"delete function was called!"<<endl<<endl;
//     if (head==NULL){
//         cout<<"the linked list is empty right now!"<<endl<<endl;
//         counter=0;
//         return;
//     }
//     int todelete;
//     cout<<"Enter roll number of the student whose record you want to delete!"<<endl;
//     cin>>todelete;
//     Node* current=head;
//     --counter;
//     if (head->rollNo==todelete){
        
//          if(head->next==NULL){
//             head=NULL;
//             free(current);
//             cout<<"The given student's record has been deleted!"<<endl<<endl;
//             return;
//         }
//          else{
//             head=head->next;
//             head->index=0;
//             free(current);
//             current=head->next;
//             while(current!=NULL){
//                 current->index=current->index -1;
//                 current=current->next;
//             }
//             cout<<"The given student's record has been deleted!"<<endl<<endl;
//             return;
//         }
//     }
//     else {
//         Node* previous=head;
//         current=head->next;
//         while(current!=NULL){
//             if (current->rollNo==todelete){
//                 previous->next=current->next;
//                 free(current);
//                 current=previous->next;
//                 while(current!=NULL){
//                     current->index=current->index -1;
//                     current=current->next;
//                 }
//                 cout<<"The given student's record has been deleted!"<<endl<<endl;
//                 return;
//             }
//             current=current->next;
//             previous=previous->next;
//         }
//     }
// }



// void deleteWholeList(){
//     counter=0;
//     //cout<<"delete list function was called!"<<endl<<endl;
//     if (head==NULL){
//         cout<<"The list is already empty!"<<endl<<endl;
//         return;
//     }
//     Node* current=head;
//     while(head!=NULL){
//         head=current->next;
//         free(current);
//         current=head;
//     }
//     cout<<"The whole list has been deleted!"<<endl<<endl;
// }

//  void getTotalCount(){
//     /* int count=0;
//      Node* current=head;
//      while(current!=NULL){
//          current=current->next;
//          count++;
//      }
//      */
//     cout<<"The total count of the list right now : "<<counter<<" Nodes"<<endl<<endl;
     
//  }

// int main(){
//     int choice;
//     do{
//         cout<<"Enter 1 to insert!"<<endl<<"Enter 2 to search "<<endl<<"Enter 3 to print the linkedList!"<<endl<<"Enter 4 to delete an element !"<<endl<<"Enter 5 to delete whole list!"<<endl<<"Enter 6 to get the total count!"<<endl<<"Enter 7 to exit the code!"<<endl;
//     cin>>choice;
//         //while (choice!=6){
//    // while (choice!=6){
//         if (choice==1){
//             insertValue();
//         }
//         else if(choice==2){
//             searchValue();
//         }
//         else  if(choice==3){
//             printList();
//         }
//         else  if(choice==4){
//             deleteElement();
//         }
//         else  if(choice==5){
//             deleteWholeList();
//         }  
//         else if (choice==6){
//             getTotalCount();
//         }
//         //else {
//         else if(choice!=7){
//             cout<<"Sorry ! the given option is not available!"<<endl<<endl;
//         }    
//            // cout<<"Enter 1 to insert!"<<endl<<"Enter 2 to search "<<endl<<"Enter 3 to print the linkedList!"<<endl<<"Enter 4 to delete an element!"<<endl<<"Enter 5 to delete whole list!"<<endl<<"Enter 6 to exit the code!"<<endl;
//    // cin>>choice;
        
//     }while(choice!=7);
//     cout<<"We've exited the code! now!"<<endl;
// }
