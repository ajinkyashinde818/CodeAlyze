#include <stdio.h>

int main(){
	int a,b,i,j;

	while(1){
		scanf("%d %d",&a,&b);
		if(a==0 && b==0)break;
		for(i=0; i<a; i++){
			if(!(i%2)){
				for(j=0; j<b; j++){
					if(!(j%2)) printf("#");
					else printf(".");
				}
			}
			else{
				for(j=0; j<b; j++){
					if(j%2) printf("#");
					else printf(".");
			}
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}
