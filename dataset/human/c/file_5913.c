#include<stdio.h>

int main(){
	int n;	//価格の数
	long int max = -1000000000;	//最大の利益
	
	//価格の数を入力
	scanf("%d",&n);
	
	long int R;	//価格
	
	//最初の価格の入力
	scanf("%ld",&R);
	
	long int min = R;//価格の最小値
	
	for(int j = 0;j < (n - 1);j++){
		//2回目以降の価格の入力
		scanf("%ld",&R);
		
		/*最大の利益と次の価格-最小値の比較
		（大きい方が最大の利益になる）*/
		max = (max > (R - min)) ? max : R - min;
		
		/*最小値と次の価格の比較
		（小さい方が最小値になる）*/
		min = (min < R) ? min : R;
	}
	
	//結果の出力
	printf("%ld\n",max);
	
	return 0;
}
