#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll P = 1e9+7;
const ll N = 1e6+7;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll t=1;
	// cin>>t;

	while(t--){
		ll n;
		cin>>n;
		vector<ll> a(n),b(n);
		for (ll i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (ll i = 0; i < n; i++) {
			cin >> b[i];
		}
		
		reverse(b.begin(),b.end());
		
		ll lpt = 0, rpt = n - 1;
		
		for (ll i = 0; i < n; i++) {
			if (a[i] == b[i]) {
				if (b[lpt] != b[i] && a[lpt] != b[i]) {
					swap(b[i], b[lpt]);
					++lpt;
				} else if (b[rpt] != b[i] && a[rpt] != b[i]) {
					swap(b[i], b[rpt]);
					--rpt;
				} else {
					cout << "No\n";
					return 0;
				}
			}
		}
		
		for (ll i = 0; i < n; i++) {
			if (a[i] == b[i]) {
				cout << "No\n";
				return 0;
			}
		}
		
		cout << "Yes\n";
		for (ll i = 0; i < n; i++) {
			cout << b[i] << " ";
		}
		cout << '\n';
		
	}

	return 0;
}
