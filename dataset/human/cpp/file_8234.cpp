#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N;
	cin >> N;
	vector<ll>A(N);
	ll ans = 1e25;
	ll sum = 0, tmp = 0;
	for (int i = 0; i < N; i++){
		cin >> A[i];
		sum += A[i];
	}

	for (int i = 0; i < N; i++){
		tmp += A[i];
		if (i + 1 < N) {
			ans = min(ans, abs(sum - 2 * tmp));
		}
	}

	cout << ans << endl;
	return 0;
}
