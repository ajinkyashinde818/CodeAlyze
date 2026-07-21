#include <iostream> // cout, endl, cin
#include <cmath> //sqrt pow
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
 
#define rep(i,n) for(int i = 0; i < n; i++)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define mod 1000000007
using ll = long long;
using namespace std;
int gcd(int a, int b){ //最大公約数
  if(!a) return b;
  if(!b) return a;
  if(a % b == 0) return b;
  return gcd(b, a % b);
}
int main(){
  int n;
  cin >> n;
  int mn = 1000000000;
  ll tot = 0;
  int cnt = 0;
  rep(i, n){
    int a;
    cin >> a;
    if(a < 0){
      cnt++;
      a = -a;
    }
    tot += a;
    mn = mn > a ? a : mn;
  }
  if(cnt & 1) cout << tot - mn * 2 << endl;
  else cout << tot << endl;
}
