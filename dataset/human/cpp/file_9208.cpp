#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using ll = long long int;

const ll MOD = 1e9 + 7;

ll pow_fast(ll n, ll k) {
  if (k == 0) {
    return 1LL;
  }
  if (k == 1) {
    return n;
  }

  if (k % 2 == 0) {
    ll tmp = pow_fast(n, k / 2);
    return tmp * tmp % MOD;
  } else {
    ll tmp = pow_fast(n, (k - 1) / 2);
    tmp *= tmp;
    tmp %= MOD;
    return tmp * n % MOD;
  }
}

template <typename T>
class stack {
 private:
  vector<T> _vec;

 public:
  stack(){};

  void push(T n) {
    _vec.push_back(n);
    return;
  }

  void pop() {
    if (this->empty()) {
      return;
    }
    _vec.erase(_vec.end() - 1);
    _vec.shrink_to_fit();
    return;
  }

  size_t size() { return _vec.size(); }

  T top() { return _vec[this->size() - 1]; }
  bool empty() { return _vec.empty(); }
};

int main() {
  ll N, M;
  cin >> N >> M;

  vector<vector<char>> A(N, vector<char>(N));
  vector<vector<char>> B(M, vector<char>(M));

  for (ll i = 0; i < N; i++) {
    string s;
    cin >> s;
    for (ll j = 0; j < N; j++) {
      A[i][j] = s[j];
    }
  }

  for (ll i = 0; i < M; i++) {
    string s;
    cin >> s;
    for (ll j = 0; j < M; j++) {
      B[i][j] = s[j];
    }
  }

  bool ans = false;
  for (ll i = 0; i <= N - M; i++) {
    for (ll j = 0; j <= N - M; j++) {
      bool ok = true;
      for (ll ni = 0; ni < M; ni++) {
        for (ll nj = 0; nj < M; nj++) {
          if (A[ni + i][nj + j] != B[ni][nj]) {
            ok = false;
          }
        }
      }
      ans |= ok;
    }
  }

  cout << (ans ? "Yes" : "No") << endl;
}
