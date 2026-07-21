//g++ -std=c++14 test.cpp -o test.out
 
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <cassert>
#include <algorithm>
#include <functional>
#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <stack>
#include <map> 
#include <unordered_map> 
#include <utility>
#include <limits.h>
#include <bitset>
#include <set>
using namespace std;
 
#define LL long long int
const LL INF = (1LL<<60);
const int INF_INT = 2147483647-1e6-1;
const LL mod = 1000000007ll;
const int mod_int = 1000000007;

double xs,ys,xt,yt;
LL N;
double x[1002],y[1002],r[1002];

double ans = 0;

void solve(){
	//pair<Ldouble,LL> = 点iまでの最短距離、i
	typedef pair<double,LL> DIST;
	N = N + 2;
	x[N-2] = xs; y[N-2] = ys; r[N-2] = 0;//始点
	x[N-1] = xt; y[N-1] = yt; r[N-1] = 0;//終点
	//ダイクストラ
	priority_queue<DIST,vector<DIST>,greater<DIST>> q;
	q.push(DIST(0,N-2));//スタート地点
	vector<double> dist(N,900000000000.0);
	dist[N-2] = 0;//スタート地点
	while(!q.empty()){
		double now_dist = q.top().first;
		LL now_node = q.top().second;
		q.pop();
		if(now_node==N-1) continue;//終点からはどこへも行かなくて良い
		for(int next_node=0;next_node<N;next_node++){
			double dx = x[next_node] - x[now_node];
			double dy = y[next_node] - y[now_node];
			double diff_dist = max(sqrt(dx*dx + dy*dy) - r[next_node] - r[now_node],0.0);
			double next_dist = now_dist + diff_dist;
			if(next_dist<dist[next_node]){
				dist[next_node] = next_dist;
				q.push(DIST(next_dist,next_node));
			}
		}
	}
	ans = dist[N-1];
}
 
int main(){
	cin >> xs >> ys >> xt >> yt;
	cin >> N;
	for(int i=0;i<N;i++) cin >> x[i] >> y[i] >> r[i];
 
    solve();

	cout << fixed << setprecision(10) << ans << endl;
    return 0;
}
