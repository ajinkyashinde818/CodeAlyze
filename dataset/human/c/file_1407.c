#include <stdio.h>

static int N;
static int book[40000];

int offset(void)
{
  int i = 1;
  int j = N-1;
  int cost = 0;

  if (!book[0]) {
    if (book[2*N]) {
      ++cost;
    } else {
      for (; i<N; ++i) {
        if (book[2*i-1] || book[2*i]) {
          break;
        } else if (book[2*(i+N)-1] || book[2*(i+N)]) {
          ++cost;
          break;
        }
      }
    }
  }

  if (!book[2*N-1]) {
    if (book[4*N-1]) {
      ++cost;
    } else {
      for (; i<j; --j) {
        if (book[2*j-1] || book[2*j]) {
          break;
        } else if (book[2*(j+N)-1] || book[2*(j+N)]) {
          ++cost;
          break;
        }
      }
    }
  }

  return cost;
}

int main(void)
{
  int i,j;
  int T;

  scanf("%d", &T);

  for (i=0; i<T; ++i) {
    int cost = 0;

    scanf("%d", &N);
    getchar();
    for (j=0; j<N*4; ++j) {
      switch (getchar()) {
      case 'Y':
        book[j] = 1;
        break;
      case 'N':
        book[j] = 0;
        break;
      }
    }
    getchar();

    cost += offset() + N;
    cost += book[0] + book[2*N];
    for (j=1; j<N; ++j) {
      if (book[2*j-1] || book[2*j]) {
        ++cost;
      }
      if (book[2*(j+N)-1] || book[2*(j+N)]) {
        ++cost;
      }
    }
    cost += book[2*N-1] + book[4*N-1];

    printf("%d\n", cost);
  }

  return 0;
}
