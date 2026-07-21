#include<stdio.h>
#include<string.h>
#include<iostream>
#include<string>
#include<complex>
#include<algorithm>
#include<vector>
#include<math.h>
#include<set>
#include<map>

int main()
{
	char x, y;
	scanf("%c %c", &x, &y);
	if (x < y)
		printf("<\n");
	else if (x == y)
		printf("=\n");
	else
		printf(">\n");
	
	return 0;
}
