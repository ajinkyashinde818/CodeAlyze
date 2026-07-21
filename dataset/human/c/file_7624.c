#include <stdio.h>

int main(void)
{
	int c=0,z,x[9999];
	
	while(1){
		scanf("%d",&x[c]);
		if(x[c] != 0){
			c = c+1;
		}
		else{
			z = c;
			break;
		}
	}
	
	for(c=0; c<z; c++){
		printf("Case %d: %d\n",c+1,x[c]);
	}
	
	return 0;
}
