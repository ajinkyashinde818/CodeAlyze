#include<iostream>
#include<cmath>
#include<bitset>
#include<cstdlib>
#include<cstdio>
#include<vector>
using namespace std;
typedef long long ll;

int main()
{

  int N;
  cin >> N;
  while(N-- > 0)
    {
      ll s;
      cin >> hex >> s;

      bool c = (s>>31)&1?true:false;


      ll a,b,t;
      char *e;
      a = b = s;
      t = strtol("7fffffff",&e,16);
   
      a &= t;
      a >>= 7;
      t = strtol("0000007f",&e,16);
      b &= t;
      bitset<7> dou(b);
      ll new_b = 0;
      vector<ll> val(7);
      val[6] = 5000000;
      for(int i=5;i>=0;i--)
	  val[i] = val[i+1]*0.5;


      for(int i = 6;i>=0;i--)
	{
	  if(dou[i])
	    new_b += val[i];
	}
      if(c)
    cout << "-";
      cout << a;
      cout << ".";
      if(!new_b)
    cout << 0 << endl;
      else
    {
      cout << string(6-(int)log10(new_b),'0');
      while(new_b/10*10 == new_b)
        new_b /= 10;
      cout << new_b << endl;
    }
    }
  return 0;
}
