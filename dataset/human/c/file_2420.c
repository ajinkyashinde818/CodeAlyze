#include<stdio.h>
#include<string.h>
int main(void)
{
	char s[4];
	
	scanf("%s",s);
	
	if(strchr(s,'a')!=NULL && strchr(s,'b')!=NULL && strchr(s,'c')!=NULL) printf("Yes");
	else printf("No");
	
	return 0;
}
