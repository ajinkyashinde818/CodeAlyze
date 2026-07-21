// Standard I/O
#include <iostream>
#include <sstream>
#include <cstdio>
// Standard Library
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
// Template Class
#include <complex>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
// Container Control
#include <algorithm>

using namespace std;

#define rep( i, n ) for( int i = 0; i < n; ++i )
#define irep( i, n ) for( int i = n-1; i >= 0; --i )
#define reep( i, s, n ) for ( int i = s; i < n; ++i )
#define ireep( i, n, s ) for ( int i = n-1; i >= s; --i )
#define foreach(itr, x) for( typeof(x.begin()) itr = x.begin(); itr != x.end(); ++itr)

#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define all( v ) v.begin(), v.end()
#define fs first
#define sc second
#define vc vector

// for visualizer.html
double SCALE = 1.0;
double OFFSET_X = 0.0;
double OFFSET_Y = 0.0;
#define LINE(x,y,a,b) cerr << "line(" << SCALE*(x) + OFFSET_X << ","	\
	<< SCALE*(y) + OFFSET_Y << ","										\
	<< SCALE*(a) + OFFSET_X << ","										\
	<< SCALE*(b) + OFFSET_Y << ")" << endl;
#define CIRCLE(x,y,r) cerr << "circle(" << SCALE*(x) + OFFSET_X << ","	\
	<< SCALE*(y) + OFFSET_Y << ","										\
	<< SCALE*(r) << ")" << endl;

typedef long long ll;
typedef complex<double> Point;

typedef pair<int, int> pii;
typedef pair<int, pii> ipii;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector< vector<int> > vii;
typedef vector< vector<double> > vdd;

typedef vector<int>::iterator vi_itr;

const int IINF = 1 << 28;
const int MOD = 1e9+7;
const double INF = 1e30;
const double EPS = 1e-10;
const double PI = acos(-1.0);

// Direction : L U R D
const int dx[] = { -1, 0, 1, 0};
const int dy[] = { 0, -1, 0, 1 };

struct Circle
{
	Point x;
	double r;

	Circle( Point x = Point(0,0), double r = 0.0 ) :x(x), r(r) {}
};

double calc_circle_dist ( const Circle& c1, const Circle& c2 )
{
	double dist = abs(c1.x - c2.x);

	if( dist < c1.r + c2.r + EPS ) return 0.0;
	return dist - (c1.r + c2.r);
}

struct Edge
{
	double cost;
	int to;
	Edge( double cost = 0.0, int to = 0 ) :cost(cost), to(to) {}
};

const int N = 1100;
double d[N];
int from[N];
vector<Edge> edge[N];

void dijkstra ( int beg )
{
	typedef tuple<double, int, int> T;
	priority_queue<T, vector<T>, greater<T>> que;
	que.push( make_tuple(0.0, beg, -1) );

	rep(i, N) d[i] = INF;
	
	bool visit[N] = { false };
	while( !que.empty() ){
		auto p = que.top(); que.pop();

		double cost;
		int id, p_id;
		tie(cost, id, p_id) = p;
		
		if( visit[id] ) continue;
		visit[id] = true;
		d[id] = cost;
		from[id] = p_id;

		rep(i, edge[id].size()){
			if( d[edge[id][i].to] < cost + edge[id][i].cost ) continue;
			que.push( make_tuple(cost + edge[id][i].cost, edge[id][i].to, id) );
		}
	}
}

int main()
{
	Point s, e;

	double x, y;
	cin >> x >> y;
	s = Point(x, y);
	cin >> x >> y;
	e = Point(x, y);

	int N;
	vector<Circle> c;
	cin >> N;
	rep(i, N){
		Point x; double r;
		double x_, y_;
		cin >> x_ >> y_ >> r;
		x = Point(x_, y_);
		c.eb(x, r);
	}

	edge[0].eb( abs(s - e), 1 );
	edge[1].eb( abs(s - e), 0 );
	
	rep(i, N){
		edge[0].eb( max(0.0, abs(c[i].x - s) - c[i].r), i+2 );
		edge[1].eb( max(0.0, abs(c[i].x - e) - c[i].r), i+2 );

		edge[i+2].eb( max(0.0, abs(c[i].x - s) - c[i].r), 0 );
		edge[i+2].eb( max(0.0, abs(c[i].x - e) - c[i].r), 1 );
	}
	
	rep(i, N) rep(j, N){
		if( i == j ) continue;
		edge[i+2].eb( calc_circle_dist(c[i], c[j]), j+2 );
	}

	// rep(i, N+2){
	// 	printf("%d\n", i);
	// 	rep(j, edge[i].size()){
	// 		printf("  (%d -> %d) : %.16E\n", i, edge[i][j].to, edge[i][j].cost);
	// 	}
	// }
	
	dijkstra(0);

	printf("%.16E\n", d[1]);
}
