#include<stdio.h>
int main(void)
{
 int n,d,x,i,j,a[100],s;
 scanf("%d%d%d",&n,&d,&x);
 
 for(i=0;i<n;i++)
   scanf("%d",&a[i]);
 s=0;
for(i=0;i<n;i++){
  for(j=1;j<=d;j=j+a[i])
    s=s+1;
}
 
 printf("%d\n",s+x);
return 0;
}
