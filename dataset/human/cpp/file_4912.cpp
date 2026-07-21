#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    int a, b;
    while(scanf("%d %d", &a, &b)!= EOF){
        int res = a > 10?b:100 * (10 - a) + b;
        printf("%d\n", res);
    }
    return 0;
}
