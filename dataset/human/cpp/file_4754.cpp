#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> p_ll;
typedef vector<pair<ll, ll>> vec_p; //vector<pair<ll, ll>> pairs(n) ,pairs.at(i) = make_pair(i*i, i)

const ll MOD = pow(10, 9) + 7;
const ll LLINF = pow(2, 61) - 1;
const int INF = pow(2, 30) - 1;


int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll N,R;
  cin >>N>>R;

  if(N<10){
    cout << R + 100 * (10 - N) << endl;
  }
  else{
    cout << R << endl;
  }
}
