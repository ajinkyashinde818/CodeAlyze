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
#include <climits>

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
const double EPS = 1e-10;

int main(int argc, char const* argv[])
{
  int n;
  cin >> n;

  int k;
  for(int i = 1; i < 1000; i++){
    if(2 * n == i * (i + 1)){
      k = i;
      break;
    }else if(2 * n < i *  (i + 1)){
        cout << "No" << endl;
        return 0;
    }
  }
  cout << "Yes" << endl;
  cout << k + 1 << endl;
  vector<vector<int> > vec;
  vec.resize(k + 1);
  int fin = 1;
  for(int i = 0; i < k; i++){
    for(int j = 0; j < k - i; j++){
      vec[i].pb(fin + j);
    }
    for(int j = 0; j < k - i; j++){
      vec[j + i + 1].pb(fin + j);
    }
    fin = fin + k - i;
  }
  for(int i = 0; i < k + 1; i++){
    cout << k << " ";
    for(int j = 0; j < k; j++){
      cout << vec[i][j];
      if(j != k - 1)cout << " ";
    }
    cout << endl;
  }
	return 0;
}
