#include<stdio.h>
#include<stdlib.h>
int main(void){
    int n,max,min,*p,i=0,j=0;
    scanf("%d",&n);
    p=malloc(sizeof(int)*n);
    while(scanf("%d",p+i)==1){
        if(i==n-1)break;
        i++;
    }
    max=*(p+1)-*p;
    min=*(p);
    for(j=1;j<=n-1;j++){
        if((*(p+j)-min)>max){
            max=*(p+j)-min;
        }
        if(min>*(p+j)){
            min=*(p+j);
        }
    }
    free(p);
    printf("%d\n",max);
    return 0;
}
