#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int up(const void *a,const void *b){
    char x = *(const char*)a, y = *(const char*)b;
    return  x - y;
}

int down(const void *a,const void *b){
    char x = *(const char*)a, y = *(const char*)b;
    return y - x;
}

int main(void){
    char s[101],t[101];
    int size_S,size_T;
    
    scanf("%s %s",s,t);
    size_S = strlen(s);
    size_T = strlen(t);
    
    qsort(s,size_S,sizeof(char),up);
    qsort(t,size_T,sizeof(char),down);
    
    if(strcmp(s,t) < 0)printf("Yes\n");
    else printf("No\n");
}
