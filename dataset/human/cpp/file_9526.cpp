#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;

  vector<string> vecN(N);
  vector<string> vecM(M);

  for (int i = 0; i < N; i++) {
    cin >> vecN[i];
  }

  string linM;
  for (int i = 0; i < M; i++) {
    cin >> vecM[i];
    //確認用の一行を作っとく
    linM += vecM[i];
  }

  //確認したい箇所を一行にする。
  // N行の選択
  for (int i = 0; i <= N - M; i++) {
    // N列の選択
    for (int j = 0; j <= N - M; j++) {
      string linN = {};
      // 取得行の範囲
      for (int k = 0; k < M; k++) {
        linN += vecN[i + k].substr(j, M);
      }
      if (linM == linN) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }

  cout << "No" << endl;
}
