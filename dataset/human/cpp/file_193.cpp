#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int R, G, B;
    cin >> R >> G >> B;
    int N;
    cin >> N;

    int ans = 0;
    for(int i=0; i<=(N+R-1)/R; i++)
    {
        for(int j=0; j<=(N+G-1)/G; j++)
        {
            if(N >= R*i + G*j && (N - R*i - G*j)%B==0)
            {
                // cout << i << ", " << j << ", " << (N - R*i - G*j)/B << '\n';
                ans++;
            }
        }
    }
    cout << ans << endl;


    return 0;
}
