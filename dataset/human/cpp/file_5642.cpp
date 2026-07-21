#include "bits/stdc++.h"
using namespace std;

constexpr long long MOD = 46116646144580591;

int main() {
	long long N, L;
	cin >> N >> L;
	map <long long, bool> mp;
	long long NOW = 0;
	for (int i = 0; i < N; i++) {
		string S;
		cin >> S;
		long long Cur = 0, Pow = 1;
		for (int j = 0; j < S.size(); j++) {
			if (S[j] == '0') Cur += Pow;
			else Cur += Pow * 2;
			Cur %= MOD;
			Pow *= 3, Pow %= MOD;
			if (!mp[Cur]) {
				long long X = L - j;
				NOW ^= (X & -X);
				mp[Cur] = true;
			}
		}
	}
	std::cout << (NOW == 0 ? "Bob" : "Alice") << endl;
}
