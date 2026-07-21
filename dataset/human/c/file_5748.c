#include <stdio.h>

#define REP(i,n) for(int i = 0; i < (n); i++)
#define RREP(i,n) for(int i = (n) - 1; i >= 0; i--)
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define RFOR(i,b,a) for(int i = (b) - 1; i >= (a); i--)
#define STRS(i,str) for(int i = 0; (str)[i]; i++)
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAXI(a,b) if(a < (b)) a = (b)
#define MINI(a,b) if(a > (b)) a = (b)

int main(){
	int n;
	int a;
	int min, max;
	scanf("%d%d%d", &n, &min, &a);
	max = a - min;
	MINI(min, a);
	FOR(i, 2, n){
		scanf("%d", &a);
		MAXI(max, a - min);
		MINI(min, a);
	}
	printf("%d\n", max);
}
