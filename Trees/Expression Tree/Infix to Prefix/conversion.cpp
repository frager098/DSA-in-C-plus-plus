#include <iostream>
#include <cstdlib>
using namespace std;

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
        ptr -> next = *top ;
        *top = ptr ;
    }
}

int topNodePrecedence( stack* top ){
    stack* curr = top ;
    if(top == NULL){
        return 0;
    }
    else{
        return (curr -> precedence);
    }
}

string infixToPrefix(string infix){
    stack* top = NULL ;
    string prefix ="";

    for (int ind = infix.length() - 1 ; ind >= 0 ; ind-- ){
        int getPrecedence = precedence(infix[ind]);
        int precedence = topNodePrecedence(top);

        if ( getPrecedence == 0 ){
            prefix = infix[ind] + prefix;
        }
        else if ((getPrecedence >= precedence && infix[ind] != '(') || top == NULL || top->oper == ')'){
            push(&top, infix[ind]);
        }
        else{
            while ((getPrecedence < precedence && top->oper != ')') || (infix[ind] == '(' && top->oper != ')')){
                if (top->oper == ')' && infix[ind] == '('){
                    stack* popValue = pop(&top);
                    free(popValue);
                    popValue = NULL;
                    break;
                }
                stack* popValue = pop(&top);
                prefix = popValue->oper + prefix;
                free(popValue);
                popValue = NULL;
                precedence = topNodePrecedence(top);
            }
            if (infix[ind] != '('){
                push(&top, infix[ind]);
            } 
        }
    }
    while(top != NULL){
        stack* popValue = pop(&top);
        if (popValue->oper != '(' || popValue->oper != ')') {
            prefix = popValue->oper + prefix;
        }
        free(popValue);
        popValue = NULL;
    }
    return prefix;
}  

int main(){
    string infix = "a+b*c" ;
    string prefix = infixToPrefix(infix);
    cout << prefix;
    return 0;
}