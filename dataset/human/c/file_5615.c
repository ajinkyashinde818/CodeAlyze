#include <stdio.h>
//提出するとき問題番号変えんの忘れるわぁ
int main(void){
	long long int x, y=0,r, i=0;
	scanf("%ld",&x);
	r = x;
	r = x % 11;
	x = x - r;
	i = 2 * x / 11;
	
	i = (r == 0) ? i : i + 1;
	i = (r < 7) ? i : i + 1;
	
	printf("%ld\n",i);
	return 0;
}
