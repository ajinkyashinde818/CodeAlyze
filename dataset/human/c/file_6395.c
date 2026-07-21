#include<stdio.h>
#include<math.h>
int exmax(int, int);
int exmin(int, int);
int main() {
	int a, i, xA, minv,maxv;
	maxv = -1*(int)pow(10, 9);
	scanf("%d%d", &a,&minv);
	for (i = 1; i < a ; i++) {
		scanf("%d", &xA);
		maxv = exmax(maxv, xA - minv);
		minv = exmin(minv, xA);
		if (i == a-1)
		{
			printf("%d", maxv);
		}
	}
	printf("\n");
	return 0;
}
int exmax(int x, int y) {
	if (x > y)
	{
		return x;
	}
	else
	{
		return y;
	}
}
int exmin(int x, int y) {
	if (x > y)
	{
		return y;
	}
	else {
		return x;
	}
	
}
