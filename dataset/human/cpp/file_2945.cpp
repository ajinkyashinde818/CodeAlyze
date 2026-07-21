#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

using namespace std;

#define int long long

int32_t main()
{
    int n,sum=0,flag=1e9,fl=0; cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        int temp; cin>>temp;
        a[i]=abs(temp);
        sum+=a[i];
        if(temp<0)
        {
            fl++;
        }
        flag=min(flag,abs(temp));
    }
    if(fl%2==0) cout<<sum;
    else cout<<sum-flag*2;
    return 0;
}
