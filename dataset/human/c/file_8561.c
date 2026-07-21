#include <stdio.h>

int main(void) {

  long n;
  scanf("%ld", &n);
  long a[n];
  for (long i = 0; i < n; i++) {
    scanf("%ld", &a[i]);
  }
  long plus = 0, minus = 0, sum = 0;
  long abs, min = -1, min_i;
  for (long i = 0; i < n; i++) {
    if (a[i] >= 0) {
      plus++;
      abs = a[i];
    } else {
      minus++;
      abs = -a[i];
    }
    sum += abs;
    if (min == -1 || abs < min) {
      min = abs;
      min_i = i;
    }
  }
  if (plus == 0 || minus == 0) {
    sum -= min*2;
  }
  printf("%ld\n", sum);
  if (plus == 0) {
    for (long i = 0; i < n; i++) {
      if (i == min_i) {
        continue;
      }
      printf("%ld %ld\n", a[min_i], a[i]);
      a[min_i] -= a[i];
    }
  } else if (minus == 0) {
    long other;
    for (long i = 0; i < n; i++) {
      if (i != min_i) {
        other = i;
        break;
      }
    }
    for (long i = 0; i < n; i++) {
      if (i != min_i && i != other) {
        printf("%ld %ld\n", a[min_i], a[i]);
        a[min_i] -= a[i];
      }
    }
    printf("%ld %ld\n", a[other], a[min_i]);
  } else {
    long p_1,m_1;
    for (long i = 0; i < n; i++) {
      if (a[i] >= 0) {
        p_1 = i;
        break;
      }
    }
    for (long i = 0; i < n; i++) {
      if (a[i] < 0) {
        m_1 = i;
        break;
      }
    }
    for (long i = 0; i < n; i++) {
      if (i != p_1 && i != m_1) {
        if (a[i] >= 0) {
          printf("%ld %ld\n", a[m_1], a[i]);
          a[m_1] -= a[i];
        } else {
          printf("%ld %ld\n", a[p_1], a[i]);
          a[p_1] -= a[i];
        }
      }
    }
    printf("%ld %ld\n", a[p_1], a[m_1]);
  }

  return 0;
}
