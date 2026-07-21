#include "bits/stdc++.h"
using namespace std;

int N;
pair<double, double> P[1010];
double R[1010];
double Dis[1010];
double INF = 1000000000000000000;
static double Root[1010][1010] = {};
bool Search[1010] = {};

void BFS() {
	Dis[0] = 0;
	for (int i = 1; i <= N + 1; i++) {
		Dis[i] = INF;
		Search[i] = true;
	}
	queue<int> Q;
	Q.push(0);
	while (Q.size()) {
		int q = Q.front();
		Q.pop();
		for (int i = 0; i <= N + 1; i++) {
			double qi_dis = Dis[q] + Root[q][i];
			if (qi_dis < Dis[i]) {
				Dis[i] = qi_dis;
				Q.push(i);
			}
		}
		Search[q] = false;
	}
}

int main() {
	double sx, sy, gx, gy;
	cin >> sx >> sy >> gx >> gy >> N;
	P[0] = { sx, sy }, R[0] = 0.0;
	for (int i = 1; i <= N; i++) {
		cin >> P[i].first >> P[i].second >> R[i];
	}
	P[N + 1] = { gx, gy }, R[N + 1] = 0.0;
	for (int i = 0; i <= N + 1; i++) {
		for (int j = i; j <= N + 1; j++) {
			double disx = P[i].first - P[j].first;
			double disy = P[i].second - P[j].second;
			Root[i][j] = Root[j][i] = max(0.0, sqrt(disx * disx + disy * disy) - R[i] - R[j]);
		}
	}
	BFS();
	printf("%.12f", Dis[N + 1]);
}
