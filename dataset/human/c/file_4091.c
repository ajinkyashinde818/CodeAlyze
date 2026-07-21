#include<stdio.h>

int main(){
	int x,y,k,ans;
	scanf("%d %d %d",&x,&y,&k);
    
	

    int i = x;
	while(1){
		if(x%i==0&&y%i==0){
			k--;
			ans = i;
		}
		i--;
		if(k==0){
			printf("%d",ans);
			return 0;
		}
	}
}
