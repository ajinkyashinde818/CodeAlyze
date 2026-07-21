#include <stdio.h>

int main(void)
{
	//iはループ変数、indexは添字、input_valueは入力値を格納
	int i, index;
	int input_value[10000];

	//初期値は0
	index = 0;

	while(1){
		scanf("%d", &input_value[index]);
		//入力値が0ならばループを抜ける
		if(input_value[index] == 0){
			break;
		}
		index++;
	}

	//入力した回数だけ出力する
	for(i = 0; i < index; i++){
		printf("Case %d: %d\n", (i + 1), input_value[i]);
	}

	return 0;
}
