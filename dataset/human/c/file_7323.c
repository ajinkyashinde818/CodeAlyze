#define _CRT_SECURE_NO_WARNINGS

/* include ***********************/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

/* define *************************/
//for
#define REP(i,n) for(int i=0,i##_len=(int)(n);i<i##_len;i++)
#define REPS(i,n) for(int i=1,i##_len=(int)(n);i<=i##_len;i++)
#define RREP(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define RREPS(i,n) for(int i=(int)(n);i>0;i--)
#define FOR(i,s,n) for(int i=(int)(s),i##_len=(int)(n);i<i##_len;i++)
#define RFOR(i,s,n) for(int i=(int)(s)-1,i##_len=(int)(n);i>=i##_len;i--)

//printf
#define PRINTD(d) printf("%d\n",(d))
#define PRINTL(d) printf("%lld\n",(d))

//memset
#define m0(s) memset(s,0,sizeof(s))
#define ml(s) memset(s,63,sizeof(s))
#define fill(s,c) memset(s,c,sizeof(s))

#define INF 1e9
#define MOD 1000000007

typedef long long ll;
typedef unsigned long long ull;
int a, b, q;
ll s[200000], t[200000];
ll x;

int diff[4][2] = {
	{ 0, -1 },
	{ -1, 0 },
	{ 1, 0 },
	{ 0, 1 },
};

ll Min(ll a, ll b) {
	return (a)<(b) ? (a) : (b);
}
ll Max(ll  a, ll  b) {
	return (a) > (b) ? (a) : (b);
}
void Swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void hSwap(ll x[], int i, int j)
{
	ll temp;

	temp = x[i];
	x[i] = x[j];
	x[j] = temp;
}
void ShowData(ll x[], int left, int right)
{
	int i;
	for (i = left; i <= right; i++)printf("%lld  ", x[i]);
	printf("\n");
}
void QSort(ll x[], int left, int right, int n) {
	int i, j;	//左端,右端
	ll pivot;	//軸

	i = left;
	j = right;
	pivot = x[(left + right) / 2];

	while (1) {
		if (n > 0) {				//n>0なら昇順、n<=0なら降順
			while ((x[i] < pivot) && (i <= right))i++;	//軸値より大きい要素
			while ((pivot < x[j]) && (i <= right))j--;	//軸値より小さい要素
		}
		else {
			while ((x[i] > pivot) && (i <= right))i++;	//軸値より小さい要素
			while ((pivot > x[j]) && (i <= right))j--;	//軸値より大きい要素
		}
		if (i >= j)	break;
		hSwap(x, i, j);
		i++; j--;
	}
	//ShowData(x, left, right);

	if (left < i - 1)QSort(x, left, i - 1, n);
	if (j + 1 <  right)QSort(x, j + 1, right, n);
}
int binary_search(ll ary[], ll key, int left, int right) {
	if (right < left) return -1;
	int mid = left + (right - left) / 2;
	if (ary[mid] > key) {
		if (mid - 1 < left)return mid-1;
		return binary_search(ary, key, left, mid - 1);
	}
	else if (ary[mid] < key) {
		if (mid + 1 > right)return mid;
		return binary_search(ary, key, mid + 1, right);
	}
	else {
		return mid;
	}
}

ll absl(ll num) {
	if (num < 0)return -num;
	return num;
}

int main() {
	scanf("%d%d%d", &a, &b, &q);
	REP(i, a) {
		scanf("%lld", &s[i]);
	}
	REP(i, b) {
		scanf("%lld", &t[i]);
	}
	QSort(s, 0, a-1, 1);
	QSort(t, 0, b - 1, 1);
	//ShowData(s, 0, a - 1);
	//ShowData(t, 0, b - 1);
	REP(i, q) {
		scanf("%lld", &x);
		int o = binary_search(s, x, 0, a - 1);
		int p = binary_search(t, x, 0, b - 1);
		//printf("o=%d p=%d\n", o, p);
		ll u[2], v[2];
		u[0] = ((o == -1) ? -1e15 : s[o]);
		v[0] = ((p == -1) ? -1e15 : t[p]);
		u[1] = ((o == a-1) ? 1e15 : s[o+1]);
		v[1] = ((p == b-1) ? 1e15 : t[p+1]);
		//printf("%lld %lld %lld %lld\n", u[0], v[1], u[0], v[1]);
		ll ans = 1e18;
		REP(i, 2) {
			REP(j, 2) {
				ans = Min(ans, absl(x - u[i]) + absl(u[i] - v[j]));
				ans = Min(ans, absl(x - v[j]) + absl(v[j] - u[i]));
			}
		}
		PRINTL(ans);
	}
}
