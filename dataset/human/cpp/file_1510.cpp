#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+10;
vector<int>a[MAXN];
int n,t;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n*2;i++) if (i*(i-1)/2==n) {
		t=i; break;
	}
	else if (i*(i-1)/2>n) {
		printf("%s\n","No"); return 0;
	}
	printf("%s\n","Yes");
	a[1].push_back(1); a[2].push_back(1);
	for (int i=3;i<=t;i++) {
		int s=(i-1)*(i-2)/2;
		for (int j=s+1;j<=s+i-1;j++) {
			a[i].push_back(j); a[j-s].push_back(j);
		}
	}
	printf("%d\n",t);
	for (int i=1;i<=t;i++) {
		int len=a[i].size();
		printf("%d ",len);
		for (int j=0;j<len;j++)
		 printf("%d ",a[i][j]);
		printf("\n"); 
	}
}
