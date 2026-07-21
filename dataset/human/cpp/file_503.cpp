#include <iostream>
using namespace std;
int main()
{
  int r, g, b, n;
  cin >> r >> g >> b >> n;
  int c = 0;
  for(int rc=0;rc<=n;rc++)
  {
      for(int gc=0;gc<=n;gc++)
      {
          if((n-rc*r-gc*g)%b==0&&(n-rc*r-gc*g>=0))
          {
              //cout<<rc<<" "<<gc<<" "<<(n-rc*r-gc*g)/b<<"\n";
              c++;
          }
      }
  }
  cout<<c;
  return 0;
}
