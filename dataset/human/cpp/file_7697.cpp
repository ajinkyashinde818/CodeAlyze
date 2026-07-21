#include<iostream>
#include<iomanip>
#include<queue>
#include<string>
#include<stack>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<cassert>
#include<ctime>
#include<algorithm>
#include<utility>
#include<map>
#include<set>
#include<vector>
#include<functional>

using namespace std;

#ifdef DEBUG
#define dprintf      printf
#define dout(x)      cout<<#x" = "<<(x)<<endl
#define darray(x,n)    {int i;rep(i,n)cout<<#x"["<<i<<"] = "<<*((x)+i)<<endl;}
#define dloop(i,s,g) for((i)=(s);(i)<(g);(i)++)
#define drep(i,n)    for((i)=0;(i)<(n);(i)++)
#define dstop()      scanf("%*c")
#else
#define dprintf      (1)?0:printf
#define dout(x)
#define darray(x,n)
#define dloop(i,s,g) if(1){}else
#define drep(i,n)    if(1){}else
#define dstop()      if(1){}else
#endif

#define F    first
#define S    second
#define pb   push_back
#define mp   make_pair

#define loop(i,s,g) for((i)=(s);(i)<(g);(i)++)
#define rep(i,n)    for((i)=0;(i)<(n);(i)++)
#define all(x)      (x.begin(),x.end())
#define in(T,...) T __VA_ARGS__; impl(__VA_ARGS__);
#define array(T,id,n) T id[n]; rep(i,n)cin>>id[i];

//#define int long long;
#ifndef int
#define INF (0x7fffffff)
#else
#define INF (0x7fffffffffffffff)
#endif

typedef  long long           ll;
typedef  unsigned            ui;
typedef  unsigned long long  ull;
typedef  pair<int,int>       i_i;
typedef  pair<ll,int>        ll_i;
typedef  pair<ll,ll>         ll_ll;
typedef  pair<double,int>    d_i;
typedef  pair<double,double> d_d;

void impl(){};
template <typename T,typename... TS >
void impl(T &head,TS &... tail)
{
  cin>>head;
  impl(tail ...);
}

signed main(void)
{
  in(int,n);
  long long a[212345]={};
  int i;
  int temp;
  int sum=0;
  long long sumf[212345]={};
  long long sumb[212345]={};
  cin>>a[0];
  sumf[0]+=a[0];
  loop(i,1,n)
    {
      cin>>a[i];
      sumf[i]+=sumf[i-1]+a[i];
    }
  sumb[n-1]=a[n-1];
  loop(i,1,n)
    sumb[n-i-1]+=sumb[n-i]+a[n-i-1];
  darray(sumf,n);
  darray(sumb,n);
  int min=INF;
  rep(i,n-1)
    if(min>abs(sumf[i]-sumb[i+1]))min=abs(sumf[i]-sumb[i+1]);
  
  /*
  cin>>a[0];
  for(i=1;i<n;i++)
    {
      cin>>temp;
      a[i]=temp*2+a[i-1];
    }
  *//*
  darray(a,n);
 
  dout(sum);
  int f=1,b=n-2;
  int sf=a[0],sb=a[n-1];
  rep(i,n-2)
    {
      if(abs((sf+a[f])-sb)>abs(sf-(sb+a[b])))
	sb+=a[b--],dout(sb);
      else
	sf+=a[f++],dout(sf);
    }
    cout<<abs(sf-sb)<<endl;*/
  cout<<min<<endl;
  return 0;
}
