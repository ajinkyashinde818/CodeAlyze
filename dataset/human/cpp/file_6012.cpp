#include <iostream>
#include <vector>
#include <bitset>
#include <utility>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;
typedef long long ll;

int main(){
	ll n, c;
	cin >> n >> c;

	vector<pair<ll, int> > v(n);

	for(int i=0; i<n; i++){
		cin >> v[i].first >> v[i].second;
	}

	ll curv=0;
	vector<ll> maxlo(n), maxlr(n);
	ll maxloi=0, maxlri=0;
	for(int i=0; i<n; i++){
		curv+=v[i].second;
		maxloi=max(maxloi, curv-v[i].first);
		maxlri=max(maxlri, curv-2*v[i].first);
		maxlo[i]=maxloi;
		maxlr[i]=maxlri;
	}
	curv=0;
	ll maxroi=0, maxrri=0, res=0;
	res=maxlo[n-1];
	for(int i=n-1; 0<=i; i--){
		curv+=v[i].second;
		maxroi=max(maxroi, curv-(c-v[i].first));
		maxrri=max(maxrri, curv-2*(c-v[i].first));
		if(i!=0) res=max({res,
			              maxroi,
				          maxroi+maxlr[i-1],
		                  maxrri+maxlo[i-1]});
	}
	res=max({res, maxroi, 0ll});

	cout << res << endl;

	return 0;

}
