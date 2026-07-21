#include <stdio.h>
#define N 200000
int main()
{
    int i,j,min,n,A[N],max;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
      scanf("%d",&A[i]);
    }
    max=-2000000000;
    min=A[0];
    for(i=1;i<n;i++)
    {
      if(A[i]-min>max)
      max=A[i]-min;
      if(A[i]<min)
      min=A[i];
    }
    printf("%d\n",max);
    return 0;
}
