#include <stdio.h>

int main(){
  int a, b, c, ans;

  scanf("%d %d %d", &a, &b, &c);

  ans = 0;
  while (1) {
    if (c > 0) {
      ans++;
      c--;
      if (b > 0) {
        ans++;
        b--;
      }
      else if (a > 0) {
        a--;
      }
      else {
        break;
      }
    }
    else if (c == 0) {
      break;
    }
  }

  while (1) {
    if (b > 0) {
      ans++;
      b--;
    }
    else {
      break;
    }
  }

  printf("%d\n", ans);

  return 0;
}
