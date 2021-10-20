#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define next ptr_to_next_node
#define prev ptr_to_prev_node
#define ch character
typedef struct _NODE{
    char character;
    struct _NODE *ptr_to_next_node;
    struct _NODE *ptr_to_prev_node;
}Node;
Node *newNode(char, Node*, Node*);
void insert(Node**, char);
void deletion(Node**);
void backspace(Node**);
void go_left(Node**, int);
void go_right(Node**, int);
void go_home(Node**);
void go_end(Node**);
void show(Node *head){
    Node *now = head->next;
    while(now != head){
        printf("%c ", now->ch);
        now = now->next;
    }
    puts("");
}
void freeList(Node *head){
    Node *now = head->next;
    while(now != head){
        now = now->next;
        free(now->prev);
    }
    free(now);
}
Node *head, *tail, *cursor;
int main(void){
    head = newNode('\0', NULL, NULL);
    head->next = head->prev = head;
    tail = cursor = head;
    char buf[10], c;
    int n, val;
    scanf("%d", &n);
    while(n--){
        scanf("%s", buf);
        if(!strcmp(buf, "insert")){
            getchar();
            scanf("%c", &c);
            insert(&cursor, c);
        }
        else if(!strcmp(buf, "deletion")){
            deletion(&cursor);
        }
        else if(!strcmp(buf, "backspace")){
            backspace(&cursor);
        }
        else if(!strcmp(buf, "go_left")){
            scanf("%d", &val);
            go_left(&cursor, val);
        }
        else if(!strcmp(buf, "go_right")){
            scanf("%d", &val);
            go_right(&cursor, val);
        }
        else if(!strcmp(buf, "go_home")){
            go_home(&cursor);
        }
        else if(!strcmp(buf, "go_end")){
            go_end(&cursor);
        }
        else if(!strcmp(buf, "show")){
            show(head);
        }
    }
    freeList(head);
    return 0;
}
Node *newNode(char c, Node *p, Node *n){
    Node *ret = (Node*)malloc(sizeof(Node));
    ret->ch = c, ret->prev = p, ret->next = n;
    return ret;
}
void insert(Node **cur, char c){
    Node *tmp = newNode(c, *cur, (*cur)->next);
    (*cur)->next->prev = tmp;
    (*cur)->next = tmp;
}
void deletion(Node **cur){
    if((*cur)->next == tail) return;
    Node *tmp = (*cur)->next;
    (*cur)->next = tmp->next;
    (*cur)->next->prev = *cur;
    free(tmp);
}
void backspace(Node **cur){
    if(*cur == head) return;
    Node *tmp = *cur;
    tmp->prev->next = tmp->next;
    tmp->next->prev = tmp->prev;
    *cur = tmp->prev;
    free(tmp);
}
void go_left(Node **cur, int step){
    while(step--) *cur = (*cur)->prev;
}
void go_right(Node **cur, int step){
    while(step--) *cur = (*cur)->next;
}
void go_home(Node **cur){
    *cur = head;
}
void go_end(Node **cur){
    *cur = head->prev;
}