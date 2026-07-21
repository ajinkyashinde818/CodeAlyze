#include<stdio.h>
int main(){
	int i,j,k;
	int r,g,b,n;
	int xp,cnt=0;
	scanf("%d%d%d%d",&r,&g,&b,&n);
	for(i=0;i<=3000;i++){
		for(j=0;j<=3000;j++){
			if((n-(i*r)-(j*g))>=0 && (n-(i*r)-(j*g))%b==0){
				cnt++;
			}
		}
	}
	printf("%d\n",cnt);
	return 0;
}
