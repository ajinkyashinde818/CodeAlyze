#include<stdio.h>
int main(){
	int w,h,n,i;
	int xp,yp,x,y;
	int cnt=0;
	scanf("%d %d %d",&w,&h,&n);
	for(i=0;i<n;i++){
		scanf("%d %d",&x,&y);
		if(i==0){
			xp=x;
			yp=y;
		}
		while(xp!=x || yp!=y){
			if(xp<x && yp<y){
				xp++;
				yp++;
			}
			else if(xp>x && yp>y){
				xp--;
				yp--;
			}
			else if(yp<y)yp++;
			else if(yp>y)yp--;
			else if(xp<x)xp++;
			else if(xp>x)xp--;
			cnt++;
		}
	}
	printf("%d\n",cnt);
	return 0;
}
