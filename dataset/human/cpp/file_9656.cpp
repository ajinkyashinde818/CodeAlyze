#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <fstream>
#include <map>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <set>
#include <queue>
#include <list>

using namespace std;
char a[55][55],b[55][55];
int main()
{
    int n,m;
    bool ju=false;
    scanf("%d%d",&n,&m);
    //getchar();
    for(int i=0;i<n;++i)
        scanf("%s",a[i]);
    for(int i=0;i<m;++i)
        scanf("%s",b[i]);
    int k=n-m;
    for(int i=0;i<=k;++i)
    {
        if(ju) break;
        for(int j=0;j<=k;++j)
        {
            bool juu=true;
            for(int x=0;x<m;++x)
                for(int y=0;y<m;++y)
            {
                if(a[i+x][j+y]!=b[x][y])
                {
                    juu=false;
                    break;
                }
            }
            if(juu)
            {
                ju=true;
                break;
            }
        }
    }
    if(ju) printf("Yes\n");
    else printf("No\n");
    return 0;
}
