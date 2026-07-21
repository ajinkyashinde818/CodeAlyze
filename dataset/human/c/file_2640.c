#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define i_cin(X) scanf("%d", &X)
#define i_cin2(X,Y) scanf("%d %d",&X,&Y)
#define i_cin3(X,Y,Z) scanf("%d %d %d",&X,&Y,&Z)
#define l_cin(X) scanf("%ld",&X)
#define l_cin2(X,Y) scanf("%ld %ld",&X,&Y)
#define s_cin(X) scanf("%s",&X)

#define  i_cout(X) printf("%d\n",X)
#define  f_cout(X) printf("%g\n",X)
#define  i_cout2(X,Y) printf("%d %d\n",X,Y)
#define  l_cout(X) printf("%ld\n",X)
#define  s_cout(X) printf("%s\n",X)
#define  ll_cout(X) printf("%lld\n",X)

typedef long long int lli;
#define rept(x, s, n) for (int x = s; x < n; x++)

#define Yes_RTN s_cout("Yes");return 0
#define No_RTN  s_cout("No");return 0
#define YES_RTN s_cout("YES");return 0
#define NO_RTN  s_cout("NO");return 0


int i_cins(int n, int* A);
int l_cins2(int n, long* A,long* B);
int s_dsort(const void* a, const void* b);
int s_asort(const void* a, const void* b);


int main(void) {

	char    S[4], s[4] = "abc";
	int     i, j;

	s_cin(S);
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			if (S[i] == s[j]) {
				s[j] = 0x00; break;
			}
		}
		if (j==3) { No_RTN; }
	}
	Yes_RTN;
}
	
int s_dsort(const void* a, const void* b) {
	return(*(int*)b - *(int*)a);
}
int s_asort(const void* a, const void* b) {
	return(*(int*)a -*(int*)b);
}
int l_cins2(int n, long* a, long* b) {
	int i;
	rept(i, 0, n) {
		l_cin2(*(a + i), *(b + i));
	}
	return 0;
}
int i_cins(int n, int* a) {
	int i;
	rept(i, 0, n) {
		i_cin(*(a + i));
	}

	return 0;
}
