#include<stdio.h>
int main(void)
{
	int w,h,n;
	int i,j;
	int cnt=0;
	int sx,sy,x,y;
	
	scanf("%d %d %d",&w,&h,&n);
	scanf("%d %d",&sx,&sy);
	for(i=0;i<n-1;i++){
		scanf("%d %d",&x,&y);
		if(sx==x){
			if(sy<y){
				cnt+=y-sy;
			}
			else if(y<sy){
				cnt+=sy-y;
			}
		}
		else if(sy==y){
			if(sx<x){
				cnt+=x-sx;
			}
			else if(x<sx){
				cnt+=sx-x;
			}
		}
		else if(x>sx){
			if(y>sy){
				if(x-sx<y-sy){
					cnt+=y-sy;
				}
				else{
					cnt+=x-sx;
				}
			}
			else if(y<sy){
				cnt+=x-sx+sy-y;
			}
		}
		else if(x<sx){
			if(y<sy){
				if(sx-x<sy-y){
					cnt+=sy-y;
				}
				else {
					cnt+=sx-x;
				}
			}
			else if(y>sy){
				cnt+=sx-x+y-sy;
			}
		}
		sx=x;
		sy=y;
	}
	printf("%d\n",cnt);
	return 0;
}
