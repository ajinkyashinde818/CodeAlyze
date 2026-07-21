#include <stdio.h>

int main (int argc, const char * argv[]) {
	
	int h,w,i,j,n=0;
	while(1){
		scanf("%d %d",&h,&w);
		if(h==0&&w==0)break;
		
		for(i=0;i<h;i++){
			for(j=0;j<w;j++){
				n=i+j;
				if(n%2==0)printf("#");
				else printf(".");
				
			}
			printf("\n");
		}
		printf("\n");
	}
	
	
    return 0;
}
