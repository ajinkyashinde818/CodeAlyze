#include <bits/stdc++.h>
using namespace std;
double distance(double x1, double y1, double r1, double x2, double y2, double r2){
	double tmp1 = r1 + r2;
	double tmp2 = pow((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2), 0.5); 
	return max((double) 0, tmp2 - tmp1); 
}
int main(){
	double X[1010] = {}; 
	double Y[1010] = {}; 
	double R[1010] = {}; 
	int N; 
	cin >> X[0] >> Y[0] >> X[1001] >> Y[1001] >> N; 
	for(int i = 1; i <= N; i++){
		cin >> X[i] >> Y[i] >> R[i]; 
	}
	double dist[1010][1010] = {}; X[N+1] = X[1001]; Y[N+1] = Y[1001]; 
	for(int i = 0; i <= N+1; i++){
		for(int j = 0; j <= N+1; j++){
			dist[i][j] = distance(X[i], Y[i], R[i], X[j], Y[j], R[j]); 
		}
	}
	double D[1010] = {}; 
	fill(D, D+N+2, 1941941145141919.19419); 
	D[0] = 0.0; 
	priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> que; 
	que.push(make_pair(D[0], 0)); 
	while(que.size()){
		pair<double, int> p = que.top(); que.pop();  
		for(int i = 0; i <= N+1; i++){
			if(p.second == i) continue; 
			if(D[i] > p.first + dist[p.second][i]){
				que.push(make_pair(p.first + dist[p.second][i], i)); 
				D[i] = p.first + dist[p.second][i]; 
			}
		}
	}
	cout.precision(20); 
	cout << D[N+1] << endl; 
}
