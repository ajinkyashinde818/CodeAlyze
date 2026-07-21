#include<bits/stdc++.h>

using namespace std;
using ll = long long;
inline int ri() { int n; cin >> n; return n;}

//経路復元なしDijkstra法
template<class T> 
vector<T> dijkstra(int start, const vector<vector<pair<int,T>>>& Hen){
	T INF = numeric_limits<T>::max();
	int N = Hen.size();
	vector<T> dist(N, INF);
	dist[start] = 0;
	priority_queue<pair<T,int>, vector<pair<T,int>>, greater<pair<T,int>>> que;
	que.push({0, start});
	while(que.size()) {
		int ver = que.top().second;
		T cost = que.top().first; que.pop();
		if(cost != dist[ver])continue;
		for(auto i : Hen[ver]) {
			if(dist[i.first] > cost + i.second) {
				dist[i.first] = cost + i.second;
				que.push({dist[i.first], i.first});
			}
		}
	}
	return dist;
}


int main()
{
    vector<tuple<double, double, double>> pos;
    {
        double xa, ya, xb, yb; cin >> xa >> ya >> xb >> yb;
        pos.push_back({xa, ya, 0}), pos.push_back({xb, yb, 0});
    }
    int n; cin >> n;
 
    for(int i = 0; i < n; i++) {
        double x, y, r; cin >> x >> y >> r;
        pos.push_back({x, y, r});
    }
 
    vector<vector<pair<int,double>>> hen(n + 2);
    for(int i = 0; i < n + 2; i++) {
        for(int j = i + 1; j < n + 2; j++) {
            double xa, ya, ra, xb, yb, rb, dist;
            tie(xa, ya, ra) = pos[i], tie(xb, yb, rb) = pos[j];
            dist =  sqrt((xa - xb) * (xa - xb) + (ya - yb) * (ya - yb)) - (ra + rb);
            dist = max(dist, 0.0);
            hen[i].push_back({j, dist});
            hen[j].push_back({i, dist});
        }
    }
 
    cout << fixed <<setprecision(12) << dijkstra(0,hen)[1] << '\n';
 
 
}
