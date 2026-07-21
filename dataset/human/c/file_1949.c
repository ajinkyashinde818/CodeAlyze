#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int main(){
  int n,i;
  int a[30],b[30],c[30];
  int sum = 0;

  scanf("%d", &n);

  for(i = 1;i <= n;i++) scanf("%d", &a[i]);
  for(i = 1;i <= n;i++) scanf("%d", &b[i]);
  for(i = 1;i <= n - 1;i++) scanf("%d", &c[i]);

  for(i = 1;i <= n;i++){
    sum += b[a[i]];
    if(a[i] + 1 == a[i + 1]) sum += c[a[i]];
  }

  printf("%d\n", sum);

  return 0;
}
