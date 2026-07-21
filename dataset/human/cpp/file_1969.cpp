#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <utility>
#include <set>
#include <cctype>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <numeric>

typedef long long ll;
#define INF 1 << 29
#define LLINF 1LL << 60
#define EPS 1e-6
#define ALL(c) (c).begin(), (c).end()
#define CNT(c,x) count(ALL(c),x)
#define dump(x)  cerr << #x << " = " << (x) << endl;
template<typename A, size_t N, typename T>
void FILL(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

using namespace std;

ll v[100010];
ll dp[100010][2];

int main(){
  int N;
  cin >> N;

  ll sum = 0;
  ll mv = LLINF;
  int minus = 0;
  for (int i = 0; i < N; i++){
    ll x;
    cin >> x;
    sum += abs(x);
    if (x < 0LL) minus++;
    mv = min(mv, abs(x));
  }
  if(minus % 2) sum -= (mv * 2LL);
  cout << sum << endl;
  return 0;
}
