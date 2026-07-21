/*
氏名：鈴木丈人
学籍番号：190441067
概要：1つの整数xを読み込み、それをそのまま出力するプログラム
*/
#include<stdio.h>
int main(void)
{
	int i = 0;   //判定用
	int j = 0;
	int data[10000] = { 0 };   //入力された数値

	while (1)
	{
		scanf("%d", &data[i]);
		if (data[i] == 0)
		{
			break;
		}
		i++;

	}

	for (j = 0; j < i; j++)
	{
		printf("Case %d: %d\n", j + 1, data[j]);
	}

	return 0;
}
