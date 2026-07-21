#include <stdio.h>
#define rep(i,n)Rep(i,0,n)
#define Rep(i,a,n)for(int i=(int)(a);i<(int)(n);i++)
typedef long long ll;
typedef long double ld;

int main() {
	int n, a[100001], tmp;
	scanf("%d", &n);
	rep(i, n)scanf("%d", &a[i]);
	tmp = a[0];
	rep(i, 100002) {
		if (tmp == 2) { printf("%d", i + 1); return 0; }
		tmp = a[tmp - 1];
	}
	printf("-1"); return 0;
}
