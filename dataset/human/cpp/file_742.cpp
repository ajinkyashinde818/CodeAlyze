#include<bits/stdc++.h>
using namespace std;

int R, G, B, N;

int main()
{
    cin >> R >> G >> B >> N;

    int ans = 0;
    for(int i = 0; i <= N; i++)
    {
        for(int j = 0; j <= N; j++)
        {
            if((N - i * R - j * G) % B == 0 && (N - i * R - j * G) >= 0)ans++;
        }
    }

    cout << ans << endl;
    return 0;
}
