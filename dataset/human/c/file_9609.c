#include <stdio.h>

int n, m;
char N[100][9];
long long int M[100];
char B[1000][9];

bool input() {
  int i;

  scanf("%d %d", &n, &m);
  if(!n) return false;

  for (i = 0; i < n; i++) {
    scanf(" %s %d", N[i], &M[i]);
  }
  for (i = 0; i < m; i++) {
    scanf(" %s", B[i]);
  }

  return true;
}


int main() {
  int i, j, k;
  long long int sum;

  while (input()) {
    sum = 0;
    for (i = 0; i < m; i++) {
      for (j = 0; j < n; j++) {
        for (k = 0; k < 8; k++) {
          if (N[j][k] == '*') continue;
          if (N[j][k] != B[i][k]) break;
        }
        if (k == 8) sum += M[j];
      }
    }

    printf("%d\n", sum);

  }

}
