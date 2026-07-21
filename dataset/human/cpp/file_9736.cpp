#include<bits/stdc++.h>
using namespace std;
const int _=1e5+5,yl=1e9+7;
void inc(int &x,int y){x+=y;if(x>=yl)x-=yl;}
long long  n,ans,F[26];string s;

int main(){
	cin>>n>>s;ans=1;
	for(int i=0;i<n;++i)F[s[i]-'a']++;
	for(int i=0;i<26;++i)ans=ans*(F[i]+1)%yl;
	--ans;cout<<ans<<endl;
}
