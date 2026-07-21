#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <fstream>
#include <sstream>
#include <map>
#include <set>
#include <string>
#include <cstdlib>
#include <vector>
#include <cassert>
#include <cctype>
using namespace std;
typedef long long ll;

const int MAXN=200000+10;
int a[MAXN];

int main()
{
    int n;
    ll minn=0,x=0,y=0,sum=0;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    /*for(int i=0;i<n;i++)
        cout<<a[i]<<endl;*/
    for(int i=0;i<n;i++)
    {
        sum+=a[i];
        minn+=abs(a[i]);
    }
    //cout<<sum<<endl;
    for(int i=0;i<n-1;i++)
    {
        x+=a[i];//cout<<x<<endl;
        y=sum-x;//cout<<y<<endl;
        if(x-y<0)
        {
            if(minn>y-x)minn=y-x;
        }
        else if(x-y>=0)
        {
            if(minn>x-y)minn=x-y;
        }
    }
    cout<<minn<<endl;
    return 0;
}
