#include <cmath>
#include <cstdlib>
#include <cstdio>
inline int getInt(){ int s; scanf("%d", &s); return s; }

#include <set>
using namespace std;

int main(){
  const int t = getInt();
  const int d = getInt();
  const int ta = getInt();
  const int tb = getInt();
  const int da = getInt();
  const int db = getInt();

  double ans = 1e10;

  for(int i = 0; i * da <= d; i++){
    for(int j = 0; i * da + j * db <= d; j++){
      if(i + j == 0) continue;
      ans = min(ans, fabs(t - (double)(ta * i * da + tb * j * db) / (da * i + db * j)));
    }
  }

  printf("%.9f\n", ans);

  return 0;
}
