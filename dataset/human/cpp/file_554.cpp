#include <bits/stdc++.h>

using namespace std;

int r, g, b, n;
int k;

int main(){
	scanf("%d%d%d%d", &r, &g, &b, &n);

	for(int i = 0; i*r <= n; i++){
		for(int j = 0; j*g <= n; j++){
			if(n - i*r - j*g < 0) break;

			if((n - i*r - j*g) % b == 0) k++;
		}
	}

	printf("%d\n", k);
	
	return 0;
}
