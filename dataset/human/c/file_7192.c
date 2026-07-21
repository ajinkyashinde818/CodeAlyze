/*
整数を2つ入力し、それらを縦・横として枠を描け。
前問で描いた長方形のプログラムを、if文で書くものを変えるとよい。

やり方：
	・長方形のを流用。
	・一行目または最終行の時のみ、全て「#」。
	・それ以外は、最初と最後の文字のみ「#」。他は「.」。

結果：正解。

*/
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int main()
{
	int n=0;
	int h,w,count=0;
	int i[100],k[100];
	while(1){
		scanf("%d %d",&i[n],&k[n]);
		if(i[n]==0&&k[n]==0){
			break;
		}
		n++;
	}
	count=n;
	for(n=0; n<count; n++){
		for(h=0; h<i[n]; h++){
			for(w=0; w<k[n]; w++){
				if(h%2==0){
					if(w%2==0){
						printf("#");
					}
					else{
						printf(".");
					}
				}
				else{
					if(w%2==0){
						printf(".");
					}
					else{
						printf("#");
					}
				}
			}
			puts("");
		}
		puts("");
	}
	return 0;
}
