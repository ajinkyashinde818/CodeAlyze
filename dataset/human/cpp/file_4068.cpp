#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <climits>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <fstream>

#define DIV 1000000007

using namespace std;

long long N;
long long sx, sy, gx, gy;
long long x[1005];
long long y[1005];
long long r[1005];

vector<pair<double, int> >tree[1005];

int main(){
	cin >> sx >> sy >> gx >> gy;
	cin >> N;
	x[0] = sx;
	y[0] = sy;
	x[N+1] = gx;
	y[N+1] = gy;
	for(int i = 1; i <= N; i++){
		cin >> x[i] >> y[i] >> r[i];
	}


	for(int i = 0; i <= N + 1; i++){
		for(int j = 0; j <= N + 1; j++){
			double x1 = x[i];
			double y1 = y[i];
			double r1 = r[i];
			double x2 = x[j];
			double y2 = y[j];
			double r2 = r[j];
			double len = max(0.0, sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2)) - r1 - r2);
			tree[i].push_back(make_pair(len, j));
		}
	}

	/*
	for(int i = 0; i <= N + 1; i++){
		cout << "from " << i << endl;
		for(int j = 0; j < tree[i].size(); j++){
			cout << i << " -> " << tree[i][j].second << " : " << tree[i][j].first << endl;
		}
	}
	*/

	set<int> done;
	priority_queue<pair<double, int> , vector<pair<double, int> >, greater<pair<double, int> > > Q;

	Q.push(make_pair(0, 0));
	while(!Q.empty()){
		int dst = Q.top().second;
		double cost = Q.top().first;
		Q.pop();
		if(dst == N+1){
			printf("%.20f\n", cost);
			return 0;
		}
		if(done.count(dst) != 0){
			continue;
		}
		done.insert(dst);
		for(int i = 0; i < tree[dst].size(); i++){
			int next = tree[dst][i].second;
			double ncost = tree[dst][i].first;
			if(done.count(next) != 0){
				continue;
			}
			Q.push(make_pair(cost + ncost, next));
		}
	}
}
