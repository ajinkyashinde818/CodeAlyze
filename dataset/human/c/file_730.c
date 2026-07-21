#include <stdio.h>
#include <stdlib.h>
#define int long long
#define p (int)(1e9 + 7)

int MOD(int a){
	a %= p;
	return a >= 0 ? a : a + p;
}

signed main(){
	int N, i;
	scanf("%lld", &N);
	char *S = (char *)malloc(sizeof(char) * (N + 1));
	scanf("%s", S);
	int num[26];
	for(i = 0; i < 26; i++){
		num[i] = 1;
	}
	for(i = 0; i < N; i++){
		num[(int)S[i] - (int)'a']++;
	}
	int ans = 1;
	for(i = 0; i < 26; i++){
		ans = MOD(ans * num[i]);
	}
	printf("%lld\n", MOD(ans - 1));
	return 0;
}
