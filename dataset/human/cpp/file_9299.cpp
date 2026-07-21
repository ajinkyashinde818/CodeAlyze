#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <array>
#include <cmath>
#include <iterator>
#include <utility>
#include <set>
#include <random>
#include <map>
#include <stack>
#include <queue>
#include <list>
 
using namespace std;
 
 
// "#"は1 ","は0
int main() {
    int N, M;
    char tmp;
    bool flag = false;
    bool flag2 = false;
 
    cin >> N >> M;
    //vector <vector<int>> v1, v2;
    //
    //v1 = vector<vector<int>>(N, vector<int>(N, 0));
 
    //v2 = vector<vector<int>>(M, vector<int>(M, 0));
 
    int v1[50][50];
    int v2[50][50];
 
 
 
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < N; j++)
        {
            cin >> tmp;
            if (tmp == '#')
            {
                v1[i][j] = 1;
            }
            else
            {
                v1[i][j] = 0;
            }
        }
    }
 
    for (size_t i = 0; i < M; i++)
    {
        for (size_t j = 0; j < M; j++)
        {
            cin >> tmp;
            if (tmp == '#')
            {
                v2[i][j] = 1;
            }
            else
            {
                v2[i][j] = 0;
            }
        }
    }
 
    // 探索
    for (size_t i = 0; i <= N - M; i++)
    {
        for (size_t j = 0; j <= N - M; j++)
        {
            for (size_t k = 0; k < M; k++)
            {
                for (size_t l = 0; l < M; l++)
                {
                    if (v1[i + k][j + l] == v2[k][l])
                    {
                        flag = true;
                    }
                    else
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag == false)
                {
                    break;
                }
                
            }
            if (flag == true)
            {
                flag2 = true;
                break;
            }
        }
        if (flag2 == true)
        {
            break;
        }
    }
 
 
    if (flag2)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
 
    return 0;
}
