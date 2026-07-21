#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"
#include "numeric"
#include "cassert"
#include "ctime"

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(begin, i, end) for (int i = begin; i < (int)(end); i++)
#define all(v) v.begin(), v.end()
const int MOD = 1000000007;

int main()
{
    ll N, M;
    cin >> N >> M;
    vector<string> A(N), B(M);
    rep(0, i, N)
    {
        cin >> A.at(i);
    }
    rep(0, i, M)
    {
        cin >> B.at(i);
    }

    for (ll i = 0; i <= N - M; i++)
    {
        for (ll j = 0; j <= N - M; j++)
        {
            ll flag = 1;

            for (ll k = 0; k < M; k++)
            {
                for (ll l = 0; l < M; l++)
                {
                    if (A.at(i + k).at(j + l) != B.at(k).at(l))
                    {
                        flag = 0;
                    }
                }
            }

            if (flag == 1)
            {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
}
