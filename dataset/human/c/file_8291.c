#include<stdio.h>

int main(){
	int n,i,k;
	char s[100],t;
	scanf("%d%s%d",&n,s,&k);
	t=s[k-1];
	for(i=0;i<n;i++){
		if(s[i]!=t)printf("*");
		else printf("%c",s[i]);
	}
	puts("");
	return 0;
}
