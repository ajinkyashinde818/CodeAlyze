#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <math.h>
#include <map>
#include <set>
using namespace std;
int main ()
{
	int a,b;
	scanf("%i%i",&a,&b);
	if(a>9)	printf("%i",b);
	else printf("%i",b+100*(10-a));
	return 0;
}
