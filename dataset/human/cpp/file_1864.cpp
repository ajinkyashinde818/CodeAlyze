#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

bool used[200001];
int c[100000];
signed main() {
	int a, b; scanf("%d%d", &a, &b);
	for (int d = 0; d < b; d++)scanf("%d", &c[d]);
	for (int d = b - 1; d >= 0; d--) {
		if (!used[c[d]]) {
			printf("%d\n", c[d]);
			used[c[d]] = true;
		}
	}
	for (int i = 1; i <= a; i++) {
		if (!used[i])printf("%d\n", i);
	}
}
