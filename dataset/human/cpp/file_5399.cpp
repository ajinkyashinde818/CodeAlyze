#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

template <class T>
inline void read(T &x)
{
    x = 0;
    int f = 0;
    char ch = getchar();
    while (!isdigit(ch))    { f |= ch == '-'; ch = getchar(); }
    while (isdigit(ch))     { x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar(); }
    x = f ? -x : x;
    return;
}

int n, r;

int main()
{
    read(n), read(r);
    printf("%d\n", n < 10 ? 100 * (10 - n) + r : r);
    return 0;
}
