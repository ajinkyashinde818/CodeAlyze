#include<iostream>
#include <list>
#include<stack>
#include<queue>
#include <vector>
#include <set>
#include<algorithm>
#include<math.h>
#include<stdlib.h>
#include<string>
#include <functional>
#include<fstream>
#include<iomanip>

#define FOR(k,m,n) for(int (k)=(m);(k)<(n);(k)++)
#define REP(i,n) FOR((i),0,(n))
#define ll long long
#define ld long double
#define CLR(a) memset((a),0,sizeof(a))
#define SZ(x) (int((x).size()))
#define WAITING(str) int str;std::cin>>str;
#define DEBUGING(str) cout<<str<<endl
using namespace std;

const ll MOD = 1000000007;// 10^9+7
const ll INF = (1ll << 60);


//変数

struct P {
	ld x, y, r;

	ld dist(P oth)const {
		ld d = powl(x - oth.x, 2) + powl(y - oth.y, 2);
		d = sqrtl(d);
		d -= r + oth.r;
		return max(0.L, d);
	}
};


constexpr int MAX_N = 1002;
ld cost[MAX_N][MAX_N];
ld d[MAX_N];
bool used[MAX_N];

int N;



//サブ関数
//入力
void input()
{
	vector<P> ps(2);
	cin >> ps[0].x >> ps[0].y >> ps[1].x >> ps[1].y;
	cin >> N;
	ps.resize(N + 2);
	REP(i, N)cin >> ps[i + 2].x >> ps[i + 2].y >> ps[i + 2].r;
	REP(i, N + 2)REP(j, N + 2)cost[i][j] = ps[i].dist(ps[j]);
}

void dijkstra(int s)
{
	fill(d, d + N + 2, INF);
	fill(used, used + N + 2, false);
	d[s] = 0;

	while (true) {
		int v = -1;
		REP(u, N + 2)if (!used[u] && (v == -1 || d[u] < d[v]))v = u;
		if (v == -1)break;
		used[v] = true;

		REP(u, N + 2)d[u] = min(d[u], d[v] + cost[v][u]);
	}
}

//計算
void calc()
{
	dijkstra(0);
	cout << fixed;
	cout << setprecision(15) << d[1] << endl;
}


//出力
void output()
{

}


//デバッグ
void debug()
{
	int N;
	cin>>N;
}


//メイン関数
int main()
{
	input();
	calc();
	output();
	debug();
	
	return 0;
}
