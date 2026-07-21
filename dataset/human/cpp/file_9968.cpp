#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N=1e5+10;
const ll mod=1e9+7;

int n;
ll ans;
int vis[29];
char s[N];

void dfs(int k, ll sum) {
	if (k==26) {
		ans+=sum;
		ans%=mod;
		return;
	}
	if (vis[k])	dfs(k+1, sum*vis[k]%mod);
	dfs(k+1, sum);
}

int main() {
	scanf("%d", &n);
	scanf("%s", s+1);
	for(int i=1; i<=n; i++) {
		vis[s[i]-'a']++;
	}
	dfs(0, 1);
	cout<<ans-1<<endl;
	return 0;
}
