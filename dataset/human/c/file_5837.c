#include <stdio.h>
int main(){
	int b,n,i,min,max,ans=-214783648,tmp;
	scanf("%d",&n);
	scanf("%d",&tmp);
	max = min = tmp;
	for(i=1; i<n; i++){
		scanf("%d",&tmp);
		max = tmp;
		b = max - min;
		if(min > tmp)min = tmp;
		if(n == 2 || ans < b)ans = b;
	}
	printf("%d\n",ans);
	return 0;
}
