#include<stdio.h>

int main()
{
  int n, d, x, a[100];

  scanf("%d", &n);
  scanf("%d %d", &d, &x);
  for(int i = 0; i < n; i++){
    scanf("%d", &a[i]);
  }

  int ans;

  for(int i = 0; i < n; i++){
    int count = 0;
    while(1){
      if(count * a[i] + 1 <= d){
        ans++;
        count++;
      }else{
        break;
      }
    }
  }

  ans = ans + x;

  printf("%d", ans);

  return 0;
}
