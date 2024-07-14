#include <iostream>
#include <cstdlib>
using namespace std;
struct bstNode{
    int data;
    bstNode * left;
    bstNode * right;
};

bstNode* insert(bstNode * root , int value ){
    if(root == NULL){
        bstNode *node = (bstNode*)malloc(sizeof(bstNode));
        node -> data = value ;
        node -> left = NULL ;
        node -> right = NULL ;
        return node ;
    }
    else {
        if(value < root->data){
           root -> left = insert( root -> left , value);
        }
        else{
           root -> right = insert( root -> right , value );
    
        }
    }
    return root ;
}

void search(bstNode* root ,int value){
    if(root -> data == value ){
        cout << "value found!"<<endl;
        // return ;
    }
    else if(value < root->data){
         search (root->left , value) ;
        cout<<"left"<<endl;
    }
    else{
        search( root -> right , value );
        cout<<"right"<<endl;
    }
}

void InOrderTraversal(bstNode* root){
    if(root!=NULL){
    InOrderTraversal(root->left);
    cout<<root->data<<"-->";
    InOrderTraversal(root->right);
    }
    // cout<<endl;
}

void preOrderTraversal(bstNode* root){
    if(root!=NULL){
    cout<<root->data<<"-->";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
    }
}

void postOrderTraversal(bstNode* root){
    if(root!=NULL){
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<<root->data<<"-->";
    }
}
int minimum(bstNode* root){
    if(root ->left == NULL){
        cout <<"minimum value is :"<<root -> data<<endl ; 
        return  root->data;
    }
    minimum(root ->left);
}
int maximum(bstNode* root){
    if(root->right==NULL){
        cout<<"maximum value is:"<<root -> data<<endl;
        return root->data; 
    }
    maximum(root -> right) ;
}
bstNode * deleteNode(bstNode * root ,int value){
    if (root -> data == value){
        if (root ->right == NULL && root ->left == NULL){
            free(root);
            return NULL ;
        }
        else if (root ->left == NULL){
            bstNode * temp = root -> right ;
            free(root); 
            return temp ; 
        }
        else if (root -> right == NULL){
            bstNode * temp = root ->left ;
            free (root);
            return temp ;
        }
        else if( root -> left != NULL && root -> right != NULL){
            cout<<"You wanna attach node from left or right?"<<endl<<"Press 1 for left and 2 for right:"<<endl;
            int check;cin>>check;
            int temp ;
            if (check == 1){
               temp = maximum(root -> left );
               root = deleteNode(root , temp);
               root -> data = temp ;
               return root ;               
            }
            else {
                int temp = minimum(root -> right);
                root = deleteNode(root , temp);
                root -> data = temp;
                return root ;
            }
        }
    }
    else{
        if (value < root -> data){
            root -> left = deleteNode(root -> left , value );
        }
        else{
            root->right = deleteNode(root -> right , value);
        }
    }
    return root ;

}


int main(){
bstNode * root = NULL ;
int value ;
int i = 10 ;
while(i != 0){
    cout<<"Press 1 to insert "<<endl<< "2 to search"<<endl<<"3 to Traverse through In Order"<<endl<<"4 to Traverse through Pre Order"<<endl<<"5 to Traverse through Post Order"<<endl<<"6 for minimum node and 7 for maximum node"<<endl<<"0 to exit"<<endl<<"8 to delete Node"<<endl;
    cin >> i ;
    if(i == 1){
    cout<<"Enter value:";
    cin >> value ;
        root = insert(root , value );
    }
    else if(i == 2){
    cout<<"Enter value:";
    cin >> value ;
        search(root , value);
    }
    else if( i == 3){
        InOrderTraversal(root);
    }
    else if(i==4){
        preOrderTraversal(root);
    }
    else if(i==5){
        postOrderTraversal(root);
    }
    else if(i==6){
        minimum(root->right);
    }
    else if(i==7){
        maximum(root -> left);
        }
    else if ( i == 8 ){
        cout << "Enter node you want to delete:"<<endl;
        int value ;
        cin>>value;
        root = deleteNode(root , value);
    }
    else{
        cout<<"exit";
    }
}
}