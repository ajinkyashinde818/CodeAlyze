#include <stdio.h>
#include <stdlib.h>

int main()
{
  int n;
  int i;
  int ans = 0;
  
  scanf("%d", &n);

  int a[n];
  int b[n];
  int c[n-1];

  for(i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    a[i] = a[i] - 1;
  }

  for(i = 0; i < n; i++) {
    scanf("%d", &b[i]);
  }

  for(i = 0; i < n-1; i++) {
    scanf("%d", &c[i]);
  }

  for(i = 0; i < n; i++) {
    ans += b[a[i]];
    if(i != 0) {
      if((a[i] - a[i-1] == 1)) {
	ans += c[a[i-1]];
      }
    }
  }

  printf("%d\n", ans);
  
  return(0);
}
