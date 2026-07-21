#include <stdio.h>

int main(void)
{
	int i,a[32768];
	for(i=1;i<=32768;i++){
		scanf("%d",&a[i]);
		if(a[i]==0){
			break;
		}
	}
	for(i=1;i<=32768;i++){
		if(a[i]==0){
			break;
		}
		else{
			printf("Case %d: %d\n",i,a[i]);
		}
	}
	return 0;
}
