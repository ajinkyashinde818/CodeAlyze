#include <stdio.h>

int main(void)
{
	int n, k;
	char str[11];
	scanf("%d%*c%s%*c%d%*c", &n, str, &k);
	char tmp = str[k-1];
	int i;
	for(i=0;i<n;i++) {
		if(str[i] != tmp) str[i] = '*';
	}
	printf("%s", str);
	
	return 0;
}
