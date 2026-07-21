#include <stdio.h>

#define REP(i,n) for(int i=0;i<(n);i++)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define RFOR(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define STR(i,str) for(int i=0;(str)[i];i++)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX3(a,b,c) ((a)>(b)?(a)>(c)?(a):(c):(b)>(c)?(b):(c))
#define MIN3(a,b,c) ((a)<(b)?(a)<(c)?(a):(c):(b)<(c)?(b):(c))
#define RNG(a,b) ((a)>(b)?(a)-(b):(b)-(a))
#define RNG3(a,b,c) ((a)>(b)?(b)>(c)?(a)-(c):(c)>(a)?(c)-(b):(a)-(b):(b)>(c)?(c)>(a)?(b)-(a):(b)-(c):(c)-(a))
#define MAXS(a,b) {if((a)<(b))(a)=(b);}
#define MINS(a,b) {if((a)>(b))(a)=(b);}

int main(){
	int n;
	scanf("%d", &n);
	puts(n%10 == 9 || 90 <= n && n <= 99 ? "Yes" : "No");
}
