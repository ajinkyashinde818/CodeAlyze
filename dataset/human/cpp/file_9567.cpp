#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N,M;
    bool yn = false;
    cin >> N >> M;
    char A[N][N] = {'-'};
    char B[M][M] = {'-'};

    // string A
    for(int i=0; i<N; i++)
    {
        string str;
        cin >> str;
        for(int j=0; j<N; j++)
        {
            A[i][j] = str[j];
        }
    }

    // string B
    for(int i=0; i<M; i++)
    {
        string str;
        cin >> str;
        for(int j=0; j<M; j++)
        {
            B[i][j] = str[j];
        }
    }

    for(int i=0; i<=N-M; i++)
    {
        bool b = false;
        for(int j=0; j<=N-M; j++)
        {
            bool isMatch = true;
            for(int k=0; k<M; k++)
            {
                for(int l=0; l<M; l++)
                {
                    if(A[i+k][j+l]!=B[k][l])
                        isMatch = false;
                }
            }
            if(isMatch)
            {
                yn = true;
                break;
            }
        }
        if(yn) break;
    }

    if(yn) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
