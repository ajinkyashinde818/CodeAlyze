#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<string>
#include<cmath>
#include<cstring>
#include<queue>
#include<map>
#include<climits>
#include<set>

using namespace std;
typedef pair<int, int> pii;
typedef long long int ll;
typedef pair<ll, ll> pll;
int dx[4] = { 1,0,0,-1 };
int dy[4] = { 0,1,-1,0 };
#define MOD 1000000007
#define ARRAY_MAX 100005

const double INF = 1e15 + 7;

typedef pair<ll, double> plld;

typedef struct edge {

	int to;
	double cost;

}EDGE;

void dijkstra(int n, vector<vector<EDGE> >& G, int x,vector<double>& d) {
	/*頂点の個数、辺の情報、始点となる頂点、最短距離の情報*/

	/*最終的にdは経由点からの最短距離が格納される、その過程では暫定的な最短距離が格納され、最短距離が見つかれば、その都度更新される*/

	//vector<ll> d(n,INF);/*最終的な最短距離を保持、初期化はINF*/
	d[x] = 0;
	priority_queue<plld, vector<plld>, greater<plld> > que;/*vectorのpriority_queueで暫定的な最短距離が小さい順に取り出す*/
	que.push(plld(0, x));/*経由点からダイクストラを適用するので経由点の暫定的な最短距離のコストは0*/

	while (!que.empty()) {/*queが空になれば最短距離が全て探索できたことになる*/

		plld p = que.top();/*最短距離の１番小さいものの取り出し*/
		que.pop();/*取り出したので調べたとみなし、queから出す*/
		int v = p.second;/*取り出した頂点の番号*/
		if (d[v] < p.first) {
			/*取り出した頂点からの最短距離よりも短い経路があるので更新の必要はない*/
			continue;
		}

		for (int i = 0; i < G[v].size(); i++) {
			/*取り出した頂点から辺でつながっている頂点への最短距離を調べて現在の値より短ければ更新する*/
			EDGE e = G[v][i];/*取り出した頂点からつながっている頂点を1つ取り出す*/
			if (d[e.to] > d[v] + e.cost) {
				/*現在の最短距離よりも、現在の頂点を経由する経路のほうが最短距離が短い場合は最短距離を更新し、次の頂点を調べる*/
				d[e.to] = d[v] + e.cost;/*最短経路の更新*/
				que.push(plld(d[e.to], e.to));/*先の頂点を調べるためqueに格納*/
			}
		}
	}
}



int main() {


	ios::sync_with_stdio(false);
	cin.tie(0);
	double xs, ys, xt, yt;
	int n;
	cin >> xs >> ys >> xt >> yt >> n;

	vector<vector<EDGE> > G(n+2);/*n個の各頂点からそれ以外の頂点へのコスト*/
	vector<double> d(n+2, INF);/*最短経路*/
	vector<double> x(n + 2), y(n + 2), r(n + 2);//(x,y),半径

	x[0] = xs;
	y[0] = ys;
	r[0] = 0;

	for (int i = 1; i <= n; i++)
	{
		cin >> x[i] >> y[i] >> r[i];
	}
	x[n+1] = xt;
	y[n+1] = yt;
	r[n+1] = 0;

	for (int i = 0; i <= n + 1; i++) 
	{
		for (int j = i + 1; j <= n + 1; j++) 
		{
			double len = sqrt((x[j] - x[i])*(x[j] - x[i]) + (y[j] - y[i])*(y[j] - y[i]));
			double radius = r[i] + r[j];
			double dis = max(0.0,len - radius);
			G[i].push_back(EDGE{ j,dis });
			G[j].push_back(EDGE{ i,dis });
		}
	}

	dijkstra(n, G, 0, d);

	printf("%.12f\n", d[n + 1]);

	return 0;
}
