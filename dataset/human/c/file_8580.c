#include<stdio.h>
int main(){int n,i,j,c=1,a[100010];scanf("%d", &n);for(i=1;i<=n;i++)scanf("%d",&a[i]);for(j=a[1];j!=2;c++){j=a[j];if(c>n){printf("-1");return 0;}}printf("%d",c);return 0;}
