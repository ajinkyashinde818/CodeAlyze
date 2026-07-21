#include <bits/stdc++.h>


const int N = 100005;

int nxt[N][2], idx, n, dep[N]; bool end[N];
long long l;
std::string s;

void insert(const std::string &s) {
	int p = 0;
	for (char ch : s) {
		int v = ch & 1;
		if (!nxt[p][v])
			nxt[p][v] = ++idx, dep[idx] = dep[p] + 1;
		p = nxt[p][v];
	}
	end[p] = 1;
}

long long lowbit(long long x) {return x & -x;}
long long calc(int d) {return lowbit(l - d + 1);}

int main() {
	std::ios::sync_with_stdio(0), std::cin.tie(0);
	std::cin >> n >> l;
	for (int i = 0; i < n; ++i)
		std::cin >> s, insert(s);
	long long ans = 0;
	for (int i = 0; i <= idx; ++i)
		if (!end[i] && (!nxt[i][0] ^ !nxt[i][1]))
			ans ^= calc(dep[i] + 1);
	std::cout << (ans ? "Alice" : "Bob") << '\n';
	return 0;
}
