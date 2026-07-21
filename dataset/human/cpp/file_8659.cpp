#include "bits/stdc++.h"
using namespace std;
char a[50][51];
char b[50][51];
int main() {
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		scanf("%s", a[i]);
	}
	for (int i = 0; i < M; i++) {
		scanf("%s", b[i]);
	}
	for (int i = 0; i <= N - M; i++) {
		for (int j = 0; j <= N - M; j++) {
			bool OK = 1;
			for (int k = 0; k < M; k++) {
				for (int l = 0; l < M; l++) {
					if (a[i + k][j + l] != b[k][l]) {
						OK = 0;
						break;
					}
				}
				if (!OK) break;
			}
			if (OK) {
				printf("Yes\n");
				return 0;
			}
		}
	}
	printf("No\n");
}
