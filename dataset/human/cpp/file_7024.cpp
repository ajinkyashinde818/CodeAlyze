#include <iostream>

using namespace std;
int n,i,p,l,r,c,nr;
int a[200005];
int b[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;
    for(i=1;i<=n;i++)
        cin>>a[i];
    for(i=1;i<=n;i++)
        cin>>b[i];

    for(i=1;i<=n/2;i++)
        swap(b[i], b[n-i+1]);

    for(i=1;i<=n;i++)
    {
        if(a[i]==b[i])
        {
            if(!c)
                l=i;
            r=i;
            c=a[i];
        }
    }

    if(!c)
    {
        cout<<"Yes\n";
        for(int i=1;i<=n;i++)
            cout<<b[i]<<' ';
        return 0;
    }

    nr=0;
    for(i=1;i<=n;i++)
    {
        if(a[i]==c)
            nr++;
        if(b[i]==c)
            nr++;
    }
    if(nr>n)
    {
        cout<<"No";
        return 0;
    }

    p=l;
    for(i=1;i<=n;i++)
    {
        if(a[i]==c)
            continue;
        if(b[i]==c)
            continue;

        if(p>r)
            break;

        swap(b[i], b[p]);
        p++;
    }

    cout<<"Yes\n";
    for(i=1;i<=n;i++)
        cout<<b[i]<<' ';
    return 0;
}
