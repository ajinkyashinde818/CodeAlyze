#include<iostream>
#include<algorithm>

using namespace std;
typedef long long ll;

ll N, a[200000];
ll sum[200001] = {};//sum[i] i-1番目までの累積和

ll my_abs(ll a) {
	if (a < 0)return a * -1;
	return a;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> a[i];
		sum[i + 1] = sum[i] + a[i];
	}
	//累積和
	ll res = 1000000000000;
	if (N == 2) {
		cout << my_abs(a[0] - a[1]) << endl;
		return 0;
	}
	for (int i = 1; i < N - 1; i++) {
		res = min(res, my_abs((sum[i] - sum[1]) - (sum[N - 1] - sum[i]) + a[0] - a[N - 1]));
	}
	cout << res << endl;
	return 0;
}
