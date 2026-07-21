#include <stdio.h>
int main(){
int H,W,x,y;
	for(;;){
		scanf("%d %d",&H,&W);
		if(!H&&!W){
		break;
		}
		for(x=1;x<=H;x++){
			for	(y=1;y<=W;y++){
				if(x%2==1&&y%2==1||x%2==0&&y%2==0){
					printf("#");
				}
				else {
				printf(".");
				}
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}
