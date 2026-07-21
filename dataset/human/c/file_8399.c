#include <stdio.h>

int main(void){
	int n;
	scanf("%d",&n);
	char s[n+1];
	scanf("%s",s);
	int k;
	scanf("%d",&k);
	
	for(int i=0;i < n;i++){
		if(s[i] != s[k-1]){
			s[i] = '*';
		}
	}
	printf("%s",s);
	return 0;
}
