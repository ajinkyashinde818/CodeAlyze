#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;
int n;
int parent[20][100001];
vector<int> G[100001];
int depth[100001];

void init(){
	for(int k=0;k+1<20;k++){
		for(int v=1;v<=n;v++){
			if(parent[k][v]<0)parent[k+1][v]=-1;
			else parent[k+1][v]=parent[k][parent[k][v]];
		}
	}
}

int lca(int u,int v){
	if(depth[u]>depth[v])swap(u,v);
	for(int k=0;k<20;k++){
		if((depth[v]-depth[u])>>k & 1){
			v=parent[k][v];
		}
		if(u==v)return u;
	}
	for(int k=19;k>=0;k--){
		if(parent[k][u]!=parent[k][v]){
			u=parent[k][u];
			v=parent[k][v];
		}
	}
	return parent[0][u];
}

vector<int> route;
ll bfs(){
	init();
	queue<int> que;
	que.push(1);
	while(que.size()){
		int q=que.front();
		que.pop();
		route.push_back(q);
		for(int i=0;i<G[q].size();i++){
			int next=G[q][i];
			if(depth[next]>depth[q])que.push(next);
		}
	}
	ll res=depth[route[0]];
	for(int i=0;i<route.size()-1;i++){
		res+=(ll)depth[route[i]]+depth[route[i+1]]-depth[lca(route[i],route[i+1])]*2;
	}
	return res;
}

int dfs(int v,int d){
	depth[v]=d;
	for(int i=0;i<G[v].size();i++){
		if(depth[G[v][i]]==-1)dfs(G[v][i],d+1);
	}
}

int main(void){
	scanf("%d",&n);
	parent[0][1]=-1;
	for(int i=2;i<=n;i++){
		scanf("%d",&parent[0][i]);
		G[parent[0][i]].push_back(i);
	}
	memset(depth,-1,sizeof(depth));
	dfs(1,0);
	printf("%lld\n",bfs());
	return 0;
}
