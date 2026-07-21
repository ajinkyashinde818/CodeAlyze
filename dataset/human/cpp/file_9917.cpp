/// 一开始题意就理解错了
#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 10,MOD = 1e9 + 7;
typedef long long LL;
int cnt[26];
char str[maxn];
LL mut(LL a,LL b){
	return (a%MOD)*(b%MOD) %MOD;
}
int main(){
	int N;
	scanf("%d%s",&N,str);
	for(int i = 0 ; i < N; ++i) ++cnt[str[i] - 'a'];
	LL ans = 1;
	for(int i = 0 ; i < 26 ; ++i){
		ans = mut(cnt[i]+1,ans);
	}
	cout<<ans-1<<endl;
	return 0;
}
