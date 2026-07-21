#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int n,r;
int main(void) 
{
	scanf("%d%d",&n,&r);
	if(n<=10)
		printf("%d\n",1000-100*n+r);
	else
		printf("%d\n",r);
    return 0;
}
