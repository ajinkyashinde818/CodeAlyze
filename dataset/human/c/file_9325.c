#include <stdio.h>

int main()
{
	int N, K;
    int cnt = 0;

	scanf("%d %d", &N, &K);

	int h[N];

	for(int i=0; i<N; i++){
		scanf("%d", &h[i]);
        if(K <= h[i])   cnt++;
	}

	printf("%d\n", cnt);

	return 0;
}
