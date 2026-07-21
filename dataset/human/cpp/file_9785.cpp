#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

int main()
{
	int N;
	string S;
	cin >> N >> S;
	map<char, int> dic;
	for (int i = 0; i < N; i++) {
		dic[S[i]] += 1;
	}
	ll res = 1;
	for (auto p : dic) {
		res = res * (p.second + 1) % mod;
	}
	cout << (res + mod - 1) % mod << endl;
	return 0;
}
