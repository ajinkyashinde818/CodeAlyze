#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
  int t,d;
  cin>>t>>d;
  int ta,tb,da,db;
  double ans = 999999999999;
  cin>>ta>>tb>>da>>db;
  for(int i=0;i*da<=d;i++)
    for (int j=0; i*da+j*db<=d; j++) {
      if(i+j==0)
	continue;
      double tmp  = (ta * (i*da*0.1) + tb * (j*db*0.1)) /  ((i*da*0.1) + (j*db*0.1));
      // cerr<<tmp<<endl;
      ans=min(ans,fabs(t-tmp));
    }
  cout<<ans<<endl;
  return 0;
}
