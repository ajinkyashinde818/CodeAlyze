#include <stdio.h>
#include <math.h>

typedef long long ll;

int main() {
	int n;
	scanf("%d", &n);
	int streak = 0;
	int got3 = 0;
	for (int i = 0; i < n; i++)
	{
		int d1, d2;
		scanf("%d %d", &d1, &d2);
		if (d1 == d2)
		{
			streak++;
			if (streak == 3) got3 = 1;
			
		}
		else
		{
			streak = 0;
		}
		
		
	}
	if (got3)
	{
		printf("Yes");
	}
	else
	{
		printf("No");
	}
	
	return 0;
}
