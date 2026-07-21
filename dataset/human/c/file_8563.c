#include <stdio.h>

int a[100*1000];
int ans_x[100*1000];
int ans_y[100*1000];
int ans_n = 0;

int main( int argc , char *argv[] )
{
	int n;
	int sum = 0;
	int min = 10001;
	int max = -10001;
	int min_n;
	int max_n;
	int tmp;
	int tmp2;

	int i;

	scanf( "%d\n" , &n );

	for( i = 0 ; i < n-1 ; i++ ) {
		scanf( "%d " , &(a[i]) );
	}

	scanf( "%d\n" , &(a[n-1]) );

	for( i = 0 ; i < n ; i++ ) {
		if( max < a[i] ) {
			max = a[i];
			max_n = i;
		}

		if( min > a[i] ) {
			min = a[i];
			min_n = i;
		}
	}

	if( max_n == min_n ) {
		min = 10001;

		for( i = 0 ; i < n ; i++ ) {
			if( min > a[i] && i != max_n ) {
				min = a[i];
				min_n = i;
			}
		}
	}

	sum = max;
	tmp = max;

	for( i = 0 ; i < n ; i++ ) {
		if( i != max_n && i != min_n && a[i] < 0 ) {
			ans_x[ans_n] = tmp;
			ans_y[ans_n] = a[i];
			ans_n++;
			tmp = tmp - a[i];

			sum -= a[i];
		}
	}

	sum += -min;
	tmp2 = min;

	for( i = 0 ; i < n ; i++ ) {
		if( i != max_n && i != min_n && a[i] >= 0 ) {
			ans_x[ans_n] = tmp2;
			ans_y[ans_n] = a[i];
			ans_n++;
			tmp2 = tmp2 - a[i];

			sum += a[i];
		}
	}

	ans_x[ans_n] = tmp;
	ans_y[ans_n] = tmp2;
	ans_n++;

	printf( "%d\n" , sum );

	for( i = 0 ; i < ans_n ; i++ ) {
		printf( "%d %d\n" , ans_x[i] , ans_y[i] );
	}

	return 0;
}
