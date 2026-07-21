#include <iostream> // cin, cout, cerr, clog
#include <algorithm> // minmax, sort, swap
#include <numeric> // iota, gcd, lcm 
#include <cstdio> // printf, scanf
#include <climits> // INT_MIN, LLONG_MIN
#include <cmath> // long, trig, pow
#include <vector> // vectors
#include <string> // string
#include <queue> // queue
#include <stack> // stack
#include <map> // key-value pairs sorted by keys
#include <unordered_map> // hashed by keys
#define _for(i,n) for(int i = 0; i <= n; i++)

typedef long long ll; // at least int64 > 9*10^18
typedef unsigned long long ull; // at least uint64

using namespace std;

int main() {
  int R,G,B,n;
  cin >> R >> G >> B >> n;
  int rmax = n/R;
  int gmax = n/G;
  int bmax = n/B;
  int count = 0;
  _for(r,rmax) _for(g,(n-r*R)/G) if ((n-r*R-g*G)%B==0) count++;
  cout << count << endl;
  return 0;
}
