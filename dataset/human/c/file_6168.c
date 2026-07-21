#include<stdio.h>
#define N 200000
int main(){
 
  int i, j, R[N], n, max = 0, min;
 
  scanf("%d",&n);
 
  for(j = 0;j < n;j++) scanf("%d",&R[j]);
 
  min = R[0];
  max = R[1] - R[0];
  for(j = 1;j < n;j++){
    if( max < R[j]-min ) max = R[j] - min;
    else max = max;
    if( min < R[j] ) min = min;
    else min = R[j];
  }
 
  printf("%d\n",max);
  return 0;
}
