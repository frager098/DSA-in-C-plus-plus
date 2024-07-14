#include <iostream>
#include <cstdlib>
using namespace std;

struct node {
    char value;
    node* left;
    node* right;
};

struct stack {
    node* treeNode;
    stack* next;
};

void print(stack** top) {
    stack* curr = *top;
    if (*top == NULL) {
        cout << "stack is empty" << endl;
    }
    else {
        while (curr != NULL) {
            cout << "Stack: " << curr->treeNode->value;
            curr = curr->next;
        }
    }
    cout << endl;
}

int precedence(char oper) {
    if (oper == '(' || oper == ')') {
        return 6;
    }
    else if (oper == '*' || oper == '/') {
        return 5;
    }
    else if (oper == '+' || oper == '-') {
        return 4;
    }
    else if (oper == '=' || oper == '<' || oper == '>' || oper == '!') {
        return 3;
    }
    else if (oper == '&') {
        return 2;
    }
    else if (oper == '|') {
        return 1;
    }
    else {
        return 0;
    }
}

void push(stack** top, node* treeNode) {
    stack* curr = *top;
    stack* ptr = (stack*)malloc(sizeof(stack));
    ptr->treeNode = treeNode;
    ptr->next = NULL;
    if (*top == NULL) {
        (*top) = ptr;
    }
    else {
        ptr->next = *top;
        *top = ptr;
    }
}

stack* pop(stack** top) {
    stack* curr = *top;
    *top = curr->next;
    free(curr);
}

node* prefixToTree(string prefix, int& index) {
    if (index >= prefix.length()) return NULL;

    char ch = prefix[index++];
    node* ptr = (node*)malloc(sizeof(node));
    ptr->value = ch;
    ptr->left = ptr->right = NULL;

    if (precedence(ch) != 0) {
        ptr->left = prefixToTree(prefix, index);
        ptr->right = prefixToTree(prefix, index);
    }
    return ptr;
}

void preOrderTraversal(node* root) {
    if (root != NULL) {
        cout << root->value << " ";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

int main() {
    string prefix = "&+*ab-c<xd|!cy+5<";
    int index = 0;
    node* root = prefixToTree(prefix, index);
    cout << "Prefix Expression: " << prefix << endl;
    cout << "Preorder Traversal: ";
    preOrderTraversal(root);
    cout << endl;
    return 0;
}