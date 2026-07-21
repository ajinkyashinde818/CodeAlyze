#include <iostream>
#include <algorithm>

using namespace std;

long long N, C, cal;
long long x[100002],v[100002],a[100002],b[100002],c[100002],d[100002],e[200002];

int main(){
  cin >> N >> C;
  int i;
  x[0]=0;
  cal=0;
  a[0]=0;
  int amaxi=0;
  for (i=1;i<=N;++i) {
    cin >> x[i] >> v[i];
    cal += v[i] - (x[i] - x[i-1]);
    a[i] = cal;
    if (a[amaxi] < a[i]) {
      amaxi=i;
    }
    c[i] = a[amaxi];
  }
  cal=0;
  x[N+1] = C;
  b[N+1] = 0;
  int bmaxi=N+1;
  for (i=N;i>0;--i) {
    cal += v[i] - (x[i+1] - x[i]);
    b[i] = cal;
    if (b[bmaxi] < b[i]) {
      bmaxi=i;
    }
    d[i] = b[bmaxi];
  }
  cal=c[N];
  if (d[1]>cal) {
    cal=d[1];
  }
  for (i=1;i<=N;++i) {
    if (a[i]-x[i]+d[i+1] > cal) {
      cal=a[i]-x[i]+d[i+1];
    }
    if (b[i]-(C-x[i])+c[i-1] > cal) {
      cal=b[i]-(C-x[i])+c[i-1];
    }
  }
  cout << cal << endl;
  return 0;
}
