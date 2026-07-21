#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <list>
#include <stack>
#include <set>
#include <map>
#include <algorithm>

#define int long long
#define MOD7 1000000007
#define MOD9 1000000009

#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(a) (a).begin(), (a).end()

using namespace std;

int nextInt() {int a; cin >> a; return a;}
char nextChar() {char a; cin >> a; return a;}
double nextDouble() {double a; cin >> a; return a;}
string nextString() {string a; cin >> a; return a;}

void inputVector(vector<int> &v, int &n) {rep(i,n){v.push_back(nextInt());}}
void inputVector(vector<double> &v, int &n) {rep(i,n){v.push_back(nextDouble());}}
void inputVector(vector<string> &v, int &n) {rep(i,n){v.push_back(nextString());}}

int N;
int xs, ys, xt, yt;
vector<int> x, y, r;
double d[1002][1002];

class QInfo {
public:
	int id;
	double dist;

	QInfo() {}
	QInfo(int id, double dist) {
		this->id = id;
		this->dist = dist;
	}

	bool operator< (const QInfo &a) const {
		return dist > a.dist;
	}
};

signed main() {
	cin >> xs >> ys >> xt >> yt;
	cin >> N;

	x.push_back(xs);
	y.push_back(ys);
	r.push_back(0);
	x.push_back(xt);
	y.push_back(yt);
	r.push_back(0);
	for (int i = 2; i <= N + 1; i++) {
		x.push_back(nextInt());
		y.push_back(nextInt());
		r.push_back(nextInt());
	}

	rep(i, N + 2) {
		d[i][i] = 0;
		for (int j = i + 1; j < N + 2; j++) {
			int dx = x[i] - x[j];
			int dy = y[i] - y[j];
			d[i][j] = max(0.0, sqrt(dx*dx + dy*dy) - r[i] - r[j]);
			d[j][i] = d[i][j];
		}
	}

	double minDist[1002];
	rep(i, 1002) {
		minDist[i] = -1;
	}

	priority_queue<QInfo> q;
	q.push(QInfo(0, 0));
	while (!q.empty()) {
		QInfo info = q.top(); q.pop();

		if (minDist[info.id] > -0.1 && info.dist > minDist[info.id]) continue;

		if (info.id == 1) {
			printf("%.10f\n", info.dist);
			break;
		}

		rep(i, N + 2) {
			if (i == info.id) continue;
			if (minDist[i] < -0.1 || minDist[i] > info.dist + d[info.id][i]) {
				minDist[i] = info.dist + d[info.id][i];
				q.push(QInfo(i, minDist[i]));
			}
		}
	}

    return 0;
}
