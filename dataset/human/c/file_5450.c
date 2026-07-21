#include<stdio.h>

int main(){
	int i,j,n,x,y,px,py,dx,dy;
	int ans,w,h;
	
	scanf("%d%d%d",&w,&h,&n);
	scanf("%d%d",&px,&py);
	ans=0;
	for(i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		dx=x-px;
		dy=y-py;
		if(dx*dy>0){
			if(dx<0)dx=-1*dx;
			if(dy<0)dy=-1*dy;
			
			if(dy>=dx)ans+=dy;
			else ans+=dx;
		}
		else{
			if(dx<0)dx=-1*dx;
			if(dy<0)dy=-1*dy;
			ans+=dx+dy;
		}
		px=x;
		py=y;
	}
	printf("%d\n",ans);
	
	return 0;
}
