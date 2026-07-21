#include<stdio.h>
#define INF (1<<30)

int main(){
	int i,n,ans,min,x;	scanf("%d",&n);
	scanf("%d",&min);
	ans=INF*(-1);

	for(i=1;i<n;i++){
		scanf("%d",&x);
		if(ans<x-min){
			ans=x-min;
		}

		if(min>x)min=x;
	}

	printf("%d\n",ans);
	return 0;
}
