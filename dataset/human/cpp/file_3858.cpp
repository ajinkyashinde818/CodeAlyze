#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <map>
#include <list>
#include <set>
#include <numeric>
#include <queue>
#include <stack>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <climits>
#include <cfloat>
#include <ctime>
#include <complex>
#include <cassert>
#include <array>
#include <bitset> 
#include <unordered_map>
#include <random>

using namespace std;
typedef long long LL;
typedef pair<double,int> P;

int N;
double xs[1002];
double ys[1002];
double rs[1002];
double ds[1002][1002];
double dist[1002];
int main() {
	cin >> xs[0] >> ys[0] >> xs[1] >> ys[1];
	cin >> N;
	N+=2;
	for(int i=2;i<N;i++){
		cin >> xs[i] >> ys[i] >> rs[i];
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			auto f=[](double x,double y){
				return sqrt(x*x+y*y);
			};
			double d=f(xs[i]-xs[j],ys[i]-ys[j]);
			ds[i][j]=max(0.0,d-rs[i]-rs[j]);
		}
	}
	for(int i=1;i<N;i++){
		dist[i]=1e30;
	}
	priority_queue<P,vector<P>,greater<P> > pq;
	pq.push(P(0,0));
	while(pq.size()){
		double d=pq.top().first;
		int p=pq.top().second;
		pq.pop();
		if(dist[p]<d)continue;
		for(int i=0;i<N;i++){
			double d2=d+ds[p][i];
			if(d2<dist[i]){
				dist[i]=d2;
				pq.push(P(d2,i));
			}
		}
	}
	cout.precision(18);
	cout << dist[1] << endl;


	return 0;
}
