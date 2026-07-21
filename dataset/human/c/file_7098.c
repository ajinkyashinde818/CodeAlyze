#include<stdio.h>
#include<math.h>

int main(void){
	int H,W,i,j,f,a,y;

	for(;;){
		for(;;){
			scanf("%d %d", &H, &W);
			if(H==0 && W==0){
				return 0;
			}
			if(1<=H && H<=300){
				f=1;
			}
			if(1<=W && W<=300){
				f++;
			}
			if(f==2){
				break;
			}
		}
		for(i=1;i<=H;i++){
			for(j=1;j<=W;j++){
				y=i+j;
				a=pow(-1,y);
				if(a==1){
					printf("#");
				}else{
					printf(".");
				}
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}
