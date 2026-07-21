#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 100000 + 7;

vector<int> A[MAX_N];

int main() {
  int N;
  scanf("%d", &N);

  int bb4ac = 1 + 8 * N;
  int sqrt_bb4ac = (sqrt(bb4ac) + 0.5);
  if (sqrt_bb4ac * sqrt_bb4ac != bb4ac) {
    puts("No");
    return 0;
  }

  if ((1 + sqrt_bb4ac) & 1) {
    puts("No");
    return 0;
  }

  int K = (1 + sqrt_bb4ac) / 2 - 1;
  for (int i = 1, sum = 0; i <= K; i++) {
    for (int j = 0; j < i; j++) {
      sum++;
      A[i].push_back(sum);
    }
  }

  puts("Yes");
  printf("%d\n", K + 1);

  printf("%d ", K);
  for (int i = 1; i <= K; i++)
    printf("%d%c", A[i].back(), " \n"[i == K]);

  for (int i = 1; i <= K; i++) {
    printf("%d ", K);
    int cnt = 0;
    for (int j = 0; j < (int)A[i].size(); j++)
      printf("%d%c", A[i][j], " \n"[++cnt == K]);
    for (int j = i + 1; j <= K; j++)
      printf("%d%c", A[j][(int)A[i].size() - 1], " \n"[++cnt == K]);
  }

  return 0;
}
