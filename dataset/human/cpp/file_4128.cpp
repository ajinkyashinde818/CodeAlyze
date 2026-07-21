#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include<queue>
#include<utility>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef double db;
typedef vector<db> vd;
typedef vector<vd> vvd;
typedef pair<db, int> P;
int main() {
	ll xs, ys, xt, yt;
	int n;
	cin >> xs >> ys >> xt >> yt;
	cin >> n; 
	n += 2;

	vl X(n), Y(n), R(n);
	for (int i = 1; i < n-1; i++) {
		cin >> X[i] >> Y[i] >> R[i];
	}
	X[0] = xs;
	X[n - 1] = xt;
	Y[0] = ys;
	Y[n - 1] = yt;
	R[0] = 0;
	R[n - 1] = 0;
	vvd C(n, vd(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			double d = sqrt((db)(X[i] - X[j])*(X[i] - X[j]) + (Y[i] - Y[j])*(Y[i] - Y[j]));
			C[i][j] = max((db)0, d - R[i] - R[j]);
		}
	}
	vd ANS(n, (db)10000000000);
	priority_queue<P> que;
	que.push(P((db)0, 0));
	while (!que.empty()) {
		P p = que.top(); que.pop();
		int v = p.second;
		db d = -p.first;
		if (d > ANS[v]) {
			continue;
		}
		for (int i = 0; i < n; i++) {
			if (ANS[i] > d + C[v][i]) {
				ANS[i] = d + C[v][i];
				que.push(P(-ANS[i], i));
			}
		}
	}

	cout.precision(13);
	cout << ANS[n - 1] << endl;

	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << C[i][j] << " ";
		}cout << endl;
	}*/
	return 0;
}
