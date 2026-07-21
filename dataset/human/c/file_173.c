#include <stdio.h>

int main(void)
{
	char hexa[9];
	int binary[32];
	int i, n, j, m, f;
	double decimal, radix;
	int out[13], show, hide;
	
	double dif;
	
	scanf("%d", &n);
	for (i = 0; i < n; i++){
		for (j = 0; j < 13; j++){
			out[j] = 0;
		}
		
		scanf("%s", hexa);
		for (j = 0; j < 8; j++){
			if (hexa[j] >= '0' && hexa[j] <= '9'){
				m = hexa[j] - '0';
			}
			else {
				m = hexa[j] - 'a' + 10;
			}
			
			binary[j * 4 + 0] = m / 8;
			m %= 8;
			binary[j * 4 + 1] = m / 4;
			m %= 4;
			binary[j * 4 + 2] = m / 2;
			m %= 2;
			binary[j * 4 + 3] = m;
		}
		
		for (j = 1, radix = 8388608.0, decimal = 0.0; j < 32; j++, radix /= 2){
			decimal += radix * binary[j];
		}
		
		if (binary[0] == 1){
			printf("-");
		}
		
		for (j = 0, radix = 100000.0, show = 5, hide = 6; radix >= 0.0000001; j++){
			while (decimal >= radix){
				if (j < show){
					show = j;
				}
				if (j > hide){
					hide = j;
				}
				out[j]++;
				decimal -= radix;
			}
			
			dif = radix * 9 / 10;
			radix -= dif;
		}
		
		for (j = show; j <= hide; j++){
			printf("%d", out[j]);
			if (j == 5){
				printf(".");
			}
		}
		puts("");
	}
	
	return (0);
}
