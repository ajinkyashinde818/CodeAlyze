#include <bits/stdc++.h>
using namespace std;

int main()
{
    int R,G,B,N;
    cin >> R >> G >> B >> N;

    int ans=0;
    for(int r=0;r<=N;++r)
    {
        for(int g=0;g<=N;++g)
        {
            int b = (N-r*R-g*G)/B;
            if (0<=b&&(r*R+g*G+b*B)==N)
            {
                ans++;
            }
        }
    }
    cout << ans << endl;
}
