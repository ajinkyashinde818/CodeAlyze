#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
int main()
{
    int a, b;
    scanf("%d%d",&a, &b);
    if(a < 10)
    printf("%d\n", 100 * (10 - a) + b);
    else printf("%d\n",b);
    return 0;
}
