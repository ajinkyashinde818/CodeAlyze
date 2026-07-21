#include <bits/stdc++.h>
using namespace std;

int	main()
{
    int R, G, B, N;
    cin >> R >> G >> B >> N;
    int64_t cnt = 0;
    for (int r = 0; R * r <= N; ++r) {
        for (int g = 0; R * r + G * g <= N; ++g) {
            if ((N - (R * r + G * g)) % B == 0)
                ++cnt;
        }
    }
    cout << cnt << endl;
}
