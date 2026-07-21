#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1000000007;
constexpr ll INF = 1ll<<60;

int main(int argc, char **argv)
{
	ll N, M; cin >> N >> M;
	vector<string> A(N), B(M);
	for (ll i = 0; i < N; ++i) cin >> A[i];
	for (ll i = 0; i < M; ++i) cin >> B[i];

	bool ok;
	for (ll h = 0; h < N-M+1; ++h)
	{
		for (ll w = 0; w < N-M+1; ++w)
		{
			ok = true;
			for (ll hh = 0; hh < M; ++hh)
			{
				for (ll ww = 0; ww < M; ++ww)
				{
					if (A[h+hh][w+ww] != B[hh][ww])
						ok = false;
				}
			}
			if (ok)
				goto exit;
		}
	}
 exit:
	std::cout << (ok ? "Yes" : "No") << std::endl;
}
