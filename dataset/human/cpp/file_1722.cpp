#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n,k;
vector<int> ans[maxn];
int main() {
	scanf("%d",&n);
	k = -1;
	for(int i=1;i<=n*2;i++) if((long long)i*(i-1)==n*2) k = i;
	if(k==-1) return !printf("No");
	printf("Yes\n");
	int x = 1, y = 2;
	for(int i=1;i<=n;i++) {
		ans[x].push_back(i);
		ans[y].push_back(i);
		y++;
		if(y==k+1) {
			x = x+1;
			y = x+1;
		}
	}
	printf("%d\n",k);
	for(int i=1;i<=k;i++) {
		printf("%d ",ans[i].size());
		for(auto t : ans[i]) printf("%d ",t);
		printf("\n");
	}
}
