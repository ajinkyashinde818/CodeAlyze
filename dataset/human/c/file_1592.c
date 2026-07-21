#include<stdio.h>
#include<string.h>
char s[100001];
int main()
{
	int l,r,res=0,i;
	scanf("%s",s);
	l=0;r=strlen(s)-1;
	while(l<r)
    {
		if(s[l]==s[r]) {l++,r--;}
		else if(s[l]=='x') {res++,l++;}
		else if(s[r]=='x') {res++,r--;}
		else
		{
			puts("-1");
			return 0;
		}
	}
	printf("%d\n",res);
	return 0;
}
