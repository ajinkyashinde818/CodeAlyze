#include<stdio.h>
int main(void)
{
	int w,h,n,i,x,y,z=0,a[1001],b[1001];
	scanf("%d %d %d",&w,&h,&n);
	for(i=0;i<n;i++) scanf("%d %d",&a[i],&b[i]);
	for(i=0;i<n-1;i++){
		x=a[i+1]-a[i]; y=b[i+1]-b[i];
		if(x>=0&&y>=0||x<0&&y<0){
			if(x<0){
				x=x*-1; y=y*-1;
			}
			if(x>=y) z+=x;
			else z+=y;
			
		}
		if(x>=0&&y<0||x<0&&y>=0){
			if(x<0) x=x*-1;
			if(y<0) y=y*-1;
			z+=x+y;
		}
	}
	printf("%d\n",z);
	return 0;
}
