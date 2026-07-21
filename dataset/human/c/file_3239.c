#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define PI 3.141592653589793
#define MOD 1000000007

//qsort用、昇順
int compare_int(const void *a, const void *b)
{
	return *(int*)a-*(int*)b;
}
//qsort(data, 10, sizeof(int), compare_int)

long int a[1000000];
long int d[1000000];

int main(){
	long int k, n;
	scanf("%ld%ld", &k, &n);
	scanf("%ld", &a[0]);
	for(int i=1; i<n; i++){
		scanf("%ld", &a[i]);
		d[i] = a[i]-a[i-1];
	}
	d[0] = k-a[n-1] + a[0];

	long int max=0;
	for(int i=0; i<n; i++){
		if(max<d[i]) max = d[i];
	}

	printf("%ld\n", k-max);
	
	return 0;
}
