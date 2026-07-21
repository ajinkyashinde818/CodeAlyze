#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
int n,a[300001],b[300001],f1[300001],f2[300001],sol[300001],aux[300001];
set<pii> s;
set<int> s2;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        f1[a[i]]++;
    }
    bool ok=1;
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
        if(a[i]==b[i])
            ok=0;
        f2[b[i]]++;
        s2.insert(b[i]);
    }
    for(int i=1;i<=n;i++)
    {
        if(f2[i]>0)
            s.insert({f1[i],i});
        aux[i]=f2[i];
    }
    if(ok)
    {
        cout<<"Yes\n";
        for(int i=1;i<=n;i++)
            cout<<b[i]<<" ";
        return 0;
    }
    for(int i=1;i<=n;i++)
        if(f1[i]>n/2&&f2[i]>n/2)
        {
            cout<<"No";
            return 0;
        }
    bool found=1;
    for(int i=1;i<=n;i++)
    {
        bool deleted=0;
        if(f2[a[i]]>0)
        {
            s.erase({f1[a[i]],a[i]});
            deleted=1;
        }
        if(s.empty())
        {
            found=0;
            break;
        }
        auto it=s.end();
        it--;
        int nr=(*it).second;
        sol[i]=nr;
        f2[nr]--;
        if(f2[nr]==0)
            s.erase({f1[nr],nr});
        if(deleted&&f2[a[i]]>0)
            s.insert({f1[a[i]],a[i]});
        if(f2[a[i]]>0)
        {
            s.erase({f1[a[i]],a[i]});
            f1[a[i]]--;
            s.insert({f1[a[i]],a[i]});
        }
    }
    if(found)
    {
        cout<<"Yes\n";
        for(int i=1;i<=n;i++)
            cout<<sol[i]<<" ";
        return 0;
    }
    for(int i=1;i<=n;i++)
        f2[i]=aux[i];
    for(int i=1;i<=n;i++)
    {
        bool deleted=0;
        if(s2.find(a[i])!=s2.end())
        {
            s2.erase(a[i]);
            deleted=1;
        }
        if(s2.empty())
        {
            cout<<"No";
            return 0;
        }
        auto it=s2.end();
        it--;
        int nr=*it;
        sol[i]=nr;
        f2[nr]--;
        if(f2[nr]<=0)
            s2.erase(nr);
        if(deleted)
            s2.insert(a[i]);
    }
    cout<<"Yes\n";
    for(int i=1;i<=n;i++)
        cout<<sol[i]<<" ";
    return 0;
}
