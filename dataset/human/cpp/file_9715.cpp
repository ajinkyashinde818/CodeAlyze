#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    long long N;
    string S;

    cin >> N;
    cin >> S;

    long long cnt[26];
	for (int i = 0; i < 26; ++i) {
		cnt[i] = 0;
	}
  
    for(int i=0; i<N; ++i)
    {
        cnt[S[i]-'a']++;
    }

    const long long MOD = 1000000007;

	long long ans = 1;
	for (int i = 0; i < 26; ++i) {
		ans = ans * (1 + cnt[i]) % MOD;
	}
    ans = (ans - 1) % MOD;
	cout << ans << endl;

    return 0;
}
