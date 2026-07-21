#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <cmath>
#include <stdio.h>
using namespace std;

typedef pair<double,double> P;
typedef pair<P,double> PP;
int N;

double xs,ys,xt,yt;
double x,y,r;

double dist(P a, P b){
	return sqrt((a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second));
}
vector<PP> zahyou(1002);
int main(){
	cin >> xs >> ys >> xt >> yt;
	cin >> N;
	zahyou[0] = PP(P(xs,ys),0);
	zahyou[N+1] = PP(P(xt,yt),0);
	for(int i=1;i<=N;i++){
		cin >> x >> y >> r;
		zahyou[i] = PP(P(x,y),r);
	}
	vector<vector<pair<double,int>>> v(N+2);
	for(int i=0;i<N+1;i++){
		for(int j=i+1;j<N+2;j++){
			double d = dist(zahyou[i].first,zahyou[j].first);
			//cout << d << endl;
			v[i].push_back(make_pair(max(0.0,d-zahyou[i].second-zahyou[j].second),j));
			v[j].push_back(make_pair(max(0.0,d-zahyou[i].second-zahyou[j].second),i));
		}
	}
	priority_queue<pair <double,int> > P;
	P.push(make_pair(0,0));
	double C[N+2];
	double inf = 1e10;
	for(int i=0;i<N+2;i++){
		C[i] = inf;
	}
	C[0] = 0;
	while(!P.empty()){
		pair<double,int> t = P.top();
		int s = t.second;
		P.pop();
		if(C[s] < t.first) continue;
		for(int i=0;i<v[s].size();i++){
			pair<double,int> e = v[s][i];
			if(C[e.second] > C[s] + e.first){
				C[e.second] = C[s] + e.first;
				P.push(make_pair(-C[e.second],e.second));
			}
		}
	}
	printf("%.9f\n",C[N+1]);
}
