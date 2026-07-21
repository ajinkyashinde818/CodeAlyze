#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

//for
#define REP(i,n) for(int i=0,i##_len=(int)(n);i<i##_len;i++)
#define REPS(i,n) for(int i=1,i##_len=(int)(n);i<=i##_len;i++)
#define RREP(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define RREPS(i,n) for(int i=(int)(n);i>0;i--)
#define SREP(i,s,n) for(int i=(int)(s),i##_len=(int)(n);i<i##_len;i++)

//printf
#define PRINTD(d) printf("%d\n",(d))

//memset
#define m0(s) memset(s,0,sizeof(s))
#define ml(s) memset(s,63,sizeof(s))
#define fill(s,c) memset(s,c,sizeof(s))

#define INF 1e9

typedef long long ll;
int diff[4][2] = {
	{ 0, -1 },
	{ -1, 0 },
	{ 1, 0 },
	{ 0, 1 },
};

int Min(int a, int b) {
	return (a)<(b) ? (a) : (b);
}
int Max(int a, int b) {
	return (a) > (b) ? (a) : (b);
}

int main() {
	int n;
	int d, x;
	int a[100];
	scanf("%d %d %d", &n, &d, &x);
	REP(i, n) {
		scanf("%d", &a[i]);
	}
	int cnt = 0;
	REP(i, n) {
		cnt++;
		REPS(j, d) {
			if (j*a[i] + 1 <= d) {
				cnt++;
			}
			else {
				break;
			}
		}
	}
	PRINTD(cnt + x);
}
