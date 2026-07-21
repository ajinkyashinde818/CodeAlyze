#include<stdio.h>
int n,a[20],b[20],c[19],i,r=0;
int main(){
    scanf("%d",&n);
    for(i=0;i<n;)scanf("%d",&a[i++]);
    for(i=0;i<n;){scanf("%d",&b[i]);r+=b[i++];}
    for(i=0;i<n-1;)scanf("%d",&c[i++]);
    for(i=0;i<n-1;i++)if(a[i+1]-a[i]==1)r+=c[a[i]-1];
    printf("%d",r);
    return 0;
}
