#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <cmath>
using namespace std;
typedef long long i64;
typedef long double ld;
typedef pair<i64,i64> P;
#define rep(i,s,e) for(int i = (s);i <= (e);i++)

int n;
int m;

string A[50];

string B[50];

int main()
{
    cin >> n >> m;
    for(int i = 0;i < n;i++)
    {
        cin >> A[i];
    }
    for(int i = 0;i < m;i++)
    {
        cin >> B[i];
    }

    for(int i = 0;i + m - 1 < n;i++)
    {
        for(int j = 0;j + m - 1 < n;j++)
        {
            bool same = true;
            for(int x = i;x < i + m;x++)
            {
                for(int y = j;y < j + m;y++)
                {
                    if(A[x][y] != B[x - i][y - j])
                    {
                        same = false;
                    }
                }
            }

            if(same)
            {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}
