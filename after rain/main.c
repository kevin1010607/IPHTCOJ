#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct _NODE
{
    char color[10];
    struct _NODE *next;
} Node;
void insert(Node** head, char* color, int dest){
    Node *now = *head, *ist = (Node*)malloc(sizeof(Node));
    strcpy(ist->color, color);
    while(dest-- && now->next) now = now->next;
    ist->next = now->next;
    now->next = ist;
}
void erase1(Node** head, int dest){
    if(!(*head)->next) return;
    Node *now = *head, *tmp; dest--;
    while(dest-- && now->next->next) now = now->next;
    tmp = now->next;
    now->next = now->next->next;
    free(tmp);
}
void erase2(Node** head, char* color){
    Node *now = *head, *tmp;
    while(now->next){
        if(!strcmp(now->next->color, color)){
            tmp = now->next;
            now->next = now->next->next;
            free(tmp);
        }
        else now = now->next;
    }
}
void reverse(Node** head, int dest1, int dest2){
    Node *pre = *head, *node, *now;
    for(int i = 0; i<dest1-1 && pre->next; i++) pre = pre->next;
    if(!pre->next) return;
    node = pre->next, now = pre->next->next;
    for(int i = 0; i<dest2-dest1 && now; i++){
        node->next = now->next;
        now->next = pre->next;
        pre->next = now;
        now = node->next;
    }
}
void show(Node **head) {
    Node *now = (*head)->next;
    while(now!=NULL) {
        printf("%s ", now->color);
        now = now->next;
    }
    puts("");
}
int n;
char buf[100];
int num1, num2;
Node *head;
int main() {
    head = (Node*)malloc(sizeof(Node)); // create an empty node
    memset(head->color,'\0',sizeof(head->color));
    head->next = NULL;
    scanf("%d",&n);
    while(n--) {
        scanf("%s",buf);
        if(!strcmp(buf,"insert")) {
            scanf("%s%d",buf,&num1);
            insert(&head, buf, num1); // insert <color> <dest>
        }
        else if(!strcmp(buf,"erase1")) {
            scanf("%d",&num1);
            erase1(&head, num1); // erase1 <dest>
        }
        else if(!strcmp(buf,"erase2")) {
            scanf("%s",buf);
            erase2(&head, buf); // erase2 <color>
        }
        else if(!strcmp(buf,"reverse")) {
            scanf("%d%d",&num1,&num2);
            reverse(&head, num1, num2); // reverse <dest1> <dest2>
        }
        else if(!strcmp(buf,"show")) {
            show(&head);
        }
    }
    return 0;
}