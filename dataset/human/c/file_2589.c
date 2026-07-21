#include<stdio.h>
int main(void)
{
	char m[4];
	int i;
	int a = 0,b = 0;
	int c = 0;

	scanf("%c%c%c",&m[0],&m[1],&m[2]);
	
	for(i = 0;i < 3;i++){
		if(m[i] == 'a'){
			a++;
		}
		if(m[i] == 'b'){
			b++;
		}
		if(m[i] == 'c'){
			c++;
		}
	}


	if(a == 1 && b == 1 && c == 1)
		printf("Yes\n");
	else    printf("No\n");

	return 0;
}
