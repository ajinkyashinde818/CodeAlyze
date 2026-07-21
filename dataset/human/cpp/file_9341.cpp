#include <cstdio>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <stack>
#include <vector>
#include <algorithm>
#include <set>
#include <deque>
#include <utility>
#include <chrono>
#include <sstream>
#include <iomanip>
#define INF 1 << 30
#define MOD 1000000007;
#define pi 3.14159265358979
#define rep(i, n) for (int (i) = 0; (i) < (int)(n); (i)++)
#define rer(i, l, r) for (int (i) = (int)(l); (i) <= (int)(r); (i)++)
#define reu(i, l, r) for (int (i) = (int)(l); (i) < (int)(r); (i)++)
#define D(x) cout << x << endl
#define d(x) cout << x
#define all(x) (x).begin(), (x).end()
#define pub(x) push_back(x)
#define pob() pop_back()
#define puf(x) push_front(x)
#define pof() pop_front()
#define mp(x, y) make_pair((x), (y))
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<long long> vll;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef pair<long, long> pll;
template<typename T, typename U> inline void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if (x < y) x = y; }
static const int dx[] = {0, 0, 1, -1};
static const int dy[] = {-1, 1, 0, 0};

string s[55];
string t[55];
int n, m;

bool check(int x, int y) {
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < m; j++) {
      if (s[x + i][y + j] != t[i][j]) {
        return false;
      }
    }
  }
  return true;
}

int main() { 
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> t[i];
  }

  bool flag = false;

  for (int i = 0; i < n - m + 1; i++) {
    for (int j = 0; j < n - m + 1; j++) {
      if (check(i, j)) {
        flag = true;
      }
    }
  }

  if (flag) {
    D("Yes");
  } else {
    D("No");
  }
  return 0;
}
