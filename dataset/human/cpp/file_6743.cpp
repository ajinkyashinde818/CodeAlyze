#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <tuple>
#include <queue>
#include <set>
#include <cstdio>
#include <climits>
#include <cmath>
#include <array>
#include <functional>
#include <list>
#include <iomanip>
#include <set>
#include <cctype>
using namespace std;
typedef string::const_iterator State;
const int MOD=1000000007;
const int INF=1000000000;
typedef long long ll;
typedef vector<int> vi;
const double eps=1e-9;
const int inf=1e9;
typedef pair<int,int> P;
ll p=0;
ll q=0;
bool zerodiv=false;
string t;

int Euclid(int a, int b)
{
  if(b>a) swap(a,b);
  if(b==0) return a;
  else
    {
      return Euclid(b,a%b);
    }
}

ll ppow(ll x,ll num,ll mod)
{
  ll ret=1;
  while(num>0)
    {
      if(num&1)
	{
	  ret=(ret*x)%mod;
	}
      x=(x*x)%mod;
      num=num>>1;
    }
  return ret%mod;
}

class Parser{
public:

  ll number(State &begin)
  {
    ll ret=0;
    while(isdigit(*begin))
      {
	ret*=10;
	ret+=(*begin-'0');
	begin++;
      }
    return ret;
  }

  ll expression(State &begin)
  {
    ll ret=term(begin);
    for(;;)
      {
	if(*begin=='+')
	  {
	    begin++;
	    ret=(ret+term(begin))%p;
	  }
	else if(*begin=='-')
	  {
	    begin++;
	    ret=(ret+(p-term(begin)))%p;
	  }
	else
	  {
	    break;
	  }
      }
    return ret%p;
  }

  ll term(State &begin)
  {
    ll ret=factor(begin);
    for(;;)
      {
	if(*begin=='*')
	  {
	    begin++;
	    ret=(ret*factor(begin))%p;
	  }
	else if(*begin=='/')
	  {
	    begin++;
	    State tmp=begin;
	    if(factor(tmp)==0)
	      {
		zerodiv=true;
		return 0;
	      }
	    ret=(ret*(ppow(factor(begin),p-2,p)))%p;
	  }
	else
	  {
	    break;
	  }
      }
    return ret;
  }

  ll factor(State &begin)
  {
    ll ret;
    if(*begin=='(')
      {
	begin++;
        ret=expression(begin);
	begin++;
	return ret;
      }
    else
      {
	ret=number(begin)%p;
      }
    return ret;
  }
};


int main(int argc,char const* argv[])
{
  getline(cin,t);
  zerodiv=false;
  int pindex=0;
  int lindex=0;
  int rindex=0;
  p=0;
  q=0;
  bool pointspawn=false;
  int check=1;
  for(int i=0;i<t.size();i++)
    {
      if(t[i]=='(') lindex=i;
      else if(t[i]==')') rindex=i;
      else if(t[i]=='.') 
	{
	  pointspawn=true;
	  pindex=i;
	}
      else if(pointspawn) check*=10;
    }
  for(int i=0;i<t.size();i++)
    {
      if(t[i]=='.') continue;
      else if(t[i]=='(') break;
      else
	{
	  q*=10;
	  q+=int(t[i]-'0');
	}
    }
  //Parser ps;
  int large=1;
  int small=1;
  int rotation=rindex-pindex-1;
  int ptorota=lindex-pindex-1;
  for(int i=0;i<ptorota;i++)
    {
      small*=10;
    }
  for(int i=1;i<rotation;i++)
    {
      large*=10;
    }
  while (t.find('(') != string::npos)t.erase(t.find('('), 1);
  while (t.find(')') != string::npos)t.erase(t.find(')'), 1);
  while (t.find('.') != string::npos)t.erase(t.find('.'),1);
  while(isdigit(t[0]))
    {
      p*=10;
      p+=int(t[0]-'0');
      t.erase(0,1);
    }
  int molecu;
  if(p!=q)
    {
      molecu=p-q;
    }
  else
    {
      molecu=p;
    }
  int denomi=large-small;
  if(denomi==0)
    {
      denomi=check;
    }
  //cout << molecu << ' ' << denomi << endl;
  while(Euclid(molecu,denomi)!=1)
    {
      int div=Euclid(molecu,denomi);
      molecu/=div;
      denomi/=div;
    }
  cout << molecu << '/' << denomi << endl;
    
  return 0;
}
