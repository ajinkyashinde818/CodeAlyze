#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<string> A(N);
    for (int r = 0; r < N; r++)
    {
        cin >> A.at(r);
    }
    vector<string> B(M);
    for (int r = 0; r < M; r++)
    {
        cin >> B.at(r);
    }

    for (int ra = 0; ra < N - M + 1; ra++)
    {
        for (int ca = 0; ca < N - M + 1; ca++)
        {
            bool matched = true;
            for (int r = 0; r < M; r++)
            {
                for (int c = 0; c < M; c++)
                {
                    if (A.at(ra + r).at(ca + c) != B.at(r).at(c))
                    {
                        matched = false;
                        break;
                    }
                }
                if (!matched)
                {
                    break;
                }
            }
            if (matched)
            {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
}
