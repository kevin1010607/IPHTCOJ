#include<stdio.h>
#include<stdlib.h>
typedef struct _node{
    int number;
    struct _node *next;
}Node;
Node *createList(int);
void freeList(Node*);
int solveJosephus(Node**, int);
int main(void){
    int n, k;
    while(~scanf("%d %d", &n, &k)){
        Node *head = createList(n);
        printf("%d\n", solveJosephus(&head, k));
        freeList(head);
    }
    return 0;   
}
Node *newNode(int data){
    Node *ret = (Node*)malloc(sizeof(Node));
    ret->number = data, ret->next = NULL;
    return ret;
}
Node *createList(int n){
    Node *head = newNode(1);
    Node *now = head;
    for(int i = 2; i <= n; i++){
        now->next = newNode(i);
        now = now->next;
    }
    now->next = head;
    return head;
}
void freeList(Node *head){
    Node *now = head->next;
    while(now != head){
        Node *tmp = now;
        now = now->next;
        free(tmp);   
    }
    free(now);
}
int solveJosephus(Node **head, int step){
    int n = 1;
    Node *now = *head;
    while(now->next != *head) now = now->next, n++;
    *head = now;
    int t = n-1;
    while(t--){
        int s = (step-1)%n;
        while(s--) *head = (*head)->next;
        Node *tmp = (*head)->next;
        (*head)->next = tmp->next;
        free(tmp);
        n--;
    }
    return (*head)->number;
}