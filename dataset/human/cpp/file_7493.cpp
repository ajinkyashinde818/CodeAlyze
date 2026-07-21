#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int n;
double a[1000000], ans, whole, above, bottom;

int main(void){
    // Here your code !
    scanf("%d", &n);
    whole = 0;
    for (int i = 0; i < n; ++i) {
      scanf("%lf", &a[i]);
      whole += a[i];
    }
    if (n == 2) {
      ans = a[0] - a[1];
      printf("%d\n", (int)abs(ans));
    }
    else{
      ans = 2147483647;
      above = 0; bottom = 0;
      for (int i = 0; i < n; ++i){
        if (i == (n - 1)) break;
        above += a[i];
        bottom = whole - above;
        ans = min(abs(above - bottom), ans);
      }
      printf("%d\n", (int)ans);
    }
    return 0;
}
