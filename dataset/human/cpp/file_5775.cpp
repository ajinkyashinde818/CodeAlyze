//ΔARC087E
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
const int N = 111111;
int n,w,s[N];
int tot,l[N],r[N],h[N];
char ch[N];
LL k;
int ad(int u){
	h[++tot]=h[u]+1;
	return tot;
}
void dfs(int u,int d){
	if(d==w)
		return;
	if(ch[d]=='0'){
		if(!l[u])
			l[u]=ad(u);
		dfs(l[u],++d);
	}
	else{
		if(!r[u])
			r[u]=ad(u);
		dfs(r[u],++d);
	}
}
LL lowbit(LL x){
	return x&-x;
}
int main()
{
	int i;
	LL ans;
	cin>>n>>k;
	s[0]=1;
	while(n--){
		scanf("%s",ch);
		w=strlen(ch);
		dfs(0,0);
	}
	ans=0;
	for(i=0;i<=tot;i=i+1)
		if((l[i]==0)^(r[i]==0))
			ans^=lowbit(k-h[i]);//,cout<<k-h[i]<<endl;
	if(ans==0)
		cout<<"Bob\n";
	else
		cout<<"Alice\n";
	return 0;
}
