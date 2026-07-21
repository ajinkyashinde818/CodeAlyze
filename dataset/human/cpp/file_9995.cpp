#include<stdio.h>
#include<string.h>
#include<utility>
#include<iostream>
#include<queue>
#include<math.h>
#include<algorithm>
#include<vector>
#include<map>
#include<stack>

using namespace std;
typedef long long ll;
#define REP(i,n) for(int i=0;i<(int)(n);i++)

int main()
{
    long int n;
    char s[100005]={};
    scanf("%ld\n%s",&n,s);
    int ch[27]={};
    REP(i,n){
        ch[s[i]-'a']++;
    }
    long long int ans=1;
    REP(i,26){
        ans*=ch[i]+1;
        ans%=1000000007;
    }
    ans-=1;
    if(ans<0)ans+=1000000007;
    printf("%lld\n",ans);
    return 0;
}
