#include <bits/stdc++.h>
using namespace std;

const int MAX_SIZE = 50;
char A[MAX_SIZE][MAX_SIZE];
char B[MAX_SIZE][MAX_SIZE];

int main() {
  int N, M;
  scanf("%d%d", &N, &M);

  for (int y = 0; y < N; y++) {
    for (int x = 0; x < N; x++) {
      cin >> A[y][x];
    }
  }
  for (int y = 0; y < M; y++) {
    for (int x = 0; x < M; x++) {
      cin >> B[y][x];
    }
  }

  bool exist = false;
  for (int dy = 0; dy < N; dy++) {
    for (int dx = 0; dx < N; dx++) {
      // テンプレート画像が収まらない場合、判定を行わない
      if (dy + M - 1 >= N || dx + M - 1 >= N) continue;

      bool match = true;
      for (int y = 0; y < M; y++) {
        for (int x = 0; x < M; x++) {
          if (A[dy + y][dx + x] != B[y][x]) match = false;
        }
      }
      if (match) exist = true;
    }
  }

  printf("%s", exist ? "Yes" : "No");
  return 0;
}
