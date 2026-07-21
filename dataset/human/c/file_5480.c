#include <stdio.h>

int s[1000001];
int p[1000001];

int main(void)
{
	int i, j, k;
	int n;
	
	for (i = 0; i <= 1000000; i++){
		s[i] = 1;
	}
	s[0] = s[1] = 0;
	
	for (i = 2; i * i <= 1000000; i++){
		if (s[i] == 0) continue;
		for (j = i * i; j <= 1000000; j += i){
			s[j] = 0;
		}
	}
	k = 2;
	p[1] = 2;
	for (i = 3; i <= 1000000; i++){
		if (s[i] == 1){
			p[k] = i + p[k - 1];
			k++;
		}
	}
	
	while (scanf("%d", &n), n != 0){
		printf("%d\n", p[n]);
	}
	return (0);
}
