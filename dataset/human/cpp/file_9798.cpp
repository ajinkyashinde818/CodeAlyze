#include<bits/stdc++.h>
using namespace std;
const int N=100005;
const int P=1e9+7;
int n,cnt[30];char str[N];
int main() {
	scanf("%d%s",&n,str+1);
	for(int i=1; i<=n; i++)
		cnt[str[i]-'a']++;
	long long res=1;
	for(int i=0; i<=25; i++)
		res=(res*(cnt[i]+1))%P;
	printf("%lld\n",(res-1+P)%P);
	return 0;	
}
