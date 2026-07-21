#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<string>
#include<stack>
#include<cstdio>
#include<cmath>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<int,P> P1;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define rep(i,x) for(int i=0;i<x;i++)
#define rep1(i,x) for(int i=1;i<=x;i++)
#define rrep(i,x) for(int i=x-1;i>=0;i--)
#define rrep1(i,x) for(int i=x;i>0;i--)
#define sor(v) sort(v.begin(),v.end())
#define rev(s) reverse(s.begin(),s.end())
#define lb(vec,a) lower_bound(vec.begin(),vec.end(),a)
#define ub(vec,a) upper_bound(vec.begin(),vec.end(),a)
#define uniq(vec) vec.erase(unique(vec.begin(),vec.end()),vec.end())
#define mp1(a,b,c) P1(a,P(b,c))

const int INF=1000000000;
const int dir_4[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
const int dir_8[8][2]={{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};

ld dist(ld x1,ld y1,ld x2,ld y2){
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int main(){
	int n;
	int x[1005],y[1005],r[1005];
	scanf("%d%d%d%d%d",&x[0],&y[0],&x[1],&y[1],&n);
	r[0] = 0;
	r[1] = 0;
	rep1(i,n){
		scanf("%d%d%d",&x[i+1],&y[i+1],&r[i+1]);
	}
	
	static ld d[1005][1005];
	rep(i,n+2)rep(j,n+2){
		d[i][j] = max ( (ld)0.0 , dist(x[i],y[i],x[j],y[j])-r[i]-r[j] );
	}
	
	ld cost[1005];
	bool used[1005];
	priority_queue<pair<ld,int>,vector<pair<ld,int>>,greater<pair<ld,int>>> que;
	rep(i,1005){
		cost[i] = 10000000000.0;
		used[i] = false;
	}
	cost[0] = 0.0;
	que.push(pair<ld,int>(0.0,0));
	while(!que.empty()){
		pair<ld,int> p = que.top(); que.pop();
		if(!used[p.sc]){
			used[p.sc] = true;
			rep(i,n+2){
				if(cost[i] > cost[p.sc] + d[p.sc][i]){
					cost[i] = cost[p.sc]+d[p.sc][i];
					que.push(pair<ld,int>(cost[i],i));
				}
			}
		}
	}
	cout.precision(20);
	cout << cost[1] << endl;
}
