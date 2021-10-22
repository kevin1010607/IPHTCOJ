#include<stdio.h>
#include<stdlib.h>
typedef struct _NODE{
    int level;
    struct _NODE *left_child, *right_child;
}Node;
Node *newNode(int level){
    Node *res = (Node*)malloc(sizeof(Node));
    res->level = level;
    res->left_child = res->right_child = NULL;
    return res;
}
void build_tree(Node **root, int *arr, int l, int r){
    if(l > r) {*root = NULL; return;}
    int mid = (l+r)/2;
    *root = newNode(arr[mid]);
    build_tree(&((*root)->left_child), arr, l, mid-1);
    build_tree(&((*root)->right_child), arr, mid+1, r);
}
int query_heatstroke(Node *root, int x){
    if(root == NULL) return 0;
    if(x < root->level) return query_heatstroke(root->left_child, x);
    else if(x > root->level) return query_heatstroke(root->right_child, x);
    else return 1;
}
void eat_rat(Node **root, int x){
    if(*root == NULL) return;
    if(x < (*root)->level) eat_rat(&((*root)->left_child), x);
    else if(x > (*root)->level) eat_rat(&((*root)->right_child), x);
    else{
        if((*root)->left_child==NULL || (*root)->right_child==NULL){
            Node *tmp = *root;
            *root = ((*root)->left_child)?(*root)->left_child:(*root)->right_child;
            free(tmp);
        }
        else{
            Node *tmp = (*root)->left_child;
            while(tmp->right_child) tmp = tmp->right_child;
            (*root)->level = tmp->level;
            eat_rat(&((*root)->left_child), tmp->level);
        }
    }
}
void freeTree(Node *root){
    if(!root) return;
    freeTree(root->left_child);
    freeTree(root->right_child);
    free(root);
}
int n, q, x, s[1000005];
int main(void){
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", s+i);
    Node *root = NULL;
    build_tree(&root, s, 0, n-1);
    scanf("%d", &q);
    while(q--){
        scanf("%d", &x);
        if(query_heatstroke(root, x)){
            eat_rat(&root, x);
            printf("We might as well eat it.\n");
        }
        else printf("No dinner tonight.\n");
    }
    freeTree(root);
    return 0;
}