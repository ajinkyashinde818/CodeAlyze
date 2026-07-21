#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int comp(const void *a,const void *b){
    return -strcmp((char*)a,(char*)b);
}
int main(void){
    char s[100+5], t[100+5];
    scanf("%s %s", s, t);
    
    qsort(s, strlen(s), sizeof(char), strcmp);
    qsort(t, strlen(t), sizeof(char), comp);
    if(strcmp(s, t)>=0)printf("No\n");
    else printf("Yes\n");
}
