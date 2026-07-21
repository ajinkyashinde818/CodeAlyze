#include <algorithm>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <vector>

using namespace std;
using LLONG = long long;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<string> A(N), B(M);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < M; ++i) cin >> B[i];
    for (int x = 0; x <= N - M; ++x)
    {
        for (int y = 0; y <= N - M; ++y)
        {
            bool areSame = true;
            for (int i = 0; i < M; ++i)
            {
                for (int j = 0; j < M; ++j)
                {
                    if (A[x + i][y + j] != B[i][j])
                    {
                        areSame = false;
                        break;
                    }
                }
                if (!areSame) break;
            }
            if (areSame)
            {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;

    return 0;
}
