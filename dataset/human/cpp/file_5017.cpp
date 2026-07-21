#include <iostream>
using namespace std;

int inner()
{
  int contest, display, inner;
  inner = 0;
  cin >> contest >> display;
  if(contest >= 10)
  {
    return display;
  }
  else
  {
   inner = display + (100 * (10 - contest));
   return inner;
  }
}
int main()
{
  cout << inner() << endl;
}
