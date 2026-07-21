#include<cstdio>
#include<iostream>
#include<map>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
using namespace std;

const int maxn = 2e5 + 5;
long long sum[maxn],a[maxn],vis[maxn];

int main(){
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 1;i <= n;i++){
		sum[i] = sum[i - 1] + a[i];
	}
	for(int i = 1;i <= n - 1;i++){
		vis[i] = abs(sum[n] - sum[i] - sum[i]);
	}
	sort(vis + 1,vis + n);
	cout << vis[1];
}
