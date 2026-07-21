#include <iostream>
using namespace std;
main()
{
    int R,G,B,N,ret = 0;;
    cin >> R >> G >> B >> N;
    for (int r = 0; r * R <= N; r++)
    {
        for (int g = 0; g * G <= N; g++)
        {
            if (r * R + g * G <= N && (N - r * R - g * G) % B == 0)
            {
                ret++;
            }
        }
    }
    cout << ret << endl;
    return 0;
}
