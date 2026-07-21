#include<stdio.h>
#include <string.h>
#include <math.h>

int main(){
	int K,S;
	int X,Y,Z;
	int count=0;
	
	scanf("%d %d",&K,&S);
	
	for(X=0;X<=K;X++){
		for(Y=0;Y<=K;Y++){
			if(X+Y+K>=S && X+Y<=S){
					count++;
			}
		}
	}
	printf("%d\n",count);
	
	return 0;
}
