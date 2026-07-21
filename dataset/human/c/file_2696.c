#include <stdio.h>

int main() {
	int k,s;
	int ans=0;
	scanf("%d %d", &k, &s);
	for(int i=0; i<=k; i++){
		for(int j=0; j<=k; j++){
			if (s-i-j<=k && s-i-j>=0) ans++;
		}
	}
	printf("%d", ans);
	return 0;
}
