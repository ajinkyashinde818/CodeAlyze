#include<stdio.h>
int main()
{
	int K,S,X,Y,Z,i=0;
	scanf("%d %d",&K,&S);
	if(3*K<S){
		printf("0");
		return 0;
	}
	if(3*K==S){
		printf("1");
		return 0;
	}
	for(X=0;X<=K;X++){
		if(X>S)break;
		for(Y=X+1;Y<=K;Y++){
			if(X+Y>S)break;
			for(Z=Y+1;Z<=K;Z++)
			{
				if(X+Y+Z>S)break;
				if(X+Y+Z==S)i=i+6;
			}
		}
	}
	
	for(X=0;X<=K;X++){
		for(Z=0;Z<=K;Z++){
			if(X*2+Z>S)break;
			if(X==Z)continue;
			if(2*X+Z==S)i=i+3;
		}
	}
    for(X=0;X<=K;X++){
    	if(3*X>S)break;
    	if(3*X==S)i++;
	}
	printf("%d\n",i);
	return 0;
}
