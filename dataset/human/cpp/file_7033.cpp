#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	vector<int> al(n + 1, -1), ar(n + 1, -1), bl(n + 1, -1), br(n + 1, -1);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
	}
	for(auto i = 0; i < n; ++ i){
		cin >> b[i];
	}
	int tot = 0;
	vector<int> cnt(n + 1);
	for(auto x = 1, ai = 0, bi = 0; x <= n; ++ x){
		while(ai < n && a[ai] < x){
			++ ai;
		}
		if(ai < n && a[ai] == x){
			int aj = ai;
			while(aj < n && a[aj] == x){
				++ aj;
			}
			tie(al[x], ar[x]) = pair{ai, aj};
			ai = aj;
		}
		while(bi < n && b[bi] < x){
			++ bi;
		}
		if(bi < n && b[bi] == x){
			int bj = bi;
			while(bj < n && b[bj] == x){
				++ bj;
			}
			tie(bl[x], br[x]) = pair{bi, bj};
			bi = bj;
		}
		if(~al[x] && ~bl[x]){
			++ tot;
			if(ar[x] - al[x] + br[x] - bl[x] > n){
				cout << "No\n";
				return 0;
			}
			if(bl[x] <= al[x]){
				if(br[x] <= al[x]){
					++ cnt[0];
					-- cnt[al[x] - br[x] + 1];
					++ cnt[ar[x] - bl[x]];
					-- cnt[n];
				}
				else{
					++ cnt[ar[x] - bl[x]];
					-- cnt[al[x] + n - br[x] + 1];
				}
			}
			else{
				++ cnt[max(0, ar[x] - bl[x])];
				-- cnt[al[x] + n - br[x] + 1];
			}
		}
	}
	for(auto t = 0; t < n; ++ t){
		if(cnt[t] == tot){
			cout << "Yes\n";
			rotate(b.begin(), b.begin() + n - t, b.end());
			for(auto x: b){
				cout << x << " ";
			}
			cout << "\n";
			return 0;
		}
		cnt[t + 1] += cnt[t];
	}
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////
