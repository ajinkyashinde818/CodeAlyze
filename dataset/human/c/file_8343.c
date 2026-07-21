#include<stdio.h>
#include<string.h>

int main(){
	int i,n,k;
	char s[11];
	scanf("%d",&n);
	scanf("%s",s);
	scanf("%d",&k);
	k--;
	for(i=0;i<n;i++){
		if(s[k]=='\0')break;
		if(s[k]!=s[i])s[i]='*';
	}
	printf("%s\n",s);
	return 0;
}
