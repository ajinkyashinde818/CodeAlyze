#include <stdio.h>

long long abs(long long num)
{
	if(num < 0)
		return -num;
	else
		return num;
}

int main(void)
{
	int n;
	long long a[200000];
	long long all, sunuke, min;
	int i;
	
	scanf("%d", &n);
	all = 0;
	for(i=0; i<n; i++){
		scanf("%lld", &a[i]);
		all += a[i];
	}
	
	sunuke = a[0];
	min = abs(2*sunuke-all);
	for(i=1; i<n-1; i++){
		sunuke += a[i];
		
		if( abs(2*sunuke-all) < min )
			min = abs(2*sunuke-all);
	}
	
	printf("%lld\n", min);
	
	return 0;
}
