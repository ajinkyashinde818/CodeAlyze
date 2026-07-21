#include<stdio.h>

int main(){
	int k,s;
	int x = 0;
	int y = 0;
/*	int z = 0;	*/
	int count = 0;

	scanf("%d %d",&k,&s);

	for(x=0; x<=k; x++){
		for(y=0; y<=k; y++){
			if( 0 <= s-x-y && s-x-y <= k ) count++;
/*
			for(z=0; z<=k; z++){
				if( x+y+z == s ) count++;
			}
*/
		}
	}

	printf("%d\n",count);

	return 0;
}
