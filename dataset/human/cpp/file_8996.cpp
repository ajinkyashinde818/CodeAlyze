#include <bits/stdc++.h>
using namespace std;

int mod = 1000000007;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<vector<char>> A(N, vector<char>(N));
    vector<vector<char>> B(M, vector<char>(M));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> A[i][j];
        }
    }
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> B[i][j];
        }
    }

    bool ans = false;
    for (int i = 0; i < N - M + 1; i++)
    {
        for (int j = 0; j < N - M + 1; j++)
        {
            bool x = false;//違う画素があるか
            for (int k = 0; k < M ; k++)
            {
                for (int l = 0; l < M ; l++)
                {
                    if (A[i + k][j + l] != B[k][l])
                        x = true;
                }
            }
            if(!x)
                ans = true;
            if (ans)
                break;
        }
        if(ans)
            break;
    }
    cout << (ans ? "Yes" : "No");
}
