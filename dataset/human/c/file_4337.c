#include <stdio.h>
#include <stdlib.h>
#define int long long
#define ms_valtype int

//比較関数
int compare_ms(ms_valtype a, ms_valtype b){
	return b - a;
}

//昇順
void sort_sub(ms_valtype *origin, int left, int right, ms_valtype *tmp){
	if(right - left > 1){
		int i, j, k, half = (left + right) / 2;
		sort_sub(origin, left, half, tmp);
		sort_sub(origin, half, right, tmp);
		for(i = left; i < right; i++){
			tmp[i] = origin[i];
		}
		for(i = left, j = left, k = half; i < right; i++){
			if(k == right){
				origin[i] = tmp[j];
				j++;
			}
			else if(compare_ms(tmp[j], tmp[k]) <= 0 && j < half){
				origin[i] = tmp[j];
				j++;
			}
			else{
				origin[i] = tmp[k];
				k++;
			}
		}
	}
}

void sort(ms_valtype *origin, int N){
	ms_valtype *tmp = (ms_valtype *)malloc(sizeof(ms_valtype) * N);
	sort_sub(origin, 0, N, tmp);
	free(tmp);
}

signed main(){
	int N, i, ans = 0;
	scanf("%lld", &N);
	int *p = (int *)malloc(sizeof(int) * 2 * N);
	for(i = 0; i < 2 * N; i++){
		scanf("%lld", &p[i]);
	}
	sort(p, 2 * N);
	for(i = 1; i <= 2 * N; i++){
		ans += p[i - 1] * (2 * N - i);
	}
	printf("%.12lf\n", (double)ans / (2 * N - 1));
	return 0;
}
