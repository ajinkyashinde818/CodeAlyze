#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> x(n),y(n);
    vector<int> ll(n+1,-1),rr(n+1,-1),uu(n+1,-1),vv(n+1,-1);
    for(auto& xx:x)
    cin>>xx;
    for(auto& xx:y)
    cin>>xx;
    int res=0;
    vector<int> hh(n+1,0);
    for(int k=1,i=0,j=0;k<=n;k++)
    {
        while(i<n and x[i]<k)
        ++i;
        if(i<n and x[i]==k)
        {
            int jj=i;
            while(jj<n and x[jj]==k)
            ++jj;
            tie(ll[k],rr[k])={i,jj};
            i=jj;
        }
        while(j<n and y[j]<k)
        ++j;
        if(j<n and y[j]==k)
        {
            int jj=j;
            while(jj<n and y[jj]==k)
            ++jj;
            tie(uu[k],vv[k])={j,jj};
            j=jj;
        }
        if(~ll[k] and ~uu[k])
        {
            ++res;
            if(rr[k]-ll[k]+vv[k]-uu[k]>n)
            {
                cout<<"No\n";
                return 0;
            }
            if(uu[k]<=ll[k])
            {
                if(vv[k]<=ll[k])
                {
                    ++hh[0];
                    --hh[ll[k]-vv[k]+1];
                    ++hh[rr[k]-uu[k]];
                    --hh[n];
                }
                else
                {
                    ++hh[rr[k]-uu[k]];
                    --hh[ll[k]+n-vv[k]+1];
                }
            }
            else
            {
                ++hh[max(0,rr[k]-uu[k])];
                --hh[ll[k]+n-vv[k]+1];
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        if(hh[i]==res)
        {
            cout<<"Yes\n";
            rotate(y.begin(),y.begin()+n-i,y.end());
            for(auto xx:y)
            cout<<xx<<" ";
            cout<<endl;
            return 0;
        }
        hh[i+1]+=hh[i];
    }
    return 0;
}
