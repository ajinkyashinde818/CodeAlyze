#include <stdio.h>
#include <math.h>
#include <limits.h>
#define N 200000
int main() {
  int n,i,min,max,R[N];
  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&R[i]);
  min=R[0];
  max=-1000000000;
  for(i=1;i<n;i++){
    if(max<R[i]-min)max=R[i]-min;
    if(min>R[i])min=R[i];
  }
  printf("%d\n",max);
  return 0;
}
