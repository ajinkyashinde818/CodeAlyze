#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
char festival[500];
char curr;
int init()
{
int i;
i=0;
	while(curr != 10)
	{
		scanf("%c",&curr);
		festival[i]=curr;
		i++;
	}
return i;
}

int output(int i)
{
int j;
for(j=0;j<i-9;j++)
	printf("%c",festival[j]);
return 0;
}

int main(int argc, char *argv[]) 
{
int i;
i = init();
output(i);
return 0;
}
