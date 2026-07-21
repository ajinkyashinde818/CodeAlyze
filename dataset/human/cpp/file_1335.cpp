#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int r, g, b, r_rem, g_rem, n, count = 0, ball[3];
    cin >> ball[0];
    cin >> ball[1];
    cin >> ball[2];
    cin >> n;
    sort(ball, ball + 3, greater<int>());
    r = n / ball[0];
    r_rem = n % ball[0];
    for(int i = r; i >= 0; i--)
    {
        if(r_rem == 0) 
        {
            count += 1;
            r_rem += ball[0];
            continue;
        }
        g = r_rem / ball[1];
        g_rem = r_rem % ball[1];
        for(int j = g; j >= 0; j--)
        {
            if((g_rem == 0) || (g_rem % ball[2] == 0))
            {
                count += 1;
                g_rem += ball[1];
                continue;
            }
            g_rem += ball[1];
        }
        r_rem += ball[0];
    }
    cout << count << endl;
    return 0;
}
