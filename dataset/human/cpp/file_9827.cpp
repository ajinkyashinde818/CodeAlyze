#include<bits/stdc++.h>
using namespace std;
template<class T>inline void init(T&x){
	x=0;char ch=getchar();bool t=0;
	for(;ch>'9'||ch<'0';ch=getchar()) if(ch=='-') t=1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch-48);
	if(t) x=-x;return;
}
int n;
const int N=1e5+10;
const int mod=1e9+7;
typedef long long ll;
char S[N];
template<class T>inline void Inc(T&x,int y){x+=y;if(x>=mod) x-=mod;return;}
template<class T>inline void Dec(T&x,int y){x-=y;if(x < 0 ) x+=mod;return;}
int cnt[26];
int main()
{
	init(n);cin>>(S+1);
	for(int i=n;i;--i) ++cnt[S[i]-'a'];
	int ans=1;
	for(int i=0;i<26;++i) {
		ans=(ll)ans*(cnt[i]+1)%mod;
	}
	Dec(ans,1);
	cout<<ans<<endl;
	return 0;
}
