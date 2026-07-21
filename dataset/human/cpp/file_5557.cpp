#include <bits/stdc++.h>
using namespace std;

constexpr int64_t INF = 1'010'000'000'000'000'017LL;
constexpr int64_t MOD = 1'000'000'007LL;
constexpr double EPS = 1e-12;
constexpr double PI = 3.14159265358979323846;

#define FOR(i, start, end) for(int64_t i=start; i<end; i++)
#define REP(i, n) FOR(i, 0, n)

// 最大公約数gcd
// 最小公倍数lcm=m*n/gcd
uint64_t gcd(uint64_t m, uint64_t n) {
  uint64_t temp;
  while (m % n != 0){
    temp = n;
    n = m % n;
    m = temp;
  }
  return n;
}

uint64_t lcm(uint64_t m, uint64_t n) {
  return (m*n)/gcd(m,n);
}

signed main() {
  uint64_t n, r;
  cin >> n >> r;
  
  uint64_t k;
  
  if (n<10) {
    cout << r + 100*(10-n) << endl;
  }
  else {
    cout << r << endl;
  }
  return 0;
}
