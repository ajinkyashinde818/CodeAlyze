#include<stdio.h>

int main(){
  int n,k,i;
  int a[200000];
  int max = -10;

  scanf("%d %d", &k, &n);

  for(i = 0;i < n;i++) scanf("%d", &a[i]);

  for(i = 1;i < n;i++){
    if(max < (a[i] - a[i - 1])) max = a[i] - a[i - 1];
  }

  if((k - a[n - 1] + a[0]) > max) max = k - a[n - 1] + a[0];

  printf("%d\n", k - max);

  return 0;
}
