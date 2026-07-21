#include<stdio.h>
int main(){
	int x, y, z, k, s;
	x=0;
	scanf("%d %d", &k,&s);
	for(z=0; z<=k; z++){
		for(y=0; y<=s-z&&y<=k; y++){
			if(s-z-y<=k){
				x++;
			}
		}
	}
	printf("%d", x);
	}
