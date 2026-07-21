#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>

// Acknowledgement: Special thanks to kyomukyomupurin, who developed this
// template.
template <class T, class U>
std::ostream& operator<<(std::ostream& os, const std::pair<T, U>& p) {
  return os << '(' << p.first << ", " << p.second << ')';
}

template <class T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
  int n = 0;
  for (auto e : vec) os << (n++ ? ", " : "{") << e;
  return os << (n ? "}" : "{}");
}

template <class T>
std::ostream& operator<<(std::ostream& os, const std::set<T>& st) {
  int n = 0;
  for (auto e : st) os << (n++ ? ", " : "{") << e;
  return os << (n ? "}" : "{}");
}

template <class T, class U>
std::ostream& operator<<(std::ostream& os, const std::map<T, U>& mp) {
  int n = 0;
  for (auto e : mp) os << (n++ ? ", " : "{") << e;
  return os << (n ? "}" : "{}");
}

template <class T>
std::istream& operator>>(std::istream& is, std::vector<T>& vec) {
  for (T& e : vec) is >> e;
  return is;
}

#ifdef LOCAL
#define debug(...) \
  std::cerr << "[" << #__VA_ARGS__ << "]: ", debug_out(__VA_ARGS__)
#else
#define debug(...)
#endif

void debug_out() { std::cerr << '\n'; }

template <class Head, class... Tail>
void debug_out(Head&& head, Tail&&... tail) {
  std::cerr << head;
  if (sizeof...(Tail) != 0) std::cerr << ", ";
  debug_out(std::forward<Tail>(tail)...);
}
using namespace std;
using int64 = long long;

bool isMatch(int x, int y, vector<vector<char>> a, vector<vector<char>> b) {
  int size = b.size();
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (a[i + x][j + y] != b[i][j]) return false;
    }
  }
  return true;
}

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<char>> a(N, vector<char>(N));
  vector<vector<char>> b(M, vector<char>(M));
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < M; i++) {
    cin >> b[i];
  }
  if (N == 1) {
    if (a[0][0] == b[0][0]) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
    return 0;
  }
  char hidariue = b[0][0];
  for (int i = 0; i <= N - M; i++) {
    for (int j = 0; j <= N - M; j++) {
      debug(a[i][j]);
      if (a[i][j] != hidariue) continue;
      if (isMatch(i, j, a, b)) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
  return 0;
}
