#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        int r,g,b,n,rs=0;
        cin>>r>>g>>b>>n;
        for(int i=0;r*i<=n;i++)
        {
                for(int j=0;r*i+g*j<=n;j++)
                {
                        int lf=n-r*i-g*j;
                        rs+=((lf%b)==0);
                }
        }
        cout<<rs<<"\n";
        return 0;
}
/**

**/
