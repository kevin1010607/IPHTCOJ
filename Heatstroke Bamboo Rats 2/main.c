#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define left left_child
#define right right_child
typedef struct _NODE{
    int level;
    struct _NODE *left_child, *right_child;
}Node;
Node *newNode(int val){
    Node *res = (Node*)malloc(sizeof(Node));
    res->level = val, res->left = res->right = NULL;
    return res;
}
void build_tree(Node **now, int *arr, int l, int r){
    if(l > r) {*now = NULL; return;}
    int mid = (l+r)/2;
    *now = newNode(arr[mid]);
    build_tree(&((*now)->left), arr, l, mid-1);
    build_tree(&((*now)->right), arr, mid+1, r);
}
int query_heatstroke(Node *now, int x){
    if(now == NULL) return 0;
    if(x < now->level) return query_heatstroke(now->left, x);
    else if(x > now->level) return query_heatstroke(now->right, x);
    return 1;
}
void eat_rat(Node **root, int x){
    if(*root == NULL) return;
    if(x < (*root)->level) eat_rat(&((*root)->left), x);
    else if(x > (*root)->level) eat_rat(&((*root)->right), x);
    else{
        if(!(*root)->left || !(*root)->right){
            Node *tmp = *root;
            *root = (!(*root)->left)?(*root)->right:(*root)->left;
            free(tmp);
        }
        else{
            Node *tmp = (*root)->left;
            while(tmp->right) tmp = tmp->right;
            (*root)->level = tmp->level;
            eat_rat(&((*root)->left), tmp->level);
        }
    }
}
void buy_rat(Node **root, int x){
    if(!(*root)){*root = newNode(x); return;}
    if(x < (*root)->level) buy_rat(&((*root)->left), x);
    else buy_rat(&((*root)->right), x);
}
void free_tree(Node *root){
    if(!root) return;
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}
int n, q, a[10005], v;
char s[15];
Node *root;
int main(void){
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", a+i);
    build_tree(&root, a, 0, n-1);
    scanf("%d", &q);
    while(q--){
        scanf("%s %d", s, &v);
        if(!strcmp(s, "heatstroke")){
            if(query_heatstroke(root, v)){
                eat_rat(&root, v);
                printf("We might as well eat it.\n");
            }
            else printf("No dinner tonight.\n");
        }
        else if(!strcmp(s, "buy")){
            buy_rat(&root, v);
        }
    }
    free_tree(root);
    return 0;
}