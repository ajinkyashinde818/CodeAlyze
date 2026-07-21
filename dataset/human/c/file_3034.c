#include <stdio.h>

#define MAX_H 200001
int House[MAX_H];

// always x < y ex) 1 , 19   D:20 (1+20)-19
int GetDistance(int x, int y, int D)
{
	int dist = y - x;

	if (dist < 0)
		dist += D;

	return dist;
}

int main()
{
	#ifdef _WIN32
		freopen("input.txt", "r", stdin);
	#endif

	int K, N;
	scanf("%d %d", &K, &N);

	for (int n = 0; n < N; n++)
		scanf("%d", &House[n]);
	
#ifdef _WIN32
	printf("input : %d %d\n", K, N);
	for (int n = 0; n < N; n++)
		printf("%d ", House[n]);
	printf("\n");
#endif

	int Result = 0;
	for (int i = 0; i < N; i++)
	{
		int temp = GetDistance(House[i], House[(i + 1) % N], K);
		if (Result < temp)
			Result = temp;
	}

	printf("%d", K- Result);

	return 0;
}
