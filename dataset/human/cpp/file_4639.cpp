#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
int n,r;
int main()
{
	scanf("%d%d",&n,&r);
	if (n>=10) printf("%d\n",r);
	else printf("%d\n",r+100*(10-n));
return 0;
}
