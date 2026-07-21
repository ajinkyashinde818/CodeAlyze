#include<stdio.h>
int a,b,c,k,s,cnt;
int main() {
	scanf("%d %d",&k,&s);
	for(int i=0;i<=k;i++)
		for(int j=0;j<=k;j++){
			int m=s-i-j;
			if(m>=0&&m<=k) cnt++;
		}
	printf("%d\n",cnt);
	return 0;
}
