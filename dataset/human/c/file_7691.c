#include <stdio.h>
#define N 100000

int main(void)
{
	int i=0;
	int buff[N];
	do {
		scanf("%d", &buff[i]);
		i++;
	} while(buff[i-1]!= 0);
	
	i = 0;
	while(buff[i] != 0){
		printf("Case %d: %d\n", i+1, buff[i]);
		i++;
	}

	return 0;

}
