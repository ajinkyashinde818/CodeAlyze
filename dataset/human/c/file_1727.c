#include<stdio.h>

int main()
{
    int n,i,t=0;
    scanf("%d",&n);
    int a[n],b[n],c[n-1];
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
        }
    for(i=0;i<n;i++){
        scanf("%d",&b[i]);
        }
    for(i=0;i<n-1;i++){
        scanf("%d",&c[i]);
        }
    for(i=0;i<n;i++){
        if(a[i-1]==a[i]-1&&i!=0){
            t=t+b[a[i]-1]+c[a[i]-2];
        }
        else{
                t=t+b[a[i]-1];
        }
        }
        printf("%d",t);

    }
