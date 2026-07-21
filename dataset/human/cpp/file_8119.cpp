#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  long a[n];
  int i;
  for(i=0;i<n;i++){
    cin >> a[i];
  }
  long long s[n];
  s[0] = a[0];
  for(i=1;i<n;i++){
    s[i] = a[i] + s[i-1];
  }
  long long minn = abs(s[n-1]-2*s[0]);
  long long tmp;
  for(i=1;i<n-1;i++){
    tmp = abs(s[n-1]-2*s[i]);
    if(tmp<minn)minn=tmp;
  }
  cout << minn;
}
