#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int x,r,k;
	scanf("%d%d",&k,&r);
	if(k<=10)
	x=r+100*(10-k);
	else x=r;
	printf("%d",x);
	
 }
