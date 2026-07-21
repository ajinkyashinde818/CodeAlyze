#include<stdio.h>
#include <string.h>
int main()
{
	char a[4];
	int i;
	gets(a);
	
	if(!strcmp(a, "abc")){
		printf("Yes");
	}
	else if(!strcmp(a, "acb")){
		printf("Yes");
	}
	else if(!strcmp(a, "bac")){
		printf("Yes");
	}
	else if(!strcmp(a, "bca")){
		printf("Yes");
	}
	else if(!strcmp(a, "cab")){
		printf("Yes");
	}
	else if(!strcmp(a, "cba")){
		printf("Yes");
	}
	else{
		printf("No");
	}
	return 0;
}
