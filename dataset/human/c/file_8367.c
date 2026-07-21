#include <stdio.h>
#include <string.h>
int main(void){
	int n,k;
	scanf("%d",&n);
	char S[n+1];
	scanf("%s",S);
	scanf("%d",&k);
	char mozi=S[k-1];
	for(int i=0;i<n;i++){
		if(S[i]==mozi)printf("%c",S[i]);
		else printf("*");
	}
	
	return 0;
}
