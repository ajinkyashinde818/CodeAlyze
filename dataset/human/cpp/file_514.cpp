#include<iostream>
#include<vector>
#include<cstdio>
#include<string>
#include<algorithm>
#include <utility>
#include<queue>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<string> vs;
typedef vector<vector<string>> vvs;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
bool praime_numbers[100001];

static const int MOD = 1000000007;

const int int_inf = 2147483647;
const ll long_inf = 9223372036854775807ll;

#define rep(i,n) for(int i = 0;i<n;i++)
#define rep(j,n) for(int j = 0;j<n;j++)
#define defvi(a,c) vector<int>(a,c)
#define defvvi(a,b,c) vector<vector<int>>(a, vector<int>(b, c))

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

void check_1D(vector<int>& ls);
void check_2D(vector<vector<int>>& ls);
int main() {
	ios::sync_with_stdio(false);
	//ここからコードを書く
	int r, g, b, n,count = 0;
	cin >> r >> g >> b >> n;
	
	for (int i = 0; i < n+1; i++) {
		for (int j = 0; j < n+1; j++) {
			if (r * i + g * j > n)continue;
			if ((n-(r*i + g*j)) % b == 0)count ++;
		}
	}
	cout << count << endl;
	//ここまで
}

//デバック用関数
//一次元の配列を出力する関数
void check_1D(vector<int>& ls) {
	int length = ls.size();
	for (int i = 0; i < length; i++) {
		cout << ls[i] << ' ';
	}
	cout << endl;
}
//二次元配列を出力する関数
void check_2D(vector<vector<int>>& ls) {
	for (int i = 0; i < ls.size(); i++) {
		for (int j = 0; j < ls[0].size(); j++) {
			cout << ls[i][j] << ' ';
		}
		cout << endl;
	}
}


//最大公約数
int gcd(int a, int b) {
	if (a < b)swap(a, b);
	if (a % b == 0)return a;
	else return gcd(b, a % b);
}
//最小公倍数
int lcm(int a, int b) {
	return a * b / gcd(a, b);
}

//エラトステネスの篩
int praime_number() {
	for (int i = 0; i < 100001; i++)praime_numbers[i] = true;
	for (int i = 0; i * i < 100001; i++) {
		if (i < 2) { praime_numbers[i] = false; continue; }
		if (praime_numbers[i]) {
			for (int j = i * 2; j < 100001; j += i) {
				praime_numbers[j] = false;
			}
		}
	}
}

//Union Find
class UnionFind {
public:
	//親の番号を格納する。親だった場合は-(その集合のサイズ)
	vector<int> Parent;

	//作るときはParentの値を全て-1にする
	//こうすると全てバラバラになる
	UnionFind(int N) {
		Parent = vector<int>(N, -1);
	}

	//Aがどのグループに属しているか調べる
	int root(int A) {
		if (Parent[A] < 0) return A;
		return Parent[A] = root(Parent[A]);
	}

	//自分のいるグループの頂点数を調べる
	int size(int A) {
		return -Parent[root(A)];//親をとってきたい]
	}

	//AとBをくっ付ける
	bool connect(int A, int B) {
		//AとBを直接つなぐのではなく、root(A)にroot(B)をくっつける
		A = root(A);
		B = root(B);
		if (A == B) {
			//すでにくっついてるからくっ付けない
			return false;
		}

		//大きい方(A)に小さいほう(B)をくっ付けたい
		//大小が逆だったらひっくり返しちゃう。
		if (size(A) < size(B)) swap(A, B);

		//Aのサイズを更新する
		Parent[A] += Parent[B];
		//Bの親をAに変更する
		Parent[B] = A;

		return true;
	}
};

//DFS(深さ優先探索)
class DFS {
	//n頂点数
	int n;
	//隣接リスト
	vector<vector<int>> ls;
	//経路復元のための配列
	vector<int> restore;
	DFS(int a) {
		n = a;
		ls = vector<vector<int>>(a + 1, vector<int>(0));
		restore = vector<int>(a + 1);
	}
	//有向辺を追加
	void append_edge(int from, int to) {
		ls[from].push_back(to);
	}
	void both_append_edge(int from, int to) {
		ls[from].push_back(to);
		ls[to].push_back(from);
	}
};

//BFS(幅優先探索)
class BFS {
	//n、頂点数
	int n;
	//隣接リスト
	vector<vector<int>> ls;
	//経路復元のための配列
	vector<int> restore;
	//各頂点への最短経路を格納する配列
	vector<int> shortest;
	BFS(int a) {
		n = a + 1;
		ls = vector<vector<int>>(a + 1, vector<int>(0));
		restore = vector<int>(a + 1);
		shortest = vector<int>(a + 1);
	}

	//有向辺を追加
	void append_edge(int from, int to) {
		ls[from].push_back(to);
	}

	//両方向辺を追加
	void both_append_edge(int a, int b) {
		ls[a].push_back(b);
		ls[b].push_back(a);
	}

	//始点と終点を指定して幅優先探索→最短の移動回数を返す。失敗なら-1
	//もしfinishに-1を指定するとおそらく全部のnodeへの最短ルートを得られる。
	int solve(int start, int finish) {
		vector<bool> check = vector<bool>(n + 1, true);
		queue<int> que;
		que.push(start);
		que.push(0);
		check[start] = false;
		restore[start] = -1;
		shortest[start] = 0;
		while (!que.empty())
		{
			int node = que.front();
			que.pop();
			int cost = que.front();
			que.pop();
			if (node == finish)return cost;
			int length = ls[node].size();
			for (int i = 0; i < length; i++) {
				if (check[ls[node][i]])continue;
				que.push(ls[node][i]);
				que.push(cost + 1);
				restore[ls[node][i]] = node;
				check[ls[node][i]] = false;
				shortest[ls[node][i]] = cost + 1;
			}
		}
		return -1;
	}
};

//ダイクストラ法
class Dijkstra {
	//n,頂点数
	int n;
	pair<ll, ll> pa;
	//隣接リスト
	vector<vector<pair<ll, ll>>> ls;
	//復元のための配列
	vector<ll> restore;
	//最短経路を格納する配列
	vector<ll> shortest;
	//a頂点数
	Dijkstra(int a) {
		n = a;
		ls = vector<vector<pair<ll, ll>>>(a + 1, vector < pair<ll, ll>>(0));
		restore = vector<ll>(a + 1);
		shortest = vector<ll>(a + 1, int_inf);
	}

	//片方向の辺を追加
	void append_edge(ll from, ll to, ll weight) {
		ls[from].push_back(make_pair(weight, to));
	}

	//両方向の辺を追加
	void  both_append_edge(ll from, ll to, ll weight) {
		ls[from].push_back(make_pair(weight, to));
		ls[to].push_back(make_pair(weight, from));
	}

	//最短経路を出す
	int solve(ll start) {
		//頂点を入れる優先度付きキュー
		priority_queue < pair<ll, ll>, vector<pair<ll, ll>>, greater< pair<ll, ll>>> pq;
		shortest[start] = 0;
		for (int i = 0; i < n; i++) {
			pq.push(make_pair(shortest[i], i));
		}
		while (!pq.empty())
		{
			pair<int, int> edge = pq.top();
			ll cost = edge.first;
			ll node = edge.second;
			ll length = ls[node].size();
			for (int i = 0; i < length; i++) {
				edge = ls[node][i];
				int alt = cost + edge.first;
				if (shortest[edge.second] > alt) {
					shortest[edge.second] = alt;
					restore[edge.second] = node;
					pq.push(make_pair(alt, edge.second));
				}
			}
		}
	}
};

//ワーシャルフロイド
class Warshall_Floyd {
	//頂点数
	int n;
	//グラフを隣接行列で持つ
	vector<vector<long long>> ls;
	Warshall_Floyd(int a) {
		ls = vector<vector<ll>>(a + 1, vector<ll>(a + 1, int_inf));
		n = a;
	}
	//有向の辺を追加
	void append_edge(ll from, ll to, ll weight) {
		ls[from][to] = weight;
	}
	//無向の辺を追加
	void both_append_edge(ll from, ll to, ll weight) {
		ls[from][to] = weight;
		ls[to][from] = weight;
	}
	//ワーシャルフロイド
	void solve() {
		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					ls[i][j] = min(ls[i][j], ls[i][k] + ls[k][j]);
				}
			}
		}
	}
};

//LCS　最長共通部分列
class LCS {
	vector<vector<int>> dp;
	string s, t;
	LCS(string a, string b) {
		s = a; t = b;
		dp = vector<vector<int>>(s.size() + 5, vector<int>(t.size() + 5, 0));
	}

	int go() {
		int slen = s.size(), tlen = t.size();
		for (int i = slen - 1; i >= 0; i--) {
			for (int j = tlen - 1; j >= 0; j--) {
				if (s[i] == t[j]) {
					dp[i][j] = dp[i + 1][j + 1] + 1;
				}
				else {
					dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
				}
			}
		}
		return dp[0][0];
	}
	//復元する
	string Restore() {
		string ans = "";
		int k = 0, l = 0, slen = s.size(), tlen = t.size();
		while (k < slen && l < tlen) {
			if (dp[k][l] == dp[k + 1][l]) {
				++k;
			}
			else if (dp[k][l] == dp[k][l + 1]) {
				++l;
			}
			else {
				ans += s[k];
				++k; ++l;
			}
		}
		return ans;
	}
};
