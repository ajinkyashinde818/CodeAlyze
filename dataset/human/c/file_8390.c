#include <stdio.h>
#include<string.h>
int main(void) {
	// your code goes here
	int n,k,i;
	scanf("%d",&n);
	char str[n];
	scanf("%s",str);
	scanf("%d",&k);
	for(i=0;i<strlen(str);i++)
	{
	    if(str[i]!=str[k-1])
	    str[i]='*';
	}
	printf("%s",str);
	return 0;
}
