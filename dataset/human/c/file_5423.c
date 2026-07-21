#include<stdio.h>
int main(void)
{
	int a,b,n,x[10001],y[10001],i,j;
	int xx,yy,t;
	t=0;
	scanf("%d %d %d",&a,&b,&n);
	for(i=1;i<=n;i++){
		scanf("%d %d",&x[i],&y[i]);		
	}
	for(i=1;i<n;i++) {
		xx=x[i]-x[i+1];
		yy=y[i]-y[i+1];
		if(xx*yy<0) {
			if(xx<0) {
				xx=-xx;
			}
			if(yy<0) {
				yy=-yy;
			}
			t+=xx+yy;
		}
		else {
			if(xx<0) {
				xx=-xx;
			}
			if(yy<0) {
				yy=-yy;
			}
			if(xx>yy){
				t+=xx;
			}
			else{
				t+=yy;
			}
		}
	}
	printf("%d\n",t);
	return 0;
}
