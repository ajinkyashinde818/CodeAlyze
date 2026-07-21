#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
	char a[3];
	scanf("%s",a);
	if(a[0]=='9' || a[1] == '9'){
		printf("Yes\n");
	}
	else{
		printf("No\n");
	}
	return 0;
}
