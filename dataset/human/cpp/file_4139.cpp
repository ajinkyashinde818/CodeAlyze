#include<iostream>
#include<algorithm>
#include<queue>
#include<math.h>
#include<iomanip>
using namespace std;
typedef pair<double,int> P;
double x[1010],y[1010],r[1010];
double D(int a,int b){
	double cnt=(x[a]-x[b])*(x[a]-x[b]);
	cnt+=(y[a]-y[b])*(y[a]-y[b]);
	cnt=(double)sqrt((double)cnt);
	return max(0.0,cnt-r[a]-r[b]);
}
int main(){
int n;
bool vis[1010];
priority_queue<P,vector<P>,greater<P> >Q;
	cin>>x[0]>>y[0]>>x[1]>>y[1]>>n;
	for(int i=2;i<n+2;i++)cin>>x[i]>>y[i]>>r[i];
	for(int i=0;i<=n+1;i++)vis[i]=false;
	Q.push(make_pair(0.0,0));
	while(!Q.empty()){
		double a=Q.top().first;int b=Q.top().second;
		Q.pop();
		if(!vis[b]){
			if(b==1){
				cout<<fixed<<setprecision(10)<<a<<endl;
			}
			vis[b]=true;
			for(int i=0;i<n+2;i++){
				if(vis[i]==false){
					Q.push(make_pair(a+D(i,b),i));
				}
			}
		}
	}
	return 0;
}
