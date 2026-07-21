#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
  int N, R;
  cin >> N >> R;
  if (N >= 10) {
    cout << R << endl;
  } else {
    cout << R + 100 * (10 - N) << endl;
  }
  return 0;
}
