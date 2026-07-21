#include<stdio.h>
#include<string.h>

typedef struct{
    int kind;
    int f;
    char c;
}query;

typedef struct{
    char mbuf[200000];
    int size;
}buffer;

int main(void){
    char i_s[100001];
    scanf("%s",i_s);
    int q_n;
    scanf("%d",&q_n);
    query q[q_n];
    buffer f,b;
    f.size = 0;
    b.size = 0;
    buffer *tf,*tb;
    tf = &f;
    tb = &b;
    for(int i = 0;i < q_n;i++){
        scanf("%d",&q[i].kind);
        if(q[i].kind == 2)scanf("%d %c",&q[i].f,&q[i].c);
    }
    for(int i = 0;i < q_n;i++){
        if(q[i].kind == 1){
            buffer *tmp = tf;
            tf = tb;
            tb = tmp;
            continue;
        }
        if(q[i].f == 1){
            tf->size++;
            tf->mbuf[tf->size-1] = q[i].c;
        }
        else {
            tb->size++;
            tb->mbuf[tb->size-1] = q[i].c;
        }
    }
    for(int i = tf->size-1;i >= 0;i--)printf("%c",tf->mbuf[i]);
    if(tf == &b)for(int i = strlen(i_s)-1;i >= 0;i--)putchar(i_s[i]);
    else printf("%s",i_s);
    for(int i = 0;i < tb->size;i++)printf("%c",tb->mbuf[i]);
    return 0;
}
