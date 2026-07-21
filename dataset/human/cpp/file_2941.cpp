#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<set>
#include<map>
#include<queue>
#include<cstring>
#include<sstream>
using namespace std;

typedef long long ll;
  int A[100010];
int main() {
  int N; cin >> N;
  int cnt = 0;
  int minA = 1e9;
  for ( int i = 0; i < N; i++ ) {
    cin >> A[i];
    if ( A[i] < 0 ) cnt++;
    minA = min(minA,abs(A[i]));
  }

  ll ans = 0;
  if ( cnt % 2 == 0 ) {
    for ( int i = 0; i < N; i++ ) ans += abs(A[i]);
  } else {
    bool f = true;
    for ( int i = 0; i < N; i++ ) {
      if (f && abs(A[i]) == minA) {
	ans -= abs(A[i]);
	f = false;
      } else {
	ans += abs(A[i]);
      }
    }
  }
  cout << ans << endl;
  return 0;
}
