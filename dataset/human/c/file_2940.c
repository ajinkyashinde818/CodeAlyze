#include<stdio.h>
int min(int a, int b);
int max(int a, int b);
int K, S, ans, i, l;
int main(){
	scanf("%d%d", &K, &S);
	for(i=max(S-K, 0), l=min(K<<1, S); i<=l; i++){
		ans+=min((K<<1)-i+1, i+1);
	}
	printf("%d\n", ans);
}

int min(int a, int b){
	return a>b?b:a;
}
int max(int a, int b){
	return a<b?b:a;
}
