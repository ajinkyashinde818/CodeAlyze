#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
typedef long long LL;
typedef long double Lf;
#define Rep(i,a,n)for(int i=(int)(a);i<(int)(n);i++)
#define rep(i,n)Rep(i,0,n)
#define Ma(x,y) ((x)>(y)?(x):(y))
#define mi(x,y) ((x)<(y)?(x):(y))
#define N 100009
#define MOD 1000000007
int acs(const void* a, const void* b) { return *(int*)a - *(int*)b; }//1,2,3,4
int des(const void* a, const void* b) { return *(int*)b - *(int*)a; }//8,7,6,5
int cmp_char(const void* a, const void* b) { return *(char*)a - *(char*)b; }//a,b,c,d
int cmp_str(const void* a, const void* b) { return strcmp(*(const char**)a, *(const char**)b); }//aaa,aab
//temmie_のsnippet

int main() {
	int a[27],n;char s[N];LL ans=1;
	rep(i,26)a[i]=1;
	scanf("%d%s",&n,s);
	rep(i,n)a[s[i]-97]++;
	rep(i,26){ans*=a[i];ans%=MOD;}
	printf("%lld",ans-1);
	return 0;
}
