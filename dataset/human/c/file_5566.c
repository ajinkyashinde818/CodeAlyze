#include <stdio.h>
#include <math.h>
#define MAX 104730

int num[MAX];

int main(void){
	int i, j, in, cnt, sum;
	for(i = 2; i < sqrt(MAX); i++){
		for(j = i; i * j < MAX; j++)	num[i*j] = 1;
	}

	while(1){
		scanf("%d", &in);
		if(in == 0)	break;
		cnt = 0; sum = 0;
		for(i = 2; i < MAX; i++){
			if(cnt == in)	break;
			if(num[i] == 0){
				sum += i;
				cnt++;
			}
		}
		printf("%d\n", sum);
	}

  return 0;
}
