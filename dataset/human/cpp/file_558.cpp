#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll r, g, b, n;
    cin >> r >> g >> b >> n;

    ll limitr = ceil(n / r);
    ll limitg = ceil(n / g);
    ll ans =0;
    for (int i = 0; i <= limitr; i++)
    {
        for(int j=0;j<=limitg ;j++)
        {
            if( n - i*r - j*g >=0 )
            {
                if( (n - i*r - j*g )%b==0 )
                    ans++;
            }
        }
    }
    cout<<ans;
}
