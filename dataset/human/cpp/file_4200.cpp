class in{struct It{int it;const bool rev;explicit constexpr It(int it_, bool rev=false):it(it_),rev(rev){}int operator*(){return it;}bool operator!=(It& r){return it!=r.it;}void operator++(){rev?--it:++it;}};const It i,n;public:explicit constexpr in(int n):i(0),n(n<0?0:n){}explicit constexpr in(int i,int n):i(i,n<i),n(n){}const It& begin(){return i;}const It& end(){return n;}};

#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
template<class T>
struct Pt {
 	T x, y;
	Pt() {}
	Pt(T x, T y) : x(x), y(y) {}
	Pt operator+(const Pt &a) const { return Pt(x + a.x, y + a.y); }
	Pt operator-(const Pt &a) const { return Pt(x - a.x, y - a.y); }
	Pt operator*(const Pt &a) const { return Pt(x * a.x - y * a.y, x * a.y + y * a.x); }
	Pt operator/(const Pt &a) const { const T d2 = a.abs2(); return Pt((x * a.x + y * a.y) / d2, (y * a.x - x * a.y) / d2); }
	Pt operator+() const { return Pt(+x, +y); }
	Pt operator-() const { return Pt(-x, -y); }
	Pt operator*(const T &k) const { return Pt(x * k, y * k); }
	Pt operator/(const T &k) const { return Pt(x / k, y / k); }
	friend Pt operator*(const T &k, const Pt &a) { return Pt(k * a.x, k * a.y); }
	Pt &operator+=(const Pt &a) { x += a.x; y += a.y; return *this; }
	Pt &operator-=(const Pt &a) { x -= a.x; y -= a.y; return *this; }
	Pt &operator*=(const Pt &a) { return *this = *this * a; }
	Pt &operator/=(const Pt &a) { return *this = *this / a; }
	Pt &operator*=(const T &k) { x *= k; y *= k; return *this; }
	Pt &operator/=(const T &k) { x /= k; y /= k; return *this; }
	T abs() const { return sqrt(x * x + y * y); }
	T abs2() const { return x * x + y * y; }
	T arg() const { return atan2(y, x); }
	T dot(const Pt &a) const { return x * a.x + y * a.y; }
	T det(const Pt &a) const { return x * a.y - y * a.x; }
	bool operator<(const Pt &a) const { return (x != a.x) ? (x < a.x) : (y < a.y); }
	friend ostream &operator<<(ostream &os, const Pt &a) { os << "(" << a.x << ", " << a.y << ")"; return os; }
};

using P = Pt<double>;
const double EPS = 1.0e-12;
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    P s, t;
    cin >> s.x >> s.y >> t.x >> t.y;
    int n;
    cin >> n;
    vector<pair<P, double>> c(n);
    for(auto& p : c)
      cin >> p.first.x >> p.first.y >> p.second;
    vector<double> dist(n);
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> que;
    for(int i : in(n)) {
        dist[i] = max(0.0, (c[i].first - s).abs() - c[i].second);
        que.emplace(dist[i], i);
    }
    bool used[1000];
    memset(used, 0, sizeof(used));
    while(!que.empty()) {
        double cost; int v;
        tie(cost, v) = que.top(); que.pop();
        if(used[v]) continue;
        used[v] = true;
        for(int i : in(n)) if(used[i] == false) {
            double ncos = max(0.0, (c[v].first - c[i].first).abs() - c[v].second - c[i].second);
            if(ncos + dist[v] < dist[i]) {
                dist[i] = ncos + dist[v];
                que.emplace(dist[i], i);
            }
        }
    }
    double ans = (s - t).abs();
    for(int i : in(n)) {
        double dis = max(0.0, (c[i].first - t).abs() - c[i].second);
        ans = min(ans, dis + dist[i]);
    }
    cout << fixed << setprecision(12) << ans << endl;
    return 0;
}
