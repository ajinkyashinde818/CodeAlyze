#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long LL;
const int MAXN=2e5+5;
const int MOD=1000000000;
const LL INF=(2e5)*(1e9)+5;
LL a[MAXN];
LL sum[MAXN];

int main()
{
    ios::sync_with_stdio(false);
    int n;
    while(cin>>n)
    {
        LL tot=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            sum[i]=sum[i-1]+a[i];
            tot+=a[i];
        }
        LL Min=INF;
        for(int i=1;i<n;i++)
        {
            if(Min>abs(2*sum[i]-tot))
                Min=abs(2*sum[i]-tot);
        }
        cout<<Min<<endl;
    }

    return 0;
}
