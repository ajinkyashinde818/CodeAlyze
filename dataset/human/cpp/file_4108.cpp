#include <bits/stdc++.h>
using namespace std;

template<class T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, T b) { if (a > b) { a = b; return 1; } return 0; }

// 幾何ライブラリ

using DD = double; // double or long double
const DD INF = 1e30;
const DD EPS = 1e-15;
const DD PI = acosl(-1.0); // PI arccosを用いる(double or long double)
DD torad(DD deg) {return (DD)deg * PI / 180;} // degからrad(ang)に変換
DD todeg(DD ang) {return (DD)ang * 180 / PI;} // rad(ang)からdegに変換

/* Point */
struct Point {
    DD x, y;
    Point(DD x = 0.0, DD y = 0.0) : x(x), y(y) {}
};
// 四則演算
inline Point operator + (const Point &p, const Point &q) {return Point(p.x + q.x, p.y + q.y);}
inline Point operator - (const Point &p, const Point &q) {return Point(p.x - q.x, p.y - q.y);}
inline Point operator * (const Point &p, DD a) {return Point(p.x * a, p.y * a);}
inline Point operator * (DD a, const Point &p) {return Point(a * p.x, a * p.y);}
inline Point operator / (const Point &p, DD a) {return Point(p.x / a, p.y / a);}
// 反転 (x軸対象)
inline Point conj(const Point &p) {return Point(p.x, -p.y);}
// 回転 (rad)
inline Point rot(const Point &p, DD ang) {return Point(cos(ang) * p.x - sin(ang) * p.y, sin(ang) * p.x + cos(ang) * p.y);}
inline Point rot90(const Point &p) {return Point(-p.y, p.x);}
// 内積dot・外積cross
inline DD dot(const Point &p, const Point &q) {return p.x * q.x + p.y * q.y;}
inline DD cross(const Point &p, const Point &q) {return p.x * q.y - p.y * q.x;}
// ノルム
inline DD norm(const Point &p) {return dot(p, p);}
inline DD abs(const Point &p) {return sqrt(dot(p, p));}
// 偏角(0~2*PI) arctanを用いる(x = y = 0 の時、未定義動作)
inline DD amp(const Point &p) {DD res = atan2(p.y, p.x); if (res < 0) res += PI*2; return res;}
// 誤差EPSを考慮した一致判定
inline bool eq(const Point &p, const Point &q) {return abs(p - q) < EPS;}
// 比較演算子 xを優先
inline bool operator < (const Point &p, const Point &q) {return (abs(p.x - q.x) > EPS ? p.x < q.x : p.y < q.y);}
inline bool operator > (const Point &p, const Point &q) {return (abs(p.x - q.x) > EPS ? p.x > q.x : p.y > q.y);}
//（複素平面上での乗法除法）
inline Point operator * (const Point &p, const Point &q) {return Point(p.x * q.x - p.y * q.y, p.x * q.y + p.y * q.x);}
inline Point operator / (const Point &p, const Point &q) {return p * conj(q) / norm(q);}

/* Line */
struct Line : vector<Point> {
    Line(Point a = Point(0.0, 0.0), Point b = Point(0.0, 0.0)) {
        this->push_back(a); // thisはvector<Point>のこと
        this->push_back(b); // thisはvector<Point>のこと
    } // Pointを2つ記憶する →→ [0],[1]
};

/* Circle */
struct Circle : Point {
    DD r;
    Circle(Point p = Point(0.0, 0.0), DD r = 0.0) : Point(p), r(r) {}
};

// 3点Pointが一直線錠に並ぶかの判定
int simple_ccw(const Point &a, const Point &b, const Point &c) {
    // 外積を用いて判定する(EPSを考慮する)
    if (cross(b-a, c-a) > EPS) return 1;
    if (cross(b-a, c-a) < -EPS) return -1;
    return 0;
} // 1：a-bから見てcは左側(反時計回り)、-1：a-bから見てcは右側(時計回り)、0：一直線上

// 直線Lineの交点
vector<Point> crosspoint(const Line &l, const Line &m) {
    vector<Point> res;
    DD d = cross(m[1] - m[0], l[1] - l[0]);
    if (abs(d) < EPS) return vector<Point>(); // parallel
    res.push_back(l[0] + (l[1] - l[0]) * cross(m[1] - m[0], m[0] - l[0]) / d);
    return res;
}

// 円Circleの交点
vector<Point> crosspoint(const Circle &e, const Circle &f) {
    vector<Point> res;
    DD d = abs(e - f);
    if (d < EPS) return vector<Point>(); // 中心が一致（交点を持たない）
    if (d > e.r + f.r + EPS) return vector<Point>(); // ２円が離れている（交点を持たない）
    if (d < abs(e.r - f.r) - EPS) return vector<Point>(); // 一方の円が他方の円に完全に含まれている（交点を持たない）
    DD rcos = (d * d + e.r * e.r - f.r * f.r) / (2.0 * d); // 余弦定理 abs(rcos) = abs(cos * e.r) <= e.r ←→ e.r - abs(rcos) <= 0
    DD rsin; // rsin = sin * e.r
    if (e.r - abs(rcos) < EPS) rsin = 0; // cos = +-0
    else rsin = sqrt(e.r * e.r - rcos * rcos); // それ以外
    Point dir = (f - e) / d;
    Point p1 = e + dir * Point(rcos, rsin);
    Point p2 = e + dir * Point(rcos, -rsin);
    res.push_back(p1);
    if (!eq(p1, p2)) res.push_back(p2);
    return res;
}

// 外心
Point gaisin(Point a, Point b, Point c) {
    Line ab((a+b)/2, (a+b)/2 + rot90(a-b));
    Line bc((b+c)/2, (b+c)/2 + rot90(b-c));
    return crosspoint(ab, bc)[0];
}

// 凸包 反時計回り
vector<pair<Point, int> > ConvexHull(vector<pair<Point, int>> &ps) {
    int n = (int)ps.size();
    vector<pair<Point, int> > res(2*n);
    sort(ps.begin(), ps.end());
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (k >= 2) {
            while (cross(res[k-1].first - res[k-2].first, ps[i].first - res[k-2].first) < EPS) {
                k--;
                if (k < 2) break; // i=0は絶対に残す
            }
        }
        res[k].first = ps[i].first; // Point
        res[k].second = ps[i].second; // int
        k++;
    } // i=0,n-1は必ず含まれる
    int t = k+1;
    for (int i = n-2; i >= 0; i--) {
        if (k >= t) {
            while (cross(res[k-1].first - res[k-2].first, ps[i].first - res[k-2].first) < EPS) {
                --k;
                if (k < t) break; // i=n-1は絶対に残す
            }
        }
        res[k].first = ps[i].first;
        res[k].second = ps[i].second;
        k++;
    } // i=0,n-1は必ず含まれる
    res.resize(k-1); // i=0が２回含まれているのでk-1
    return res;
}

// 円と線分の交点

// 3点の位置関係
int ccw_for_crosspoint_cs(const Point &a, const Point &b, const Point &c) {
    // 一直線上にない
    if (cross(b-a, c-a) > EPS) return 1;
    if (cross(b-a, c-a) < -EPS) return -1;
    // 一直線上にある
    if (dot(b-a, c-a) < -EPS) return 2; // c → a → b
    if (norm(b-a) < norm(c-a) - EPS) return -2; // a → b → c
    return 0; // a → c → b
}
// Line上にPonitが乗っているか
bool isinterPS_crosspoint_cs(const Point &p, const Line &s) {
    return (ccw_for_crosspoint_cs(s[0], s[1], p) == 0);
}
// PointからLineへの垂線の交点
Point proj_for_crosspoint(const Point &p, const Line &l) {
    DD t = dot(p - l[0], l[1] - l[0]) / norm(l[1] - l[0]);
    return l[0] + (l[1] - l[0]) * t;
}
// 円と線分の交点
vector<Point> crosspoint_CS(const Circle &e, const Line &s) {
    vector<Point> res;
    Point p = proj_for_crosspoint(e, s);
    DD rcos = abs(e - p), rsin;
    if (rcos > e.r + EPS) return vector<Point>(); // 交点なし
    else if (e.r - rcos < EPS) rsin = 0; // 接する
    else rsin = sqrt(e.r * e.r - rcos * rcos);
    Point dir = (s[1] - s[0]) / abs(s[1] - s[0]); // 単位ベクトル
    Point p1 = p - dir * rsin;
    Point p2 = p + dir * rsin;
    if (isinterPS_crosspoint_cs(p1, s)) res.push_back(p1);
    if (isinterPS_crosspoint_cs(p2, s) && !eq(p1, p2)) res.push_back(p2);
    return res;
}

// 多角形の符号付面積
DD CalcArea(const vector<Point> &pol) {
    DD res = 0.0;
    for (int i = 0; i < (int)pol.size(); ++i) {
        res += cross(pol[i], pol[(i+1)%(int)pol.size()]) / 2.0;
    }
    return res/2.0;
}

int main() {
    Point s, t;
    cin >> s.x >> s.y >> t.x >> t.y;
    int n; cin >> n;
    vector<Circle> data(n+2);
    for (int i = 0; i < n; i++) cin >> data[i].x >> data[i].y >> data[i].r;
    int ss = n, tt = n + 1;
    data[n] = Circle(s, 0.0);
    data[n+1] = Circle(t, 0.0);

    vector<vector<DD>> G(n+2,vector<DD>(n+2,0.0));
    for (int i = 0; i < n + 2; i++) {
        for (int j = 0; j < n + 2; j++) {
            chmax(G[i][j], abs(data[i] - data[j]) - data[i].r - data[j].r);
        }
    }

    vector<DD> dist(n+2, INF);
    vector<bool> check(n+2, false);
    dist[ss] = 0.0;
    for (int i = 0; i < n + 2; i++) {
        double save = INF;
        int v = -1;
        for (int j = 0; j < n + 2; j++) {
            if (!check[j] && chmin(save, dist[j])) v = j;
        }
        check[v] = true;
        for (int j = 0; j < n + 2; j++) chmin(dist[j], dist[v] + G[v][j]);
    }
    
    cout << fixed << setprecision(10) << dist[tt] << endl;
    return 0;
}
