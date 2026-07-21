#include <stdio.h>
#include <stdlib.h>

int main(void)
{	
	int a[30],b[100],c[100];
	int n,ans = 0,before = -5,dishnum = -1;
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++){
		scanf("%d",&b[i]);
	}
	for(i=0;i<n-1;i++){
		scanf("%d",&c[i]);
	}
	for(i=0;i<n;i++){
		dishnum = a[i] - 1;
		if(dishnum - 1 == before){
			ans += c[dishnum-1];
//			printf("ボーナス%d",ans);
		}
		ans += b[dishnum];
		before = dishnum;
//		printf("合計%d 料理名%d 前の料理 %d\n",ans,dishnum,before);
	}
	printf("%d",ans);
	return 0;
}
