#include <stdio.h>

int main(void){
    int i,k,n,a,b,c,max;
    max=0;
    scanf("%d %d",&k,&n);
    scanf("%d",&c);
    b=c;
    for(i=1;i<n;i++){
        scanf("%d",&a);
        if(a-b>max)max=a-b;
        b=a;
    }
    if((k+c-a)>max){
            max=k+c-a;
    }
    printf("%d",k-max);
    return 0;
}
