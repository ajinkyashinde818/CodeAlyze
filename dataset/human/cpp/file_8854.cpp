#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = 1e9;
const ll LLINF = 1e18;
const ll MOD = (ll)1e9 + 7;

int main()
{
  int N, M; scanf("%d %d", &N, &M);
  vector<string> A(N), B(M);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }
  for (int i = 0; i < M; ++i) {
    cin >> B[i];
  }

  bool ok = false;
  for (int i = 0; i + M <= N; ++i) {
    string::size_type pos = -1;
    while ((pos = A[i].find(B[0], pos + 1)) != string::npos) {
      ok = true;
      for (int j = 0; j < M; ++j) {
        if (A[i + j].find(B[j], pos) != pos) {
          ok = false;
          break;
        }
      }
      if (ok) { break; }
    }
    if (ok) { break; }
  }
  printf("%s\n", ok ? "Yes" : "No");
  return 0;
}
