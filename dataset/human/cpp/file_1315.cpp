#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

int main()
{
    int R, G, B, N, ans = 0;
    cin >> R >> G >> B >> N;
    int rmax = N / R;
    for (int i = 0; i < rmax + 1; i++)
    {
        int rest1 = N - R * i;
        int gmax = rest1 / G;
        if (gmax != 0)
        {
            for(int j = 0; j < gmax + 1; j++)
            {
                int rest2 = rest1 - G * j;
                int rest = rest2 % B;
                if (rest == 0) ans++;
                else continue;
            }   
        }
        else
        {
            int rest = rest1 % B;
            if (rest == 0) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
