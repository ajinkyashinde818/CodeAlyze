#include <bits/stdc++.h>

const int MAXN = 1010;
typedef double db;
struct vec {
	db x, y;
	vec() { x = y = 0; }
	vec(db a, db b) { x = a, y = b; }
	db operator ^ (vec b) const { return x * b.y - y * b.x; }
	db operator * (vec b) const { return x * b.x + y * b.y; }
	db norm2() const { return x * x + y * y; }
	db norm() const { return sqrt(x * x + y * y); }
	vec operator - (vec b) const { return vec(x - b.x, y - b.y); }
	vec operator + (vec b) const { return vec(x + b.x, y + b.y); }
	vec operator * (db k) const { return vec(x * k, y * k); }
	bool operator < (const vec & b) const {
		return x == b.x ? y < b.y : x < b.x;
	}
	friend std::istream & operator >> (std::istream & in, vec & x) {
		in >> x.x >> x.y;
		return in;
	}
	friend std::ostream & operator << (std::ostream & out, vec & x) {
		out << x.x << ' ' << x.y;
		return out;
	}
} ps[MAXN];
int n, rs[MAXN], vis[MAXN];
double dis[MAXN];
db calc(int a, int b) {
	return std::max((ps[a] - ps[b]).norm() - rs[a] - rs[b], 0.);
}
void relax(db & x, db v) { x > v ? x = v : 0; }
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	vec x, y; std::cin >> x >> y >> n;
	ps[1] = x, ps[n + 2] = y;
	for (int i = 2; i <= n + 1; ++i) std::cin >> ps[i] >> rs[i];
	n += 2;
	for (int i = 0; i <= n; ++i) dis[i] = 1e100; dis[1] = 0;
	for (int i = 1; i <= n; ++i) {
		int t = 0;
		for (int j = 1; j <= n; ++j) if (!vis[j] && dis[j] < dis[t]) t = j;
		vis[t] = true;
		for (int j = 1; j <= n; ++j) if (!vis[j])
			 relax(dis[j], dis[t] + calc(t, j));
	}
	std::cout << std::fixed << std::setprecision(10);
	std::cout << dis[n] << std::endl;
	return 0;
}
