#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<vector<char>> A, B;
    for (int i = 0; i < N; i++)
    {
        vector<char> tmp;
        for (int j = 0; j < N; j++)
        {
            char n;
            cin >> n;
            tmp.push_back(n);
        }
        A.push_back(tmp);
    }
    for (int i = 0; i < M; i++)
    {
        vector<char> tmp;
        for (int j = 0; j < M; j++)
        {
            char n;
            cin >> n;
            tmp.push_back(n);
        }
        B.push_back(tmp);
    }
    bool judge = false;
    for (int i = 0; i <= N - M; i++)
    {
        for (int j = 0; j <= N - M; j++)
        {
            bool match = true;
            for (int k = 0; k < M; k++)
            {
                for (int n = 0; n < M; n++)
                {
                    if (A[i + k][j + n] != B[k][n])
                    {
                        match = false;
                    }
                }
            }
            if (match)
            {
                judge = true;
            }
        }
    }
    if (judge)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}
