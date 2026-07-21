#include <stdio.h>
#include <stdbool.h>

#define MAX_N 100000
#define LIMIT 1000000

int main()
{
    int n;
    int a[MAX_N + 1];
    int counter;
    int nextIndex;
    bool isPossible;
    
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
	scanf("%d", &a[i]);
    }

    counter = 0;
    nextIndex = 1;
    isPossible = false;
    while ((isPossible == false) && (counter < LIMIT))
    {
	counter++;
	nextIndex = a[nextIndex];
	if (nextIndex == 2)
	{
	    isPossible = true;
	}
    }

    if (isPossible == true)
    {
	printf("%d\n", counter);
    }
    else
    {
	printf("-1\n");
    }

    return 0;
}
