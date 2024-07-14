#include <iostream>
#include <iomanip>
#include <stdlib.h>
using namespace std;

struct Record{
    int data;
    Record* next;
};

// SORTED INSERT FUNCTION
void sort_insert(Record*array[] , int size){
    Record* ptr = (Record*)malloc(sizeof(Record));
    cout << "enter the data that youw want to insert: ";
    cin >> ptr->data;
    ptr->next=NULL;
    int index = ptr->data % size;
    if(array[index]==NULL){
        array[index]=ptr;
    }
    else if (ptr->data < array[index]->data){
        ptr->next=array[index];
        array[index]=ptr;
    }
    else{
        Record* curr = array[index];
        while (curr->next!=NULL && ptr->data > curr->next->data){
            curr=curr->next;
        }
        ptr->next=curr->next;
        curr->next=ptr;
    }
}

// INSERT FUNCTION
void insert(Record* array[] , int size){
    Record* ptr = (Record*)malloc(sizeof(Record));
    cout << "enter the data that youw want to insert: ";
    cin >> ptr->data;
    ptr->next=NULL;
    int index = ptr->data % size;
    if(array[index]==NULL){
        array[index]=ptr;
        cout << "the Record has been inserted" << endl;
        return;
    }
    else{
        Record* curr = array[index];
        while (curr->next!=NULL){
            curr=curr->next;
        }
        curr->next=ptr;
        cout << "the Record has been inserted" << endl;
    }
}

// SEARCH FUNCTION
void search(Record* array[] , int size){
    int tosearch;
    cout << "enter the data that you want to search: ";
    cin >> tosearch;
    int index = tosearch % size; 
    Record* curr = array[index];
    if(array[index]==NULL){
        cout << "the list is empty" << endl;
        return;
    }
    while (curr!=NULL){
        if(curr->data==tosearch){
            cout << "the data is: " << curr->data << endl;
            cout << endl;
            break;
        }
        else{
            curr=curr->next;
        }
    }
    if(curr==NULL || curr->data!=tosearch){
        cout << "the data not found in the list" << endl;
        return;
    }
}

// PRINT FUNCTION
void print(Record* array[] , int size){
    for (int i = 0; i < size; i++){
        Record* curr = array[i];
        cout << "Index " << i << ": ";
        if(curr!=NULL){
            while (curr!=NULL){
                cout << curr->data;
                if(curr->next!=NULL){
                    cout << "   -->   ";
                }
                curr=curr->next;
            }
        }
        cout << endl;
    }
}

// DELETE VALUE FUNCTION
void delete_value(Record* array[] , int size){
    int todel;
    cout << "enter the data that you want to delete: ";
    cin >> todel;
    int index = todel % size; 
    Record* curr = array[index];
    Record* prev = NULL;
    if(array[index]==NULL){
        cout << "the list is empty" << endl;
        return;
    }
    if(curr->data==todel){
        array[index]=curr->next;
        free(curr);
        cout << "The Record has been deleted" << endl;
        return;
    }
    while (curr!=NULL && curr->data!=todel){
        prev=curr;
        curr=curr->next;
    }
    if(curr==NULL){
        cout << "the data not found in the list" << endl;
        return;
    }
    if(curr->next==NULL){
        prev->next=NULL;
        free(curr);
        cout << "the Record has been deleted" << endl;
        return;
    }
    prev->next=curr->next;
    free(curr);
    cout << "the Record has been deleted" << endl;
}

// DELETE LIST FUNCTION
void delete_list(Record* array[] , int size){
    for (int i = 0; i < size; i++){    
        Record* curr = array[i];
        Record* all;
        if(array[i]==NULL){
            cout << "the list is already empty" << endl;
            return;
        }
        if(curr!=NULL){
            while (curr!=NULL){
                all=curr->next;
                free(curr);
                curr=all;
            }
            array[i]=NULL;
        }
    }
    cout << "the list has been deleted" << endl;
}

// MAIN FUNCTION
int main(){
    int size;
    cout << "enter the size of the array: ";
    cin >> size;
    Record* array[size] ;

    int select;
    cout << "enter 0 to exit" << endl;
    cout << "enter 1 to insert" << endl;
    cout << "enter 2 to search" << endl;
    cout << "enter 3 to print" << endl;
    cout << "enter 4 to delete_value" << endl;
    cout << "enter 5 to delete_list" << endl;
    cout << "enter your choice: ";
    cin >> select;

    while (select!=0){
        if(select==1){sort_insert(array , size);}
        if(select==2){search(array , size);}
        if(select==3){print(array , size);}
        if(select==4){delete_value(array , size);}
        if(select==5){delete_list(array , size);}
        cout << "enter your choice again: ";
        cin >> select;
    }
    
   return 0;
}