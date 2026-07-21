#include <bits/stdc++.h>

using namespace std;

const int N = 200005;

int n;
int a[N], b[N];

int main() {
	scanf("%d", &n);

	for(int i = 0; i < n; i++) scanf("%d", a + i);
	for(int i = 0; i < n; i++) scanf("%d", b + i);
	reverse(b, b + n);

	int l = 0;
	while(l < n and a[l] != b[l]) l++;

	if(l < n) {
		int r = l;
		while(r + 1 < n and a[r + 1] == b[r + 1]) r++;
		int pos = l;
		for(int i = 0; i < l and pos <= r; i++) {
			if(a[i] != b[pos] and b[i] != b[pos]) {
				swap(b[i], b[pos++]);
			}
		}
		for(int i = r + 1; i < n and pos <= r; i++) {
			if(a[i] != b[pos] and b[i] != b[pos]) {
				swap(b[i], b[pos++]);
			}
		}
		if(pos <= r) return printf("No\n"), 0;
	}

	printf("Yes\n");
	for(int i = 0; i < n; i++) {
		printf("%d%c", b[i], " \n"[i + 1 == n]);
	}
}
