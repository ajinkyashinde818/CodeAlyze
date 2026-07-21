#include <iostream>
#include <map>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <limits>

using namespace std;

typedef unsigned long long ull;

int main()
{
    int m, n;
    string M[50];
    string N[50];
    
    cin >> n >> m;
    
    for (int i = 0; i < n; i++)
    {
        cin >> N[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> M[i];
    }
    
    bool isFound = false;
    for (int i = 0; i <= n - m; i++)
    {
        for (int j = 0; j <= n - m; j++)
        {
            if (N[i].find(M[0].c_str(), j) == static_cast<size_t>(j))
            {
                isFound = true;
                for (int k = 1; k < m; k++)
                {
                    if (N[i+k].find(M[k].c_str(), j) != static_cast<size_t>(j))
                    {
                        isFound = false;
                        break;
                    }
                }
            }
            if (isFound)
            {
                break;
            }
        }
        if (isFound)
        {
            break;
        }
    }
    
    printf("%s\n", isFound ? "Yes" : "No");
    
    return 0;
}
