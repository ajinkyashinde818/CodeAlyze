#include<stdio.h>
int x[10000],y[10000];
int main(void)
{
	int i,j,h,w,n,z[10000],e[10000],tol,su,sm;
	scanf("%d %d %d",&h,&w,&n);
	for(i=0;i<n;i++){
		scanf("%d %d",&x[i],&y[i]);
	}
	su=0;
	sm=0;
	tol=0;
	for(i=0;i<n;i++){
		e[i]=x[i]-x[i+1];
		z[i]=y[i]-y[i+1];
		z[n-1]=0;
		e[n-1]=0;
		if((e[i]>0&&z[i]>0)||(e[i]<0&&z[i]<0)){
		if(e[i]<0&&z[i]<0){
				e[i]=e[i]*-1;
				z[i]=z[i]*-1;
			}
			if(e[i]<z[i]){
				su=su+z[i];
			}
			else{
				su=su+e[i];
			}
		}
		else{
			if(e[i]<0){
				e[i]=e[i]*-1;
			}
			if(z[i]<0){
				z[i]=z[i]*-1;
			}
			sm=sm+(e[i]+z[i]);
		}
	}
	tol=su+sm;
	printf("%d\n",tol);
	return 0;
}
