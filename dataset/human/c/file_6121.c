#include<stdio.h>

int main()
{
  int n,i=0,j,A[200000],res,res1,mini,a,max=-1000000000;

  scanf("%d",&n);
  for(i=0; i<n; i++){
    scanf("%d",&A[i]);
  }
  mini = A[0];
  for(i=1; i<n; i++){
       a = A[i]-mini;
       if(a > max) max = a;
      if(A[i] <mini) mini = A[i];
    }
    
  printf("%d\n",max);
  return 0;
}
