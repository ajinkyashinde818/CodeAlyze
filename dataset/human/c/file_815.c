#include <stdio.h>
#include <math.h>

int main(void) {

  int d;
  long g;
  scanf("%d %ld", &d, &g);
  long p[d],c[d];
  for (int i = 0; i < d; i++) {
  scanf("%ld %ld", &p[i], &c[i]);
  }
  int bit[d];
  bit[0] = -1;
  for (int i = 1; i < d; i++) {
    bit[i] = 0;
  }
  long score;
  long solve;
  long min = -1;
  for (long i = 0; i < pow(2,d); i++) {
    bit[0]++;
    for (int j = 1; j < d; j++) {
      bit[j] += bit[j-1]/2;
      bit[j-1] %= 2;
    }
    score = 0;
    solve = 0;
    for (int j = 0; j < d; j++) {
      if (bit[j] == 1) {
        score += (j+1)*100*p[j]+c[j];
        solve += p[j];
      }
    }
    if (score >= g) {
      if (min == -1 || solve < min) {
        min = solve;
      }
      continue;
    }
    for (int j = d-1; j >= 0; j--) {
      if (bit[j] == 0) {
        if (score+(j+1)*100*(p[j]-1) < g) {
          score += (j+1)*100*(p[j]-1);
          solve += p[j]-1;
        } else {
          solve += (g-score+(j+1)*100-1)/((j+1)*100);
          score += (j+1)*100*((g-score+(j+1)*100-1)/((j+1)*100));
          break;
        }
      }
    }
    if (score >= g) {
      if (min == -1 || solve < min) {
        min = solve;
        continue;
      }
    }
  }
  printf("%ld\n", min);

  return 0;
}
