#include<bits/stdc++.h>
    using namespace std;
    const int MAXN = 100005;
    const long long INF = 1e18;
    template <typename T> void chkmax(T &x, T y) {x = max(x, y); }
    template <typename T> void chkmin(T &x, T y) {x = min(x, y); } 
    template <typename T> void read(T &x) {
    	x = 0; int f = 1;
    	char c = getchar();
    	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
    	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
    	x *= f;
    }
    template <typename T> void write(T x) {
    	if (x < 0) x = -x, putchar('-');
    	if (x > 9) write(x / 10);
    	putchar(x % 10 + '0');
    }
    template <typename T> void writeln(T x) {
    	write(x);
    	puts("");
    }
    int n; long long ans, c;
    long long x[MAXN], v[MAXN], pre[MAXN], sum[MAXN];
    void solve(long long c) {
    	for (int i = 1; i <= n; i++) {
    		sum[i] = sum[i - 1] + v[i];
    		pre[i] = max(pre[i - 1], sum[i] - x[i]);
    	}
    	long long now = 0;
    	for (int i = n; i >= 1; i--) {
    		chkmax(ans, now + pre[i]);
    		now += v[i] - 2 * (c - x[i]);
    		c = x[i];
    	}
    }
    int main() {
    	read(n), read(c);
    	for (int i = 1; i <= n; i++)
    		read(x[i]), read(v[i]);
    	solve(c);
    	for (int i = 1; i <= n; i++)
    		x[i] = c - x[i];
    	reverse(x + 1, x + n + 1);
    	reverse(v + 1, v + n + 1);
    	solve(c);
    	writeln(ans);
    	return 0;
    }
