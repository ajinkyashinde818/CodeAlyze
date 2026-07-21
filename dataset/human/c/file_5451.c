#include <stdio.h>

int main(void){
	int w,h,n,i,j,k,ans=0,gx,gy,nx,ny;
	scanf("%d %d %d",&w,&h,&n);
	scanf("%d %d",&nx,&ny);
	for(i=1;i<n;i++){
		scanf("%d %d",&gx,&gy);
		while(!(gx==nx&&gy==ny)){
			if(gx==nx&&gy<ny){
				ny--;
				ans++;
			}
			if(gx==nx&&gy>ny){
				ny++;
				ans++;
			}
			if(gx<nx&&gy==ny){
				nx--;
				ans++;
			}
			if(gx>nx&&gy==ny){
				nx++;
				ans++;
			}
			if(gx<nx&&gy<ny){
				nx--;
				ny--;
				ans++;
			}
			if(gx<nx&&gy>ny){
				nx--;
				//ny++;
				ans++;
			}
			if(gx>nx&&gy>ny){
				nx++;
				ny++;
				ans++;
			}
			if(gx>nx&&gy<ny){
				nx++;
				//ny++;
				ans++;
			}
		}
	}
	
	printf("%d\n",ans);
	return 0;
}
