#include <bits/stdc++.h>

using namespace std;
int main()
{
    long long n,num,sum=0;
    cin>>n;
    vector<int>v;
    long long  c=0;
    for(long long  i=0;i<n;i++)
    {
        cin>>num;
        if(num<0)
        {
            c++;
        }
        v.push_back(abs(num));
        sum +=abs(num);
    }
    sort(v.begin(),v.end());
    if(c%2==0)
    {
        cout<<sum<<endl;
    }
    else
    {
        cout<<sum-2*v[0]<<endl;
    }
}
