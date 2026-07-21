#include <stdio.h>

int main(void){
	
	int i;
	int n;
	scanf("%d", &n);
	int min, pre;
	scanf("%d", &min);
	pre = min;

	int ans, r;
	scanf("%d", &r);
	ans = r - pre;
//	printf("!%d\n", ans);
	if(r<min){
		min = r;
		pre = r;
	}else if(r>pre){
		pre = r;
	}
	for(i=2; i<n; i++){
//		printf("i=%d\n", i);
		scanf("%d", &r);

			if(pre<=r){
				pre = r;
				if(ans < pre-min){
					ans = pre-min;
				}
//				printf("ans = %d\n", ans);
			}
			if(r<min){
				min=r;
				pre=r;
			}
	
	}

	printf("%d\n", ans);
	return 0;
}
