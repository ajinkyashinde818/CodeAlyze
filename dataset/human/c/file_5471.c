#include<stdio.h>
int main(void)
{
	int w,h,n,i,x[1000],y[1000],xsa,ysa,sum;
	scanf("%d %d %d",&w,&h,&n);
	for(i=0;i<n;i++){
		scanf("%d %d",&x[i],&y[i]);
	}
	sum=0;
	for(i=0;i<n-1;i++){
		xsa=x[i+1]-x[i];
		ysa=y[i+1]-y[i];
		if(xsa>=0&&ysa>=0||xsa<0&&ysa<0){
			if(xsa<0){
				xsa*=-1; ysa*=-1;
			}
			if(xsa>=ysa) sum+=xsa;
			else sum+=ysa;
		}
		if(xsa>=0&&ysa<0||xsa<0&&ysa>=0){
			if(xsa<0) xsa*=-1;
			if(ysa<0) ysa*=-1;
			sum+=xsa+ysa;
		}
	}
	printf("%d\n",sum);
	return 0;
}
