#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cmath>
#include<cctype>
#include<set>
#include<queue>
#include<vector>
#include<map>
using namespace std;
typedef long long LL;

inline int read() {
	int x=0,f=1;char ch=getchar();for(;!isdigit(ch);ch=getchar())if(ch=='-')f=-1;
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';return x*f;
}

const int mod = 1e9 + 7;
char s[200005];
int cnt[100];
LL ans = 0;

void dfs(int x,LL now) {
	if (x == 26) { 
		ans = (ans + now) % mod;
		ans = (ans + 1ll * now * cnt[26] % mod) % mod;
		return ; 
	}
	if (cnt[x]) dfs(x + 1, 1ll * now * cnt[x] % mod);
	dfs(x + 1, now);
}
int main() {
//	freopen("a.in", "r", stdin);
	int n = read();
	scanf("%s", s + 1);
	for (int i = 1; i <= n; ++i) cnt[s[i] - 'a' + 1] ++;
	dfs(1, 1);
	cout << (ans - 1 + mod) % mod;
	return 0;
}
