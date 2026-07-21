#include <bits/stdc++.h>
using namespace std;
int n,Ans[1000][1000],cnt[1000];

int main() {
	cin>>n;
	int k=0;
	for(int i=1;i*(i-1)/2<=n;i++)
		if(i*(i-1)/2==n) k=i;
	if(!k) return puts("No"),0;
	printf("Yes\n%d\n",k);
	for(int i=1,id=1;i<=k;i++)
		for(int j=i+1;j<=k;j++) {
			Ans[i][++cnt[i]]=id;
			Ans[j][++cnt[j]]=id;
			id++;
		}
	for(int i=1;i<=k;i++) {
		printf("%d ",k-1);
		for(int j=1;j<k;j++)
			printf("%d ",Ans[i][j]);
		puts("");
	}
	return 0;
}
