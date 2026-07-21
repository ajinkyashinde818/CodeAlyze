#include <stdio.h>
int main(){
	long long int N;
	char S;
	scanf("%lld",&N);
	char dummy;
	scanf("%c",&dummy);
	long long int i;
	long long int c[26];
	for(i=0;i<26;i++){
		c[i]=0;
	}
	int j;
	for(i=0;i<N;i++){
		scanf("%c",&S);
		j=(int)S-(int)'a';
		c[j]=c[j]+1;
	}
	long long int ans;
	ans=1;
	for(i=0;i<26;i++){
		ans=ans*(c[i]+1)%1000000007;
	}
	ans=ans-1;
	printf("%lld",ans);
}
