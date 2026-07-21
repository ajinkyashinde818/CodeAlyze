#include <iostream>

using namespace std;

int main()
{
    int R, G, B, N;
    cin >> R >> G >> B >> N;

    int ans = 0;
    for (int delim1 = 0; delim1 <= N; delim1++)
    {
        for (int delim2 = delim1; delim2 <= N; delim2++)
        {
            if (delim1 % R == 0 && (delim2 - delim1) % G == 0 && (N - delim2) % B == 0)
            {
                ans++;
            }
        }
    }
    cout << ans << endl;
}
