#include<stdio.h>
#include<stdlib.h>
#include<cmath>
#include<string>
typedef long long ll;
typedef unsigned long long llu;
#define Q 1000000007

ll powmod(ll x, ll y) {
	ll res = 1;
	for (ll i = 0; i < y; i++) {
		res = res * x % Q;
	}
	return res;
}

int main() 
{
	int n;

	int d[100][2];
	scanf("%d", &n);
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &d[i][0]);
		scanf("%d", &d[i][1]);
		if (d[i][0] == d[i][1]) {
			if (++cnt == 3) {
				printf("Yes\n");
				return 0;
			}
		}
		else {
			cnt = 0;
		}
	}
	printf("No\n");
	return 0;
}
