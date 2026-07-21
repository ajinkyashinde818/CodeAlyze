#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>
using namespace std;
typedef long long ll;
ll const INF = 1LL << 60;

int main() {
  ll N, M;
  cin >> N >> M;
  vector<string> A(N), B(M);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  for (int i = 0; i < M; i++) {
    cin >> B[i];
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (N - i >= M && N - j >= M && A[i][j] == B[0][0]) {
        bool succ = true;
        for (int k = 0; k < M; k++) {
          for (int l = 0; l < M; l++) {
            if (A[i + k][j + l] != B[k][l]) {
              succ = false;
              break;
            }
          }
        }
        if (succ) {
          cout << "Yes" << endl;
          return 0;
        }
      }
    }
  }
  cout << "No" << endl;
  return 0;
}
