#include <stdio.h>

int roop(int n,int k)
{
	int i, H, x = 0;
	for (i = 0; i < n; i++) {
		scanf("%d", &H);
		if (k <= H) {
			x++;
		}
	}
	return x;
}
int main()
{
	int N,K,a;

	//人数
	scanf("%d", &N);
	//制限
	scanf("%d", &K);
	
	a = roop(N,K);

	printf("%d", a);
}
