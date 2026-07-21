#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  long long int a[n];
  for(int i=0; i<n; i++){
    cin >> a[i];
  }
  long long int x=a[0];
  long long int y=0;
  for(int i=1; i<n; i++){
    y+=a[i];
  }
  long long int mi = abs(x-y);
  for(int i=1; i<n-1; i++){
    x+=a[i];
    y-=a[i];
    mi = min(mi,abs(x-y));
  }
  cout << mi << endl;
}
