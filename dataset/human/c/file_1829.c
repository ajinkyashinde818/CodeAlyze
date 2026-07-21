#include <stdio.h>

int main(void)
{
	int n, b, i;
	int satisfaction = 0;
	int a[20], c[50];

	scanf("%d", &n);

	//食べた料理を配列aに代入
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	//満足度の合計を求める
	for (i = 0; i < n; i++) {
		scanf("%d", &b);
		satisfaction = satisfaction + b;
	}

	//追加の満足度を代入
	for (i = 0; i < n - 1; i++) {
		scanf("%d", &c[i]);
	}

	//料理iを食べたあとに料理i+1を食べた場合に追加の満足度を得る
	for (i = 0; i < n - 1; i++) {
		if (a[i] + 1 == a[i + 1]) {
			satisfaction = satisfaction + c[a[i] - 1]; 
		}
	}

	//満足度の合計を出力
	printf("%d\n", satisfaction);

	return 0;
}
