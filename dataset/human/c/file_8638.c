#include <stdio.h>

int main(){
  int n;  scanf("%d", &n);
  int a[100003];
  for(int i=1; i<=n; i++)  scanf("%d", a+i);

  int count = n;
  int now = 1;
  while(count--){
    now = a[now];
    if(now == 2){
      printf("%d\n", n-count);
      return 0;
    }
  }
  printf("-1\n");
  return 0;
}
