#include <bits/stdc++.h>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;

const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 5;

int n;
ll a[MAXN],f[MAXN][2];

int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d",&n);
	for(int i = 1;i <= n;i++)
	    scanf("%lld",&a[i]);
	f[1][0] = a[1];
	f[1][1] = -a[1];
	for(int i = 2;i <= n;i++){
		f[i][0] = max(f[i - 1][0] + a[i],f[i - 1][1] - a[i]);
		f[i][1] = max(f[i - 1][0] - a[i],f[i - 1][1] + a[i]);
	}
	printf("%lld\n",f[n][0]);
	return 0;
}
