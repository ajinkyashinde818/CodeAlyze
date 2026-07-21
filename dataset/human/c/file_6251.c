#include <stdio.h>
int main(){
  int n,i,A[200000],j,max=-9999999999,min;

  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",&A[i]);

  min=A[0];

  for(j=1;j<n;j++){
      if(max<A[j]-min)
          max=A[j]-min;
      if(min>A[j])
          min=A[j];
  }
  
  printf("%d\n",max);
  return 0;
}
