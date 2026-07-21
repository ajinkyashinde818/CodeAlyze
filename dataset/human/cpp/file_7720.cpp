#include <algorithm>
#include <functional>
#include <iostream>
#include <limits.h>
#include <stdio.h>
#include <vector>

using namespace std;

int main()
{
    int n;

    scanf("%d", &n);

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        scanf(" %d", &a[i]);
    }

    long s = 0;

    for (int i = 0; i < n; i++) {
        s += a[i];
    }

    cerr << s << endl;

    long m = LONG_MAX;
    long ps = 0;

    for (int i = 0; i < n; i++) {
        ps += a[i];

        if (i == n-1)
            continue;

        m = min(m, abs(2 * ps - s));
    }

    printf("%ld", m);
}
