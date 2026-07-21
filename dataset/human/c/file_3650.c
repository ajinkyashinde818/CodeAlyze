#include <stdio.h>
#include <math.h>
int main() {
  double a, b;
  double tmp, r;
  double ans;
  scanf ("%lf %lf", &a, &b);

  ans = a * b;

  if (a < b) {
    tmp = a;
    a = b;
    b = tmp;
  }

  r = fmod (a, b);
  while (r != 0) {
    a = b;
    b = r;
    r = fmod (a, b);
  }

  ans = ans / b;
  printf ("%.0lf\n", ans);

  return 0;
}
