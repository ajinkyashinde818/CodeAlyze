#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<utility>
#include<tuple>
#include<algorithm>
#include<cmath>
#include<climits>
using namespace std;

#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;
const int mod=1e9+7;

int main(){
	int n;
  cin >> n;
  vector<ll> a(n);
	ll sum=0, abmin=INT_MAX;
	int cnt=0;
  rep(i,n){
  	cin >> a[i];
  	if(a[i]<0)
  	  cnt++;
  	sum+=abs(a[i]);
  	abmin=min(abmin,abs(a[i]));
  }
  if(cnt%2)
  	cout << sum-2*abmin << endl;
  else
  	cout << sum << endl;
  return 0;
}
