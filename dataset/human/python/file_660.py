import std.algorithm;
import std.array;
import std.ascii;
import std.container;
import std.conv;
import std.math;
import std.numeric;
import std.range;
import std.stdio;
import std.string;
import std.typecons;
void log(A...)(A arg) { stderr.writeln(arg); }
int size(T)(in T s) { return cast(int)s.length; }

immutable double EPS = 1e-7;

struct Point {
    double x, y;
    Point opBinary(string op)(in Point p) const if (op == "+" || op == "-") {
        return Point(mixin("x" ~ op ~ "p.x"), mixin("y" ~ op ~ "p.y"));
    }
    Point opBinary(string op)(double k) const if (op == "*" || op == "/") {
        return Point(mixin("x" ~ op ~ "k"), mixin("y" ~ op ~ "k"));
    }
};
double dot(in Point a, in Point b) { return a.x * b.x + a.y * b.y; }
double cross(in Point a, in Point b) { return a.x * b.y - a.y * b.x; }
double norm(in Point a) { return sqrt(dot(a, a)); }

struct Circle {
    Point p;
    double r;
};
bool contains(in Circle c, in Point p) { return norm(c.p - p) < c.r + EPS; }
bool contains(in Circle a, in Circle b) { return b.r + norm(a.p - b.p) < a.r + EPS; }
bool intersects(in Circle a, in Circle b) {
    if (contains(a, b) || contains(b, a)) return false;
    return norm(a.p - b.p) < a.r + b.r + EPS;
}

double dist(in Circle a, in Circle b) {
    return max(0, norm(a.p - b.p) - (a.r + b.r));
}

immutable INF = 1e18;

struct Edge {
    int from, to; double cost;
}

void main() {
    Point s, t;
    readf("%s %s %s %s\n", &s.x, &s.y, &t.x, &t.y);
    int N; readf("%s\n", &N);
    auto Cs = new Circle[N];
    foreach (i; 0 .. N) {
        double x, y, r; readf("%s %s %s\n", &x, &y, &r);
        Cs[i] = Circle(Point(x, y), r);
    }
    Cs ~= Circle(s, 0);
    Cs ~= Circle(t, 0);

    auto G = new double[][](N + 2, N + 2);
    foreach (i; 0 .. Cs.size) {
        foreach (j; i + 1 .. Cs.size) {
            double d = dist(Cs[i], Cs[j]);
            G[i][j] = G[j][i] = d;
        }
    }

    int from = N;
    int to = N + 1;
    auto D = new double[Cs.size];
    D[] = INF;
    struct S {
        int v; double cost;
    }
    BinaryHeap!(Array!S, "a.cost > b.cost") PQ;
    PQ.insert(S(from, 0));
    while (! PQ.empty) {
        auto c = PQ.front; PQ.removeFront;
        foreach (nv; 0 .. N + 2) {
            if (c.v == nv) continue;
            double ncost = G[c.v][nv] + c.cost;
            if (D[nv] > ncost) {
                D[nv] = ncost;
                PQ.insert(S(nv, ncost));
            }
        }
    }
    //log(D);
    writefln("%.12f", D[to]);



}
