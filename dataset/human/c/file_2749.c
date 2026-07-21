#include<stdio.h>
#include<string.h>
#include<math.h>
#include<limits.h>

int main(){
	int k,s,x,y,z;
	int pattern=0;
	scanf("%d %d",&k,&s);
	
	for(x=0;x<=k;x++){
		for(y=0;y<=k;y++){
			if(x+y>s){
				break;
			}
			z=s-x-y;
			if(z<=k){
				pattern++;
			}
		}
	}
	
	printf("%d\n",pattern);
	
	return 0;
}
