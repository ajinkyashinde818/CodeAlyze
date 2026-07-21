#include <cstdio>
#include <unordered_map>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>
using namespace std;
const int N = 100001;
int n, k;
vector<int>g[N];
int main()
{
    scanf("%d", &n);
    k = 1;
    while ((long long)k * (k - 1) / 2 < n) k += 1;
    if ((long long) k * (k  - 1) / 2 == n)
    {
        printf("Yes\n");
        printf("%d\n", k);
        for (int i = 1; i <= k ; i ++)
            for (int j = i + 1; j <= k ; j++)
            {
                g[i].push_back(n);
                g[j].push_back(n);
                n -= 1;
            }
        for (int i = 1; i <= k ; i++)
        {
            printf("%d", g[i].size());
            for (int j = 0; j < g[i].size();j ++)
                printf(" %d", g[i][j]);
            printf("\n");
        }
    }
    else
        printf("No");
    return 0;
}
