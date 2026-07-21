#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <math.h>


int merge(long int a1[], long int a2[], int a1_size, int a2_size, long int a[]);
int mergeSort(long int a[], int number);

int main(void)
{
	long int n;
	long int sum = 0;
	long int i, j, index = 0;
	long int work;
	long int max;
	long int mcount = 0;
	long int pcount = 0;
	long int a[100000] = {0};
	
	scanf("%ld", &n);
	
	for(i = 0; i < n; i++) {
		scanf("%ld", &a[i]);
		if(a[i] > 0) {
			pcount++;
		} else {
			mcount++;
		}
	}
	
	mergeSort(a, n);
	
	if(mcount == 0) {
		for(i = 1; i < n; i++) {
			sum += a[i];
		}
		printf("%ld\n", sum - a[0]);
		work = a[0];
		for(i = 1; i < n - 1; i++) {
			printf("%ld %ld\n", work, a[i]);
			work -= a[i];
		}
		printf("%ld %ld\n", a[n - 1], work);
	} else {
		if(pcount == 0) {
			for(i = 0; i < n - 1; i++) {
				sum += labs(a[i]);
			}
			printf("%ld\n", sum + a[n - 1]);
			work = a[n - 1];
			for(i = n - 2; i >= 0; i--) {
				printf("%ld %ld\n", work, a[i]);
				work -= a[i];
			}
		} else {
			for(i = 0; i < n; i++) {
				sum += labs(a[i]);
			}
			printf("%ld\n", sum);
			work = a[n - 1];
			for(i = 0; i < mcount - 1; i++) {
				printf("%ld %ld\n", work, a[i]);
				work -= a[i];
			}
			max = a[mcount - 1];
			for(i = mcount; i < n - 1; i++) {
				printf("%ld %ld\n", max, a[i]);
				max -= a[i];
			}
			printf("%ld %ld\n", work, max);
		}
	}
	
	/*
	for(i = 0; i < n; i++) {
		printf("%ld\n", a[i]);
	}
	
	for(i = 0; i < m; i++) {
		printf("%ld %ld\n", b[i], c[i]);
	}
	*/
	
	return 0;
}

int merge(long int a1[], long int a2[], int a1_size, int a2_size, long int a[])
{
	int i = 0, j = 0;
	
	while( (i < a1_size ) || (j < a2_size) ){
		if( (j >= a2_size ) || ( (i < a1_size) && (a1[i] < a2[j]) ) ) {
			a[i + j] = a1[i];
			i++;
		} else {
			a[i + j] = a2[j];
			j++;
		}
	}
	
	return 0;
}

int mergeSort(long int a[], int number)
{
	int m = number / 2, n = number - m;
	long int a1[m];
	long int a2[n];
	int i, j;
	
	if(number > 1) {
		for(i = 0; i < m; i++) {
			a1[i] = a[i];
		}
		for(i = 0; i < n; i++) {
			a2[i] = a[m + i];
		}
		mergeSort(a1, m);
		mergeSort(a2, n);
		merge(a1, a2, m, n, a);
	}
	
	return 0;
}
