//数が小さいほど、安いとき
//数が大きいと、その分利益＝大きいー小さい
//最後が小さい時だとしても購入することができない


#include <stdio.h>
#define N 200000
int main(){
	
	int num,i,max,min;
	int value[N];

	scanf("%d",&num);

	for(i=0;i<num;i++){
		scanf("%d",&value[i]);
	}

	max = value[1]-value[0];/* 大-小 */
	min = value[0];/* 0からじゃないと最後の数まで読み込んでしまう */

	for(i=1;i<num;i++){
		if(max<value[i] - min) max = value[i] - min;
		if(min>value[i]) min = value[i];/*最後は小さい値を読み込まない*/
	}

	printf("%d\n",max);
	return 0;
}
