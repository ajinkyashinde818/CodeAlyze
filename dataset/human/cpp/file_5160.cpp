#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <iomanip>
#define INF 0x3f3f3f3f
#define MAX_N 1001000
using namespace std;
void optimize_cpp_stdio()
{
    std::ios::sync_with_stdio(false);
    std::cout.tie(NULL);
    std::cin.tie(NULL);
}
int n, r;
int main()
{
    scanf("%d %d", &n, &r);
    if(n < 10)
        r = r + 100 * (10 - n);
    printf("%d\n", r);
}
