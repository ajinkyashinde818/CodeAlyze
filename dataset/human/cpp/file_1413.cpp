#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
int a[1000][1000];
int main() {
	scanf("%d", &n);
	int l = 1, r = 2 * n, m = -1;
	while(l <= r) {
		int mid = (l + r) / 2;
		if(mid > sqrt(2 * n))r = mid - 1;
		else if(mid * (mid + 1) == 2 * n) {
			m = mid;
			break;
		}
		else if(mid * (mid + 1) < 2 * n)l = mid + 1;
		else r = mid - 1;
	}
	if(m == -1)printf("No\n");
	else {
		printf("Yes\n%d\n", m + 1);
		int l = 1;
		int x = 0;
		for(int i = 1; i <= m; i++) {
			for(int j = l; j <= m; j++) a[i][j] = ++x;
			int y = x + 1;
			for(int j = m + 1; j >= l + 1; j--) a[j][i] = --y;
			l++;
		}
		for(int i = 1; i <= m + 1; i++) {
			printf("%d", m);
			for(int j = 1; j <= m; j++) printf(" %d", a[i][j]);
			printf("\n");
		}
	}
}
