#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstdlib>
#include<cmath>
#include<map>
#include<iomanip>
using namespace std;
const long long mod=1000000007;
int main()
{
    long long i,j,n,x,h=0,s;
    cin>>n;    
    vector<long long>a,b,c;
    for(i=1;i<=n;i++)
    {
        cin>>x;
        a.push_back(x);
    }
    for(i=1;i<=n;i++)
    {
        cin>>x;
        b.push_back(x);
    }
    s=(n>>1);
    for(i=s;i<n;i++)
    {
        c.push_back(b[i]);
    }
    for(i=0;i<s;i++)
    {
        c.push_back(b[i]);
    }
        h=0;
        for(j=0;j<n;j++)
        {
            if(a[j]==c[j])
            {
                h++;
                break;
            }
        }
        if(h==0)
        {
            cout<<"Yes"<<endl;
            for(j=0;j<n;j++)
            {
                cout<<c[j]<<" ";
            }
            cout<<endl;
        }
        else
        {
            reverse(b.begin(),b.end());
            h=0;
            for(j=0;j<n;j++)
            {
               if(a[j]==b[j])
               {
                   h++;
                   break;
               }
            }
            if(h==0)
            {
                cout<<"Yes"<<endl;
                for(j=0;j<n;j++)
                {
                    cout<<b[j]<<" ";
                }
                cout<<endl;
            }
            else
            {
                cout<<"No"<<endl;
            }
        }
    return 0;
}
