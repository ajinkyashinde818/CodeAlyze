#include <stdio.h>
int main(){
	int n,k,cont =0;
	scanf("%d %d\n",&n,&k);
	int a[n];
	for (int i=0;i<n;i++){
		scanf("%d",&a[i]);
		if (a[i]>=k){
			cont+=1;
		}
	}
	printf("%d\n",cont);
	return 0;
}
