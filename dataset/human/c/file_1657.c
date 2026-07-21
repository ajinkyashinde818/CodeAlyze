#include<stdio.h>
 
int main()
{
  int n=0,i;
  scanf("%d",&n);
  
  int a[n],b[n],c[n],sum=0;
  
  for(i=0;i<n;i++)
  scanf("%d",&a[i]); 
  
  for(i=0;i<n;i++)
   scanf("%d",&b[i]);

  for(i=0;i<n-1;i++)
   scanf("%d",&c[i]); 
  
   sum+=b[n-1];
  for(i=0;i<n-1;i++)
  {
    sum+=b[i];
    if(a[i]+1==a[i+1])
    sum+=c[a[i]-1];
  }
  printf("%d\n",sum);
  
 return 0; 
}
