#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int compare_int(const void *a, const void *b){return (int)(*(char*)a - *(char*)b);}
int compare_int_re(const void *a, const void *b){return (int)(-*(char*)a + *(char*)b);}

int main(void){
	char s[101],t[101];
	scanf("%s",&s);
	scanf("%s",&t);
	int x=strlen(s),y=strlen(t);
	qsort(s, x, sizeof(char), compare_int);
	qsort(t, y, sizeof(char), compare_int_re);
	
	if(strcmp(s,t)<0)	printf("Yes");
	else printf("No");
	return 0;
}
