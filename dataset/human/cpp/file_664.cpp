#include<bits/stdc++.h>
using namespace std;

int R, G, B, n, ans;

int main(){
	scanf("%d %d %d %d", &R, &G, &B, &n);
	for(int r = 0; r <= n; ++r){
		for(int g = 0; g <= n; ++g){
			int rem = n-(R*r)-(G*g);
			if(rem < 0) continue;
			if(rem%B != 0) continue;
			ans++;
		}
	}
	printf("%d\n", ans);
}
