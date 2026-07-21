#include <unordered_set>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <cstring>
#include <cassert>
#include <fstream>
#include <climits>
#include <cstdio>
#include <vector>
#include <string>
#include <memory>
#include <queue>
#include <cmath>
#include <list>
#include <set>
#include <map>


using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

const int maxn=2e5+10;
int main()
{
  int n;
  ll a[maxn];
  scanf("%d",&n);
  ll sum=0;
  for(int i=0;i<n;sum+=a[i],i++)
    scanf("%lld",&a[i]);
  ll res=0;
  ll now=0;
  for(int i=0;i<n-1;i++)
  {
    now+=a[i];
    if(i==0) res=abs(sum-now-now);
    else res=min(abs(sum-now-now),res);
  }
  cout<<res<<endl;
  return 0;
}
