#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#define loop(i, l, r) for(i=l; i<r; i++)/*Instead of function, (for).*/
#define rep(i,r) for(i=0; i<r; i++)
#define Max(a, b) ((a) > (b) ? (a) : (b))
#define Min(a, b) ((a) < (b) ? (a) : (b))
typedef long long int lli;
/*Return Combination ,(nCr)*/
int combi(int n, int r)
{
	if(r==0 || r==n) return 1;
	else return combi(n-1,r) + combi(n-1,r-1);
}
/*Return gcd(a, b)*/
int gcd(int a, int b){
	if(b == 0) return a;
	else return gcd(b, a % b);
}
int main(void)
{
	int n, i, satis=0;
	scanf("%d", &n);
	int a[n+1], b[n], c[n-1];

	rep(i,n) scanf("%d", &a[i]);
	rep(i,n) scanf("%d", &b[i]);
	rep(i,n-1) scanf("%d", &c[i]);

	int old = a[0];
	rep(i,n){
		satis += b[a[i] - 1];
		if(a[i] == old + 1){
			satis += c[old - 1];
		}
		old = a[i];
	}
	printf("%d", satis);
	return 0;
}
