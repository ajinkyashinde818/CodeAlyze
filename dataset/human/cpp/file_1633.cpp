#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <functional>
#include <cstdlib>
#include <queue>

std::vector<int> v[1000];
int main()
{
    int n;
    scanf("%d", &n);
    int k = 1;
    while(k*(k-1)/2 < n) k++;
    if(k*(k-1)/2 != n)
    {
        puts("No");
        return 0;
    }
    else
    {
        int cnt = 0;
        for(int i=1;i<=k;i++)
        {
            for(int j=i+1;j<=k;j++)
            {
                v[i].push_back(cnt+1);
                v[j].push_back(cnt+1);
                cnt++;
            }
        }
        puts("Yes");
        printf("%d\n", k);
        for(int i=1;i<=k;i++)
        {
            printf("%d ", v[i].size());
            for(int j=0;j<v[i].size();j++)
            {
                printf("%d", v[i][j]);
                if(j+1 != v[i].size()) putchar(' ');
                else putchar('\n');
            }
        }
    }
}
