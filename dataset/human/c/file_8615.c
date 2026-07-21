#include <stdio.h>

int main(void){
  int a[100000], n, i, count=0;
  scanf("%d", &n);
  for(i=0; i<n; ++i){
    scanf("%d", &a[i]);
  }
  i=0;
  while(i!=1){
    count +=1;
    i = a[i]-1;
    if (count > n) break;
  }
  if (i!=1) printf("%d\n", -1);
  else printf("%d\n", count);
  return 0;
}
