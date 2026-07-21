#include <bits/stdc++.h>

using namespace std;

int n,i,j,nxt;
long long l,state;
char s[100005];

int node[2][400005];
bool mark[400005];

void insert(){
	int id = 0;
	int l1 = strlen(s);
	
	for(int ii = 0; ii < l1; ii++){
		if(node[s[ii] - '0'][id] == -1)
		node[s[ii] - '0'][id] = ++nxt;
		
		id = node[s[ii] - '0'][id];
	}
	
	mark[id] = 1;
}

long long grundy(long long lv){
	for(int ii = 0; ii <= 60; ii++){
		if(lv & (1LL << ii))
		return 1LL << ii;
	}
}

void solve(int id, long long lv){
	if(lv == 0LL) return;
	
	if(node[0][id] != -1){
		solve(node[0][id], lv - 1);
		if(mark[node[0][id]])
		state ^= grundy(lv - 1);
		mark[id] |= mark[node[0][id]];
	}
	
	if(node[1][id] != -1){
		solve(node[1][id], lv - 1);
		if(mark[node[1][id]])
		state ^= grundy(lv - 1);
		mark[id] |= mark[node[1][id]];
	}
}

int main(){
	scanf("%d%lld", &n, &l);
	
	memset(node, -1, sizeof(node));
	
	for(i = 0; i < n; i++){
		scanf("%s", s);
		insert();
	}
	
	solve(0, l + 1);
	
	if(state > 0LL)
	printf("Alice\n");
	else
	printf("Bob\n");
}
