#include <stdio.h>

//問題文より、入力されるデータの最大個数
#define MAXCOUNT 200000

int main(void)
{
	/*
	nは入力されるデータの個数を格納
	new_price - base_priceで利益を求め、diff_priceに代入する
	*/
	int i, n, base_price, new_price, diff_price;
	int price[MAXCOUNT];

	//データの個数を入力
	scanf("%d", &n);

	//データを入力
	for(i = 0; i < n; i++){
		scanf("%d", &price[i]);
	}

	//最大の利益を求める
	for(i = 0; i < (n - 1); i++){
		//ループの最初ならば初期値を代入
		if(i == 0){
			base_price = price[i];
			new_price = price[i + 1];
			diff_price = new_price - base_price;
		}
		//基準価格は最小にする
		else if(base_price > price[i]){
			base_price = price[i];
			new_price = price[i + 1];
			//最大利益が出るならば、更新する
			if(diff_price < (new_price - base_price)){
				diff_price = new_price - base_price;
			}
		}
		//変動後の価格は最大にする
		else if(new_price < price[i + 1]){
			new_price = price[i + 1];
			//最大利益が出るならば、更新する
			if(diff_price < (new_price - base_price)){
				diff_price = new_price - base_price;
			}
		}
	}

	//結果を出力
	printf("%d\n", diff_price);
	
	return 0;
}
