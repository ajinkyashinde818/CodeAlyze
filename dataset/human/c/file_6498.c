#include<stdio.h>
#include<stdlib.h>
int main(void){
  int i, n, mi, ma, A;
  int *R;
  while(1){
  scanf("%d", &n);
  if(n >= 2 && n <= 200000)   break;
  }
  R = (int*)malloc(sizeof(int) * n);
  for(i=0; i<n; i++){
    while(1){
      scanf("%d", &R[i]);
      if(R[i]>=1 && R[i]<=1000000000)break;
    }
  }
  mi = R[0];
  ma = R[1] - mi;
  for(i=1 ;i<n; i++){
    if(ma<R[i]-mi)      ma=R[i]-mi;
    if(mi>R[i])         mi=R[i];
  }
  printf("%d\n", ma);
  free(R);
  return 0;
}
