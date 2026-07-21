#include<stdio.h>
 
int main(){
    int n,k,i;
    char s[11];
    scanf("%d",&n);
    scanf("%s",&s);
    scanf("%d",&k);
	for(i=0;i<n;i++){
		if(s[k-1]==s[i]) printf("%c",s[i]);
		else printf("*");
	}
    return 0;
}
