#include<iostream>
#include<algorithm>
#include<functional>
#include<queue>
#include<vector>
#include<cmath>
#include<iomanip>

using namespace std;

typedef pair<double, int> P;

struct Edge {
	int to;
	double cost;
	Edge(int a, double b) { to = a, cost = b; }
};

struct shelter {
	double x, y, r;
	shelter(double a, double b, double c) {
		x = a, y = b, r = c;
	}
	shelter() { x - 0, y = 0, r = 0; }
};

double getdis(shelter A, shelter B) {
	double dis = sqrt(pow(A.x - B.x, 2) + pow(A.y - B.y, 2)) - A.r - B.r;
	if (dis > 0) return dis;
	else return 0;
}

double sx, sy, tx, ty;
int N;
vector<shelter> S;
vector<vector<Edge>> E;

double dis[1002];

void djk(int s) {

	for (int i = 0; i < N + 2; i++)dis[i] = 1000000000000000;

	priority_queue<P, vector<P>, greater<P>> pq;
	pq.push(P(0, s));
	dis[s] = 0.0;
	
	while (pq.size()) {
		P now = pq.top(); pq.pop();
		int pos = now.second;
		double totalcost = now.first;
		if (totalcost > dis[pos])continue;

		for (int i = 0; i < E[pos].size(); i++) {
			int nxt = E[pos][i].to;
			double cost = E[pos][i].cost;
			if (dis[nxt] > dis[pos] + cost) {
				dis[nxt] = dis[pos] + cost;
				pq.push(P(dis[nxt], nxt));
			}
		}
	}
}

int main() {
	cin >> sx >> sy >> tx >> ty;
	cin >> N;
	S.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> S[i].x >> S[i].y >> S[i].r;
	}

	E.resize(N + 2);
	E[0].push_back(Edge(N + 1, getdis(shelter(sx, sy, 0), shelter(tx, ty, 0))));
	for (int i = 0; i < N; i++) {
		E[0].push_back(Edge(i + 1, getdis(shelter(sx, sy, 0), S[i])));//どうせ最初のスタートに戻らないので一方通行の辺でもいい
		E[i + 1].push_back(Edge(N + 1, getdis(shelter(tx, ty, 0), S[i])));//上と同じ理由でゴールも一方通行
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j)continue;
			E[i + 1].push_back(Edge(j + 1, getdis(S[i], S[j])));
			E[j + 1].push_back(Edge(i + 1, getdis(S[j], S[i])));
		}
	}

	djk(0);

	cout << setprecision(12) << dis[N + 1] << endl;

	return 0;
}
