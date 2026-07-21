#include <stdio.h>

int h, w = 5;
int M[15][10];

int main(void) {
  int i, j, k;
  while (1) {
    scanf("%d", &h);

    if (h == 0) {
      return 0;
    }

    for (i = 0; i < h; ++i) {
      for (j = 0; j < w; ++j) {
        scanf("%d", &M[i][j]);
      }
    }

    int counter = 0;
    int flag = 1;
    while (flag) {
      flag = 0;
      for (i = 0; i < h; ++i) {
        for (j = 0; j < w; ++j) {
          if (M[i][j] == 0) continue;
          for (k = j + 1; k < w && M[i][j] == M[i][k]; ++k)
            ;

          if (k - j >= 3) {
            flag = 1;
            counter += M[i][j] * (k - j);
            for (--k; k >= j; --k) {
              M[i][k] = 0;
            }
          }
        }
      }
      // for (i = 0; i < h; ++i) {
      //   for (j = 0; j < w; ++j) {
      //     printf("%d ", M[i][j]);
      //   }
      //   puts("");
      // }
      // puts("---");
      for (j = 0; j < w; ++j) {
        int d = h - 1;
        for (i = h - 1; i >= 0; --i) {
          if (M[i][j] != 0) {
            M[d][j] = M[i][j];
            if (i != d) M[i][j] = 0;
            --d;
          }
        }
      }

      // for (i = 0; i < h; ++i) {
      //   for (j = 0; j < w; ++j) {
      //     printf("%d ", M[i][j]);
      //   }
      //   puts("");
      // }
      // puts("::::::::");
    }

    printf("%d\n", counter);
  }
}
