#include <stdio.h>
int main(){
	int k=0,s=0;
	int ans=0;
	scanf("%d %d",&k,&s);
	for(int x=0;x<=k;x++){
		for(int y=0;y<=k;y++){
			if(s - x - y<=k && s - x - y>=0)ans++;
		}
	}
	printf("%d\n",ans);
}
