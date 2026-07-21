#include <stdio.h>

int main(void){
  int i;

  int n;
  scanf("%d", &n);

  int sum = 0;
  int a[n],b[n],c[n-1];
  for(i = 0; i < n; i++){
    scanf("%d", &a[i]);
  }
  for(i=0; i<n; i++){
    scanf("%d", &b[i]);
    sum += b[i];
  }
  for(i=0; i<n-1; i++){
    scanf("%d", &c[i]);
  }

  for(i=0; i<n-1; i++){
    if(a[i+1]-a[i] == 1){
      sum += c[a[i]-1];
    }
  }

   printf("%d\n", sum);

  return 0;
}
