#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pa;
const int maxn=2e5+7;
const int mod=1e9;
int n,t,m;
char a[maxn];
int main()
{
    scanf("%d%d",&n,&m);
    printf("%d\n",max(100*(10-n),0)+m);
    return 0;
}
