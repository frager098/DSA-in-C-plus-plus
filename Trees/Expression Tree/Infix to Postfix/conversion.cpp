// #include <customizedStack> 
#include <iostream>
#include <cstdlib>
using namespace std ;
struct stack{
    char oper ;
    int precedence ;
    stack* next;
};

void print(stack** top){
    stack* curr=*top;
    if(*top == NULL){
        cout<<"stack is empty"<<endl;
    }
    else{
        while(curr!=NULL){
            cout<<"Stack: "<<curr->oper<<"  ";
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

stack* pop(stack** top){
    stack* curr = *top;
    *top=curr->next;
    // stack*temp = curr ;
    // free(temp);
    return curr ;
}
void push(stack** top , char stackOperator){
    int getPrecedence = precedence(stackOperator);
    stack* curr = *top ;
    stack* ptr = (stack*)malloc(sizeof(stack)) ;
    ptr ->oper = stackOperator ;
    ptr -> precedence = getPrecedence ;
    ptr -> next = NULL ;
    if ( *top == NULL ){
    (*top) = ptr ;
    }
    else{
        // if ( ptr -> precedence)
       ptr -> next = *top ;
       *top = ptr ;
    }
}

// void  pushForTree( stackForTree** top , expressionTree* node ){

// }
int topNodePrecedence( stack* top ){
    stack* curr = top ;
    if(top == NULL){
        return 0;
    }
    else{
        return (curr -> precedence);
    }
}

string infixToPostfix(string infix ){
    stack* top = NULL ;
    string postfix ="";

    for (int ind = 0 ; ind < infix.length() ; ind++ ){
        int getPrecedence = precedence(infix[ind]);
        int precedence = topNodePrecedence(top);
    // string infix = "a+b*(c-d)<x&(c!y|x+y<55)" ;
        if ( getPrecedence == 0  ){
            postfix += infix[ind];

        }
        else if ( (getPrecedence > precedence && infix[ind] != ')' ) || top == NULL || top->oper == '('){
            push( &top , infix[ind] );

        }
        else{
            //If Operator in Stack has higher precedence or the upcoming char was closed bracket.
                while( (getPrecedence <= precedence &&  top ->oper != '(' ) || ( infix[ind] == ')' && top -> oper != '(' ) ){
                    if ( top -> oper == '(' && infix[ind] == ')'){
                        stack* popValue = pop (&top);
                        free (popValue);
                        popValue = NULL ;
                        break ;
                    }
                    stack* popValue = pop(&top);
                        postfix += (popValue -> oper) ;
                free(popValue) ;
                popValue = NULL ;
                precedence = topNodePrecedence(top);
                }
                if (infix[ind] != ')'){
                    push(&top , infix[ind]);
                } 
                
            }
            print(&top);
            cout<<infix[ind]<<endl;
        }
    while(top != NULL){
        stack* popValue = pop(&top);
        if ( popValue -> oper != '(' || popValue ->oper != ')' ) {
            postfix += popValue -> oper ;
        }
        free(popValue);
        popValue = NULL ;
    }
    return postfix ;
}  

int main(){
    string infix = "a+b*(c-d)<x&(c!y|x+y<55)" ;
    string postfix = infixToPostfix( infix) ;
    cout<<postfix;
}
