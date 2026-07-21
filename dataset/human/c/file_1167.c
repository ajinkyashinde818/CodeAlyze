#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)>(b)?(b):(a))

int cmp(const void*a, const void*b){
	return *(char*)a-*(char*)b;
}
int cmp2(const void *a, const void*b){
	return *(char*)b-*(char*)a;
}
int main(void){
	int i,j;
	char s[101],t[101];
	scanf("%s",s);
	scanf("%s",t);
	int sn = strlen(s);
	int tn = strlen(t);
	qsort(s,sn,sizeof(char),cmp);
	qsort(t,tn,sizeof(char),cmp2);
	printf("%s\n",strcmp(s,t)<0?"Yes":"No");
	return 0;
}
