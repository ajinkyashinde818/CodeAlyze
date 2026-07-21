#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    char A[N][N], B[M][M];

    for (int h = 0; h < N; ++h)
    {
        for (int w = 0; w < N; ++w){
            cin >> A[h][w];
        }
    }

    for (int h = 0; h < M; ++h)
    {
        for (int w = 0; w < M; ++w)
        {
            cin >> B[h][w];
        }
    }

    bool ans = false;
    for (int ly = 0; ly < N; ++ly){
        for (int lx = 0; lx < N; ++lx){
            if (ly + M - 1 >= N or lx + M - 1 >= N)
                continue;

            bool match = true;
            for (int y = 0; y < M; ++y)
            {
                for (int x = 0; x < M; ++x)
                {
                    if (A[ly + y][lx + x] != B[y][x])
                        match = false;
                }
            }
            if (match)
                ans = true;
        }
    }

    if (ans)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}
