#include<set>
#include<map>
#include<list>
#include<queue>
#include<stack>
#include<string>
#include<math.h>
#include<time.h>
#include<vector>
#include<bitset>
#include<memory>
#include<utility>
#include<fstream>
#include<stdio.h>
#include<sstream>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
long long x[100005],v[100005];
long long ans1[100005];
long long ans2[100005];
long long sum[100005];
multiset<long long> s;
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n;
    long long c;
    cin>>n>>c;
    int i;
    for (i=0;i<n;i++)
    {
        cin>>x[i]>>v[i];
    }
    for (i=0;i<n;i++)
    {
        sum[i+1]=sum[i]+v[i];
    }
    long long max_ans=0;
    for (i=0;i<n;i++)
    {
        ans1[i]=sum[i+1]-x[i];
        ans2[i]=(sum[n]-sum[i])-(c-x[i]);
    }
    s.erase(s.begin(),s.end());
    s.insert(0);
    for (i=0;i<n;i++)
    {
        max_ans=max(max_ans,ans2[i]-(*s.begin()));
        s.insert(-ans1[i]+x[i]);
    }
    s.erase(s.begin(),s.end());
    s.insert(0);
    for (i=n-1;i>=0;i--)
    {
        set<int>::iterator ii;
        max_ans=max(max_ans,ans1[i]-(*s.begin()));
        s.insert(-ans2[i]+(c-x[i]));
    }
    cout<<max_ans<<endl;
    return 0;
}
