#include <iostream>
#include <cstdlib>
using namespace std;
struct node {
    char value ;
    node * left ;
    node * right ;
};
struct stack {
    node * treeNode ;
    stack * next ;
};
void print(stack** top){
    stack* curr=*top;
    if(*top == NULL){
        cout<<"stack is empty"<<endl;
    }
    else{
        while(curr!=NULL){
            cout<<"Stack: "<<curr->treeNode->value;
            curr=curr->next;
        }
    }
    cout<<endl;
}
int precedence( char oper){
    if (oper == '(' || oper == ')'){
        return 6 ;
    }
    else if (oper == '*' || oper == '/'){
        return 5 ;
    }

    else if (oper == '+' || oper == '-'){
        return 4 ;
    }
    else if (oper == '=' || oper =='<' || oper == '>' || oper == '!'){
        return 3 ;
    }
    else if (oper == '&'){
        return 2 ;
    }
    else if (oper == '|'){
        return 1 ;
    }
    else{
        return 0 ;
    }
}

void push(stack** top , node* treeNode ){
    stack* curr = *top ;
    stack* ptr = (stack*)malloc(sizeof(stack)) ;
    ptr -> treeNode  = treeNode ;
    ptr -> next = NULL ;
    if ( *top == NULL ){
    (*top) = ptr ;
    }
    else{
       ptr -> next = *top ;
       *top = ptr ;
    }
}
stack* pop(stack** top){
    stack* curr = *top;
    *top=curr->next;
    free(curr) ;
}

node* postfixToTree( string postfix){
    stack * top = NULL ;
    for ( int ind = 0 ; ind < postfix.length() ; ind++){
        int getPrecedence = precedence(postfix[ind]);
        node * ptr = (node*)malloc(sizeof(node));
        if ( getPrecedence == 0 ){
            ptr -> value = postfix[ind];
            ptr -> left = NULL ;
            ptr -> right = NULL ;
            push(&top , ptr );

        }
        else{
            ptr -> value = postfix[ind];
            ptr -> right = top ->treeNode ;
            pop(&top);
            ptr -> left =  top -> treeNode ;
            pop(&top);
            push(&top , ptr);
        }
        if ( ind == postfix.length() - 1 ){
            return ptr ;
        }
    }
}
void postOrderTraversal(node * root ){
    if ( root != NULL){
    postOrderTraversal(root -> left ) ;
    postOrderTraversal(root -> right ) ;
    cout << root -> value  <<"   ";
    }
}

int main(){
    string postfix = "abcd-*+x<cy!xy+5<|&";
    node * root = postfixToTree(postfix);
    postOrderTraversal(root);    


}