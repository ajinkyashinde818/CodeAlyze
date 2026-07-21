#include <stdio.h>

int conv(char *s)
{
	int out;
	int p;
	

	out = 0;
	
	p = 0;
	
	if (s[p] == 'm'){
		p++;
		out += 1000;
	}
	if ('2' <= s[p] && s[p] <= '9' && s[p + 1] == 'm'){
		out += ((s[p] - '0') * 1000);
		p += 2;
	}
	
	if (s[p] == 'c'){
		p++;
		out += 100;
	}
	if ('2' <= s[p] && s[p] <= '9' && s[p + 1] == 'c'){
		out += ((s[p] - '0') * 100);
		p += 2;
	}
	
	if (s[p] == 'x'){
		p++;
		out += 10;
	}
	if ('2' <= s[p] && s[p] <= '9' && s[p + 1] == 'x'){
		out += ((s[p] - '0') * 10);
		p += 2;
	}

	if (s[p] == 'i'){
		out++;
	}
	if ('2' <= s[p] && s[p] <= '9' && s[p + 1] == 'i'){
		out += (s[p] - '0');
	}
	
//printf("<%d>\n", out);

	return (out);
}

	
	


int main(void)
{
	int n;
	char m1[10], m2[10];
	int result;
	int i;
	
	scanf("%d", &n);
	for (i = 0; i < n; i++){
		scanf("%s%s", m1, m2);
		
		result = conv(m1) + conv(m2);
		
		if (result >= 1000){
			if (result / 1000 >= 2){
				printf("%d", result / 1000);
			}
			printf("m");
		}
		result %= 1000;
		
		if (result >= 100){
			if (result / 100 >= 2){
				printf("%d", result / 100);
			}
			printf("c");
		}
		result %= 100;
		
		if (result >= 10){
			if (result / 10 >= 2){
				printf("%d", result / 10);
			}
			printf("x");
		}
		result %= 10;
		
		if (result > 0){
			if (result >= 2){
				printf("%d", result);
			}
			printf("i");
		}
		printf("\n");
		
	}
	
	return (0);
}
