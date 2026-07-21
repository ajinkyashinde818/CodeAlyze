#include <stdio.h>
int main(void){
	int k,s,ans=0;
	scanf("%d%d",&k,&s);
	for(int i=0;i<=k;i++){
		for(int j=0;j<=k;j++){
			int x=s-i-j;
			if(x>=0 && x<=k)ans++;
		}
	}
	printf("%d",ans);
	
	return 0;
}
