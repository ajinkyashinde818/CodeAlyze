#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare_int(const void *a, const void *b)
{
    return *(char*)a - *(char*)b;
}

int mcompare_int(const void *a, const void *b)
{
    return *(char*)b - *(char*)a;
}


int main()
{
	char s[101]={0}, t[101]={0};
    int i;

	scanf("%s",s);
	scanf("%s",t);
    qsort(s, strlen(s), sizeof(char), compare_int);
    qsort(t, strlen(s)+1, sizeof(char), mcompare_int);
	if (strcmp(s,t)<0) printf("Yes\n");
	else printf("No\n");
}
