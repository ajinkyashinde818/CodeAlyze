#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>

int main(void)
{
	int N;
	scanf("%d\n",&N);
	int a[N];
	int min_push[N];
	int n;
	for (n=0;n<N;n++){
		scanf("%d\n",&a[n]);
		a[n]--;
		min_push[n] = -1;
	}
	int i=0;
	int curr = 1 - 1;
	while (1){
		//printf("%d\n",curr);
		if (min_push[curr]>=0)break; // 到達済みなら抜ける
		min_push[curr]=i;
		if (curr==2-1)break; // ボタン2に到達したら抜ける
		curr = a[curr];
		i++;
	}
	printf("%d\n",min_push[2-1]);
	return 0;
}
