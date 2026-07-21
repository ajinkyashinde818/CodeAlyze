#include<bits/stdc++.h>
using namespace std;
int a[200050],b[200050],n;
int main()
{   
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++) scanf("%d",&b[i]);
        reverse(b+1,b+1+n);
        vector<int> p,q;
        int val=0,cnt=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]!=b[i]) continue;
            cnt++;
            p.push_back(i);
            val=b[i];
        }
        for(int i=1;i<=n;i++)
        {
            if(!cnt) break;
            if(a[i]==b[i]) continue;
            if(a[i]!=val&&b[i]!=val)
            {
                cnt--;
                q.push_back(i);
            }
        }
        if(cnt) return cout<<"No\n",0;
        for(int i=0;i<q.size();i++) swap(b[p[i]],b[q[i]]);
        cout<<"Yes\n";
        for(int i=1;i<=n;i++) cout<<b[i]<<' ';
        cout<<'\n';
        return 0;
}
