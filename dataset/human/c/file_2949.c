#include <stdio.h>
int main()
{
	int K, S, counter;
	scanf("%d %d", &K, &S);
	counter = 0;

	for(int x = 0; x <= K; ++x){
		for(int y = 0; y <= K; ++y){
			int z = S - (x + y);
			if((z >= 0) && (z <= K))
				++counter;
		}
	}
	printf("%d\n", counter);
	return 0;
}
