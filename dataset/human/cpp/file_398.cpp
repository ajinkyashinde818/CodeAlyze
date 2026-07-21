#include <bits/stdc++.h>

using namespace std;

int R, G, B, N;

bool isGood(int r, int g, int b){
	return (r % R == 0 && g % G == 0 && b % B == 0);
}

int main(){
	
	cin >> R >> G >> B >> N;
	int ans = 0;
	
	for(int i=0; i<=N; i++){
		for(int j=0; j<=i; j++){
			if(isGood(N-i, i-j, j)) ans++;
			//printf("r: %d, g: %d, b: %d\n", N-i, i-j, j);
		}
	}
	
	printf("%d\n", ans);
	
	return 0;
}
