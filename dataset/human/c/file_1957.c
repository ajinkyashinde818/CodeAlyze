#include<stdio.h>
#include<math.h>
#include<stdlib.h>
 
int N,A[21],B[21],C[21];

int main()
{
  int i,j;
  scanf("%d",&N);
  for(i=1;i<N+1;i++)
  {
    scanf("%d",&A[i]);
  }
  for(i=1;i<N+1;i++)
  {
    scanf("%d",&B[i]);
  }
  for(i=1;i<N;i++)
  {
    scanf("%d",&C[i]);
  }
  
  j=0;
  for(i=1;i<N+1;i++)
  {
    j+=B[i];
    
    if(i<N)
    {
      if(A[i+1]==A[i]+1)
      {
        j+=C[A[i]];
        
      }
    }
  }
          
  
  
  printf("%d",j);

  return 0;
}
