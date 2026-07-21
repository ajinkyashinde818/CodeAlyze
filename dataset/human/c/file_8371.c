#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int n,k;
	char s[11],sp[11];
	char tmp;
	
	scanf("%d",&n);
	scanf("%s",&s);
	scanf("%d",&k);
	
	tmp = s[k-1];
	
	for(int i=0;i<n;i++){
		if(tmp != s[i]) sp[i] = '*';
		else sp[i] = s[i];
	}
	
	sp[n] = '\0';
	
	printf("%s\n",sp);
	
	return 0;
}
