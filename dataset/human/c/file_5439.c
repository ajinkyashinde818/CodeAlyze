#include <stdio.h>

int pm(int x){if(x > 0){return 1;}else if(x < 0){return -1;}return 0;}
int zt(int x){if(x < 0){return -x;}return x;}
int max(int a,int b){if(a < b){return b;}return a;}

int main(void) {
	int w,h,n,x1,y1,x2,y2,i,res = 0;
	scanf("%d%d%d%d%d",&w,&h,&n,&x1,&y1);
	for(i = 2;i <= n;i++){
		scanf("%d%d",&x2,&y2);
		if(pm(x2-x1) == pm(y2-y1)){res+=max(zt(x2-x1),zt(y2-y1));}
		else{res+=(zt(x2-x1)+zt(y2-y1));}
		x1 = x2;
		y1 = y2;
	}
	printf("%d\n",res);
	return 0;
}
