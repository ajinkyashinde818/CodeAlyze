#include <iostream>
#include <sstream>
#include <stdio.h>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <cassert>
#include <exception>
#include <numeric>
using namespace std;
typedef long long ll;
typedef string str;
typedef pair<ll, ll> Pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<char> vc;
typedef vector<str> vs;
typedef vector<Pll> vp;
typedef vector<bool> vb;
#define rep(i, a, n) for (ll i = (a); i < (n); ++i)
#define rrep(i, a, n) for (ll i = (a); i > (n); --i)
#define erep(i, a, n) for (ll i = (a); i <= (n); ++i)
#define rerep(i, a, n) for (ll i = (a); i >= (n); --i)
#define all(c) (c).begin(), (c).end()
#define pb push_back
#define mp make_pair
#define sz(x) ((int)x.size())
#define vec_max(V) *max_element(all(V))
#define vec_min(V) *min_element(all(V))
#define vec_sum(V) accumulate(all(V), 0LL)
#define print(X) cout << (X) << "\n"
#define _ << " " <<
#define Yes print("Yes")
#define No print("No")
static const int INF = 1e+9+7;

int main(){
  vll box(3);
  ll N;
  cin >> box[0] >> box[1] >> box[2] >> N;

  sort(all(box));
  ll ans = 0;

  erep(i,0,N){
    erep(j,0,N){
      if((N - (box[0]*i + box[1]*j)) < 0) break;
      if((N - (box[0]*i + box[1]*j)) % box[2] == 0){
        ans++;
      }
    }
  }

  print(ans);

  

 return 0;
}
