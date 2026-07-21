#include<stdio.h>

//料理を表す構造体
struct cuisine {
	int satisfaction;
	int after;
};

int main() {

	//入力
	int n, a[20];
	struct cuisine cuisines[21];
	scanf("%d", &n);
	for (int i = 0; i < n; i++)      scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++)     scanf("%d", &cuisines[i].satisfaction);
	for (int i = 1; i <= n - 1; i++) scanf("%d", &cuisines[i].after);
	

	/*順繰りに計算*/

	//合計満足度にまず一品目の満足度を代入
	int ans = cuisines[a[0]].satisfaction;

	for (int i = 1; i < n; i++) {

		//i番目に食べた料理の満足度を追加
		ans += cuisines[a[i]].satisfaction;

		//追加で満足度を得られるのなら、満足度を追加
		if (a[i] - a[i - 1] == 1) {
			ans += cuisines[a[i - 1]].after;
		}
	}

	//出力
	printf("%d\n", ans);

	return 0;
}
