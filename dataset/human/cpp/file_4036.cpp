#include <bits/stdc++.h>

using namespace std;

int main(){
	int x[1002];
	int y[1002];
	int r[1002];
	r[0] = r[1] = 0;
	
	scanf("%d %d %d %d",&x[0],&y[0],&x[1],&y[1]);
	
	int n;
	scanf("%d",&n);
	n+=2;
	for(int i=2;i<n;i++){
		scanf("%d %d %d",x+i,y+i,r+i);
	}
	
	priority_queue<pair<double,int>, vector<pair<double,int>>, greater<pair<double,int>>> pq;
	
	vector<int> trace;
	
	double d[1002];
	for(int i=0;i<1002;i++) d[i] = DBL_MAX;
	pq.push(make_pair(0.0,0));
	while(!pq.empty()){
		double di = pq.top().first;
		int j = pq.top().second;
		pq.pop();
		//printf("%f %d\n",di,j);
		//if(find(trace.begin(),trace.end(),j) != trace.end()) continue;
		trace.emplace_back(j);
		if(d[j] > di){
			d[j] = di;
		} else {
			continue;
		}
		d[j] = min(d[j],di);
		for(int i=1;i<n;i++){
			//cout << x[j] << " " << x[i] << " " << y[j] << " " << y[i] << " " << r[i] << " " << r[j] << endl;
			double distance = di + max(hypot(x[j] - x[i],y[j] - y[i]) - r[i] - r[j],0.0);
			//cout << j << " - " << i << " " << distance << endl;
			pq.push(make_pair(distance,i));
		}
	}
	printf("%.10f\n",d[1]);
	return 0;
}
