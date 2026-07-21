#include <bits/stdc++.h>

int main()
{
    int n;
    scanf("%d", &n);

    long long *a = new long long[n + 1];
    a[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", a + i);
        a[i] += a[i - 1];
    }
    const long long sum = a[n];
    long long min{10000000000000000};
    for (int i = 1; i < n; i++)
    {
        min = std::min(min, std::abs(a[i] - (sum - a[i])));
    }
    printf("%lld\n", min);

    
    delete[] a;
    return 0;
}
