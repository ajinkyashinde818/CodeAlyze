#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define Rep(i,a,n)for(int i=(int)(a);i<(int)(n);i++)
#define rep(i,n)Rep(i,0,n)
typedef long long ll;

int main() {
	int R, G, B, n, flag=0; ll ans = 0;
	scanf("%d %d %d %d", &R,&G,&B,&n);
	rep(r, 1 + (n / R)) {
		rep(g, 1 + (n / G)) {
			if ((n - r * R - g * G) >= 0 && (n - r * R - g * G) % B == 0)ans++;
		}
	}
	printf("%lld", ans);
}
