#include <iostream>

using namespace std;

int main()
{
    int R,G,B,N;
    cin >> R >> G >> B >> N;
    int ct = 0;

    int lim1 = N/R;
    for (int i = 0; i <= lim1; ++i)
    {
        int lim2 = (N-i*R)/G;
        for (int j = 0; j <= lim2; ++j)
            if ((N-i*R-j*G)%B == 0)
            {
                ++ct;
            }
    }
    cout << ct << endl;

    return 0;
}
