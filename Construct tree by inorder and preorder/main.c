#include<stdio.h>
#include<stdlib.h>
typedef struct _NODE{
    int number;
    struct _NODE *ptr_to_left_node;
    struct _NODE *ptr_to_right_node;
} Node;
Node* newNode(int number){
    Node *ret = (Node*)malloc(sizeof(Node));
    ret->number = number, ret->ptr_to_left_node = ret->ptr_to_right_node = NULL;
    return ret;
}
Node* buildTree(int *inorder, int *preorder, int start, int end){
    if(start > end) return NULL;
    Node *root = newNode(preorder[0]);
    int idx = start;
    while(inorder[idx] != preorder[0]) idx++;
    root->ptr_to_left_node = buildTree(inorder, preorder+1, start, idx-1);
    root->ptr_to_right_node = buildTree(inorder, preorder+1+idx-start, idx+1, end);
    return root;
}
void showPostorder(Node *root){
    if(root){
        showPostorder(root->ptr_to_left_node);
        showPostorder(root->ptr_to_right_node);
        printf("%d ", root->number);
    }
}
void freeTree(Node *root){
    if(root){
        freeTree(root->ptr_to_left_node);
        freeTree(root->ptr_to_right_node);
        free(root);
    }
}
int n;
int main(void){
    int id = 1;
    while( ~scanf( "%d", &n ) ){
        int inorder[100], preorder[100];
        for( int i = 0; i < n; i++ )
            scanf( "%d", &inorder[i] );
        for( int i = 0; i < n; i++ )
            scanf( "%d", &preorder[i] );
        Node *root = buildTree( inorder, preorder, 0, n-1 );
        printf( "testcase%d: ", id++ );
        showPostorder( root );
        printf( "\n" );
        freeTree( root );
    }
    return 0;
}