#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
const long long MOD = 1e9 + 7;
char s[N];

int main(){
	int n;
	scanf("%d%s", &n, s);
	int L = 0, R = 0;
	long long ans = 1;
	for (int i = 0; i < 2 * n; i++){
		int t = 2 * n - i - 1 + (s[i] == 'B');
		//printf("%d\n", t);
		if (t % 2 == 0){
			L++;
		} else {
			R++;
			if (R > L) return 0 * printf("0");
			ans = ans * (L - R + 1) % MOD; 
		}
	}
	if (L != R) ans = 0;
	for (int i = 1; i <= n; i++) ans = ans * i % MOD;
	printf("%lld", ans);
	return 0;
}	 

//(())
//
