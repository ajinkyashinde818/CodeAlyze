#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int R, G, B, N;

    cin >> R >> G >> B >> N;

    int ball[3] = {R, G, B};
    sort(ball, ball + 3);

    int answer = 0;

    for (int i = 0; N >= ball[2] * i; i++)
    {
        for (int j = 0; N >= ball[2] * i + ball[1] * j; j++)
        {
            if ((N - ball[2] * i - ball[1] * j) % ball[0] == 0)
            {
                answer++;
            }
        }
    }

    cout << answer << "\n";

    return 0;
}
