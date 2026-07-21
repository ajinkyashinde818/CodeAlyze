#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>

using namespace std;

int main(){
	long long sx, sy, gx, gy;
	static double dist[1002][1002];
	while(cin >> sx >> sy >> gx >> gy){
		int N; cin >> N;
		vector<long long> x(N+2), y(N+2), r(N+2);
		x[0] = sx, y[0] = sy, r[0] = 0;
		x[N+1] = gx, y[N+1] = gy, r[N+1] = 0;
		for(int i=1;i<=N;i++) cin >> x[i] >> y[i] >> r[i];
		for(int i=0;i<N+2;i++){
			dist[i][i] = 0.0;
			for(int j=i+1;j<N+2;j++){
				double dx = x[i] - x[j];
				double dy = y[i] - y[j];
				double d = sqrt(dx*dx + dy*dy);
				dist[i][j] = dist[j][i] = max(0.0, d - r[i] - r[j]);
			}
		}
		vector<int> visit(N+2, 0);
		vector<double> res(N+2, 1e18);
		res[0] = 0.0;
		for(int i=0;i<N+2;i++){
			int minIdx = -1;
			for(int j=0;j<N+2;j++){
				if(visit[j]) continue;
				if(minIdx == -1 || res[minIdx] > res[j]) minIdx = j;
			}
			visit[minIdx] = 1;
			for(int j=0;j<N+2;j++){
				res[j] = min(res[j], res[minIdx] + dist[minIdx][j]);
			}
		}
		printf("%.9lf\n", res.back());
	}
}
