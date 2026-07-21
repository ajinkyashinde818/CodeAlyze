#include<stdio.h>
int main()
{
    int n,i,s,s2,sum;
    scanf("%d",&n);
    int a[n],b[n],c[n];
    for(i=0;i<n;i++){
    scanf("%d",&a[i]);
    }
    s=0;
    for(i=0;i<n;i++){
    scanf("%d",&b[i]);
    s=s+b[i];
    }
    for(i=0;i<n-1;i++){
    scanf("%d",&c[i]);
    }
    s2=0;
    for(i=1;i<n;i++){
    if(a[i]-a[i-1]==1){
        s2=s2+c[a[i-1]-1];
    }
    }
    sum=s+s2;
    printf("%d\n",sum);
    return 0;
}
