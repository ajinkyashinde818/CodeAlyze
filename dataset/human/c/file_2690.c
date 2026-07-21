#include <stdio.h>

int main(){
	int K,S;
	scanf("%d %d",&K,&S);

	int x,y,z;
	int xy,num=0;

	for(x=0;x<=K;x++){
		y=0;
		if(x>S)break;
		xy=S-x;
		for(y=0;y<=K;y++){
			if(y>xy)break;
			if(xy-y<=K)num++;
		}
	}
	printf("%d",num);
}
