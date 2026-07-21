#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//qsort用降順
int cmp(const void *a,const void *b){
    if(*(int*)a>*(int*)b){return 1;}
    else if(*(int*)a<*(int*)b){return -1;}
    else {return 0;}
}


int main(void){
    int a[10000];
for(int i=0;i<10000;i++){
scanf("%d",&a[i]);
}
for(int i=0;i<10000;i++){
printf("Case %d: %d\n",i+1,a[i]);
}
return 0;
}
