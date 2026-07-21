#include<stdio.h>
int main()
{
  int i,n,x,b,a,m,r;
  
  scanf("%d%d%d",&n,&b,&a);
  
  if(b>a) m=a;
  
  else m=b;
  
  for(i=2;i<n;i++)
    
    {
      
      scanf("%d",&x);
      if(x>a) a=x;
      if(x-m>a-b)
	
    {
      
      a=x;
      b=m;
    }
      
      if(x<m) m=x;
      
    }
  r=a-b;
  
  
  printf("%d\n",r);
  return 0;
}
