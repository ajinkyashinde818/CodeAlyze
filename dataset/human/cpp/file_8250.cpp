#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
vector<int>g[110000];
int segtree[524288];
int query(int a,int b,int c,int d,int e){
	if(d<a||b<c)return 999999999;
	if(c<=a&&b<=d)return segtree[e];
	return min(query(a,(a+b)/2,c,d,e*2),query((a+b)/2+1,b,c,d,e*2+1));
}
void update(int a,int b){
	a+=262144;
	while(a){
		segtree[a]=min(segtree[a],b);
		a/=2;
	}
}
int rev[110000];
int num;
int sz;
int at[110000];
int e[300000];
int bfs[110000];
int left[110000];
void dfs(int a){
	at[a]=num;
	rev[num]=a;
	left[a]=sz;
	e[sz++]=num;
	num++;
	for(int i=0;i<g[a].size();i++){
		dfs(g[a][i]);
		e[sz++]=at[a];
	}
}
int main(){
	int a;scanf("%d",&a);
	for(int i=1;i<a;i++){
		int p;scanf("%d",&p);p--;
		g[p].push_back(i);
	}
	for(int i=0;i<524288;i++)segtree[i]=999999999;
	dfs(0);
	for(int i=0;i<sz;i++)update(i,e[i]);
	//for(int i=0;i<a;i++)printf("%d ",left[i]);printf("\n");
	//for(int i=0;i<a;i++)printf("%d ",at[i]);printf("\n");
	
	queue<int>Q;
	Q.push(0);
	long long ret=0;
	int last=0;
	while(Q.size()){
		int At=Q.front();Q.pop();
		ret+=bfs[At]+bfs[last]-2*bfs[rev[query(0,262143,min(left[At],left[last]),max(left[At],left[last]),1)]];
		last=At;
		for(int i=0;i<g[At].size();i++){
			bfs[g[At][i]]=bfs[At]+1;
			Q.push(g[At][i]);
		}
	}
	printf("%lld\n",ret);
}
