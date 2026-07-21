#include <bits/stdc++.h>
using std::cout;
using std::endl;
using std::cin;

std::vector<std::vector<std::pair<int, double>>> g;
int n;

double solve(){
	std::vector<double> min_cost(n, 1e18);
	std::priority_queue<std::pair<double, int>, std::vector<std::pair<double, int>>, std::greater<std::pair<double, int>>> qu;
	qu.push({0, 0}); min_cost[0] = 0;
	
	while(!qu.empty()){
		auto p = qu.top(); qu.pop();
		
		for(auto e : g[p.second]){
			if(p.first + e.second >= min_cost[e.first]) continue;
			min_cost[e.first] = p.first + e.second;
			qu.push({min_cost[e.first], e.first});
		}
	}
	
	return min_cost[1];
}

int main(){
	int sx, sy, gx, gy; cin >> sx >> sy >> gx >> gy;
	cin >> n; n += 2; g.resize(n);
	std::vector<double> a(n), b(n), c(n);
	for(int i = 2; i < n; i++) cin >> a[i] >> b[i] >> c[i];
	a[0] = sx, b[0] = sy, c[0] = 0;
	a[1] = gx, b[1] = gy, c[1] = 0;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < i; j++){
			double dist = sqrt((a[i] - a[j]) * (a[i] - a[j]) + (b[i] - b[j]) * (b[i] - b[j]));
			double circle = c[i] + c[j];
			dist = std::max(0.0, dist - circle);
			
			g[i].push_back({j, dist});
			g[j].push_back({i, dist});
		}
	}
	
	cout << std::fixed << std::setprecision(10);
	cout << solve() << endl;
	return 0;
}
