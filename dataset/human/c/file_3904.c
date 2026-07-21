#include<stdio.h>
#include<stdlib.h>
#include<bits/stdc++.h>
int gcd(int a ,int b){
  	if(a%b==0)
  		return b;
  	else
  		return gcd(b,a%b);
}         

int main(void)
{
	int a,b,k,GCD,kk[101],j=0;
	scanf("%d %d %d",&a,&b,&k);
	GCD=gcd(a,b);
	for(int i=GCD;i>=1;i--){
		if(GCD%i==0) kk[j++]=i;
	}
	printf("%d\n",kk[k-1]);
 	return 0;
 }
