#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,c=1,now=0,mod=1e9+7,res=1;char s[212345];scanf("%d%s",&n,s);
    for (int i=1;i<n+n;++i) (now^=(s[i]==s[i-1]))?(res=1ll*res*c%mod,--c):(++c);
    for (int i=2;i<=n;++i) res=1ll*res*i%mod;
    return 0*printf("%d",(s[0]=='W'||c)?0:res);
}
