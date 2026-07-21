#include<bits/stdc++.h>
using ll = int_fast64_t;
using P = std::pair<ll,ll>;

int main(){
	int r, g, b, n, ans = 0;
	scanf("%d %d %d %d", &r, &g, &b, &n);
	for(int i=0; i<=n; i++){
		for(int j=0; j<=n; j++){
			if(i*r + j*g > n) continue;
			if((n-i*r-j*g)%b==0) ans++;
		}
	}
	printf("%d\n", ans);
}
