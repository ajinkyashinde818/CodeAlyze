#include <cstdio>
#include <cmath>
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <map>
#include <cassert>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

#define rep(i,a,b) for(int i = a; i < b; i++)
#define S(x) scanf("%d",&x)
#define S2(x,y) scanf("%d%d",&x,&y)
#define P(x) printf("%d\n",x)
#define all(v) v.begin(),v.end()
#define FF first
#define SS second
#define pb push_back
#define mp make_pair

typedef long long int LL;
typedef pair<int, int > pii;
typedef vector<int > vi;

const int N = 100001;

vector<pair<LL, LL > > A,B;
LL dpA[N], dpB[N];

int main() {
  int n;
  LL C;
  scanf("%d%lld",&n,&C);
  rep(i,0,n) {
    LL x,v;
    scanf("%lld%lld",&x,&v);
    A.pb(mp(x, v));
    B.pb(mp(C - x, v));
  }
  reverse(all(B));
  LL smA = 0;
  LL smB = 0;
  rep(i,0,n) {
    smA += A[i].SS;
    dpA[i] = max(i ? dpA[i - 1] : 0LL, smA - 2 * A[i].FF);

    smB += B[i].SS;
    dpB[i] = max(i ? dpB[i - 1] : 0LL, smB - 2 * B[i].FF);
  }
  LL ans = 0;
  smA = 0; smB = 0;
  rep(i,0,n) {
    smA += A[i].SS;
    ans = max(ans, smA - A[i].FF + ((n - 2 - i >= 0) ? dpB[n - 2 - i] : 0));

    smB += B[i].SS;
    ans = max(ans, smB - B[i].FF + ((n - 2 - i >= 0) ? dpA[n - 2 - i] : 0));
  }
  printf("%lld\n",ans);
  return 0;
}
