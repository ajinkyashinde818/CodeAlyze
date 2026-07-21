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
#define RFOR(i,s,n) for(int i=(int)(n)-1,i##_len=(int)(s);i>=i##_len;i--)

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

int diff[4][2] = {
	{ 0, -1 },
	{ -1, 0 },
	{ 1, 0 },
	{ 0, 1 },
};
//今回の変数
int b[100000];
int l[100000];
int u[100000];
ll d[100000];
ll idx[100000];
ll sum;

int Min(int a, int b) {
	return (a)<(b) ? (a) : (b);
}
int Max(int  a, int  b) {
	return (a) > (b) ? (a) : (b);
}
ll Minl(ll a, ll b) {
	return (a)<(b) ? (a) : (b);
}
ll Maxl(ll a, ll b) {
	return (a)>(b) ? (a) : (b);
}

int main() {
	int n,m;
	scanf("%d%d", &n, &m);

	ll dp[100001] = { 0 };
	dp[0] = 1;
	int a=-1;
	int cnt = 0;
	if (m==0) {
		dp[1] = 1;
	}
	else {
		scanf("%d", &a);
		cnt++;
		if (a != 1) {
			dp[1] = 1;
		}
		else {
			dp[1] = 0;
			scanf("%d", &a);
			cnt++;
		}
	}
	FOR(i, 2, n+1) {
		if (a != i) {
			dp[i] = (dp[i - 1] + dp[i - 2])%MOD;
			//PRINTL(dp[i]);
			continue;
		}

		dp[i] = 0;
		if(cnt<m)scanf("%d", &a);
		//PRINTL(dp[i]);
	}
	PRINTL(dp[n]);
}
