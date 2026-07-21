#include<stdio.h>
#define N 200000
main(){
  int i,min,max,n,r[N];
  scanf("%d",&n);
  for(i = 0; i < n; i++){
    scanf("%d",&r[i]);
  }
  max = r[1] - r[0];
  min = r[0];
  for(i = 1; i < n; i++){
    if(max > r[i]-min)max = max;
    else max = r[i]-min;
    if(min < r[i])min = min;
    else min = r[i];
  }
  printf("%d\n",max);
  return 0;
}
