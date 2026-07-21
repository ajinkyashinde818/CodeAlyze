#include <stdio.h>
int main(int argc, char *argv[])
{
	int n;
	scanf("%d",&n);
	int a=n/10;
	int b=n%10;
	int f=0;
	if(a==9)
	f=1;
	if(b==9)
	f=1;
	if(f==1)
	printf("Yes");
	else 
	printf("No"); 
	return 0;
}
