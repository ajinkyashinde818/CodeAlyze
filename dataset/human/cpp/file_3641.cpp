#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <numeric>
#include <cmath>

using namespace std;

typedef long long int ll;
typedef pair<int,int> P;

#define all(x) x.begin(),x.end()

const ll mod = 1e9+7;
const ll INF = 1e9;
const ll MAXN = 1e9;

int main()
{
	int n;
	cin>>n;
	vector<ll> a(n);
	for(int i = 0; i < n; i++){
		cin>>a[i];
	}
	int cnt = 0;
	int pos = 0;
	for(int i = 0; i < n; i++){
		if(a[i]<=0) cnt++;
		if(abs(a[pos]) > abs(a[i])) pos = i;
	}

	ll ans = 0;
	if (cnt % 2 == 0){
		for(int i = 0; i < n; i++){
			ans += abs(a[i]);
		}
	}else{
		for(int i = 0; i < n; i++){
			if(i != pos) ans += abs(a[i]);
			else ans -= abs(a[i]);
		}
	}

	cout << ans << endl;

	return 0;
}
