#include <stdio.h>

int main(void) {
	int h,w;
	int i,j;
	char mark[2]={'#','.'};
	
	scanf("%d %d",&h,&w);
	while((h!=0)||(w!=0)){
		for(i=0;i<h;i++){
			for(j=0;j<w;j++){
				printf("%c",mark[(i+j)%2]);
			}
			printf("\n");
		}
		printf("\n");
		
		scanf("%d %d",&h,&w);
	}
	
	return 0;
}
