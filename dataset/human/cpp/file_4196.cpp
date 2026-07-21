#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

inline double pow2(double x){
	return x * x;
}

int main(){
	ios_base::sync_with_stdio(false);
	cout << setiosflags(ios::fixed) << setprecision(10);
	double xs, ys, xt, yt;
	int n;
	cin >> xs >> ys >> xt >> yt >> n;
	vector<double> xb(n), yb(n), rb(n);
	for(int i = 0; i < n; ++i){
		cin >> xb[i] >> yb[i] >> rb[i];
	}
	vector<vector<double>> mat(n, vector<double>(n));
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			const double d = sqrt(pow2(xb[i] - xb[j]) + pow2(yb[i] - yb[j]));
			mat[i][j] = mat[j][i] = max(0.0, d - rb[i] - rb[j]);
		}
	}
	vector<double> dist(n);
	for(int i = 0; i < n; ++i){
		const double d = sqrt(pow2(xb[i] - xs) + pow2(yb[i] - ys));
		dist[i] = max(0.0, d - rb[i]);
	}
	vector<bool> done(n);
	for(int i = 0; i < n; ++i){
		int u = -1;
		for(int j = 0; j < n; ++j){
			if(done[j]){ continue; }
			if(u < 0 || dist[j] < dist[u]){ u = j; }
		}
		done[u] = true;
		for(int v = 0; v < n; ++v){
			dist[v] = min(dist[v], dist[u] + mat[u][v]);
		}
	}
	double answer = sqrt(pow2(xs - xt) + pow2(ys - yt));
	for(int i = 0; i < n; ++i){
		const double d = sqrt(pow2(xb[i] - xt) + pow2(yb[i] - yt));
		answer = min(answer, dist[i] + max(0.0, d - rb[i]));
	}
	cout << answer << endl;
	return 0;
}
