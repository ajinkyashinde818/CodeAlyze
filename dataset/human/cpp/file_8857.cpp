#include <algorithm>
#include <bitset>
#include <cassert>
#include <deque>
#include <fstream>
#include <iostream>
#include <map>
#include <math.h>
#include <memory>
#include <queue>
#include <sstream>
#include <stdio.h>
#include <string>
#include <vector>

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define POW(n) ((n) * (n))
#define ALL(a) (a).begin(), (a).end()
#define dump(v) (cerr << #v << ": " << v << endl)
#define cerr                                                                   \
  if (true)                                                                    \
  cerr

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<unsigned long long> vull;

// ll n = to_T<ll>("114514")
template <class T> T to_T(const string &s) {
  istringstream is(s);
  T res;
  is >> res;
  return res;
}
template <class T> string to_s(const T &a) {
  ostringstream os;
  os << a;
  return os.str();
}

void solve(long long N, long long M, vector<string> A, vector<string> B) {
  REP(y, N) REP(x, N) {
    bool flag = true;
    REP(ny, M) REP(nx, M) {
      if (!flag)
        break;

      if (y + ny >= N || x + nx >= N) {
        flag = false;
        continue;
      }
      flag = A[y + ny][x + nx] == B[ny][nx];
    }
    if (flag) {
      cout << "Yes" << endl;
      return;
    }
  }

  cout << "No" << endl;
}

int main() {
  ios::sync_with_stdio(false);
  long long M;
  long long N;
  cin >> N;
  vector<string> A(N - 1 + 1);
  cin >> M;
  vector<string> B(M - 1 + 1);
  for (int i = 0; i <= N - 1; i++) {
    cin >> A[i];
  }
  for (int i = 0; i <= M - 1; i++) {
    cin >> B[i];
  }
  solve(N, M, A, B);
  return 0;
}
