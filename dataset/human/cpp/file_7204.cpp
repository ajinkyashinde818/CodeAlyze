#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;
int main()
{
    int a;
    long long x=0,y=0,mi=0,sum=0;
    int s[200005];
    cin>>a;
    for(int i=0;i<a;i++)
    {
        cin>>s[i];
    }
    for(int i=0;i<a;i++)
    {
        sum+=s[i];
        mi+=abs(s[i]);
    }
    for(int i=0;i<a-1;i++)
    {
        x+=s[i];
        y=sum-x;
       if(x-y<0)
       {
           if(mi>y-x) mi = y-x;
       }
       if(x-y>=0)
       {
           if(mi>x-y) mi = x-y;
       }
    }
    cout<<mi<<endl;
}
