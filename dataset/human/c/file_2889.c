#include <stdio.h>


int main()
{
	int K, S;
	int count;
	int i, j, k;


	scanf("%d %d", &K, &S);
/*
	// これだと解けるが制限時間に間に合わない
	count = 0;
	for(i = 0; i <= K; i++){
		for(j = 0; j <= K; j++){
			for(k = 0; k <= K; k++){
				if(i + j + k == S)
					count++;
			}
		}
	}
*/

	count = 0;
	for(i = 0; i <= K; i++){
		for(j = 0; j <= K; j++){
			k = S - i - j;
			if(0 <= k && k <=K)
				count++;
		}
	}

	printf("%d\n", count);

	return 0;
}
