#include<stdio.h>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;
int a[200008];
int main(void)
{
	long long sum1=0,sum2=0,min,q;
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		sum1=sum1+a[i];
	}	
	min=10e15;
	for(q=0;q<n-1;q++)
	{
		long long w;
		sum2=sum2+a[q];
		sum1=sum1-a[q];
		if(sum2-sum1>0)
			w=sum2-sum1;
		else
			w=sum1-sum2;
		if(min>w)
      		min=w;	
  }
	
	printf("%lld\n",min);	
	
	return 0;
 }
