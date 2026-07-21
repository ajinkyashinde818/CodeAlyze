#include <bits/stdc++.h>
using namespace std;

int T;
typedef long long ll;
ll N;

ll p3[50], h[50];
ll MAX = (1LL<<50);

int main()
{
    p3[0] = 1;
    h[0] = 1;
    int mxh;
    for(int i = 1; ; i++)
    {
        p3[i] = p3[i-1]*3;
        h[i] = h[i-1]+p3[i-1]+p3[i];
        if( p3[i] > MAX )
        {
            mxh = i;
            break;
        }
    }

    T=1;
    while(T--)
    {
        cin>>N;
        if(N==0)
        {
            cout<<0<<'\n';
            continue;
        }
        N++;
        ll ans = 0;
        int H = 0;
        while( h[H+1] <= N )H++;
        N-=h[H];
        ans+=H*2+1;
        //cout<<ans<<'\n';
        for( int i = H; i>=0; i-- )
        {
            if( N >= p3[i] )
            {
                ans+=N/p3[i];
                N%=p3[i];
            }
            //cout<<N<<' '<<ans<<'\n';
        }
        cout<<ans-1<<'\n';
    }

    return 0;
}
