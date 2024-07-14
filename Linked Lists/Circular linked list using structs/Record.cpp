#include <iostream>
#include <cstdlib>
using namespace std;
struct Record{
    int rollno;
    float GPA;
    Record *next=NULL;
};
void insert(Record*(&head),int inp1,float inp2){
    Record* ptr=(Record*)malloc(sizeof(Record));
    Record *curr=head;
        ptr->rollno=inp1;
        ptr->GPA=inp2;
        ptr->next=NULL;
    if(head==NULL){
        head=ptr;
        head->next=head;
    }
    else{
        while(curr->next!=head){
            if(curr->rollno==ptr->rollno){
                break;
            }
            curr=curr->next;
        }
        if(curr->next==head && curr->rollno!=ptr->rollno){
            // curr->next=NULL;
            ptr->next=head;
            curr->next=ptr;
        }
        if(curr->rollno==ptr->rollno){
                cout<<"Record is already present"<<endl;
            }
    }
}  
// Search Function
void Search(Record*(&head),int rollno){
        Record *curr=head;
        // if(head==NULL){
        //     cout<<"Record is empty";
        // }
        if(head->rollno==rollno){
            cout<<"Your CGPA is: "<<head->GPA<<endl;
        }
        else if(head->rollno!=rollno){
            while(curr->next!=head){
                curr=curr->next;
                if(curr->rollno==rollno){
                    cout<<"Your CGPA is: "<<curr->GPA<<endl;
                    break;
                }
                if(curr->next==head){
                cout<<"Record Not Found!"<<endl;
                // break;
                }
            }
        }
}
void Print(Record*(&head)){
    Record* curr=head;
    if(curr==NULL){
        cout<<"Record is empty"<<endl;
    }
    else if(curr->next==head){
        cout<<"2nd";
            cout<<"Your Roll No. is: "<<curr->rollno<<" And your GPA is: "<<curr->GPA<<endl;
    }
    else{
        cout<<"3rd";
        while(curr->next!=head){
        cout<<"4th";
            cout<<"Your Roll No. is: "<<curr->rollno<<" And your GPA is: "<<curr->GPA<<endl;
            curr=curr->next;
            if(curr->next==head){
            cout<<"Your Roll No. is: "<<curr->rollno<<" And your GPA is: "<<curr->GPA<<endl;
            break;
            } 
        }
    }
}// Delete Function

void Delete(Record*(&head),int rollno){
        Record *curr=head;
        Record* pre,*cir;
        cir=head;
       while(cir->next!=head){
            cir=cir->next;
        }
        if(curr->next==head && curr->rollno==rollno){
            free(head);
            head=NULL;
            cout<<"Record has been deleted!"<<endl;
        }
        else if(curr->rollno==rollno && curr->next!=head){
        head=curr->next;
        cir->next=head;
        free(curr);
        cout<<"Record has been deleted!"<<endl;
        }
        else if(curr->rollno!=rollno && curr->next!=head){
            while(curr->next!=cir){
                pre=curr;
                curr=curr->next;
            if(curr->rollno==rollno && curr!=cir){
                pre->next=curr->next;
                free(curr);
                cout<<"Record has been deleted!"<<endl;
                break;
            }
            if(curr->next==cir || curr==cir){
                pre=curr;
                curr=curr->next;
                if(curr==cir && curr->rollno!=rollno){
                cout<<"Record Not Found!"<<endl;  
                break; 
                }
                free(curr);
                pre->next=head;      
                cout<<"Record has been deleted!"<<endl;
                break;
                      }
            }
          
        }
}
void Deleterecord(Record*(&head)){
    // Record*curr=head;
    if(head->next==head){
    free(head);
    head=NULL;
    }
    else{
        Record*curr=head->next;
        head->next=NULL;
        while(curr!=head){
            Record* temp=curr;
            free(temp);
            temp=NULL;
            curr=curr->next;
            cout<<"ok";
            // temp=curr->next;
            // temp=NULL;     No need to do that it's local variable although it's a pointer
        }
        // free(curr);
        free(head);
        head=NULL;
        
    }
}
// void Deleterecord(Record*(&head)) {
//     if (head == NULL) {
//         return;//List is empty, nothing to delete
//     }

//     Record* lastNode = head;
//     while (lastNode->next != head) {
//         lastNode = lastNode->next;
//     }

//     Record* curr = head;
//     while (curr != lastNode) {
//         Record* temp = curr;
//         curr = curr->next;
//         free(temp);
//         // cout<<"why";
//     }
//     // free(curr);
//     free(lastNode); // Free the last node
//     free(head);     // Free the head node
//     // head = NULL;    // Set head to NULL
// }
    // if(head->next!=NULL){
    // while(curr!=NULL){
    //     curr=curr->next;
    //     head=curr;
    //     free(head);
    // }
    // }
    // while(head!=NULL){
    //     if(head->next==head){
    //         free(head);
    //         head=NULL;    
    //     }
    //     else{

        
    //     }
    // }
    // while(head!=NULL){
    //     free(head);
    //     curr=curr->next;
    //     head=curr;
    //     if(head==NULL){
    //         break;
    //     }
    //     }

// Delete Record
// void Deleterecord(Record*(&head)){
//     Record*curr=head;
//     // if(head->next==head){
//     //     cout<<"head";
//     //     curr=curr->next;
//     //     free(head);
//     //     free(curr);
//     // }
//     // else{
//     while(curr!=NULL){
//         if(curr->next==curr){
//             cout<<"head";
//             curr=curr->next;
//             free(head);
//             head=curr;
//             // free(curr);
//             break;
//         }
//         else{
//             cout<<"ok ";
//             free(head);
//             curr=curr->next;
//             head=curr;
//         // free(head);
//         // cout<<"h";
//             if(curr==NULL){
//                 cout<<"Record has been deleted"<<endl;
//                 break;
//             }
//         }
//     }
//     // }
// }
int main(){
    Record *head=NULL;int i;
        i=10;
        while( i!=0 ){
        if(head==NULL){
            cout<<"You can't Search,Print and delete Record as Record is empty."<<endl;
            cout<<"Press 0 to exit"<<endl;
            cout<<"Press 1 to insert value"<<endl;
            cin>>i;
            if(i==1){
            int inp1;
            float inp2;
            cout<<"Enter Roll NO:";
            cin>>inp1;           
            cout<<"Enter CGPA:";
            cin>>inp2;
            // cout<<endl<<head<<endl;
            insert(head,inp1,inp2);     
            cout<<"ok";      
        }
        }
        else{
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
            // cout<<endl<<head<<endl;
            insert(head,inp1,inp2);           
        }
        else if(i==2){
            cout<<"Enter Roll No:";
            int rollno;
            cin>>rollno;
            Search(head,rollno);
        }
        else if(i==3){
            Print(head);
        }
        else if(i==4){
            cout<<"Enter Roll No:";
            int rollno;
            cin>>rollno;
            Delete(head,rollno);
        }
        else if(i==5){
            Deleterecord(head);
            
        }
   }
}
cout<<"Exit";
}
