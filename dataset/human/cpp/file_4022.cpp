#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <iomanip>
using namespace std;

// chmax, chmin
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

// debug stream of pair, vector
#define COUT(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl
template<class T1, class T2> ostream& operator << (ostream &s, pair<T1,T2> P)
{ return s << '<' << P.first << ", " << P.second << '>'; }
template<class T> ostream& operator << (ostream &s, vector<T> P)
{ for (int i = 0; i < P.size(); ++i) { if (i > 0) { s << " "; } s << P[i]; } return s; }
template<class T> ostream& operator << (ostream &s, vector<vector<T> > P)
{ for (int i = 0; i < P.size(); ++i) { s << endl << P[i]; } return s << endl; }


using DD = double;
const DD INF = 1LL<<60;      // to be set appropriately
const DD EPS = 1e-10;        // to be set appropriately
const DD PI = acos(-1.0);
DD torad(int deg) {return (DD)(deg) * PI / 180;}
DD todeg(DD ang) {return ang * 180 / PI;}

/* Point */
struct Point {
    DD x, y;
    Point(DD x = 0.0, DD y = 0.0) : x(x), y(y) {}
    friend ostream& operator << (ostream &s, const Point &p) {return s << '(' << p.x << ", " << p.y << ')';}
};
inline Point operator + (const Point &p, const Point &q) {return Point(p.x + q.x, p.y + q.y);}
inline Point operator - (const Point &p, const Point &q) {return Point(p.x - q.x, p.y - q.y);}
inline Point operator * (const Point &p, DD a) {return Point(p.x * a, p.y * a);}
inline Point operator * (DD a, const Point &p) {return Point(a * p.x, a * p.y);}
inline Point operator * (const Point &p, const Point &q) {return Point(p.x * q.x - p.y * q.y, p.x * q.y + p.y * q.x);}
inline Point operator / (const Point &p, DD a) {return Point(p.x / a, p.y / a);}
inline Point conj(const Point &p) {return Point(p.x, -p.y);}
inline Point rot(const Point &p, DD ang) {return Point(cos(ang) * p.x - sin(ang) * p.y, sin(ang) * p.x + cos(ang) * p.y);}
inline Point rot90(const Point &p) {return Point(-p.y, p.x);}
inline DD cross(const Point &p, const Point &q) {return p.x * q.y - p.y * q.x;}
inline DD dot(const Point &p, const Point &q) {return p.x * q.x + p.y * q.y;}
inline DD norm(const Point &p) {return dot(p, p);}
inline DD abs(const Point &p) {return sqrt(dot(p, p));}
inline DD amp(const Point &p) {DD res = atan2(p.y, p.x); if (res < 0) res += PI*2; return res;}
inline bool eq(const Point &p, const Point &q) {return abs(p - q) < EPS;}
inline bool operator < (const Point &p, const Point &q) {return (abs(p.x - q.x) > EPS ? p.x < q.x : p.y < q.y);}
inline bool operator > (const Point &p, const Point &q) {return (abs(p.x - q.x) > EPS ? p.x > q.x : p.y > q.y);}
inline Point operator / (const Point &p, const Point &q) {return p * conj(q) / norm(q);}

/* Circle */
struct Circle : Point {
    DD r;
    Circle(Point p = Point(0.0, 0.0), DD r = 0.0) : Point(p), r(r) {}
    friend ostream& operator << (ostream &s, const Circle &c) {return s << '(' << c.x << ", " << c.y << ", " << c.r << ')';}
};

int N;
Point sp, tp;
vector<Circle> c;
double dist[1100][1100];
double dp[1100];
bool seen[1100];

int main() {
    cin >> sp.x >> sp.y >> tp.x >> tp.y;
    cin >> N;
    c.resize(N);
    for (int i = 0; i < N; ++i) cin >> c[i].x >> c[i].y >> c[i].r;
    
    int s = N, t = N+1;
    for (int i = 0; i < N; ++i) {
        double ds = abs(c[i] - sp);
        dist[i][s] = dist[s][i] = max(0.0, ds - c[i].r);
        double dt = abs(c[i] - tp);
        dist[i][t] = dist[t][i] = max(0.0, dt - c[i].r);
    }
    dist[s][t] = abs(sp - tp);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            double d = abs(c[i] - c[j]);
            dist[i][j] = max(0.0, d - c[i].r - c[j].r);
        }
    }
    
    for (int i = 0; i < 1100; ++i) dp[i] = 1LL<<60, seen[i] = false;
    dp[s] = 0;
    for (int _ = 0; _ < N+2; ++_) {
        double cur = 1LL<<60;
        int v = -1;
        for (int i = 0; i < N+2; ++i) if (!seen[i] && chmin(cur, dp[i])) v = i;
        seen[v] = true;
        
        //cout << v << ": " << dp[v] << endl;
        
        for (int i = 0; i < N+2; ++i) chmin(dp[i], dp[v] + dist[v][i]);
    }
    cout << fixed << setprecision(10) << dp[t] << endl;
}
