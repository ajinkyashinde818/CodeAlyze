# include <stdio.h>

int main(){
	int dish[25];
	int points[55];
	int extra[55];
	int n;
	int max = 0;
	int ex = 0;

	scanf("%d", &n);
	for (int j = 0; j < n; ++j){
		scanf("%d", &dish[j]);
	}
	for (int v = 0; v < n; ++v){
		scanf("%d", &points[v]);
	}

	for (int h = 0; h < n-1; ++h){
		scanf("%d", &extra[h]);
	}

	for (int i = 0; i < n; ++i){
		max = max + points[i];

		if (i != 0 && dish[i] - dish[i-1] == 1){
			max = max + extra[dish[i-1]-1];
			ex = ex+1;
				}
			}

	printf("%d\n", max);


	return 0;
}
