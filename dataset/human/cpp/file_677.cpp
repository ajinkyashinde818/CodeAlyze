#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
  int r,g,b,n;
  cin>>r>>g>>b>>n;

  int ans;
  for (int i=0; i*r<=n; i++) {
    for (int j=0; i*r+j*g<=n; j++) {
      if ((i*r+j*g-n)%b==0) ans++;
    }
  }
  cout <<ans<< endl;
  return 0;
}
