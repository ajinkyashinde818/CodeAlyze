#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a,b,c,n;
    cin >> a >> b >> c >> n;
    vector<int> ab(3001,0),ac(3001,0),bc(3001,0);
    for(int o=0;o<=3000;o++)
    {
        for(int i=0;i<=3000;i++)
        {
            if(a*o+b*i<=3000) ab[a*o+b*i]++;
            if(a*o+c*i<=3000) ac[a*o+c*i]++;
            if(b*o+c*i<=3000) bc[b*o+c*i]++;
        }
    }
    int res=0;
    for(int i=0;i<=3000;i++) if(a*i<=n) res+=bc[n-a*i];
    for(int i=0;i<=3000;i++) if(b*i<=n) res+=ac[n-b*i];
    for(int i=0;i<=3000;i++) if(c*i<=n) res+=ab[n-c*i];
    cout << res/3 << endl;
    return 0;
}
