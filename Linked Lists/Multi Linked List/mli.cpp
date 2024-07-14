#include <iostream>
#include <cstdlib>
using namespace std;
struct stu{
    int ID;
    stu* std_start;
};
struct cNode{
    int cNo;
    stu* std_start;
    cNode* next;
};
void coursePrint(cNode** head){
    cNode* curr=*head;
    while(curr!=NULL){
        cout<<"Course No: "<<curr->cNo<<"   ";
        curr=curr->next;
    }cout<<endl;
}

void stuprint(stu** stuhead){
    stu* currs=*stuhead;
    while(currs!=NULL){
        cout<<"Student: "<<currs->ID<<"--->";
        currs=currs->std_start;
    }cout<<endl;
}
void stuInCourses(cNode** head,stu** stuhead){
    cNode*curr=*head;
    stu*stucurr=*stuhead;
    while(curr!=NULL){ 
    if(curr->std_start!=NULL){
        cout<<"In course "<<curr->cNo<< " Student of ID ";
        while(curr->std_start!=NULL){
        // cout<<"Student of ID "<<(curr->std_start)->ID<<" is enrolled in Course No "<<curr->cNo<<endl;
        cout<<(curr->std_start)->ID<<" are enrolled "<<"and ";
        curr->std_start=(curr->std_start)->std_start;
        // stucurr=stucurr->std_start;
        }
        curr=curr->next;
    }cout<<endl;
    }
}

void insert(cNode** head){
    cNode* ptr = (cNode*)malloc(sizeof(cNode));
    cout<<"Enter course No: ";
    int cNo;
    cin>>cNo;
    ptr->cNo=cNo;
    ptr->next=NULL;
    ptr->std_start=NULL;
    if(*head==NULL){
        *head=ptr;
    }
    else{
        cNode* curr=*head;
        while(curr->next!=NULL){
            curr=curr->next;
        }
        curr->next=ptr;
    }cout<<endl;
}
void insertStudent(stu** stuhead){
    stu* ptr=(stu*)malloc(sizeof(stu));
    stu* stucurr=*stuhead;
    cout<<"Enter Student ID";
    cin>>ptr->ID;
    ptr->std_start=NULL;
    if(stucurr==NULL){
        *stuhead=ptr;
    }
    else{
        while(stucurr->std_start!=NULL){
            stucurr=stucurr->std_start;
        }
        stucurr->std_start=ptr;
    }
}

void studentCourse(cNode** head,stu** stuhead){
    cNode* curr=*head;
    stu* stucurr=*stuhead;
    cout<<"Enter course no. in which student will enroll: "<<endl;
    int cNo;cin>>cNo;
    cout<<"Enter ID of Student who will enroll? "<<endl;
    // cout<<"Available Students are:"<<endl;
    // stuprint(stuhead);
    int ID;cin>>ID;
    if(curr->cNo==cNo){
        if(stucurr->ID == ID){
        stucurr->std_start=NULL;
        curr->std_start=stucurr;
        }
        else{
            while(stucurr->ID != ID){
                stucurr=stucurr->std_start;
                cout<<"ok";
            }
            if(stucurr->ID == ID){
            cout<<"why?";
                stucurr->std_start=NULL;
            curr->std_start=stucurr;
            cout<<"hi";
            }
            else{
                cout<<"student of "<<ID<<" not found"<<endl;
            }
        }
    }
    else{
        while(curr->cNo!=cNo){
            curr=curr->next;
            if(curr==NULL){
                cout<<"Course not found!"<<endl;
                break;
            }
        }
        if(stucurr->ID==ID && curr != NULL){
            curr->std_start=stucurr;
            }
        else{
            while(stucurr->ID != ID){
                stucurr=stucurr->std_start;
            }
            if(stucurr->ID==ID){
            curr->std_start=stucurr;
            }
            else{
                cout<<"student of "<<ID<<" not found"<<endl;
            }
        }
    }
}
// void insertS(cNode** head,stu** shead){
//     // cNode* curr=*head;
//     stu* currs=*shead;
//     stu* ptr = (stu*)malloc(sizeof(stu));
//     // cout<<"Enter course no. in which student will enroll: ";
//     // int cNo;
//     // cin>>cNo;
//     // if(curr->cNo==cNo){
//     //     curr->std_next=currs;
//     // }
//     // else{
//     //     while(curr!=NULL){
//     //         curr=curr->next;
//     //         if(curr->cNo==cNo){
//     //         curr->std_next=currs;
//     //         }
//     //     }
//     // }
//     cout<<"Enter Student ID:";
//     int ID;
//     cin>>ID;
//     ptr->ID=ID;
//     ptr->std_start=NULL;
//     if(*shead==NULL){
//         currs=ptr;
//     }
//     else{
//         while(currs->std_start!=NULL){
//             currs=currs->std_start;
//         }
//         currs=ptr;
//     }
//     cout<<"Enter course no. in which student will enroll: ";
//     int cNo;
//     cin>>cNo;
//     cNode* curr=*head;
//     if(curr->cNo==cNo){
//         curr->std_start=currs;
//         // (curr->std_next)->ID=currs;
//     }
//     else{
//         while(curr->cNo!=cNo){
//             curr=curr->next;
//         }
//         if(curr->cNo==cNo){
//             if(currs==NULL){

//             curr->std_start=currs;
//             }
//             else{
//                 while(currs!=NULL){
//                     currs=currs->std_start;
//                 }

//                 // curr
//             }
//         }
//     }

// }

// void coursePrint(cNode** head){
//     cNode* curr=*head;
//     while(curr!=NULL){
//         cout<<"Course No: "<<curr->cNo<<"   ";
//         curr=curr->next;
//     }cout<<endl;
// }

// void stuprint(stu** stuhead){
//     stu* currs=*stuhead;
//     while(currs!=NULL){
//         cout<<"Student: "<<currs->ID<<"--->";
//         currs=currs->std_start;
//     }cout<<endl;
// }
// void stuInCourses(cNode** head,stu** stuhead){
//     cNode*curr=*head;
//     stu*stucurr=*stuhead;
//     while(curr!=NULL){ 
//     if(curr!=NULL && stuhead!=NULL){
//         cout<<"Student of ID "<<stucurr->ID<<" is enrolled in Course No "<<curr->cNo<<endl;
//         curr=curr->next;
//     }
//     }
// }
int main(){
    cNode* head=NULL;
    stu* stuhead=NULL;
    int i=10;
        while(i!=7){
        cout<<"Press 1 to insert Course: "<<endl;
        cout<<"Press 2 to insert student: "<<endl;
        cout<<"Press 3 to insert student in a course: "<<endl;
        cout<<"Press 4 to print a Course: "<<endl;
        cout<<"Press 5 to print Students: "<<endl;
        cout<<"Press 6 to print Students of a Course: "<<endl;
        cout<<"Press 7 to exit"<<endl;
        cin>>i;
        if(i==1){
            insert(&head);
        }
        else if(i==2){
            insertStudent(&stuhead);
        }
        else if(i==3){
            studentCourse(&head,&stuhead);
        }
        else if(i==4){
            coursePrint(&head);
        }
        else if(i==5){
            stuprint(&stuhead);
        }
        else if(i==6){
            stuInCourses(&head,&stuhead);
        }
    }
    if(i==7){
        cout<<"exit";
    }
    
}