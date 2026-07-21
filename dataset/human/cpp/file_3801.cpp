#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 1000;
const double EPS = 1E-10;
struct Point{
	double x, y;
	Point(double _x=0, double _y=0):x(_x), y(_y){}
};
struct Circle{
	Point p; double r;
}c[MAXN + 5];
typedef Point Vector;
Vector operator + (Vector a, Vector b) {return Vector(a.x+b.x, a.y+b.y);}
Vector operator - (Vector a, Vector b) {return Vector(a.x-b.x, a.y-b.y);}
Vector operator * (Vector a, double k) {return Vector(a.x*k, a.y*k);}
Vector operator / (Vector a, double k) {return Vector(a.x/k, a.y/k);}
double cross(Vector a, Vector b) {return a.x*b.y - a.y*b.x;}
double dot(Vector a, Vector b) {return a.x*b.x + a.y*b.y;}
double length(Vector a) {return sqrt(dot(a, a));}
double dcmp(double x) {if( fabs(x) <= EPS ) return 0; else return x > 0 ? 1 : -1;}
double pow2(double x) {return x*x;}
Vector Unit(Vector a) {double l = length(a); return Vector(a.x/l, a.y/l);}
double dist(Point a, Point b) {return sqrt(pow2(a.x - b.x) + pow2(a.y - b.y));}
bool Check(Circle a, Circle b) {return dcmp(a.r + b.r - dist(a.p, b.p)) >= 0;}
bool Check(Circle a, Point b) {return dcmp(a.r - dist(a.p, b)) >= 0;}
double dist(Circle a, Circle b) {
	Vector vb = Unit(a.p - b.p), va = Unit(b.p - a.p);
	Point A = (a.p + va*a.r), B = (b.p + vb*b.r);
	return dist(A, B);
}
double dist(Circle a, Point b) {
	Vector v = Unit(b - a.p);
	return dist(b, a.p + v*a.r);
}
Point s, t;
double G[MAXN + 5][MAXN + 5], dis[MAXN + 5];
bool vis[MAXN + 5];
int N;
void dijkstra() {
	for(int i=1;i<=N+1;i++)
		dis[i] = G[0][i];
	vis[0] = true;
	for(int i=1;i<=N+1;i++) {
		double mn = 1E18;int p;
		for(int j=0;j<=N+1;j++) {
			if( !vis[j] && dis[j] < mn ) {
				p = j;
				mn = dis[j];
			}
		}
		vis[p] = true;
		for(int j=0;j<=N+1;j++) {
			if( !vis[j] ) dis[j] = min(dis[j], dis[p] + G[p][j]);
		}
	}
}
int main() {
	scanf("%lf%lf%lf%lf", &s.x, &s.y, &t.x, &t.y);
	scanf("%d", &N);
	for(int i=1;i<=N;i++)
		scanf("%lf%lf%lf", &c[i].p.x, &c[i].p.y, &c[i].r);
	for(int i=1;i<=N;i++) {
		if( Check(c[i], s) ) G[0][i] = G[i][0] = 0;
		else G[0][i] = G[i][0] = dist(c[i], s);
		if( Check(c[i], t) ) G[i][N+1] = G[N+1][i] = 0;
		else G[i][N+1] = G[N+1][i] = dist(c[i], t);
	}
	G[0][N+1] = G[N+1][0] = dist(s, t);
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++) {
			if( Check(c[i], c[j]) ) G[i][j] = 0;
			else G[i][j] = dist(c[i], c[j]);
		}
	dijkstra();
	printf("%.10lf\n", dis[N+1]);
}
