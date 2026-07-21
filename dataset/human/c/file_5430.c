#include<stdio.h>
int main(void)
{
	int h,w,n;
	int i,j;
	int x,y,x1,y1,a,b;
	int c=0;
	
	scanf("%d %d %d",&w,&h,&n);
	scanf("%d %d",&x1,&y1);
	for(i=0;i<n-1;i++){
		scanf("%d %d",&x,&y);
		if(x1==x){
			if(y1<y){
				c+=y-y1;
			}
			else{
				c+=y1-y;
			}
		}
		else if(y1==y){	
			if(x1<x){
				c+=x-x1;
			}
			else{
				c+=x1-x;
			}
		}
		else if(x1<x){
			if(y1<y){
				a=x-x1;
				b=y-y1;
				if(a<b){
					c+=b;
				}
				else{
					c+=a;
				}
			}
			else{
				a=x-x1;
				b=y1-y;
				c+=a+b;
			}
		}
		else if(x1>x){
			if(y1<y){
				a=x1-x;
				b=y-y1;
				c+=a+b;
			}
			else {
				a=x1-x;
				b=y1-y;
				if(a<b){
					c+=b;
				}
				else {
					c+=a;
				}
			}
		}
		x1=x;
		y1=y;
	}
	printf("%d\n",c);
	return 0;
}
