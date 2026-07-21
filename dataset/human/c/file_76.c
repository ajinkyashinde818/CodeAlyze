#include<stdio.h>

int main(){
	int r,g,b,n;
	scanf("%d%d%d%d",&r,&g,&b,&n);
	int ans=0,i,j;
	for(i=0;i*r<=n;i++){
		for(j=0;j*g+i*r<=n;j++){
			if((n-r*i-j*g)%b==0)ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}
