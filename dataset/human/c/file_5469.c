#include<stdio.h>

int main(void){
	
	int w,h,n,x=0,y=0,i,nowx,nowy,dx,dy,sum=0;
	
	scanf("%d %d %d",&w,&h,&n);
	
	
	for(i=0;i<n;i++){
		if(x==0&&y==0){
		scanf("%d %d",&x,&y);
		nowx = x;
		nowy = y;
		}else{
		nowx = x;
		nowy = y;
		scanf("%d %d",&x,&y);
			if(nowx>x&&nowy<y || nowx<x&&nowy>y){
				dx=nowx - x;
				dy=nowy - y;
				if(dx<0){
					dx=-1*dx;
				}
				if(dy<0){
					dy=-1*dy;
				}
				
				sum += dx+dy;
				
			}else{
				dx=nowx - x;
				dy=nowy - y;
				if(dx<0){
					dx=-1*dx;
				}
				if(dy<0){
					dy=-1*dy;
				}
				if(dx>dy){
					sum += dx;
				}else if(dx<dy){
					sum += dy;
				}else{
					sum += dx;
				}
			}
		}
	}
	
	printf("%d\n",sum);
return 0;
}
