#include <bits/stdc++.h>
 
using namespace std;
  
long snk, ari, a[223456];

int main(){
  int n;
  scanf("%d", &n);
  
  for (int i = 0; i < n; i++){
  	scanf("%ld", a + i);
  }

  long ans = 12345678901;

  long sum;
  for (int i = 0; i < n; i++){
  	sum += a[i];
  }

  snk = 0;
  ari = sum;

  for (int i = 0; i < n - 1; i++){
  	snk += a[i];
  	ari -= a[i];
  	ans = min(ans, abs(snk - ari));
  }

  cout << ans << endl;

  return 0;
}
