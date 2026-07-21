#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

constexpr int64 P = 1000000007;

struct FiniteField {
 private:
  int64 x;
 public:
  FiniteField(int64 x) : x(x) {
    if (x > P || x < 0) { cerr << "Invalied FiniteField!" << endl; exit(1); }
  }
  FiniteField() : x(0) {}
  int64 Value() const { return x; }
  inline FiniteField operator+(FiniteField o) const {
    FiniteField r(*this); r += o; return r;
  }
  inline FiniteField operator-(FiniteField o) const {
    FiniteField r(*this); r -= o; return r;
  }
  inline FiniteField operator* (FiniteField o) const {
    FiniteField r(*this); r *= o; return r;
  }
  inline FiniteField operator/ (FiniteField o) const {
    FiniteField r(*this); r /= o; return r;
  }
  inline void operator+= (FiniteField o) { x = (x + o.x) % P; }
  inline void operator-= (FiniteField o) { x = (x + P - o.x) % P; }
  inline void operator*= (FiniteField o) { x = (x * o.x) % P; }
  void operator/=(FiniteField o) {
    int64 p = P - 2; while (p) { if (p % 2) { *this *= o; } o *= o; p /= 2; }
  }
};

FiniteField Solve() {
  int raw_n;
  cin >> raw_n;
  string s;
  cin >> s;
  int n = 2 * raw_n;

  FiniteField ans = 1;
  int stack = 0;
  for (char c : s) {
    if ((stack % 2 == 0 && c == 'B') || (stack % 2 == 1 && c == 'W')) {
      // Open
      stack++;
    } else {
      // Close
      if (stack == 0) return 0;
      ans *= stack;
      stack--;
    }
  }

  if (stack > 0) return 0;

  for (int i = 1; i <= raw_n; i++) {
    ans *= i;
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cout << Solve().Value() << endl;
}
