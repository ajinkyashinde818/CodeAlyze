#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;

vector<int> a[1010];

int main() {
	scanf("%d",&n);
	for (int x=1;x*x<=n*4;x++) if (x * (x-1) == n*2) {
		printf("Yes\n%d\n",x);
		int cnt = 0;
		for (int i=1;i<=x;i++) for (int j=i+1;j<=x;j++) {
			++cnt;
			a[i].push_back(cnt);
			a[j].push_back(cnt);
		}
		for (int i=1;i<=x;i++) {
			printf("%d ",a[i].size());
			for (int j=0;j<a[i].size();j++) printf("%d ",a[i][j]);
			putchar(10);
		}
		return 0;
	}
	puts("No");
}
