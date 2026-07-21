#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
//#include <chrono> //when you use, devide by 1e+9!!!!! auto end= chrono::system_clock::now()-st;  cout<<end.count()%1e+9<<endl;
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> LP;
typedef long double db;

#define fr first
#define sc second
#define pb push_back
#define rep(i,x) for(int i=0;i<x;i++)
#define rep1(i,x) for(int i=1;i<=x;i++)
#define rrep(i,x) for(int i=x-1;i>=0;i--)
#define rrep1(i,x) for(int i=x;i>0;i--)

ll N,C;
ll X[100000],V[100000];
ll dx[100000],dv[100000];
ll rx[100000],rv[100000];
ll dp[100000];//時計まわりどこまでで最大値
ll ans;
ll hoge,fuga;

void calc(){
	dv[0]=V[0];
	rv[N-1]=V[N-1];
	rep(i,N-1){
		dv[i+1]=dv[i]+V[i+1];
	}
	rrep(i,N-1){
		rv[i]=rv[i+1]+V[i];
	}
	dp[0]=max(0LL,V[0]-X[0]);
	rep(i,N-1){
		dp[i+1]=max(dv[i+1]-X[i+1],dp[i]);
	}
	ans=max(ans,max(dp[N-1],dv[N-1]-  (C-X[0])  ));
	rep(i,N-1){
		ans=max(ans, rv[i+1] - (C-X[i+1])*2 + dp[i]    );
	}

	
}

ll tv[100000],tx[100000];

int main()
{
	ans=0;
	cin>>N>>C;
	rep(i,N){
		cin>>X[i]>>V[i];
		rx[i]=C-X[i];
		tv[i]=V[i];
		tx[i]=X[i];
	}
	calc();
	rep(i,N){
		X[i]= C-tx[N-1-i];
		V[i]= tv[N-1-i];
		rx[i]=C-X[i];
	}
	calc();
	cout<<ans<<endl;
}
