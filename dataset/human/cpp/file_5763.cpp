#include<bits/stdc++.h>
using namespace std;

const int N=100100;
typedef long long ll;
char s[N];
ll L,ans;
int n,d[N][2],cnt;

void dfs(int x,ll y){
	for(int i=0;i<2;++i)
		if(d[x][i])dfs(d[x][i],y-1);
		else if(y>0)ans^=y&-y;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>L;
	for(int i=1;i<=n;++i){
		cin>>s;
		for(int j=0,p=0;s[j];p=d[p][s[j]&1],++j)
			if(!d[p][s[j]&1])d[p][s[j]&1]=++cnt;
	}
	dfs(0,L);
	cout<<(ans?"Alice\n":"Bob\n");
	return 0;
}
