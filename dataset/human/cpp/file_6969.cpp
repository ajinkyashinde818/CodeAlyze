#include <bits/stdc++.h>
using namespace std;

int n;
pair <pair <int, int>, int> p[200010];
pair <int, int> ans[200010];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		p[i].second = i;
	for (int i = 0; i < n; ++i) {
		int a; scanf("%d", &a);
		++p[a].first.first, ++p[a].first.second;
	}
	for (int i = 0; i < n; ++i) {
		int b; scanf("%d", &b);
		if(++p[b].first.first > n) {
			puts("No");
			return 0;
		}
	}
	
	sort(p + 1, p + n + 1, greater <pair <pair <int, int>, int> > ());
	puts("Yes");
	for (int i = 1, j = 0, s1 = 0, s2 = 0; i <= n; ++i) {
		int na = p[i].first.second, nb = p[i].first.first - na;
		if (j + na + nb <= n) {
			s1 += na, s2 += nb;
			while (na--)
				ans[j++].first = p[i].second;
			while (nb--)
				ans[j++].second = p[i].second;
		}
		else {
			p[i].first.first -= n - j;
			if (s1 >= nb) {
				while (na > 0 && j < n)
					ans[j++].first = p[i].second, --na;
				while (j < n)
					ans[j++].second = p[i].second, --nb;
				p[i].first.second = na;
			}
			else if (s2 >= na) {
				while (nb > 0 && j < n)
					ans[j++].second = p[i].second, --nb;
				while (j < n)
					ans[j++].first = p[i].second, --na;
				p[i].first.second = na;
			}
			for (int j1 = 0, j2 = 0; i <= n; ++i) {
				int na = p[i].first.second, nb = p[i].first.first - p[i].first.second;
				while (na--) {
					while (ans[j1].first)
						++j1;
					ans[j1].first = p[i].second;
				}
				while (nb--) {
					while (ans[j2].second)
						++j2;
					ans[j2].second = p[i].second;
				}
			}
			break;
		}
	}
	sort(ans, ans + n);
	for (int i = 0; i < n; ++i)
		printf("%d%c", ans[i].second, i == n - 1 ? '\n' : ' ');
	return 0;
}
