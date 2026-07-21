/* https://codeforces.com/contest/1360/problem/H */
#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using vs = vector<string>;
using vi = vector<int>;
using vl = vector<ll>;
using vb = vector<bool>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using vpi = vector<pair<int, int>>;
using vpl = vector<pair<ll, ll>>;
using ld = double;

#define f first
#define s second 
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define pb push_back
#define	lb lower_bound
#define	ub upper_bound
#define	sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define ins insert

const int MAX = INT_MAX;

int main() {
	
	int n;
	cin>>n;
	vector<int> a(n);
	vector<int> b(n);
	map<int, int>cnt;
	for (int i = 0;i < n;++i) {
		cin>>a[i];
		cnt[a[i]] += 1;
	}

	for (int i = 0;i < n;++i) {
		cin>>b[i];
		cnt[b[i]] += 1;
	}

	sort(all(b), greater<int>());

	int cntr = 0;
	int l = -1;
	int match = -1;
	vector<ll> mismatches;
	for (int i = 0;i < n;++i) {
		if (a[i] == b[i]) {
			match = a[i];
			if (cnt[a[i]] > n) {
				cout<<"No"<<endl;
				return 0;
			}

			l = i;
			break;
		}
	}


	if (l != -1) {
		for (int i = 0;i < n;++i) {
			if (a[i] != match && b[i] != match) {
				mismatches.pb(i);
			}
		}

		for (int i = l, k = 0;i < n && k < mismatches.size();++i, ++k) {
			if (a[i] == b[i])
				swap(b[i], b[mismatches[k]]);
			else break;
		}
	}

	cout<<"Yes"<<endl;
	for (int i = 0;i < n;++i) cout<<b[i]<<" ";

	return 0;
}
