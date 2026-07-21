#include<iostream>
#include<algorithm>

using namespace std;

typedef long long ll;

int N;
ll C, x[100000], v[100000];
ll best[100000 + 10];

const ll INF = 1145141919810893;

int main() {
	cin >> N >> C;
	for (int i = 0; i < N; i++)cin >> x[i] >> v[i], best[i] = INF;

	ll ans = 0;
	{
		//反時計回りを事前計算して、時計回り方向の区間の終端を全探索
		ll eiyou = 0;
		best[N] = 0;//反時計回り方向で何も食べに行かない
		for (int i = N - 1; i >= 0; i--) {
			eiyou += v[i];
			ll cost = eiyou - C + x[i];
			best[i] = max(best[i + 1], cost);
		}

		eiyou = 0;
		for (int i = 0; i < N; i++) {
			ll tmp = 0;
			eiyou += v[i];
			tmp = eiyou - x[i];
			ans = max(ans, tmp);

			tmp -= x[i];
			tmp += best[i + 1];
			ans = max(ans, tmp);
		}
	}
	
	{

		//時計回りを事前計算して、反時計回り方向の区間の終端を全探索
		ll eiyou = 0;
		best[0] = 0;
		for (int i = 1; i <= N; i++) {
			eiyou += v[i - 1];
			ll cost = eiyou - x[i - 1];
			best[i] = max(best[i - 1], cost);
		}

		eiyou = 0;
		for (int i = N - 1; i >= 0; i--) {
			ll tmp = 0;
			eiyou += v[i];
			tmp = eiyou - (C - x[i]);
			ans = max(ans, tmp);

			tmp -= (C - x[i]);
			tmp += best[i];
			ans = max(ans, tmp);
		}
	}
	
	cout << ans << endl;
	return 0;
}
