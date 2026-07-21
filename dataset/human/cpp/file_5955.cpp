#include<bits/stdc++.h>
using namespace std;
struct masivs{long long val;long long poz;};
masivs r1[110005],g[110005];
long long i,j,n,m,mas[110005][2],x1[110005],d1[110005],d2,r2,x2,rez,liel,x,y,p1,p2;
bool c1(masivs maz,masivs liel)
{
    if (maz.val==liel.val)
    {
        return maz.poz>liel.poz;
    }
    return maz.val>liel.val;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    cin >> n >> m;
    i=1;
    while (i<=n)
    {
        cin >> mas[i][0] >> mas[i][1];
        i++;
    }
    j=1;
    mas[0][0]=0;
    mas[0][1]=0;
    while (j<=n)
    {
        d1[j]=mas[j][0]-mas[j-1][0]+d1[j-1];
        x1[j]=mas[j][1]+x1[j-1];
        r1[j].val=x1[j]-d1[j];
        r1[j].poz=j;
        g[j].val=x1[j]-2*d1[j];
        g[j].poz=j;
        rez=max(rez,r1[j].val);
        //cout << j << " " << r1[j] << "\n";
        j++;
    }
    r1[0].val=-1;
    r1[0].poz=-1;
    g[0].val=-1;
    g[0].poz=-1;
    sort(r1,r1+n+1,c1);
    sort(g,g+n+1,c1);
    x=r1[0].poz;
    p1=1;
    y=g[0].poz;
    p2=1;
    //cout << x << " " << y << "  " << x1[x] << " " << d1[x] << " " << x1[y] << " " << d1[y] << "\n";
    i=0;
    mas[n+1][0]=m;
    while (n-i<=x)
    {
        x=r1[p1].poz;
        p1++;
    }
    while (n-i<=y)
    {
        y=g[p2].poz;
        p2++;
    }
    while (i<n)
    {
        //cout << i << " " << x << " " << y << " " << n-i << "  ";
        d2+=mas[n-i+1][0]-mas[n-i][0];
        x2+=mas[n-i][1];
        rez=max(rez,x1[x]-d1[x]+x2-2*d2);
        rez=max(rez,x1[y]-2*d1[y]+x2-d2);
        //cout << d2 << " " << x2 << " " << x1[x] << " " << d1[x] << " " << d1[y] << " " << x1[y] << "\n";
        i++;
        while (n-i<=x)
        {
            x=r1[p1].poz;
            p1++;
        }
        while (n-i<=y)
        {
            y=g[p2].poz;
            p2++;
        }
    }
    cout << rez;
    return 0;
}
