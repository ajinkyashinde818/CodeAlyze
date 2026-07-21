#include <bits/stdc++.h>
using namespace std;

const int MAXN=110000;

typedef long long ll;

ll c,n,ans=0,sum=0;

struct data{
	ll dis,val;
}d[MAXN];

ll f[MAXN][21],g[MAXN][21],lg[MAXN];

void get_log(int n){
    int log=0;
    for(int i=1;i<=n;i++){
        lg[i]=(1<<log+1==i)?++log:log;
    }
}

ll querymaxf(int l,int r){
	if(l>r)return 0;
    int k=lg[r-l+1];
    return max(f[l][k],f[r-(1<<k)+1][k]);
}

ll querymaxg(int l,int r){
	if(l>r)return 0;
    int k=lg[r-l+1];
    return max(g[l][k],g[r-(1<<k)+1][k]);
}

void get1(){
	ll sum=0;
    for(int i=1;i<=n;i++){
    	sum+=d[i].val;
        f[i][0]=sum-d[i].dis;
    }
    for(int i=1;(1<<i)<=n;i++){
        for(int j=1;j+(1<<i)-1<=n;j++){
            f[j][i]=max(f[j][i-1],f[j+(1<<(i-1))][i-1]);
        }
    }
}

void get2(){
	ll sum=0;
    for(int i=n;i>=1;i--){
    	sum+=d[i].val;
        g[i][0]=sum-(c-d[i].dis);
    }
    for(int i=1;(1<<i)<=n;i++){
        for(int j=1;j+(1<<i)-1<=n;j++){
            g[j][i]=max(g[j][i-1],g[j+(1<<(i-1))][i-1]);
        }
    }
}

ll baoli(int limit){
	ll sum=0,M=0;
	for(int i=1;i<=limit;i++){
		sum+=d[i].val;
		M=max(M,sum-d[i].dis);
	}
	return M;
}

int main(){
	scanf("%lld%lld",&n,&c);
	get_log(n);
    for(int i=1;i<=n;i++){
		scanf("%lld%lld",&d[i].dis,&d[i].val);
	}
	for(int i=1;i<=n;i++){
		sum+=d[i].val;
		ans=max(ans,sum-d[i].dis);
	}
	sum=0;
	for(int i=n;i>=1;i--){
		sum+=d[i].val;
		ans=max(ans,sum-(c-d[i].dis));
	}
	get1();
	get2();
	//两个拼起来 
	ll prepos=0,premax=0,tmpsum=0;
	//先顺时针走 
	for(int i=1;i<=n;i++){
		tmpsum+=d[i].val;
		if(tmpsum-(2*d[i].dis)>0){
			premax=tmpsum-(2*d[i].dis);
		//	cout<<premax<<"a"<<endl;
			ans=max(ans,premax+querymaxg(i+1,n));
		}	
	}
	
	prepos=0,premax=0,tmpsum=0;
	//再走逆时针
	for(int i=n;i>=1;i--){
		tmpsum+=d[i].val;
		if(tmpsum-(2*(c-d[i].dis))>0){
			premax=tmpsum-(2*(c-d[i].dis));
			ans=max(ans,premax+querymaxf(1,i-1));
		//	ans=max(ans,premax+baoli(i-1));
		}
	}
	cout<<ans<<endl;
	return 0;
 }
