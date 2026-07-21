#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

long long int x[200000], v[200000], path[200000], pathD[200000];

int main() {
	
	long long int N, C;
	long long int ans = 0;
	
	cin >> N >> C;
	
	for(int i = 0; i < N; i++){
		cin >> x[i] >> v[i];
	}
	
	path[0] = 0;
	path[1] = v[0] - x[0];
	for(int i = 1; i < N; i++){
		path[i + 1] = path[i] + v[i] - x[i] + x[i - 1];
	}
	
	for(int i = 1; i <= N; i++){
		path[i] = max(path[i], path[i - 1]);
	}
	
	reverse(x, x + N);
	for(int i = 0; i < N; i++){
		x[i] = C - x[i];
	}
	reverse(v, v + N);
	
	pathD[0] = 0;
	ans = max(ans, path[N]);
	pathD[1] = v[0] - 2 * x[0];
	ans = max(ans, pathD[1] + path[N - 1]);
	for(int i = 1; i < N; i++){
		pathD[i + 1] = pathD[i] + v[i] - 2 * (x[i] - x[i - 1]);
		ans = max(ans, pathD[i + 1] + path[N - i - 1]);
		//cout << pathD[i + 1] << " " << path[N - i - 1] << endl;
	}
	
	// check reverse direction
	
	path[0] = 0;
	path[1] = v[0] - x[0];
	for(int i = 1; i < N; i++){
		path[i + 1] = path[i] + v[i] - x[i] + x[i - 1];
	}
	
	for(int i = 1; i <= N; i++){
		path[i] = max(path[i], path[i - 1]);
	}
	
	reverse(x, x + N);
	for(int i = 0; i < N; i++){
		x[i] = C - x[i];
	}
	reverse(v, v + N);
	
	pathD[0] = 0;
	ans = max(ans, path[N]);
	pathD[1] = v[0] - 2 * x[0];
	ans = max(ans, pathD[1] + path[N - 1]);
	for(int i = 1; i < N; i++){
		pathD[i + 1] = pathD[i] + v[i] - 2 * (x[i] - x[i - 1]);
		ans = max(ans, pathD[i + 1] + path[N - i - 1]);
		//cout << pathD[i + 1] << " " << path[N - i - 1] << endl;
	}
	
	cout << ans << endl;
	
	return 0;
}
