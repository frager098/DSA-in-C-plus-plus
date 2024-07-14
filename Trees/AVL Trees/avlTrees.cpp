#include <iostream>
#include <cstdlib>
using namespace std;
struct node
{
    int value;
    int heightFromLeft;
    int heightFromRight;
    node *left;
    node *right;
};
//Function for finding minimum node from right subtree
int minimum(node *root)
{
    if (root->left == NULL)
    {
        cout << "minimum value is :" << root->value << endl;
        return root->value;
    }
    minimum(root->left);
}
//Function for finding maximum node from left subtree
int maximum(node *root)
{
    if (root->right == NULL)
    {
        cout << "maximum value is:" << root->value << endl;
        return root->value;
    }
    maximum(root->right);
}
//Function for calculating height of particular node
node * height(node *root)
{
    if (root->left != NULL && root->right != NULL)
    {

        if ((root->left)->heightFromRight >= (root->left)->heightFromLeft && (root->right)->heightFromLeft >= (root->right)->heightFromRight)
        {
            root->heightFromLeft = (root->left)->heightFromRight + 1;
            root->heightFromRight = (root->right)->heightFromLeft + 1;
        }
        else if ((root->left)->heightFromRight >= (root->left)->heightFromLeft && (root -> left)-> heightFromRight != 0 )
        {
            root->heightFromLeft = (root->left) ->heightFromRight + 1 ;
            root ->heightFromRight = ( root ->right)->heightFromRight + 1 ;
        }
        else if ((root->right)->heightFromLeft >= (root->right)->heightFromRight && (root -> right)-> heightFromLeft != 0 ) 
        {
            root->heightFromRight = (root->right)->heightFromLeft + 1;
            root -> heightFromLeft = ( root -> left)->heightFromLeft + 1;
        }
        else
        {
            root->heightFromLeft = (root->left)->heightFromLeft + 1;
            root->heightFromRight = (root->right)->heightFromRight + 1;
        }
    }
    else if (root->left != NULL && root->right == NULL)
    {
        if ((root->left)->heightFromRight >= (root->left)->heightFromLeft)
        {

            root->heightFromLeft = (root->left)->heightFromRight + 1;
        }
        else
        {
            root -> heightFromLeft = ( root -> left ) -> heightFromLeft + 1 ;
        }
        root->heightFromRight = 0;
    }
    else if (root->right != NULL && root->left == NULL)
    {
        if ((root->right)->heightFromLeft >= (root->right)->heightFromRight)
        {
            root->heightFromRight = (root->right)->heightFromLeft + 1;
        }
        else
        {
            root -> heightFromRight = (root -> right) -> heightFromRight + 1 ;
        }
        root->heightFromLeft = 0;
    }
    else
    {
            root->heightFromLeft = 0;
            root ->heightFromRight = 0 ;
    }
    return root;
}

void preOrderTraversal(node *root)
{
    if (root != NULL)
    {
        cout << "root value is:" << root->value << " and Height from left is:" << root->heightFromLeft << " and Height from Right is:" << root->heightFromRight;
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}
node *shiftRight(node *root)
{
    node* unBalanced = root ;
    node* temp = ( root -> left )-> right ;
    root = root -> left ;
    root -> right = unBalanced ;
    unBalanced -> left = temp ;
    return root ;
}
node *shiftLeft(node *root)
{
    node* unBalanced = root ;
    node* temp = ( root -> right )-> left ;
    root = root -> right ;
    root -> left = unBalanced ;
    unBalanced -> right = temp ;
    return root ;
}
node *balanceNode(node *root, int balanceFactor)
{
    //Checking the cases for double shifting by its children
    int balanceFactorOfLeftChild;
    int balanceFactorOfRightChild;
    if (root->left != NULL)
    {
        root->left = height(root->left);
        balanceFactorOfLeftChild = root->left->heightFromLeft - root->left->heightFromRight;
    }
    if (root->right != NULL)
    {
        root->right = height(root->right);
        balanceFactorOfRightChild = root->right->heightFromLeft - root->right->heightFromRight;
    }
    //For Shift left and Shift Right
    if (balanceFactor > 1 && balanceFactorOfLeftChild < 0)
    {
        root->left = shiftLeft(root->left);
        root->left->left = height(root->left->left);
        root->left = height(root->left);
        root = shiftRight(root);
        root->right = height(root->right);
        root = height(root);
        return root;
    }
    //For shift right and Shift left
    else if (balanceFactor < -1 && balanceFactorOfRightChild > 0)
    {
        root->right = shiftRight(root->right);
        root->right->right = height(root->right->right);
        root->right = height(root->right);
        root = shiftLeft(root);
        root->left = height(root->left);
        root = height(root);
        return root;
    }
    //Shift Right
    else if (balanceFactor > 1 )
    {
        root = shiftRight(root);
        root->right = height(root->right);
        root->heightFromRight = root->right->heightFromRight + 1;
        return root;
    }
    //Shift Left
    else 
    {
        root = shiftLeft(root);
        root->left = height(root->left);
        root->heightFromLeft += root->left->heightFromLeft + 1;
    }
    return root;
}

node *insert(node *root, int value)
{
    node *unBalanced = NULL;

    if (root == NULL)
    {
        node *ptr = (node *)malloc(sizeof(node));
        ptr->value = value;
        ptr->heightFromLeft = 0;
        ptr->heightFromRight = 0;
        ptr->left = NULL;
        ptr->right = NULL;
        root = ptr;
        cout<<"Value is Inserted!"<<endl;
        return root;
    }
    else if (value < root->value)
    {
        root->left = insert(root->left, value);
        root = height(root);
    }
    else
    {
        root->right = insert(root->right, value);
        root = height(root);
    }
    root = height(root);
    int balanceFactor = root->heightFromLeft - root->heightFromRight;
    if ((balanceFactor > 1 || balanceFactor < -1) && unBalanced == NULL)
    {
        unBalanced = root;
    }
    if (unBalanced)
    {
        root = balanceNode(unBalanced, balanceFactor);
    }
    return root;
}
//Function for deletion of Node
node *deleteNode(node *root, int value)
{
    if (root->value == value)
    {
        if (root->right == NULL && root->left == NULL)
        {
            free(root);
            cout<<"Node has been deleted!"<<endl;
            return NULL;
        }
        else if (root->left == NULL)
        {
            node *temp = root->right;
            free(root);
            cout<<"Node has been deleted!"<<endl;
            return temp;
        }
        else if (root->right == NULL)
        {
            node *temp = root->left;
            free(root);
            cout<<"Node has been deleted!"<<endl;
            return temp;
        }
        else if (root->left != NULL && root->right != NULL)
        {
            cout << "You wanna attach node from left or right?" << endl
                 << "Press 1 for left and 2 for right:" << endl;
            int check;
            cin >> check;
            int temp;
            if (check == 1)
            {
                temp = maximum(root->left);
                root -> left= deleteNode(root->left, temp);
                root->value = temp;
            }
            else if ( check == 2)
            {
                int temp = minimum(root->right);
                root -> right = deleteNode(root->right, temp);
                root->value = temp;
            }
            else
            {
                cout<<"Wrong input!"<<endl;
            }
        }
    }
    else
    {
        if (value < root->value)
        {
            root->left = deleteNode(root->left, value);
        }
        else
        {
            root->right = deleteNode(root->right, value);
        }
    }
    root = height(root);
    int balanceFactor = root->heightFromLeft - root->heightFromRight;
    if ( balanceFactor > 1 || balanceFactor < -1 )
    {
        root = balanceNode(root , balanceFactor);
        root = height(root);
    }
    return root;
}

void search ( node* root , int toSearch)
{
    if ( root == NULL)
    {
        cout<<"Value not found!"<<endl;
        return ;
    }
    if(root -> value == toSearch)
    {
        cout<<"Value found!"<<endl ;
        return;
    }
    else if(root -> value < toSearch )
    {
        search(root->right,toSearch);
    }
    else
    {
        search(root->left , toSearch);
    }
}
int main()
{
    node *root = NULL;
    int i = 10;
    while (i != 0)
    {
        cout << "Enter 0 for Exit" << endl;
        cout << "Enter 1 for insertion" << endl;
        cout << "Enter 2 for Post Order Traversal" << endl;
        cout << "Enter 3 to find minimum node" << endl;
        cout << "Enter 4 to find maximum node" << endl;
        cout << "Enter 5 to delete node" << endl;
        cout << "Enter 6 to Search node" << endl;
        cin >> i;
        if( i == 0 )
        {
            cout<<"Exit"<<endl;
        }
        else if (i == 1)
        {
            cout << "Enter value for node:";
            int value;
            cin >> value;
            root = insert(root, value);
        }
        else if (i == 2)
        {
            preOrderTraversal(root);
            cout<<endl;
        }
        else if (i == 3)
        {
            minimum(root->right);
        }
        else if (i == 4)
        {
            maximum(root-> left );
        }
        else if (i == 5)
        {
            cout << "Enter value to delete a node:"<<endl;
            int value;
            cin >> value;
            root = deleteNode(root , value);
        }
        else if ( i == 6 )
        {
            cout<<"Enter Value you want to Search:";
            int toSearch; cin >> toSearch;
            search(root,toSearch);
        }
        else
        {
            cout<<"Wrong input! Try Again"<<endl;
        }
    }
}