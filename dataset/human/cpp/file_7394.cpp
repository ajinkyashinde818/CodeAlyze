#include <cstdio>
#include <iostream>
#include <iomanip>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <cmath>

#define ll long long int
#define pb push_back
#define mk make_pair
#define pq priority_queue

using namespace std;
typedef pair<int, int> P;
typedef pair<ll, int> Pl;
typedef pair<ll, ll> Pll;
const int inf = 1e9;
const ll linf = 1LL << 50;

int main(int argc, char const* argv[])
{
  int n;
  cin >> n;
  vector<ll> sum;
  for(int i = 0; i < n; i++){
    int x;
    cin >> x;
    if(i == 0)sum.pb((ll)x);
    else sum.pb((ll)x + sum[i - 1]);
  }
  ll res = linf;
  for(int i = 0; i < n - 1; i++){
    res = min(res, abs(sum[n-1] - 2 * sum[i]));
  }
  cout << res << endl;
	return 0;
}
