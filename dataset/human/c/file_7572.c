#include <stdio.h>
//#define scanf scanf_s
typedef long long int lli;

// 入力XをCase i: Xの形式で出力
// X=0なら終了
int main()
{
	int iInputX;
	int iCnt = 1;
	scanf("%d", &iInputX);

	while (iInputX != 0)
	{
		printf("Case %d: %d\n", iCnt, iInputX);
		iCnt++;
		scanf("%d", &iInputX);
	}

	return 0;
}
