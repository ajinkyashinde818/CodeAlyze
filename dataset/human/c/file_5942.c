#include <stdio.h>

int max(int a, int b)
{
	if(a > b) return a;
	else return b;
}

int min(int a, int b)
{
	if(a < b) return a;
	else return b;
}

int main(void)
{
	int n;
	scanf("%d", &n);
	
	int i, r[n];
	for(i=0; i<n; i++){
		scanf("%d", &r[i]);
	}
	
	int maxpt = -2000000000;
	int minpt = r[0];
	for(i=1; i<n; i++){
		maxpt= max(maxpt, r[i]-minpt);
		minpt = min(minpt, r[i]);
	}
	printf("%d\n", maxpt);
	
	return 0;
}
