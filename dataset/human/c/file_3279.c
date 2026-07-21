#include <stdio.h>
int main(void){
    int k,n,max=0;
    scanf("%d %d",&k,&n);
    int a[n];
    for(int i=0; i<n; i++)
        scanf("%d",&a[i]);
    for(int i=0; i<n-1; i++){
        if(a[i+1]-a[i]>max)
            max=a[i+1]-a[i];
    }
    if(k+a[0]-a[n-1]>max)
            max=k+a[0]-a[n-1];
    printf("%d",k-max);
}
