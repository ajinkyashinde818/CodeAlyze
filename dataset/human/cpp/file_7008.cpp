#include<bits/stdc++.h>
using namespace std;
const int maxn = 400001;
int n, a[maxn], b[maxn], ta[maxn], tb[maxn], l = 1, r = 1;
int main() {
	cin >> n;
	for(int i = 1; i <= n; ++ i) {
		cin >> a[i];
		ta[a[i]] ++;
	}
	for(int i = 1; i <= n; ++ i) {
		cin >> b[i];
		tb[b[i]]++;
	}
	for(int i = 1; i <= n; ++ i) {
		if(ta[i] + tb[i] > n) {
			puts("No");
			exit(0);
		}
	}
	memset(b, 0, sizeof(b));
	for(int i = 1;i <= n; ++ i) {
		for(int j = 1; j <= tb[i]; ++ j) {
			while(b[l]) ++ l;
			while(a[r] <= a[l] && r <= n) ++ r;
			while(b[r]) ++ r;
			if(a[l] != i) b[l ++] = i;
			else b[r ++] = i;
		}
	}
	l = 1;
	for(int i = n + 1; b[i]; ++ i) {
		while(b[l]) ++ l;
		if(a[l] != b[i]) a[l] = b[i];
		else {
			while(a[r = (rand() % n + 1)] == b[i] || b[r] == a[l]);
			b[l] = b[r];
			b[r] = b[i];
		}
	}
	puts("Yes");
	for(int i = 1; i <= n; ++ i) printf("%d ", b[i]);
	return 0;
}
