#include<stdio.h>
#define FOR(i,a,b) for(int i=a;i<b;i++)
int main(){
	int k,s,ans = 0;
	scanf("%d %d",&k,&s);
	FOR(x,0,k+1){
		FOR(y,0,k+1){
			int z = s-x-y;
			if(z >= 0 && z <= k) ans++;
		}
	}
	printf("%d",ans);
}
