#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define _CRT_SECURE_NO_WARNINGS
#define TLong long long
#define TBMod 1000000007

int ASC(const void *a,const void *b){
	return strcmp(a,b);
}

int DESC(const void *a,const void *b){
	return strcmp(b,a);
}

int main(int argc, char const *argv[])
{
	char s[103],t[103];
	scanf("%s",s);	scanf("%s",t);
	qsort(s,strlen(s),sizeof(char),ASC);
	qsort(t,strlen(t),sizeof(char),DESC);
	if(strcmp(s,t) < 0)	puts("Yes");
	else puts("No");
	return 0;
}
