#include <stdio.h>
#include <string.h>

void bit_conv(char *bit, int hex)
{
	int i;
	
	if (hex >= '0' && hex <= '9'){
		hex -= '0';
	}
	else {
		hex -= 'a';
		hex += 10;
	}
	
	for (i = 3; i >= 0; i--){
		bit[3 - i] = 0;
		if ((hex >> i) & 1){
			bit[3 - i] = 1;
		}
	}
}

int mpow(int num, int n)
{
	int ret;
	
	ret = 1;
	while (n--){
		ret *= num;
	}
	
	return (ret);
}

int main(void)
{
	char bit[512];
	char input[512];
	int Q;
	int i, j, k;
	int ip;
	double fp;
	
	scanf("%d", &Q);
	for (i = 0; i < Q; i++){
		scanf("%s", input);
		for (j = 0; input[j] != '\0'; j++){
			bit_conv(&bit[j * 4], input[j]);
		}
		if (bit[0] == 1) printf("-");
		
		ip = 0;
		for (j = 1; j <= 24; j++){
			ip = (ip << 1) + bit[j];
		}
		printf("%d.", ip);
		int m = 0;
		fp = 0;
		double dec = 1.0;
		for (j = 0; j < 7; j++){
			dec /= 2.0;
			if (bit[j + 25] == 1){
				m = j;
				fp += dec;
			}
		}
		for (j = 0; j <= m; j++){
			printf("%d", (int)(fp * mpow(10, j + 1)) % 10);
		}
		printf("\n");
	}
	
	return (0);
}
