/*  include  */
#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <locale.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <setjmp.h>
#include <string.h>
#include <signal.h>
#include <stdarg.h>
#include <stdbool.h>

/*  typedef  */
typedef long long ll;
typedef char string[100];

/*  define  */

	/*  define funcs  */
#define sort_d(array,end){int size=end-array;qsort(array,size,sizeof(int),intcmp);}
#define sort_c(array,end){int size=end-array;qsort(array,size,sizeof(char),charcmp);}
#define rand_range(min,max) (min)+(rand())%((max)-(min)+(1))
#define rep(i,j) for(int i=0;i<j;i++)
#define swap(a,b) ((a!=b)&&(a+=b,b=a-b,a-= b))
#define getarray_d(array,size){array=(int *)malloc(sizeof(int)*size);}
#define getarray_c(array,size){array=(char *)malloc(sizeof(char)*size);}
#define fill(array,end,val){int size=end-array;rep(i,size)array[i]=val;}
/*  otter  �\�J���E�\�\  */
#define intptr int *
#define random srand((unsigned)time(NULL))
#define ON 1
#define OFF 0
#define TREE_SIZE 1000
#define MATRIX_SIZE 10

/*  include my header  */


/*  functions in funcs.h  */

int intcmp(const void* a, const void* b);
int charcmp(const void* a, const void* b);
bool is_sorted(const int* start, const int* end);
int count(const int* start, const int* end, int target);
void shuffle(int* start, int* end);
void tree_init(void);
int tree_root(int x);
void unite(int x, int y);
bool same(int x, int y);

int intcmp(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
}

int charcmp(const void* a, const void* b)
{
	return *(char*)a - *(char*)b;
}

bool is_sorted(const int* start, const int* end)
{
	while (start != end) {
		if (*start > * (start + 1)) return false;
		start++;
	}
	return true;
}

int count(const int* start, const int* end, int target)
{
	int cnt = 0;
	int* array;
	int* p;

	array = (int*)malloc((end - start) * sizeof(int));

	if (array == NULL) {
		printf("Err0r");
		exit(-1);
	}

	memcpy(array, start, sizeof(int) * (end - start));
	sort_d(array, array + (end - start));
	p = (int*)bsearch(&target, array, end - start, sizeof(int), intcmp);

	if (p == NULL) {
		free(array);
		return 0;
	}
	while (*p == target)
		p++;
	p--;
	while (*p == target) {
		cnt++;
		p--;
	}

	free(array);

	return cnt;
}

void shuffle(int* start, int* end)
{
	random;

	int a, b;
	int size = end - start;

	rep(i, 500) {
		a = rand_range(0, size - 1);
		b = rand_range(0, size - 1);
		swap(start[a], start[b]);
	}
}
int tree[TREE_SIZE];

void tree_init(void)
{
	for (int i = 0; i < TREE_SIZE; i++) tree[i] = i;
}

int tree_root(int x)
{
	if (tree[x] == x) return x;
	return tree[x] = tree_root(tree[x]);
}

void unite(int x, int y)
{
	int rx = tree_root(x);
	int ry = tree_root(y);
	if (rx == ry) return;
	tree[rx] = ry;
}

bool same(int x, int y)
{
	int rx = tree_root(x);
	int ry = tree_root(y);
	return rx == ry;
}

void matrix_pow(int matrix[][MATRIX_SIZE], int ans_matrix[][MATRIX_SIZE], int num, int n)
{
	int ans;
	rep(cnt, n - 1) {
		rep(i, num) {
			rep(j, num) {
				ans = 0;
				rep(k, num) {
					ans += matrix[i][k] * matrix[k][j];
				}
				ans_matrix[i][j] = ans;
			}
		}
	}
}

/*  scan  */
#define sd(a) scanf("%d",&a);
#define sc(a) scanf("%c",&a), getchar();
#define sf(a) scanf("%f",&a);
#define ss(a) scanf("%s",a);

/*  print  */
#define odn(a) printf("%lld\n",a);
#define ocn(a) printf("%c\n",a);
#define ofn(a) printf("%f\n",a);
#define osn(a) printf("%s\n",a);
#define od(a) printf("%d ",a);
#define oc(a) printf("%c ",a);
#define of(a) printf("%f ",a);
#define os(a) printf("%s ",a);

int word_chop(char* strs, char words[][100])
{
	int cnt = 0;
	int w = 0;
	while (*strs != '\0') {
		if (*strs == ' ') {
			w++;
			cnt = 0;
			*strs++;
		}
		words[w][cnt] = *strs;
		strs++;
		cnt++;
	}
	return w + 1;
}

ll pow_mod(ll n, ll k, ll m)
{
	if (k == 0) return 1;
	else if (k % 2) return pow_mod(n, k - 1, m) * n % m;
	else {
		int t = pow_mod(n, k / 2, m);
		return t * t % m;
	}
}


/*  struct  */
typedef struct {
	int first;
	int second;
}pair;
void sort_first(pair* b, pair* e)
{
	int* dec;
	int s2 = e - b;
	int size = e - b;
	getarray_d(dec, size);
	rep(i, size) dec[i] = b[i].first;
	sort_d(dec, dec + s2);
	rep(i, size) b[i].first = dec[i];
}
void sort_second(pair* b, pair* e)
{
	int* dec;
	int s2 = e - b;
	int size = e - b;
	getarray_d(dec, size);
	rep(i, size) dec[i] = b[i].second;
	sort_d(dec, dec + s2);
	rep(i, size) b[i].second = dec[i];
}
/*  local val  */
//None


/*  main program  */
int main()
{
	int N,R;
	sd(N);
	sd(R);
	if(N<10){
		od(R+(100*(10-N)));
	}else{
		od(R);
	}
}
