#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int comp(const void *a,const void *b){
    return -strcmp((char*)a,(char*)b);
}

int main(void){
    char s[101],t[101];
    scanf("%s %s",s,t);
    qsort(s,strlen(s),1,strcmp);
    qsort(t,strlen(t),1,comp);
    if(strcmp(s,t) < 0)puts("Yes");
    else puts("No");
    return 0;
}
