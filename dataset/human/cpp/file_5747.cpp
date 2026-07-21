#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
int N; long long L; string s[100009];
long long solve(int d, int l, int r) {
	if (s[l].size() == d) l++;
	int pl = l;
	while (l != r && s[l][d] == '0') l++;
	int f1 = (pl != l ? 1 : 0);
	int f2 = (l != r ? 1 : 0);
	if (f1 + f2 == 0) return 0;
	if (f1 + f2 == 1) {
		long long rem = L - d;
		long long cr = 1;
		while (rem % 2 == 0) rem /= 2, cr *= 2;
		long long res = -1;
		if (f1 == 1) res = solve(d + 1, pl, l);
		if (f2 == 1) res = solve(d + 1, l, r);
		return cr ^ res;
	}
	long long res1 = solve(d + 1, pl, l);
	long long res2 = solve(d + 1, l, r);
	return res1 ^ res2;
}
int main() {
	cin >> N >> L;
	for (int i = 0; i < N; i++) cin >> s[i];
	sort(s, s + N);
	long long ret = solve(0, 0, N);
	cout << (ret != 0 ? "Alice" : "Bob") << endl;
	return 0;
}
