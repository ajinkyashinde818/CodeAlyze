#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1000000007;
constexpr ll INF = 1ll<<60;

int main(int argc, char **argv)
{
	ll N; cin >> N;
	vector<ll> A(N);
	for (ll i = 0; i < N; ++i) cin >> A[i];

	vector<ll> sum_l(N+1, 0), sum_r(N+1, 0);

	for (ll i = 0; i < N; ++i) sum_l[i+1] = sum_l[i] + A[i];
	ll X = accumulate(A.begin(), A.end(), 0ll);

	ll res{INF};
	for (ll i = 1; i < N; ++i)
	{
		res = min(res, abs(2*sum_l[i] - X));
	}
	std::cout << res << std::endl;
}
