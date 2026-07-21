#include<stdio.h>
#include<stdlib.h>

int maxprofit(int *A,int n)
{
  int i,pro,min;
  pro=A[1]-A[0];
  min=A[0];
  for(i=1;i<n;i++){
    /* min???A[0]..A[i-1]?????§???????°???????*/
    /* pro?????????????????§?????? */
    if(A[i]-min>pro) pro=A[i]-min;
    if(min>A[i]) min=A[i];
  }
  return pro;
}

int main()
{
  int *A;
  int i,n;
  scanf("%d",&n);
  A=malloc(n*sizeof(int));
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  printf("%d\n",maxprofit(A,n));
  return 0;
}
