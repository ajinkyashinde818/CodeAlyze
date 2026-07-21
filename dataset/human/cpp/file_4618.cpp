#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int main()
{
    int n;
    int r;
    scanf("%d %d", &n, &r);
    if (n >= 10)
    {
        printf("%d\n", r);
    }
    else
    {
        printf("%d\n", r + 100 * (10 - n));
    }
}
