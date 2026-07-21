#include<stdio.h>
int main(void)
{
	int e,y,y2,e2,i;
	char wa[5]="MTSH";
	int reki[5]={1868,1912,1926,1989,2017};
	scanf("%d %d",&e,&y);
	if(e==0){
		for(i=0;i<4;i++){
			if(y<reki[i+1]){
				e2=i;
				y2=y-reki[i]+1;
				break;
			}
		}
		printf("%c%d\n",wa[e2],y2);
	}
	else{
		y2=reki[e-1]+y-1;
		printf("%d\n",y2);
	}
	return 0;
}
