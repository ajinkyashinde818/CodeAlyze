#include<stdio.h>

int main(void)
{
 int n,d,x,a[100],s;
 int i,j;
 scanf("%d%d%d",&n,&d,&x);
 for(i=0;i<n;i++) scanf("%d",&a[i]);
 s=0;
 for(i=0;i<n;i++){
    for(j=1;j<=d;j+=a[i]) s++;
  }
 s+=x;
 printf("%d\n", s);
 return 0;
}
