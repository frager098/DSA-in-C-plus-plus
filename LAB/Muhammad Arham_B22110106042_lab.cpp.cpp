#include <iostream>
#include <cstdlib>
using namespace std ;
struct node
{
    int value ;
    node* left ;
    node*right ;
    int height = 0 ;
};
// Part a
int median(int * S , int size )
{
    int mid = 0 + size / 2 ;
    cout<<"Median Value is :"<<S[mid]<<endl;
    return S[mid];
}
int* forS1( int* S , int size , int M , int * S1)
{
    cout<<"why";
    int lastIndex = M / 2 ;
    cout<<lastIndex<<endl;
    for ( int i = 0 ; i <= lastIndex ; i++)
    {   cout<<"ok"<<endl;
        int j = 0 ;
        S1[j] = S[i];
        j++ ;
    }
    return S1;
}
int* forS2( int* S , int size , int M ,int* S2)
{
    int startingIndex = M/2 ;
    int lastIndex = M  ;
    // int *S2=S;
    for ( int i = (M/2) + 1 ; i < lastIndex ; i++)
    {   int j = 0 ;
        S2[j] = S[i];
        j++ ;
    }
    return S2;
}
int* forS3( int* S , int size , int M , int * S3)
{
    int startingIndex = M + 1;
    int lastIndex =  ( (3*M)/ 2) + 1 ;
    for ( int i = startingIndex ; i <= lastIndex ; i++)
    {
        int j = 0 ;
        S3[j] = S[i];
        j++ ;
    }
    return S3;
}
int* forS4( int* S , int size , int M , int* S4)
{
    int startingIndex = ( (3*M)/+2); 
    int lastIndex = size;

    for ( int i = startingIndex ; i <= lastIndex ; i++)
    {
        int j = 0 ;
        S4[j] = S[i];
        j++ ;
    }
    return S4;
}
void printArray(int*S , int size)
{
    
    // size = (sizeof(S)/sizeof(S[0]) );
        cout<<size<<"inPRint"<<endl;
    for ( int i = 0  ; i <= size ; i++ )
    {
        cout<<S[i]<<"--->";
    }
    cout<<endl;
}
node* height( node * root )
{
    if( root -> left == NULL && root -> right == NULL )
    {
        root -> height = 0 ;
    }
    else if( root -> left != NULL  )
    {
        root -> height = root -> left ->height + 1 ;
    }
    else if ( root -> right != NULL)
    {
        root ->height = root -> right ->height + 1 ;
    }
    else if (root -> left != NULL && root -> right != NULL )
    {
        if ( root -> left -> height > root -> right -> height )
        {
            root ->height = (root -> left) -> height+ 1  ;
        }
        else
        {
            root -> height = root -> right -> height + 1 ;
        }
    }
    return root ;
}
node* insert ( int *S , node* root)
{   int level = 1 ;
    int size = sizeof(S)/sizeof(S[0]);
    for ( int i = 0 ; i < size ; i ++)
    {

    if ( root == NULL )
    {
        node* temp = (node* )malloc(sizeof(node));
        temp -> value = S[i];
        temp -> left = NULL ;
        temp -> right = NULL ;
        root = temp ;
        cout<<"level of node is:"<<level<<endl;
        root = height ( root);
        return root ;
    }
    else if( S[i] < root->value)
    {
        root -> left = insert(S,root->left);
    }
    else
    {
        root -> right = insert(S,root->right);
        
    }
    }
    level++;
    return root ;
}

int main(){
    int M ; int root ; int * S1; int * S2; int* S3 ; int *S4; int rootIndex; node* ptr1 = NULL;node* ptr2=NULL;node*ptr3=NULL ; node*ptr4=NULL;
    int S[]={22,44,75,90,92,99,110,112,125,130,131};
    int size = sizeof(S)/sizeof(S[0]);
    cout<<size<<endl;
    M =  median(S , size);
    rootIndex = size/2;
    int i = 100 ;
    while ( i != 0 )
    {
        cout<<"Enter 1 to get Median M of a given array S"<<endl;
        cout<<"Enter 2 to divide given array S into 4 parts S1 , S2 , S3 , S4"<<endl;
        cin>> i ;
        if ( i== 1)
        {
        cout<<size<<endl;
        M =  median(S , size);
        // cout<<;
        }
        else if ( i == 2 )
        {
            root = M ;
            S1 = forS1(S , size , rootIndex , S1);
            printArray(S1,rootIndex/2);
            S2 = forS2(S , size , rootIndex , S2);
            S3 = forS3(S , size , rootIndex , S3);
            S4 = forS4(S , size , rootIndex , S4);
            printArray(S2,rootIndex);
            printArray(S3,(3*rootIndex)/2 );
            printArray(S4,2*rootIndex);

        }
        else if ( i ==3 )
        {
            int S1[] ={22,44,75};
            int S2[] ={90,22,99};
            int S3[] ={110,112,125};
            int S4[] ={130,131};
            ptr1 = insert(S1 , ptr1 );
            ptr2 = insert(S2 , ptr2 );
            ptr3 = insert(S3 , ptr3 );
            ptr4 = insert(S4 , ptr4 );
        }
        }
}