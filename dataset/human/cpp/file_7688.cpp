#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >>n;
  vector<long> a(n);
  long sum = 0;
  for (int i=0; i<n; i++){
    cin >> a.at(i);
    sum += a.at(i);
  }
  
  long bufsum=0;
  long minsub=2000000000;
  long bufsub;
  for (int i=0; i<n-1; i++){
    bufsum += a.at(i);
    if (bufsum<=sum/2){ bufsub = (sum-bufsum)-bufsum;}
    else{ bufsub = bufsum-(sum-bufsum);}
    minsub = min(minsub, bufsub);
  }
  cout <<minsub <<endl;
}
