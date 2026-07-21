#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    if(n<=10)
    printf("%d\n",k+(10-n)*100);
    else printf("%d\n",k);
    return 0;
}
