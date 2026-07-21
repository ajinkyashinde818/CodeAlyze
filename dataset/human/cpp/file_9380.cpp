#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <bitset>
using namespace std;

const long int INF = 1000000007;

bool isInclude(vector<vector<char>> a, vector<vector<char>> b, int M, int x, int y)
{
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (b[i][j] != a[y+i][x+j])
            {
                return false;
            }
            
        }
        
    }

    return true;
}

int main(void)
{
    int N, M;
    cin >> N >> M;
    vector<vector<char>> a(N, vector<char>(N)), b(M, vector<char>(M));
    for (int  i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> a[i][j];
        }
        
    }

    for (int  i = 0; i < M; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> b[i][j];
        }
    }
    
    // 左上のマス
    for (int y = 0; y <= N-M; y++)
    {
        for (int x = 0; x <= N-M; x++)
        {
            // 含まれているか
            if (isInclude(a, b, M, x, y))
            {
                cout << "Yes" << endl;
                return 0;
            }
                        
        }
        
    }

    cout << "No" << endl;
    return 0;
}
