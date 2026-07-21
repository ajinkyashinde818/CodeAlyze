#include <stdio.h>
int main(){
	int i,a[100000];
	int count=0;
	i=0;
	while(1){
		scanf("%d",&a[i]);
		if(a[i]==0) break;
		count++;
		i++;
	}
	for(i=1;i<=count;i++){
		printf("Case %d: %d\n",i,a[i-1]);
	}
	return 0;
}
