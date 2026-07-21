#include <algorithm>
#include <iostream>
#include <climits>
#include <cstdio>
#include <queue>

using namespace std;

typedef unsigned int uint;

const int INF = INT_MAX >> 1;
const int N = 505;
const int W = 32;
const int B = N / W + 2;
const int M = 200005;

typedef pair<int , int> data;

#define mkp(a , b) make_pair(a , b)
#define ft first
#define sd second

queue<data> q;

uint done[N][B] , graph[N][B];
int tov[M] , nxt[M];
bool vis[N];
int f[N][N];
int last[N];
int n , m , tot , cirlen , ans;

inline void set(uint *bits , int x){bits[x / W] |= 1 << x % W;}

inline void insert(int x , int y){tov[++ tot] = y , nxt[tot] = last[x] , last[x] = tot;}

int dfs(int x , int dep = 0)
{
	vis[x] = 1;
	for (int i = last[x] , y , ret;i;i = nxt[i])
	{
		if ((y = tov[i]) == 1) return dep + 1;
		if (!vis[y])
		{
			ret = dfs(y , dep + 1);
			if (ret) return ret;
		}
	}
	return 0;
}

void bfs()
{
	ans = INF;
	if (!cirlen) return;
	for (int i = 0;i < cirlen;++ i)
		for (int x = 1;x <= n;++ x)
			f[i][x] = INF;
	f[0][1] = 0 , q.push(mkp(0 , 1)) , set(done[0] , 0);
	for (data cur;!q.empty();)
	{
		cur = q.front() , q.pop();
		for (int i = 0 , nxti = cur.ft == cirlen - 1 ? 0 : cur.ft + 1;i <= (n - 1) / W;++ i)
		{
			uint state = ~done[nxti][i] & graph[cur.sd][i];
			if (state)
				for (int j = 0 , y = i * W + 1;j < W;++ j , ++ y)
					if ((state >> j) & 1)
					{
						f[nxti][y] = f[cur.ft][cur.sd] + 1;
						q.push(mkp(nxti , y)) , set(done[nxti], y - 1);
					}
		}
	}
	for (int i = 0 , ret;i < cirlen;++ i)
	{
		ret = 0;
		for (int x = 1;x <= n;++ x) ret = max(ret , f[i][x]);
		ans = min(ans , ret);
	}
}

int main()
{
	//freopen("f.in" , "r" , stdin) , freopen("f.out" , "w" , stdout);
	scanf("%d%d" , &n , &m);
	for (int i = 1 , x , y;i <= m;++ i) scanf("%d%d" , &x , &y) , insert(x , y) , set(graph[x] , y - 1);
	cirlen = dfs(1) , bfs() , printf("%d\n" , ans == INF ? -1 : ans);
	//fclose(stdin) , fclose(stdout);
	return 0;
}
