#include <algorithm>
#include <bitset>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <tuple>
#include <vector>

using namespace std;

#define rep(i, n) for (int64_t i = 0; i < (int64_t)(n); i++)
#define irep(i, n) for (int64_t i = 0; i <= (int64_t)(n); i++)
#define rrep(i, n) for (int64_t i = (n)-1; i >= 0; i--)
#define rirep(i, n) for (int64_t i = n; i >= 0; i--)

template <int64_t MOD>
class Modint {
  using Self = Modint<MOD>;

  int64_t m_value;

 public:
  Modint(int64_t value) : m_value((value % MOD + MOD) % MOD) {}
  Self pow(int64_t e) const {
    if (e == 0) {
      return (Self)1;
    } else if (e % 2 == 0) {
      return ((*this) * (*this)).pow(e / 2);
    } else {
      return (*this).pow(e - 1) * (*this);
    }
  }
  Self inv() const { return pow(MOD - 2); }
  Self& operator=(const Self& rh) {
    m_value = rh.m_value;
    return *this;
  }
  Self operator-() const { return Self(-m_value); }
  Self operator+(const Self& other) const {
    return Self(m_value + other.m_value);
  }
  Self operator-(const Self& other) const {
    return Self(m_value - other.m_value);
  }
  Self operator*(const Self& other) const {
    return Self(m_value * other.m_value);
  }
  Self operator/(const Self& other) const { return (*this) * other.inv(); }
  Self& operator+=(const Self& rh) { return (*this) = (*this) + rh; }
  Self& operator-=(const Self& rh) { return (*this) = (*this) - rh; }
  Self& operator*=(const Self& rh) { return (*this) = (*this) * rh; }
  int64_t value() const { return m_value; }
};

int main() {
  int N;
  cin >> N;
  string s;
  cin >> s;

  vector<int> pos(26, 1);
  for (char c : s) {
    pos[c - 'a']++;
  }

  using Mint = Modint<1'000'000'007>;
  Mint result = 1;
  for (int p : pos) {
    result *= p;
  }
  result -= 1;
  cout << result.value() << endl;

  return 0;
}
