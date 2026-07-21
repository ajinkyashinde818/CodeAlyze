#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N=200000;

int n,a[N+9],b[N+9],p[2][N+9],ans[N+9];

int main(){
  scanf("%d",&n);
  for (int i=1;i<=n;++i)
	scanf("%d",&a[i]);
  for (int i=n;i>=1;--i)
	if (!p[0][a[i]]) p[0][a[i]]=i;
  for (int i=1;i<=n;++i){
	scanf("%d",&b[i]);
	if (!p[1][b[i]]) p[1][b[i]]=i;
  }
  int mx=0;
  for (int i=1;i<=n;++i)
	if (p[0][i]&&p[1][i]) mx=max(mx,p[0][i]-p[1][i]+1);
  for (int i=1;i<=n;++i) ans[(i+mx-1)%n+1]=b[i];
  for (int i=1;i<=n;++i)
	if (a[i]==ans[i]) {puts("No");return 0;}
  puts("Yes");
  for (int i=1;i<=n;++i)
	printf("%d ",ans[i]);
  puts("");
  return 0;
}
