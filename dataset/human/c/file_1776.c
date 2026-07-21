#include <stdio.h>

int main(){
	int n,sum;
	scanf("%d",&n);
	int a[n],b[n],c[n];
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
	}
	for(int i=1;i<n;i++){
		scanf("%d",&c[i]);
	}
	sum=b[a[1]];
	for(int i=2;i<=n;i++){
		//printf("b[%d]=%d\n",i,b[i]);
		if(a[i]==a[i-1]+1){
			sum+=(b[a[i]]+c[a[i]-1]);
		}else{
			sum+=b[a[i]];
		}
		//printf("%d\n",sum);
	}
	printf("%d\n",sum);
	return 0;
}
