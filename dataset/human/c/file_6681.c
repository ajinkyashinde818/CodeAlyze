#include<stdio.h>
int main(void){
    int n,m,min,max,j;
    scanf("%d",&n);
    m=n-1;
    int r[m];
    scanf("%d",&r[0]);
    for(n=1;n<=m;n++){
        scanf("\n%d",&r[n]);
    }
    min=r[0];
    for(j=1;j<=m;j++){
        if(j==1){
            max=r[1]-min;
        }
        if(max<r[j]-min){
            max=r[j]-min;
        }
        if(min>r[j]){
            min=r[j];
        }
    }
    printf("%d\n",max);
    return 0;
}
