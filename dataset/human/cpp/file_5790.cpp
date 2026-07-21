#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;
typedef struct pair<ll,ll> P;
typedef struct pair<int,P> P2;

P dp[100001]={};
ll r[100001]={};

ll d[1001]={};
int a[200001]={};
int main() {
	int n;
	ll l;
	cin>>n>>l;
	string str;
	ll lastn=1;
	for(int i=0;i<n;++i){
		cin>>str;
		ll pos=1;
		r[1]=0;
		for(int j=1;j<str.size()+1;++j){
			if(str[j-1]=='0'){
				if(dp[pos].first==0){
					lastn++;
					dp[pos].first=lastn;
					r[lastn]=j;
					pos=lastn;
				}else{
					pos=dp[pos].first;
				}
			}
			if(str[j-1]=='1'){
				if(dp[pos].second==0){
					lastn++;
					dp[pos].second=lastn;
					r[lastn]=j;
					pos=lastn;
				}else{
					pos=dp[pos].second;
				}
			}
		}
		dp[pos].first=pos;
	}
	ll res=0;
	for(int i=1;i<lastn+1;++i){

		if((dp[i].first!=i)&&((dp[i].first==0)||(dp[i].second==0))){
			ll d=l-r[i];
			ll g=1;
			while(d%2==0){
				g=g<<1;
				d=d/2;
			}
			res=res^g;
		}
	}
	if(res==0){
		cout<<"Bob"<<endl;
	}else{
		cout<<"Alice"<<endl;
	}
	return 0;
}
