#define NDEBUG

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <assert.h>
// for DEBUG {{{
#ifdef NDEBUG
#define DEBUG_PRINT(fmt, ...) ((void)0)
#else
#define DEBUG_PRINT(fmt, ...) fprintf(stderr, fmt, ##__VA_ARGS__)
#endif
#define ASSERT_RANGE(min,x,max) assert(((x)>=(min)) && ((x)<=(max)))
// }}}

typedef long long ll;

#define GET_D(x) fscanf(stdin,"%d",&(x)) > 0
#define GET_LLD(x) fscanf(stdin,"%lld",&(x)) > 0
#define GET_S(x) fscanf(stdin,"%s",(x)) > 0
#define PUT_D(x) fprintf(stdout,"%d\n",(x))

#define FOR(i,min,max) for ((i) = (min); (i) < (max); (i)++)

int sort_int(int *a, int N) {// {{{
	int i;
	for (i = 0; i < N-1; i++) {
		int j;
		for (j = i + 1; j < N; j++) {
			if (a[i] > a[j]) {
				int tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
	}
	return 0;
}// }}}
void merge_int(int *a, int *b, int lower, int sep, int upper) {// {{{
	int i_lower = lower;
	int i_upper = sep;
	int i_b = 0;
	while ((i_lower < sep) && (i_upper < upper)) {
		if (a[i_lower] < a[i_upper]) {
			b[i_b++] = a[i_lower++];
		} else {
			b[i_b++] = a[i_upper++];
		}
	}
	if (i_lower >= sep) {
		while (i_upper < upper) {
			b[i_b++] = a[i_upper++];
		}
	} else {
		while (i_lower < sep) {
			b[i_b++] = a[i_lower++];
		}
	}
	for (i_lower = 0; i_lower < i_b; i_lower++) {
		a[i_lower+lower] = b[i_lower];
	}
}// }}}
void merge_sort_int(int *a, int *b, int lower, int upper) {// {{{
	int sep;
	if ((lower == upper) || (lower + 1 == upper)) {
		return;
	}
	sep = (lower + upper) / 2;
	merge_sort_int(a,b,lower,sep);
	merge_sort_int(a,b,sep,upper);
	merge_int(a,b,lower,sep,upper);
}// }}}


#define N_MIN 1
#define N_MAX 100000

int main(int argc, char **argv) {
	int n;
	int k;
	int h[N_MAX];
	GET_D(n);
	GET_D(k);
	{
		int i;
		FOR(i,0,n) {
			GET_D(h[i]);
		}
	}
	{
		int ret = 0;
		int i;
		FOR(i,0,n) {
			ret += (h[i] >= k);
		}
		PUT_D(ret);
	}
	return 0;
}
