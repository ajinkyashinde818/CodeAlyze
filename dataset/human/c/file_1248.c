#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int asc(const void *a,const void *b){
    return *(char *)a-*(char *)b;
}
int desc(const void *a,const void *b){
    return *(char *)b-*(char *)a;
}
int main(void){
    char s[101],t[101];
    scanf("%s",s);
    scanf("%s",t);
    qsort(s,strlen(s),sizeof(char),asc);
    qsort(t,strlen(t),sizeof(char),desc);
    if(strcmp(s,t)<0) printf("Yes");
    else printf("No");
    return 0;
}
