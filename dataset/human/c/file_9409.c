#include <stdio.h>
#include <string.h>

int main(void){
	int n,d,x;
	int a[101];
	int i;
	int ans;

	scanf("%d",&n);
	scanf("%d %d",&d,&x);

	ans = x;

	for(i = 1;i <= n; i++ ){
		scanf("%d",&a[i]);
		ans += (1 + ((d - 1) / a[i]) );
	}

	printf("%d\n", ans);

	return 0;
}
