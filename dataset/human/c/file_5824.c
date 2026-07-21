#include<stdio.h>
int main(void){
    int n;
    int R[200000];
    int i,j;
    int max=-1000000000;
    int min;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&R[i]);
    min=R[0];
    for(i=1;i<n;i++){
        max=max<R[i]-min ? R[i]-min:max;
        min=min>R[i] ? R[i]:min;
    }
    printf("%d\n",max);
    return 0;
}
