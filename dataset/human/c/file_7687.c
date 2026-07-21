#include <stdio.h>
 
int main(void) {
	int s[10000];
	int n,y;
	n=0;
	while(1){
		scanf("%d",&s[n]);
		if(s[n]==0){
			break;
		};
		n++;
	}
	for(y=0;y<n;y++){
		printf("Case %d: %d\n",y+1,s[y]);
	}
	return 0;
}
