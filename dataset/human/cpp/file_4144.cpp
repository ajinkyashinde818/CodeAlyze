#include <bits/stdc++.h>
using namespace std;

struct edge{
	int to;
	double dist;
};

int N;
long long xs,ys,xt,yt;
vector<vector<edge>> graph(1111);
vector<double> d(1111,1.0e40);

int main(){
	cin >> xs >> ys >> xt >> yt >> N;
	
	vector<long long> x;
	vector<long long> y;
	vector<long long> r;
	
	x.push_back(xs);
	y.push_back(ys);
	r.push_back(0);
	for(int i=0;i<N;i++){
		long long X,Y,R;
		cin >> X >> Y >> R;
		x.push_back(X);
		y.push_back(Y);
		r.push_back(R);
	}
	x.push_back(xt);
	y.push_back(yt);
	r.push_back(0);
	
	for(int i=0;i<N+1;i++)for(int j=i+1;j<N+2;j++){
		double D=sqrt(pow(x[i]-x[j],2)+pow(y[i]-y[j],2));
		D=max(0.0,D-(r[i]+r[j]));
		edge e={j,D};
		graph[i].push_back(e);
		e.to=i;
		graph[j].push_back(e);
	}
	
	d[0]=0.0;
	
	priority_queue<pair<double,int>,vector<pair<double,int>>,greater<pair<double,int>>> que;
	
	que.push(make_pair(0.0,0));
	
	while(!que.empty()){
		pair<double,int> p=que.top();
		que.pop();
		int v=p.second;
		if(d[v]<p.first)continue;
		for(auto e:graph[v]){
			if(d[e.to]>d[v]+e.dist){
				d[e.to]=d[v]+e.dist;
				que.push(make_pair(d[e.to],e.to));
			}
		}
	}
	
	printf("%.10f\n",d[N+1]);
	return 0;
}
