#include <bits/stdc++.h>

using namespace std;

char c[111111];

int main()
{
	long long n, l;
	cin >> n >> l;
	vector<string> v;
	for (int i = 0; i < n; i++) {
		scanf("%s", c);
		v.push_back(c);
	}
	sort(v.begin(), v.end());
	v.push_back("a");
	fill(c, c + v.front().length(), 0);
	auto x = 0ll;
	for (auto it = v.begin() + 1;; ++it) {
		int r = 0;
		while (it[0][r] == it[-1][r])
			r++;
		if (*it == "a") r = -1;
		for (int i = r + 1; i < it[-1].length(); i++) {
			if (c[i]) continue;
			auto y = l - i;
			for (n = 1; y % 2 == 0; n *= 2)
				y /= 2;
			x ^= n;
		}
		if (r < 0) break;
		c[r] = 1;
		fill(c + r + 1, c + it->length(), 0);
	}
	cout << (x ? "Alice" : "Bob") << endl;
	return 0;
}
