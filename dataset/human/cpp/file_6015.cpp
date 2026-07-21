#include <bits/stdc++.h>

using namespace std;

pair<long, long> s[111111];
long m1[111111], m2[111111];
int main()
{
	long n, c;
	cin >> n >> c;
	for (int i = 1; i <= n; i++)
		scanf("%ld%ld", &s[i].first, &s[i].second);
	s[n + 1].first = c;
	sort(s + 1, s + n + 1);
	long e = 0, ee = 0, m = 0, mm = 0;
	for (int i = 0; i <= n; i++) {
		m1[i] = m;
		m2[n - i] = mm;
		e += s[i + 1].second - s[i + 1].first + s[i].first;
		ee += s[n - i].second + s[n - i].first * 2 - s[n - i + 1].first * 2;
		m = max(m, e);
		mm = max(mm, ee);
	}
	long M = 0;
	for (int i = 0; i <= n; i++)
		M = max(M, m1[i] + m2[i]);
	e = 0, ee = 0, m = 0, mm = 0;
	fill(m1, m1 + n + 1, 0);
	fill(m2, m2 + n + 1, 0);
	for (int i = 0; i <= n; i++) {
		m1[i] = m;
		m2[n - i] = mm;
		e += s[i + 1].second - s[i + 1].first * 2 + s[i].first * 2;
		ee += s[n - i].second + s[n - i].first - s[n - i + 1].first;
		m = max(m, e);
		mm = max(mm, ee);
	}
	for (int i = 0; i <= n; i++)
		M = max(M, m1[i] + m2[i]);
	cout << M << endl;
	return 0;
}
