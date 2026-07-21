#include <bits/stdc++.h>
using namespace std;

int main()
{
    int R, G, B, N;
    cin >> R >> G >> B >> N;

    int res = 0;
    for (int r = 0; r <= N / R; r++)
    {
        for (int g = 0; g <= (N - R * r) / G; g++)
        {
            if ((N - R * r - G * g) % B == 0)
            {
                res++;
            }
        }
    }
    cout << res << endl;
}
