#include <bits/stdc++.h>

using namespace std;

bool doit(int i, int j, vector<string> &A, vector<string> &B)
{
    if (i + B.size() > A.size() || j + B.size() > A.size())
        return false;
    for (int _i = i; _i - i < B.size(); _i++)
        for (int _j = j; _j - j < B.size(); _j++)
            if (B[_i - i][_j - j] != A[_i][_j])
                return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<string> A(n);
    vector<string> B(m);
    for (string &s : A)
        cin >> s;
    for (string &s : B)
        cin >> s;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (doit(i, j, A, B))
            {
                cout << "Yes\n";
                return 0;
            }
    cout << "No\n";
    return 0;
}
