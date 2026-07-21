#include<bits/stdc++.h>
using namespace std;

int main()
{
    int R, G, B, N;
    cin >> R >> G >> B >> N;

    int ans = 0;
    for (int r = 0; r <= N; r++)
    {
        int total = N;
        total -= R*r;
        if (total < 0)
            break;
        
        total += G;
        for (int g = 0; g <= N; g++)
        {
            total -= G;
            // cout << total << endl;
            if (total < 0)
                break;
            
            if (total % B == 0)
            {
                ans++;            
                // cout << r << ' ' << g << ' ' << total / B << endl;
            }

        }
    }
    cout << ans << endl;
    return 0;
}
