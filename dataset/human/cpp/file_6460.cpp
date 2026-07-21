#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
char s[200100];
int n,ans=1,num;
int main(){
    int i,j,k;
    scanf("%d",&n);
    scanf("%s",s);
    for(i=0;i<2*n;i++)
      if(!(((s[i]=='W')^num)&1))num++;
        else ans=1ll*ans*num%mod,num--;
    if(num!=0){puts("0");return 0;}
    for(i=1;i<=n;i++)ans=1ll*ans*i%mod;
    printf("%d\n",ans);
	return 0;
}
