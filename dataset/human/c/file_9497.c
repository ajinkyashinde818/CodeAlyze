#include <stdio.h>

int main(){
	long N,D,X,s[109],result=0,memo=0;
	int i,j,k;
	scanf("%ld%ld%ld",&N,&D,&X);
	
	for(i=0;i<N;i++)
	{
		scanf("%ld",&s[i]);
	}
	
	for(i=0;i<N;i++)
	{
		result=1+result+(D-1)/s[i];
	}
	
	
	printf("%ld",result+X);
	
	}
