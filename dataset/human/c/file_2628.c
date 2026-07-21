#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	char  a[3];
	scanf("%c%c%c",& a[0], &a[1], &a[2]);
	if (a[0] != a[1] && a[0] != a[2] && a[1] != a[2])
		printf("Yes");
	else
		printf("No");	
return 0;
}
