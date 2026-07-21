//#pragma GCC optimize("Ofast")
#include <set>
#include <map>
#include <stack>
#include <cmath>
#include <queue>
#include <bitset>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <tr1/unordered_map>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define bql 2147483647
#define ll long long
#define ull unsigned long long
using namespace std::tr1;
using namespace std;
const int N=2e5+5;
const int mod=998244353;
const int fx[5]={0,-1,0,1,0};
const int fy[5]={0,0,-1,0,1};
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while (ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while (ch>='0' && ch<='9'){x=(x<<3)+(x<<1);x+=(ch-'0');ch=getchar();}
    return x*f;
}

void write(int x)
{
    if (x<0) putchar('-'),x=-x;
    if (x>10) write(x/10);
    putchar(x%10+'0');
}

int main()
{
  fast;
  int n,r;
  cin>>n>>r;
  if (n>=10)
      cout<<r<<endl;
  else
      cout<<r+100*(10-n)<<endl;
  return 0;
}
