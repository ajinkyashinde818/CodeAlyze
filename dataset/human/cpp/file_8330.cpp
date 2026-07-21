#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N, M;
    vector<string> A;
    vector<string> B;

    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        A.push_back(s);
    }
    for (int i = 0; i < M; i++)
    {
        string s;
        cin >> s;
        B.push_back(s);
    }

    for (int i = 0; i <= N - M; i++)
    {
        for (int j = 0; j <= N - M; j++)
        {
            bool flg = true;
            for (int k = 0; k < M; k++)
            {
                for (int l = 0; l < M; l++)
                {
                    if (A[i + k][j + l] != B[k][l])
                    {
                        flg = false;
                        break;
                    }
                }
                if (!flg)
                {
                    break;
                }
            }
            if (flg)
            {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;

    return 0;
}
