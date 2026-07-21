#include <iostream>
#include <cstdio>
using namespace std;
int n,r;
int main()
{
	scanf("%d %d",&n,&r);
	if (n>=10) return 0&printf("%d\n",r);
	else return 0&printf("%d\n",100*(10-n)+r);
	return 0;
}
