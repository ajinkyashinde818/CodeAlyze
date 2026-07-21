#include<stdio.h>
int main(void){
	int i,j,l,k,s,cnt;
	scanf("%d %d",&k,&s);
	cnt=0;
	for(i=0;i<=k;i++){
		if(i>s)break;
		for(j=0;j<=k;j++){
			if(i+j>s)break;
			l=s-i-j;
			if(l>=0&&l<=k)cnt++;
		}
	}
	printf("%d",cnt);
	return 0;
}
