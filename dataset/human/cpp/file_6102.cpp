#include <iostream>
#include <ctime>
#include <fstream>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <complex>
#include <utility>
#include <cctype>
#include <list>
#include <bitset>
#include <unordered_set>

using namespace std;

#define FORALL(i,a,b) for(int i=(a);i<=(b);++i)
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORB(i,a,b) for(int i=(a);i>=(b);--i)

typedef long long ll;
typedef long double ld;
typedef complex<ld> vec;

typedef pair<ll,int> plli;
typedef pair<ll,int> pii;
typedef map<int,int> mii;

#define pb push_back
#define mp make_pair

#define MAXN 100005

ll X[MAXN];
ll V[MAXN];
ll right_bal[MAXN];
ll left_bal[MAXN];


int main() {
  int N; ll C;
  cin >> N >> C;
  FOR(i,N) cin >> X[i] >> V[i];

  ll ans = 0;
  priority_queue<pii> right_heap;
  priority_queue<pii> left_heap;

  // go in order
  ll v = 0;
  FOR(i,N) {
    ll x = X[i];
    v += V[i];
    right_bal[i] = v - x;
    ans = max(ans, right_bal[i]);
    right_heap.push(mp(right_bal[i],i));
  }

  // go backwards
  v = 0;
  FORB(i,N-1,0) {
    ll x = (C - X[i])%C;
    v += V[i];
    left_bal[i] = v - x;
    ans = max(ans, left_bal[i]);
    left_heap.push(mp(left_bal[i],i));
  }

  // go back then forward
  v = 0;
  FORB(i,N-1,0) {
    ll x = (C - X[i])%C;
    v += V[i];

    while(!right_heap.empty() && right_heap.top().second >= i) right_heap.pop();
    if (right_heap.empty()) break;
    ans = max(ans, right_heap.top().first + v - 2*x);
  }

  // go forward then back
  v = 0;
  FOR(i,N) {
    ll x = X[i];
    v += V[i];

    while(!left_heap.empty() && left_heap.top().second <= i) left_heap.pop();
    if (left_heap.empty()) break;
    ans = max(ans, left_heap.top().first + v - 2*x);
  }

  cout << ans << endl;
}
