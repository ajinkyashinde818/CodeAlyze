#include <iostream>
using namespace std;
int main()
{
    int R, G, B, N, cnt = 0;
    cin >> R >> G >> B >> N;
    for (int i = 0; i * R <= N; i++)
    {
        for (int j = 0; i * R + j * G <= N; j++)
        {
            if ((N - (i * R + j * G)) % B == 0)
            {
                cnt++;
            }
        }
    }
    cout << cnt << endl;
}
