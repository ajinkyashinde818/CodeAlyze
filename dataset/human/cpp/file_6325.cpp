#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read(){
	ll a=0,b=getchar(),c=1;
	while(!isdigit(b))c=b=='-'?-1:1,b=getchar();
	while(isdigit(b))a=a*10+b-'0',b=getchar();
	return a*c;
}
ll n,x,y,ans=1,mod=1e9 + 7;
string s;
int main(){
	cin >> n >> s;
    for(ll i=2*n-1;i>=0;i--)
        if((i%2==0 and s[i]=='W')or(i%2==1 and s[i]=='B'))x++;
        else (ans*=x)%=mod,x--,y++;
    for(ll i=2;i<=n;i++)
        (ans*=i)%=mod;
    printf("%d",y==n?ans:0);
    return 0;
}
