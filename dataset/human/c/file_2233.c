#include <stdio.h>
#include <stdlib.h>


typedef struct p_tag{
    char c;
    struct p_tag *prev;
    struct p_tag *next;
} string;

int main(){
    char str[100002];
    int qn;
    int i;
    char q[10];
    int rot = 0;
    string *head, *tail, *buf, *buf_prev=NULL;

    (void)fgets(str, 100002, stdin);

    i = 0;
    while(str[i] != '\n'){
        buf = malloc(sizeof(string));
        if(i == 0){
            head = buf;
        }
        buf->c = str[i];
        buf->prev = buf_prev;
        buf->next = NULL;
        if(buf_prev != NULL){
            buf_prev->next = buf;
        }
        buf_prev = buf;
        i++;
    };
    tail = buf;

    (void)scanf("%d", &qn);
    (void)getchar();

    for(i=0; i < qn; i++){
        (void)fgets(q, 10, stdin);
        if(q[0] == '1'){
            rot++;
        }else{
            if(q[2] == '1' && rot % 2 == 0 || q[2] == '2' && rot % 2 == 1){
                buf = malloc(sizeof(string));
                buf->c = q[4];
                buf->next = head;
                buf->prev = NULL;
                head->prev = buf;
                head = buf;
            }else{
                buf = malloc(sizeof(string));
                buf->c = q[4];
                buf->next = NULL;
                buf->prev = tail;
                tail->next = buf;
                tail = buf;
            }
        }
    }
    if(rot % 2 == 0){
        putchar(head->c);
        while(1){
            head = head->next;
            if(head == NULL){
                putchar('\n');
                return 0;
            }
            putchar(head->c);
        }
    }else{
        putchar(tail->c);
        while(1){
            tail = tail->prev;
            if(tail == NULL){
                putchar('\n');
                return 0;
            }
            putchar(tail->c);
        }
    }
}
