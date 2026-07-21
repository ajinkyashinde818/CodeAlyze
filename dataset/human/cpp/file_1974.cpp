#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	int N;
	cin >> N;
	vector<ll> A(N);
	int n_cnt(0);
	ll ans(0);
	for(int i(0);i<N;++i){
		cin >> A[i];
		if(A[i] < 0){
			n_cnt++;
			A[i] = -A[i];
		}
		ans += A[i];
	}
	sort(A.begin(),A.end());
	if(n_cnt%2 == 1) ans = ans - 2 * A[0];
	cout << ans << endl;
	return 0;
}
