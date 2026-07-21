#include <stdio.h>

int a[100000];
int cnt=0;
int main(void)
{
	while(1){
		scanf("%d",&a[cnt]);
		if(a[cnt]==0) break;
		cnt++;
	}//配列添字maxとcnt同じ
	int p;
	for(p=0;p<cnt;p++){
		int q=p+1;
		printf("Case %d: %d\n",q,a[p]);
	}
	
	
	
	return 0;
}
