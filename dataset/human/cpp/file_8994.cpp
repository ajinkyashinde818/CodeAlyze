#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M; cin >> N >> M;
  vector<string> A(N), B(M);
  for (ll i = 0; i < N; i++) cin >> A.at(i);
  for (ll i = 0; i < M; i++) cin >> B.at(i);
  for (ll i = 0; i <= N - M; i++) {
    for (ll j = 0; j <= N - M; j++) {
      bool trial = true;
      for (ll k = 0; k < M; k++) {
	if (B.at(k) != A.at(i + k).substr(j, M)) {
	  trial = false;
	  break;
	}
      }
      if (trial) {
	cout << "Yes\n";
	return 0;
      }
    }
  }
  cout << "No\n";
  return 0;
}
