#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline unsigned long long xor128() {
	static unsigned long long x = 123456789;
	static unsigned long long y = 362436069;
	static unsigned long long z = 521288629;
	static unsigned long long w = 88675123;
	unsigned long long t = x ^ (x << 11);
	x = y;
	y = z;
	z = w;
	return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
}

int main() {
	ll N;
	cin >> N;
	vector<ll> a(N), b(N);
	for(ll i=0; i<N; i++) cin >> a[i];
	for(ll i=0; i<N; i++) cin >> b[i];

	map<ll,ll> am,bm;
	for(ll i=0; i<N; i++){
		am[a[i]]++;
		bm[b[i]]++;
	}
	for(auto&& pr:am){
		if(pr.second + bm[pr.first]> N){
			cout << "No\n";
			return 0;
		}
	}
	/*
	std::random_device seed_gen;
	std::mt19937 engine(seed_gen());
	shuffle(b.begin(), b.end(), engine);
	*/
	//shuffleの代わりにreverseもよさそう
	reverse(b.begin(), b.end());
	
	ll i=0,j=N-1;
	while(i<j){
		while(i<N && a[i]!=b[i])i++;
		while(j>=0 && a[i]==b[i])j--;
		if(i<j){
			swap(a[i],a[j]);
			swap(b[i],b[j]);
		}
	}

	while(i<N){
		ll r=xor128()%(N-1);
		if(r>=i)r++;
		swap(b[i],b[r]);
		if(r<i){
			if(a[i]==b[i] && a[r]==b[r]){
				i--;
				swap(a[i],a[r]);
				swap(b[i],b[r]);
			}else if(a[i]!=b[i] && a[r]!=b[r]){
				i++;
			}else if(a[r]!=b[r]){
				;
			}else if(a[i]!=b[i]){
				swap(a[i],a[r]);
				swap(b[i],b[r]);
			}
		}else{
			if(a[i]==b[i] && a[r]==b[r]){
				;
			}else if(a[i]!=b[i] && a[r]!=b[r]){
				i++;
				swap(a[i],a[r]);
				swap(b[i],b[r]);
			}else if(a[r]!=b[r]){
				swap(a[i],a[r]);
				swap(b[i],b[r]);
			}else if(a[i]!=b[i]){
				;
			}
		}
	}

	vector<pair<ll,ll>> ans(N);
	for(ll i=0; i<N; i++){
		ans[i]={a[i],b[i]};
	}

	sort(ans.begin(), ans.end());
	cout << "Yes\n";
	for(ll i=0; i<N; i++) cout << ans[i].second << " \n"[i==N-1];

	return 0;
}
