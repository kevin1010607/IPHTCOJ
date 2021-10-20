#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int num = 1;
typedef struct _node{
    int data;
    struct _node *next, *prev;
}Node;
Node *newNode(int data){
    Node *ret = (Node*)malloc(sizeof(Node));
    ret->data = data, ret->next = ret->prev = NULL;
    return ret;
}
void insertNext(Node **head, int val){
    Node *tmp = newNode(val);
    tmp->next = (*head)->next;
    tmp->prev = *head;
    (*head)->next->prev = tmp;
    (*head)->next = tmp;
}
void deleteNext(Node **head){
    Node *tmp = (*head)->next;
    (*head)->next = tmp->next;
    tmp->next->prev = *head;
    free(tmp);
}
void move(Node **head, int val){
    if(val > 0) while(val--) *head = (*head)->next;
    else while(val++) *head = (*head)->prev;
}
void show(Node *head){
    Node *tmp = head->prev;
    while(head != tmp){
        printf("%d ", head->data);
        head = head->next;
    }
    printf("%d\n", head->data);
}
void freeList(Node *head){
    Node *tmp = head->prev;
    while(head != tmp){
        head = head->next;
        free(head->prev);
    }
    free(head);
}
int main(void){
    char buf[10];
    int val1, val2, n;
    scanf("%d %d", &val1, &n);
    Node *head = newNode(val1);
    head->next = head->prev = head;
    while(n--){
        scanf("%s", buf);
        if(!strcmp(buf, "insert")){
            scanf("%d %d", &val1, &val2);
            num += val2;
            while(val2--) insertNext(&head, val1);
        }
        else if(!strcmp(buf, "erase")){
            scanf("%d", &val1);
            num -= val1;
            while(val1--) deleteNext(&head);
        }
        else if(!strcmp(buf, "move")){
            scanf("%d", &val1);
            val1 %= num;
            move(&head, val1);
        }
        else if(!strcmp(buf, "show")){
            show(head);
        }
    }
    freeList(head);
    return 0;
}