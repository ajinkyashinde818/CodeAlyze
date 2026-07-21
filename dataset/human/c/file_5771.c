#include<stdio.h>

int main(){
    int i,j,n,r[200000]={0},max,min;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&r[i]);
    }   
    max=r[1]-r[0];
    min=r[0];
    for(i=1;i<n;i++){
        if(max<r[i]-min){
            max=r[i]-min;
        }   
        if(min>r[i])min=r[i];
    }   
    printf("%d\n",max);
    return 0;
}
