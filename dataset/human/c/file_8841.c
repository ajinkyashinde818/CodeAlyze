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
#define PRINTL(d) printf("%lld\n",(d))

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
void Swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int main() {
	int h, w;
	scanf("%d %d", &h, &w);
	char s[52][53];
	REPS(i, h) {
		scanf("%s", &s[i][1]);
	}
	REP(i, h+2) {
		s[i][0] == '.';
		REP(j, w + 2) {
			if (i == 0 || i == h + 1)s[i][j] = '.';
		}
		s[i][w + 1] = '.';
		s[i][w + 2] = '\0';
	}

	int flag = 0;
	REPS(i, h+1) {
		if (flag)break;
		REPS(j, w+1) {
			if (flag)break;
			if (s[i][j] == '#') {
				REP(k, 4) {
					if (s[i + diff[k][0]][j + diff[k][1]] == s[i][j])break;
					if (k == 3)flag = 1;
				}
			}
		}
	}
	if (flag) {
		puts("No");
	}
	else {
		puts("Yes");
	}
}
