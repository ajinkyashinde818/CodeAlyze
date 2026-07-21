#include <stdio.h>

int main(void){
	int k,s,res=0;
	int x,y,z;
	scanf("%d %d",&k,&s);
	for(x=0;x<=k;x++){
		for(y=0;y<=k;y++){
			z = s - x - y;
			if(0<=z && z<=k)res++;
		}
	}
	printf("%d\n",res);	
}
