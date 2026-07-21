#include <stdio.h>

int main(void){
	int n,k;;
	char s[11];
	scanf("%d",&n);
	scanf("%s",s);
	scanf("%d",&k);
	char x[2];
	x[0] = s[k-1];
	for(int i=0;i<n;i++){
		if(s[i]!=x[0])printf("*");
		else printf("%c",x[0]);
	}
	return 0;
}
