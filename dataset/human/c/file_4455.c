#include<stdio.h>


int main() {
	int n ;
	scanf("%d", &n);
	int ans = 0 ;
	int f[n], s[n];
	for (int i = 0 ; i < n ; i++) {
		scanf("%d", &f[i]);
		scanf("%d", &s[i]);
	}

	for (int i = 0; i < n - 2 ; i++) {
		if (f[i] == s[i] && f[i + 1] == s[i + 1] && f[i + 2] == s[i + 2]) {
			ans = 1  ;
			break;
		}
	}
	ans ? printf("Yes") : printf("No");
}
