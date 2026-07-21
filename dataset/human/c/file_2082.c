#include <stdio.h>
typedef long long ll;

int main(void) {
  ll i, j, k, num[10] = {0, 1, 2, 3, 4, 5, 5, 4, 3, 2}, ans = 0;
  char n[1000010];
  bool b = false;
  scanf("%s", n);
  for(i = 0; n[i]; ++i) {
    if(n[i] > '4') {
      if(n[i] > '5') {
        if(b) ans += num[n[i] - '0'] - 2;
        else ans += num[n[i] - '0'];
        b = true;
      } else {
        if(b) ans += 4;
        else if(n[i + 1] > '4') ans += 6, b = true;
        else ans += 5;
      }
    } else if(b && n[i] > '3') {
      if(n[i + 1] > '4') ans += 5;
      else ans += 4, b = false;
    } else ans += num[n[i] - '0'], b = false;
  }
  printf("%lld", ans);
  return 0;
}
