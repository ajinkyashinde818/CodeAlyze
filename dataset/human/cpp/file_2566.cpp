#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long int ll;

int N;

int main(){
	cin >> N;
	ll res = 0LL;
	int cnt = 0;
	ll min_abs = 1LL << 60;
	for(int i = 0; i < N; i++){
		ll A;
		cin >> A;
		res += abs(A);
		min_abs = min(min_abs, abs(A));
		if(A < 0LL) cnt++;
	}
	if(cnt % 2 == 0) cout << res << endl;
	else cout << res - 2 * min_abs << endl;
	return 0;
}
