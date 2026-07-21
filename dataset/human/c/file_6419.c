#include <stdio.h>
int main(void){
    int n,t,j;
    int r[200000];
    int x;
    int max = 1-1000000000;
    int min ;
    scanf("%d\n",&n);
    for(t=0;t<=n;t++){
        scanf("%d",&r[t]);
        }
    min = r[0];
    for(t=1;t<=n-1;t++){
        x = r[t]-min;
        if(x>max){
            max=x;
        }
        if(r[t]<min){
            min=r[t];
        }
    }
printf("%d\n",max);
return 0;
}
