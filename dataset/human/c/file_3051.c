#include <stdio.h>

int main(void)
{

  int a=0,b=0,i=0,B=0,K=0,N=0,answer=0,Max=0;
  
  scanf("%d %d",&K,&N);
  
  int A[N];
  
  while(i<N)
  {
    scanf("%d",&a);
    A[i]=a;
    i++;
  }
  
  a=A[0];
  b=A[1];
  Max=b-a;
  
  i=0;
  
  while(i<N-1)
  {
    a=A[i];
    b=A[i+1];
    
    B=b-a;
    
    if(Max<B)
    {
      Max=B;
    }
    i++;
  }
 
  a=A[N-1];
  b=A[0];
  B=K-a+b;
 
  if(Max<B)
   {
     Max=B;
   }
  
  answer=K-Max;
  
  printf("%d",answer);
  
  return 0;
}
