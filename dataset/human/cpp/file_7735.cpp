#include"stdio.h"
#include"iostream"
#include"string.h"
#include"string"
#include"math.h"
using namespace std;
int a[200005];
int main(){
	int N,i=0;
	long long sum=0,b=0,c=0,min;
	scanf("%d",&N);
	for(i=0;i<N;i++)
	scanf("%d",&a[i]),sum=sum+a[i];
		for(i=0;i<N-1;i++)
		{	b=b+a[i];
			c=sum-b;
			if(i==0)
			min=labs(b-c);
			if(labs(b-c)<labs(min))	min=labs(b-c);
		}
		printf("%ld",min);
		
	
	
	
	
	
	return 0;
}
