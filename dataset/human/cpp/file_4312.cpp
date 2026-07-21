#include <bits/stdc++.h>
 
using namespace std;
const int N = 1e5 + 10;
 
int a[N] , b[N] , f[N] , sz[N] , xorsuma , xorsumb , _a[N] , _b[N] , n , cnt;
 
int F(int x) {
	if (f[x] != x) {
		f[x] = F(f[x]);
	}
	return f[x];
}
 
int main() {
	scanf("%d",&n);
	for (int i = 1; i <= n; i++) {
		scanf("%d",a + i);
 
		_a[i] = a[i];
		xorsuma ^= a[i];
	}
 
	for (int i = 1; i <= n; i++) {
		scanf("%d",b + i);
		_b[i] = b[i];
		xorsumb ^= b[i];
	}
	n++;
	_a[n] = a[n] = xorsuma;
	_b[n] = b[n] = xorsumb;
 
	sort(_a + 1 , _a + 1 + n);
	sort(_b + 1 , _b + 1 + n);
 
	for (int i = 1; i <= n; i++) {
		if (_a[i] != _b[i]) {
			return puts("-1") , 0;
		}
	}
	cnt = unique(_a + 1 , _a + 1 + n) - _a - 1;
 
	for (int i = 1; i <= n; i++) {
		a[i] = lower_bound(_a + 1 , _a + 1 + cnt , a[i]) - _a;
		b[i] = lower_bound(_a + 1 , _a + 1 + cnt , b[i]) - _a;
	}
 
	for (int i = 1; i <= cnt; i++) f[i] = i , sz[i] = 1;
 
	int ans = 0;
	for (int i = 1; i < n; i++) {
		if (a[i] != b[i]) {
			ans ++;
			int fathera = F(a[i]) , fatherb = F(b[i]);
			if (fathera != fatherb) {
				sz[fathera] += sz[fatherb];
				f[fatherb] = fathera;
			}
		}
	}
	for (int i = 1; i <= cnt; i++) {
		if (sz[F(i)] == 1) {
			continue;
		} else if (F(i) == i && sz[F(i)] > 1) {
			ans ++;
		}
	}
	if (sz[F(a[n])] != 1) ans --;
 
	cout<<ans<<endl;
	return 0;
}
