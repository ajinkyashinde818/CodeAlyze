#include <stdio.h>

int N; long long L; char S[100100];
int cnt,tr[100100][2],dp[100100],chk[100100];

int main()
{
	scanf ("%d %lld",&N,&L);
	while (N--){
		scanf ("%s",S);
		int now = 0;
		for (int i=0;S[i];i++){
			int &nxt = tr[now][S[i]-'0'];
			if (!nxt){
				nxt = ++cnt;
				dp[nxt] = dp[now] + 1;
			}
			now = nxt;
		}
	}

	long long win = 0;
	for (int i=0;i<=cnt;i++) if ((!tr[i][0]) ^ (!tr[i][1])){
		long long x = L - dp[i];
		win ^= x & (-x);
	}
	puts(win?"Alice":"Bob");

	return 0;
}
