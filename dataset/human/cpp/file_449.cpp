#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1000000007;
constexpr ll INF = 1ll<<60;

int main(int argc, char **argv)
{
	ll R, G, B, N;
	cin >> R >> G >> B >> N;

	ll res{0};
	for (ll r = 0; r <= N/R; ++r)
	{
		for (ll g = 0; g <= N/G; ++g)
		{
			ll b = N - r * R  - g * G;
			if (b < 0) continue;
			if (b % B == 0)
			{
				++res;
			}
				
		}
	}
	std::cout << res << std::endl;
}
