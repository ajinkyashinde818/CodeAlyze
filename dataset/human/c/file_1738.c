#include<stdio.h>
int main()
{
  int n,i,sum;
  sum=0;
  scanf("%d",&n);
  
  int a[n],b[n],c[n];
  for(i=0;i<n;++i)
  {scanf("%d",&a[i]);}
  
  for(i=0;i<n;++i)
  {scanf("%d",&b[i]);
  sum=sum+b[i];
  }
  
  for(i=0;i<n;++i)
  {scanf("%d",&c[i]);
  }
  
  for(i=0;i<n;++i)
  {
  if(a[i+1]-a[i]==1) sum=sum+c[a[i]-1];  
  }
  
  printf("%d",sum);
return 0;  
}
