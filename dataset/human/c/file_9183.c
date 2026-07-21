#include <stdio.h>
int main(void){
	int i;
	int count=0;
	int n;
	int k;
	scanf("%d %d",&n,&k);
	int h[n];
	for(i=0;i<n;i++){
		scanf("%d",&h[i]);
		if(h[i]>=k){
			count++;
		}
	}
	printf("%d",count);

return(0);
}
