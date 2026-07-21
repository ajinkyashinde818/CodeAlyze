#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int asc(const void *a,const void *b){
    return *(char*)a-*(char*)b;
}
int main(void){
    char a[4];
    scanf("%s",a);
    qsort(a,3,sizeof(char),asc);
    if(strcmp(a,"abc")==0) printf("Yes");
    else printf("No");
    return 0;
}
