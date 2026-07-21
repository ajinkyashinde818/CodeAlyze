#include<stdio.h>

#define Max 200000

int main(){
  int i, j, n, R[Max], minv, maxv;

  scanf("%d", &n);

  for(i = 0 ; i < n ; i++) scanf("%d", &R[i]);

  maxv = R[1] - R[0];
  minv = R[0];

  for(j = 1 ; j <= n - 1 ; j++){
    //if(minv > R[j]) minv = R[j];
    if(maxv < R[j] - minv) maxv = R[j] - minv;
    if(minv > R[j]) minv = R[j];
  }

  printf("%d\n", maxv);

  return 0;
}
