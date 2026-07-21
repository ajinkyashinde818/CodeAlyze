#include<stdio.h>
#define N 2000000
int main()
{
  int i,j,n,D[N],max,min;

  scanf("%d",&n);

  for(i=0;i<n;i++)
    {
      scanf("%d",&D[i]);
    }


  min = D[0];
  max = D[1]-D[0];
   
  for(i=1;i<n;i++)
    {
      if(max < (D[i]-min))max = D[i]-min;
       
      if(min > D[i])min = D[i];
    }

  printf("%d\n",max);
  return 0;
}
