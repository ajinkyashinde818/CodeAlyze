#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int N, arr[100005];
long long memo[2][100005];

long long func(int flag, int idx)
{
    if(idx == N - 1)
    {
        if(flag == 1)
        {
            return arr[idx] * -1;
        }
        return arr[idx];
    }
    long long &ret = memo[flag][idx];
    if(ret != -1)
    {
        return ret;
    }
    ret = 0;
    if(flag == 1)
    {
        ret = max(ret, func(0, idx + 1) + arr[idx] * -1);
        ret = max(ret, func(1, idx + 1) + arr[idx]);
    }
    else
    {
        ret = max(ret, func(0, idx + 1) + arr[idx]);
        ret = max(ret, func(1, idx + 1) + arr[idx] * -1);
    }
    return ret;
}

int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }
    memset(memo, -1, sizeof memo);
    printf("%lld", func(0, 0));
}
