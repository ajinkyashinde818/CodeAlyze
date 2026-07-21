#include <iostream>
#include <stdio.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <functional>
#include <list>
#include <utility>
#include <map>
#include <vector>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> Pii;
typedef pair<ll, ll> Pll;
typedef pair<int, Pii > P1;

#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,x) for(int i=1;i<=x;i++)
#define rrep(i,x) for(int i=x-1;i>=0;i--)
#define rrep1(i,x) for(int i=x;i>0;i--)
#define sor(v) sort(v.begin(),v.end())
#define rev(s) reverse(s.begin(),s.end())
#define lb(vec,a) lower_bound(vec.begin(),vec.end(),a)
#define ub(vec,a) upper_bound(vec.begin(),vec.end(),a)
#define mp1(a,b,c) P1(a,P(b,c))
#define get_arsize(a) (sizeof(a)/sizeof(a[0]))
const ll mod = 1000000007;
const double eps = 1e-10;
const int MAX = 200000;

int main() {
	int n,r;
	cin >> n >>  r;
  if (n >= 10) {
    cout << r << endl;
  } else {
    cout << r + (10 - n) * 100 << endl;
  }
  return 0;
}
