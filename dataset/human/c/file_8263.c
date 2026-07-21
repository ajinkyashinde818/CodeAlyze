#include<stdio.h>
int main(void)
{
	int n, k, i;
	scanf("%d",&n);
	char s[n+1];
	scanf("%s",&s);
	scanf("%d",&k);
	for(i=0;i<n;i++){
		if(s[k-1]!=s[i]){
			s[i]='*';
		}
	}
	printf("%s",s);
	return 0;
}
