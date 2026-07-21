#include <stdio.h>

int main(void){

	int k,s;
	int x,y,z;
	int count=0;
	scanf("%d %d", &k, &s);

	for(x=0; x<=k; x++){
		for(y=0; y<=k; y++){
			if(s-x-y<=k && s-x-y>=0){
				count++;
			}
		}
	}

	printf("%d\n",count);
	return 0;
}
