#include <cstdio>
#include <climits>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void)
{
  int t,ta,tb,d,da,db;
  scanf("%d%d%d%d%d%d",&t,&d,&ta,&tb,&da,&db);
  double res = LLONG_MAX;
  for( int i = 0; i <= 1000; i++ ) {
    for( int j = 0; j <= 1000; j++ ) {
      int v = da*i+db*j;
      if( 1 <= v && v <= d ) {
        double vt = double(ta*da*i+tb*db*j)/v;
        res = min(res,fabs(t-vt));
      }
    }
  }
  printf("%.10f\n",res);
  return 0;
}
