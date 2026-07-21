#include <stdio.h>
#include <stdlib.h>

#define rep(i, n) for (int i = 0; i < n; i = i + 1)
#define array(N, t) (t*)calloc(N, sizeof(t))
#define ll long long
#define INF ((1LL << 62) - (1LL << 31))
#define max(p, q)((p) > (q) ? (p) : (q))
#define min(p, q)((p) < (q) ? (p) : (q))
#define swap(type, a, b) { type temp = a; a = b; b = temp; }

int N;
int ans = 0;
int cnt = 0;
int D[110][2];

void solve1() {
  rep(i, N) {
    // ゾロ目が連続して3回続いたらゾロ目三回連続フラグを立てる
    if (cnt == 3) {
      ans = 1;
    }
    if (D[i][0] == D[i][1]) {
      // ゾロ目のケース
      if (cnt > 0) {
        // 前回ゾロ目だったら更に1足す
        cnt += 1;
      } else {
        // 前回ゾロ目じゃなかったら1にする
        cnt = 1;
      }
    } else {
      // ゾロ目じゃないケースは0にする
      cnt = 0;
    }
  }
}

void solve2() {
  int renzoku_cnt = 0;
  rep(i, N) {
    int d1 = D[i][0];
    int d2 = D[i][1];

    if (d1 == d2) {
      renzoku_cnt += 1;
    } else {
      renzoku_cnt = 0;
    }

    if (renzoku_cnt == 3) {
      ans = 1;
    }
  }
}

int main() {
  scanf("%d", &N);

  rep(i, N) {
    scanf("%d%d", &D[i][0], &D[i][1]);
  }
  solve2();
  if (ans == 1) {
    puts("Yes");
  } else {
    puts("No");
  }
  return 0;
}
