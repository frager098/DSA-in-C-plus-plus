#include <iostream>
#include <cstdlib>
using namespace std ;
struct stackEvaluator{
    int value ;
    stackEvaluator * next ;
};
struct stack{
    int value;
    stack* next ;
};
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

int evaluator(int oper1 , int oper2 , char operatorr){
    if ( operatorr == '+' ){
        return (int)oper1 +(int) oper2 ;
    }
    else if ( operatorr == '-'){
        return (int)oper1 - (int)oper2 ;
    }
    else if ( operatorr == '*'){
        return oper1 * oper2 ;
    }
    else if ( operatorr == '/'){
        return (int)oper1 / (int)oper2 ;
    }
    else if ( operatorr == '='){
        return (int)oper1 == (int)oper2 ;
    }
    else if ( operatorr == '!'){
        return (int)oper1 != (int)oper2 ;
    }
    else if ( operatorr == '<'){
        return (int)oper1 < (int)oper2 ;
    }
    else if ( operatorr == '>'){
        return (int)oper1 > (int)oper2 ;
    }
    else if ( operatorr == '&'){
        return (int)oper1 && (int)oper2 ;
    }
    else if ( operatorr == '|'){
        return (int)oper1 || (int)oper2 ;
    }
    else{
        return 0 ;
    }
}
void print(stackEvaluator** top){
    stackEvaluator* curr=*top;
    if(*top == NULL){
        cout<<"stack is empty"<<endl;
    }
    else{
        while(curr!=NULL){
            cout<<"Stack: "<<curr->value;
            curr=curr->next;
        }
    }
    cout<<endl;
}
void push(stackEvaluator** top , int oper){
    stackEvaluator* curr = *top ;
    stackEvaluator* ptr = (stackEvaluator*)malloc(sizeof(stackEvaluator)) ;
    ptr -> value = oper ;
    ptr -> next = NULL ;
    if ( *top == NULL ){
    (*top) = ptr ;
    }
    else{
       ptr -> next = *top ;
       *top = ptr ;
    }
}
void pop(stackEvaluator** top){
    stackEvaluator* curr = *top;
    *top=curr->next;
    free(curr) ;
}
int evaluator1 (string postfix) {
     stackEvaluator * top = NULL ;
    for ( int ind = 0 ; ind < postfix.length() ; ind++){
        int getPrecedence = precedence(postfix[ind]);
        if ( getPrecedence == 0 ){
            push(&top , postfix[ind] - '0' );
        }
        else {
            int oper2 = top->value;
            pop(&top);
            int oper1 = top->value;
            pop(&top);
            int result = evaluator(oper1 , oper2 , postfix[ind]);
            push(&top , result);
        }   
    }
    return top->value;
}

int main(){
     string postfix = "46+2/5*7+";
     int result = evaluator1(postfix);
     cout<<result ;
}
