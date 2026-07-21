#include <bits/stdc++.h>
using namespace std;

int n;
int a[200005], b[200005];
int cnta[200005], cntb[200005];
vector <int> invalid, unused;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	for (int i = 0; i < n; i++) scanf("%d", &b[i]);
	for (int i = 0; i < n; i++) cnta[a[i]]++;
	for (int i = 0; i < n; i++) cntb[b[i]]++;
	for (int i = 1; i <= n; i++) {
		if (cnta[i] + cntb[i] > n) {
			printf("No\n");
			return 0;
		}
	}
	reverse(b, b + n);
	int same = -1;
	for (int i = 0; i < n; i++) {
		if (a[i] == b[i]) {
			invalid.push_back(i);
			same = a[i];
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (cnt >= invalid.size()) break;
		if (a[i] != b[i] && a[i] != same && b[i] != same) {
			cnt++;
			unused.push_back(i);
		}
	}
	for (int i = 0; i < invalid.size(); i++) {
		swap(b[invalid[i]], b[unused[i]]);
	}
	printf("Yes\n");
	for (int i = 0; i < n; i++) printf("%d ", b[i]);
	printf("\n");
	return 0;
}
