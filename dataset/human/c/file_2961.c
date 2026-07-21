#include <stdio.h>

int main(void)
{
	int k,s;
	scanf("%d %d",&k,&s);
	int x,y,z,cnt=0;
	
	for(x=0;x<=k;x++){
		if(0<=s-x && s-x<=2*k){
			for(y=0;y<=k;y++){
				if(s-x-y<=k && 0<=s-x-y){
					cnt++;
				}
			}
		}
	}
	printf("%d\n",cnt);
	return 0;
}
