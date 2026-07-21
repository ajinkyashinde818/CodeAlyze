#include <iostream>

using namespace std;

int main()
{
    int R, G, B, N;
    cin >> R >> G >> B >> N;

    int completeCount = 0;

    int maxR = N / R;
    for(int i_R = 0; i_R < maxR + 1; i_R++)
    {
        // 残数
        int remainingN_R = N - R * i_R;
        if(remainingN_R < 0) break;

        int maxG = remainingN_R / G;
        for(int i_G = 0; i_G < maxG + 1; i_G++)
        {
            int remainingN_G = remainingN_R - G * i_G;
            if(remainingN_G < 0) break;

            if(remainingN_G % B == 0)
            {
                completeCount++;
            }
        }
    }

    cout << completeCount << endl;
}
