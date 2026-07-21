#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 7;
typedef long long ll;
int n, m;


int main()
{
    scanf("%d%d", &n, &m);
    if(n >= 10)printf("%d\n", m);
    else{
        printf("%d", m + 100 * (10 - n));
    }

    return 0;
}
