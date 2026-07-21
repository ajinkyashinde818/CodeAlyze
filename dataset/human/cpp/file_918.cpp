#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int R, G, B, N;
    cin >> R >> G >> B >> N;

    long long ans = 0LL;
    for (int r = 0; r <= 3000; r++)
    {
        for (int g = 0; g <= 3000; g++)
        {
            if ((r * R + g * G == N) || (r * R + g * G < N && (N - r * R - g * G) % B == 0))
            {
                ans++;
            }
        }
    }
    cout << ans << endl;

    return 0;
}
