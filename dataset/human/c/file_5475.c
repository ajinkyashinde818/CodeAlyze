#include<stdio.h>
int main(void){
int W,H,N,i,x,y,x2,y2,xx,yy,a=0;
scanf("%d%d%d",&W,&H,&N);
for(i=0;i<N;i++){
scanf("%d%d",&x,&y);
if(i!=0){
xx=x-x2;
yy=y-y2;
if(xx<0){xx*=-1;}if(yy<0){yy*=-1;}
if(x>=x2&&y<=y2||x<=x2&&y>=y2){
a+=xx+yy;
}
else if(x>x2&&y>y2||x<x2&&y<y2){
	if(xx>yy){
	a+=yy+(xx-yy);
	}else if(xx<yy){
	a+=xx+(yy-xx);
	}else{
	a+=xx;
	}

}

}
x2=x;
y2=y;
}
printf("%d\n",a);
return 0;
}
