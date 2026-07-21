#include <stdio.h>

#define SIZE 200005

int a[SIZE],
//record[SIZE],//町の履歴
loop[SIZE],//町1から一周ループするまでを入れておく配列
dp[SIZE] = { 0 };//各町が登場したかの判定配列。0(false)で来てない。

int main() {
	long long k;
	int n,
		town = 1,//一番最初は1の町にいる
		start = 0,//ループ開始のループ部の中身のインデックス
		length = 0,//配列loopの長さ
		loop_length = 0;//実際のループの長さ
		//z = 0;//ループで数列を割ったときのあまり

	//入力
	scanf("%d%lld", &n, &k);
	for (int i = 0; i < n; i++)scanf("%d", &a[i]);

	//ここからの処理で配列loopを作る
	//もし一度でも来たことがある町に来たら
	//配列dpが1(true)になるはずなので
	//(!dp[town-1])はfalseになる
	for (int i = 0; !dp[town - 1]; i++) {
		//配列dpの今いる町を1(true)にする
		dp[town - 1] = 1;
		//配列loopに今の町を記録する
		loop[i] = town;
		//テレポートする
		town = a[town - 1];
		//配列loopの使う長さが変わるので記録
		length++;
	}

	//配列loopのどこからループが始まっているのかを調べ、実際のループの大きさを調べる
	for (int i = 0; i < length; i++) {
		//もしtown(ループの始まりであると保証できる)と配列loopが同じだったら
		if (town == loop[i]) {
			//実際のループの大きさを記録して
			loop_length = length - i;
			//ループに入る前の場所のインデックスを記録
			start = i;
			//ループをやめる
			break;
		}
	}
	//もし配列loopの大きさよりもkが小さければ
	//無条件でloop[k]を出力すればいい
	if (k < length) {
		printf("%d", loop[k]);
	}
	else {

		//そうでなければkから実際のループに入る前を引いて
		//それから何回きっちりループしてそのあとどのくらい移動するかを出す
		//その、「そのあとどのくらい移動するか」というのは
		//ループに入る前の分を抜かした上での配列loopの添え字なので、
		//ちゃんとループに入る前を足してあげる
		printf("%d\n", loop[(k - start) % loop_length + start]);
	}
}
