#include <iostream>
#include <cassert>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <complex>

using namespace std;
typedef long long ll;

typedef long double R;
typedef complex<R> P;


namespace std {
    bool operator < (P a, P b) {
        return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
    }
    bool operator > (P a, P b) {
        return (b < a);
    }
}

const R EPS = 1e-10;
const R PI = acos(-1);

/*
 -1 -> neg
  0 -> near 0
  1 -> pos
  */
int sgn(R a) {
    if (a < -EPS) return -1;
    if (a > EPS) return 1;
    return 0;
}

int sgn(R a, R b) {
    return sgn(b-a);
}

bool near(P a, P b) {
    return !sgn(abs(a-b));
}

R cross(P a, P b) { return imag(conj(a)*b); }
R dot(P a, P b) { return real(conj(a)*b); }

/* 1->cclock
  -1->clock
   0->on
   2->back
  -2->front
  */
int ccw(P a, P b, P c) {
    assert(!near(a, b));
    if (near(a, c) || near(b, c)) return 0;
    int s = sgn(cross(b-a, c-a));
    if (s) return s;
    if (a > b) swap(a, b);
    if (dot(b-a, c-a) < 0) return 2;
    if (dot(a-b, c-b) < 0) return -2;
    return 0;
}

struct L {
    P x, y;
    L() {};
    L(P x, P y) :x(x), y(y) {};
};

P vec(const L &l) {
    return l.y - l.x;
}

R abs(const L &l) {
    return abs(vec(l));
}

struct C {
    P p;
    R r;
    C () {};
    C (P p, R r) : p(p), r(r) {};
};

R distLP(const L &l, const P &p) {
    return abs(cross(l.y-l.x, p-l.x)/abs(l.y-l.x));
}


//????????¨??????????°??????¢
R distSP(const L &s, const P &p) {
    R r = min(abs(s.x-p), abs(s.y-p));
    P s2 = vec(s)*P(0, 1);
    if (ccw(s.x, s.x+s2, p) == 1) return r;
    if (ccw(s.y, s.y+s2, p) == -1) return r;
    return min(r, distLP(s, p));
}

int CrossSC(const L&l, const C &c) {
    R mi = distSP(l, c.p);
    if (sgn(c.r, mi) == 1) return 0;
    if (sgn(c.r, mi) == 0) return 1;
    int u = 0;
    if (sgn(c.r, abs(l.x-c.p)) != -1) u++;
    if (sgn(c.r, abs(l.y-c.p)) != -1) u++;
    return u;
}

const int MN = 110;


C w[MN];
int n, m;

int main() {
    while (true) {
        cin >> n;
        if (!n) break;
        for (int i = 0; i < n; i++) {
            R x, y, r;
            cin >> x >> y >> r;
            w[i] = C(P(x, y), r);
        }
        cin >> m;
        for (int i = 0; i < m; i++) {
            R tx, ty, sx, sy;
            cin >> tx >> ty >> sx >> sy;
            L l = L(P(tx, ty), P(sx, sy));
            bool f = true;
            for (int j = 0; j < n; j++) {
                if (CrossSC(l, w[j])) {
                    f = false;
                }
            }
            if (f) {
                cout << "Danger" << endl;
            } else {
                cout << "Safe" << endl;
            }
        }
    }
    return 0;
}
