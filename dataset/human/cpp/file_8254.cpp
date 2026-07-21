#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <cfloat>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;

vector<int> G[100001];
int N;
int root;
int MAX_LOG_V = 17;

int** parent;
int* depth;
int* visit_order;

void dfs(int node_id,int parent_id,int d){
	parent[0][node_id] = parent_id;
	depth[node_id] = d;
	for(int i = 0; i < G[node_id].size(); i++){
		if(G[node_id][i] != parent_id)dfs(G[node_id][i],node_id,d+1);
	}
}

//?????????
void init(){
	dfs(root,-1,0);
	for(int k = 0; k + 1 < MAX_LOG_V; k++){
		for(int node_id = 0; node_id < N; node_id++){
			if(parent[k][node_id] < 0)parent[k+1][node_id] = -1;
			else{
				parent[k+1][node_id] = parent[k][parent[k][node_id]];
			}
		}
	}
}

int lca(int left,int right){
	if(depth[left] > depth[right])swap(left,right);
	for(int k = 0; k < MAX_LOG_V; k++){
		if((depth[right]-depth[left]) >> k & 1){
			right = parent[k][right];
		}
	}
	if(left == right)return left;
	for(int k = MAX_LOG_V-1; k >= 0; k--){
		if(parent[k][left] != parent[k][right]){
			left = parent[k][left];
			right = parent[k][right];
		}
	}
	return parent[0][left];
}

int main(){

	scanf("%d",&N);
	if(N == 1){
		printf("0\n");
		return 0;
	}

	int parent_id;

	for(int i = 2; i <= N; i++){
		scanf("%d",&parent_id);
		parent_id--;
		G[parent_id].push_back(i-1);
	}

	for(int i = 0; i < N; i++)sort(G[i].begin(),G[i].end());

	parent = new int*[MAX_LOG_V];
	for(int i = 0; i < MAX_LOG_V;i++)parent[i] = new int[N];
	depth = new int[N];
	root = 0;
	init();

	visit_order = new int[N];
	visit_order[0] = 0;

	queue<int> Q;
	int order = 1;
	for(int i = 0; i < G[0].size();i++){
		Q.push(G[0][i]);
	}

	while(!Q.empty()){

		visit_order[order++] = Q.front();
		for(int i = 0; i < G[Q.front()].size();i++){
			Q.push(G[Q.front()][i]);
		}
		Q.pop();
	}

	ll sum = 1;
	int lca_id;
	for(int i = 2; i < N; i++){
		lca_id = lca(visit_order[i-1],visit_order[i]);
		sum += (depth[visit_order[i-1]]-depth[lca_id])+(depth[visit_order[i]]-depth[lca_id]);
	}

	printf("%lld\n",sum);

	return 0;
}
