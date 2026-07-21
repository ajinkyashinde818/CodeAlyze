#include <iostream>
using namespace std;

static const int MAX_N = 100000;

long long N, C;
long long x[MAX_N], v[MAX_N];
long long l[MAX_N], r[MAX_N];
long long lmax[MAX_N], rmax[MAX_N];

int main(int argc, char* argv[]){
  cin >> N >> C;
  for(int i = 0; i < N; i++)
	cin >> x[i] >> v[i];
  l[0] = v[0];
  r[N-1] = v[N-1];
  for(int i = 1; i < N; i++) l[i] = v[i]+l[i-1];
  for(int i = 0; i < N; i++) l[i] -= x[i];
  for(int i = N-2; i >= 0; i--) r[i] = v[i]+r[i+1];
  for(int i = 0; i < N; i++) r[i] -= (C-x[i]);
  lmax[0] = l[0];
  rmax[N-1] = r[N-1];
  for(int i = 1; i < N; i++) lmax[i] = max(lmax[i-1], l[i]);
  for(int i = N-2; i >= 0; i--) rmax[i] = max(rmax[i+1], r[i]);
  for(int i = 0; i < N-1; i++) l[i] = max(l[i], l[i]-x[i]+rmax[i+1]);
  for(int i = N-1; i >= 1; i--) r[i] = max(r[i], r[i]-(C-x[i])+lmax[i-1]);
  long long ans = 0;
  for(int i = 0; i < N; i++){
	if(l[i] > ans) ans = l[i];
	if(r[i] > ans) ans = r[i];
  }
  cout << ans << endl;
  return 0;
}
