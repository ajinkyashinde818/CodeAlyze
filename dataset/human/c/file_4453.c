#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <inttypes.h>

//int compare_int(const void *a, const void *b){//qsort 整数比較<
//	return *(int*)a - *(int*)b;
//}
//int compare_int2(const void *a, const void *b){//qsort 整数比較>
//	return *(int*)b - *(int*)a;
//}
//

//long long int combination(int n, int r)
//{
//	if (r == 0 || r == n)
//		return (1);
//	else if (r == 1)
//		return (n);
//	return (combination(n - 1, r - 1) + combination(n - 1, r));
//}

int main(void){
	int n;
	int d1[110]={0};
	int d2[110]={0};
	int i;
	int count=0;

	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d %d",&d1[i],&d2[i]);
		if(d1[i]==d2[i]){
			count++;
		}else{
			count=0;
		}
		if(count==3){
			printf("Yes");
			return 0;
		}
	}
	printf("No");
	return 0;
}
