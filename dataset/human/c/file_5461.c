#include<stdio.h>
int main(void)
{
	int w,h,n,x[10001],y[10001],s,t,u,i,j;
	scanf("%d %d %d",&w,&h,&n);
	for(i=0;i<n;i++){
		scanf("%d %d",&x[i],&y[i]);
	}
	u=0;
	for(i=1;i<n;i++){
		s=x[i]-x[i-1];
		t=y[i]-y[i-1];
		if(s<=0&&t<=0){
			s=s*-1;
			t=t*-1;
			if(s<t){
				u=u+t;
			}
			else{
				u=u+s;
			}
		}
		else if(s>0&&t>0){
			if(s<t){
				u=u+t;
			}
			else{
				u=u+s;
			}
		}
		else if(s>0&&t<=0){
			t=t*-1;
			u=u+s+t;
		}
		else{
			s=s*-1;
			u=u+s+t;
		}
	}
	printf("%d\n",u);
	return 0;
}
