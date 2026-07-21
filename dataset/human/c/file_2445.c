#include<stdio.h>

int main()
{
	char s[3];
	int count = 0;
	
	scanf("%s",s);
	
	if(s[0] == s[1]) count++;
	if(s[0] == s[2]) count++;
	if(s[1] == s[2]) count++;
	
	if(count != 0) printf("No\n");
	else printf("Yes\n");
	
	return 0;
}
