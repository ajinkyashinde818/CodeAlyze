#include <stdio.h>

int main(){
	int n,k,i;
	char s[12]="";
	if(scanf("%d %s %d",&n,s,&k)!=3)return 1;
	k--;
	for(i=0;i<n;i++){
		if(s[i]!=s[k]){
			s[i]='*';
		}
	}
	printf("%s\n",s);
	return 0;
}
