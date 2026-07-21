#include <stdio.h>

int main(void)
{
	int lake, homes;
	int dist[1000000];
	int diff, maxdist;
	int i;

	//Input
	scanf("%d%d", &lake, &homes);

	i = 0;
	while (i < homes)
	{
		scanf("%d", &dist[i]);
		i++;
	}

	//Find most long distance.
	i = 0;
	maxdist = 0;
	while (i < homes)
	{
		if(i == homes - 1)
		{
			diff = lake - dist[i] + dist[0];
		}
		else diff = dist[i + 1] - dist[i];
		if(maxdist < diff)
			maxdist = diff;
		i++;
	}

	printf("%d\n", lake - maxdist);

	return (0);
}
