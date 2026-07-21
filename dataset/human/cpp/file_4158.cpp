/*
 * 16-12-4_AOJ064_E.cpp
 *
 *  Created on: 2016/12/04
 *      Author: ryoma
 */
#include<iostream>
#include<algorithm>
#include<queue>
#include<limits.h>
#include<math.h>
#include<iomanip>
using namespace std;

typedef pair<double,int> Pdi;

const long long INF = (long long)1e9*4+1;

double G[1010][1010];
int xs,ys,xt,yt;
int N;
int x[1010],y[1010],r[1010];
double d[1010];

void dijkstra(){
	fill(d,d+N+2,INF);
	d[0] = 0;
	priority_queue<Pdi> que;
	que.push(make_pair(0,0));
	while(!que.empty()){
		Pdi p = que.top();
		que.pop();
		int v = p.second;
		if(d[v] < -p.first)
			continue;
		for(int i=0;i<=N+1;i++){
			if(i==v)
				continue;
			if(d[i] > d[v] + G[v][i])
			{
				d[i] = d[v] + G[v][i];
				que.push(make_pair(-d[i],i));
			}
		}
	}
}

int main(){
	cin >> xs >> ys >> xt>> yt;
	x[0] = xs;
	y[0] = ys;
	cin >> N;
	for(int i=1;i<=N;i++){
		cin >> x[i] >> y[i] >> r[i];
	}
	x[N+1] = xt;
	y[N+1] = yt;
	for(int i=0;i<=N+1;i++){
		for(int j=i+1;j<=N+1;j++){
			double dis=sqrt((long long)(x[i]-x[j])*(x[i]-x[j])+(long long)(y[i]-y[j])*(y[i]-y[j]));
			dis -= r[i]+r[j];
			G[j][i] = G[i][j] = max(dis,0.);
		}
	}
	dijkstra();
	cout << fixed<<setprecision(11) << d[N+1] << endl;
	return 0;
}
