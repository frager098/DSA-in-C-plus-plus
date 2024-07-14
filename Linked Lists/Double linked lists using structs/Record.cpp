#include <iostream>
#include <cstdlib>
using namespace std;
struct Record{
    int rollno;
    float GPA;
    Record *next;
    Record* pre;
};
void insert(Record**head){
    Record*ptr=(Record*)malloc(sizeof(Record));
    Record*curr=*head;
    int rollno;
    float GPA;
    cout<<"Enter roll no: ";
    cin>>rollno;
    cout<<"Enter GPA: ";
    cin>>GPA;
    ptr->rollno=rollno;ptr->GPA=GPA;ptr->next=NULL;
    // ptr->pre=NULL;
    if(*head==NULL){
        ptr->pre=NULL;
        *head=ptr;
    }
    else{
        while(curr->next!=NULL){
            if(curr->rollno==ptr->rollno){
                cout<<"Record already exists!";
                break;
            }
            curr=curr->next;
            // || curr->rollno!=ptr->rollno
            if(curr->next==NULL){
                 ptr->pre=curr;
                 curr->next=ptr;
                 break;
            }
            // (curr->pre)->next=ptr->next;
        }
        if((*head)->next==NULL){
        ptr->pre=curr;
        curr->next=ptr;
        }
        // Duri creation of 2nd Record ptr prev is NULL and curr->next is also NULL so we just linked the 2 nodes in the next line
        // ptr->pre=curr->next;  
        // ptr->pre=curr;
        // ptr->pre=curr;
        // (curr->next)->pre=curr;
        // ptr->pre=curr->next;
        // ptr->pre=curr;
        // curr->next=ptr->pre;
        // cout<<"k";
    }
}
void search(Record**head){
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
            if(curr==NULL){
                cout<<"Record Not Found!"<<endl;
                break;
            }
            if(curr->rollno==rollno){
                cout<<"Your GPA is:"<<curr->GPA<<endl;
                break;
            }
        }      
    }   
}
        // (curr->next)->pre=NULL;
        // (*head)->pre=NULL;
void deletesinglerecord(Record**head){
    Record* curr=*head;cout<<"Enter roll no. you wanna delete:";
    int rollno;cin>>rollno;
    if(curr->rollno==rollno){
        free(*head);
        // *head=curr->next;
         (*head)=curr->next;
         (*head)->pre=NULL;
        cout<<"h";
    }
    // else if((curr->next)->rollno==rollno){
    //         (*head)->next=(curr->next)->next;
    //         free(curr);
    // }
    else{
        while(curr!=NULL){
            // curr->next=(curr->next)->pre;
            curr=curr->next;
            if(curr==NULL){
                cout<<"Record Not Found!"<<endl;
                break;
            }
            if(curr->rollno==rollno){
                // (curr->pre)->next=(curr->next)->next;    It's stopping the flow of program
                // Record* d1=curr->next;
                // cout<<"s";
                // Record* d2=curr->pre->next;
                // curr->pre=NULL;curr->next=NULL;
                // d2=d1;
                // (curr->next)->next=(curr->pre)->pre;
                // (curr->pre)->next=(curr->next)->pre;
                // curr->pre=curr->next;
                // curr->next=curr->pre;
                // (curr->pre)->next=curr->next;
                // (curr->pre)->next=(curr->next)->pre;

                // *pre=(curr->next)->pre;
                // curr->next=(curr->next)->pre;
                // cout<<"h";
                (curr->pre)->next=curr->next;
                free(curr);
                break;
            }
        }
    }
}
// void search(Record**head){
//     Record* curr=*head;
//     int rollno;
//     cout<<"Enter roll no. that you wanna search : ";
//     cin>>rollno;
//     if(curr->rollno==rollno){
//         cout<<"Your GPA is:"<<curr->GPA<<endl;
//     }
//     else{
//         while(curr!=NULL){
//             curr=curr->next;
//             if(curr->rollno==rollno){
//                 cout<<"Your GPA is:"<<curr->GPA<<endl;
//                 break;
//             }
//         }      
//         if(curr==NULL){
//             cout<<"Record Not Found!";
//         }
//     }   
// }
void print(Record**head){
    Record* curr=*head;
    while(curr!=NULL){
        cout<<"Your Roll No. is:"<<" "<<curr->rollno<<"   ";
        cout<<"And your GPA is:"<<" "<<curr->GPA<<endl;
        curr=curr->next;
    }
}
void deleteRecord(Record**head){
    Record* curr=*head;
    while(*head!=NULL){
        if(*head==NULL){
            break;   
        }
        free(*head);
        curr=curr->next;
        (*head)=curr;
    }
}
int main(){
    Record *head=NULL;
    // Record *pre=NULL;
    int i=10;
    while(i!=0){
        if(head==NULL){
            cout<<"You can't Search,Print,Delete Records as Records are empty"<<endl;
            cout<<"Press 0 to exit"<<endl;
            cout<<"Press 1 to insert record"<<endl;
                cin>>i;
                if(i>1 || i<0){
                    cout<<"You need to enter 0 to exit and 1 to insert"<<endl;
                    continue;
                }
                else if(i==0){
                    cout<<"exit";
                }
                else{
                    insert(&head);
                }
            }
        else{
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
                    deletesinglerecord(&head);
                }
                else if(i==5){
                    deleteRecord(&head);
                }   
                else if(i>5 || i<0){
                    cout<<"You need to enter 0 to exit and 1 to insert"<<endl;
                    continue;
                }    
                else{
                    cout<<"exit";
                }        
        }
    }
}