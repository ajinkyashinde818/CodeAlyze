#include<stdio.h>

int main(){
  int i, j, n, max, min, res;
  int a[200000];

  scanf("%d", &n);
  for(i=0; i<n; i++){
    scanf("%d", &a[i]);
  }

  min = a[0];
  res = a[1] - min;
  if(res < 0) min = a[1];
  
  for(i=2; i<n; i++){
    if(a[i]- min > res) res = a[i]- min;
    else if(min > a[i])  min = a[i];
  }

  printf("%d\n", res);
}
