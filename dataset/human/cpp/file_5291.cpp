#include <bits/stdc++.h>

using namespace std;

const int maxn=1e5+5,mod=1e9+5;

typedef long long ll;

int main()
{
    int n,r;
    while(scanf("%d%d",&n,&r)!=EOF)
    {
       if(n<10)
        printf("%d\n",r+100*(10-n));
       else
        printf("%d\n",r);
    }
    return 0;
}
