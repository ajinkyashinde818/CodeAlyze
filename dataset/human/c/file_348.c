#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX(a,b) ((a)>(b)?(a):(b)) 


int main()
{
	int N,R;
	scanf("%d%d",&N,&R);
	if(N>=10)printf("%d",R);
	else printf("%d",R+100*(10-N));
	return 0;
}
