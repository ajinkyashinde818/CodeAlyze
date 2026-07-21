#include <stdio.h>

int main(void) {
	int n,k,i;
	char s[15],c;
	scanf("%d",&n);
	scanf("%s",s);
	scanf("%d",&k);
	
	c = s[k-1];
	
	for(i=0;i<n;i++){
		if(s[i]!=c) s[i]='*';
	}
	printf("%s",s);
	return 0;
}
