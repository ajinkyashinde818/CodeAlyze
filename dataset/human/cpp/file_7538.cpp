#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  long long p=0;
  for(int i=0;i<n;i++){
    cin >> a[i];
    p+=a[i];
  }
  
  long long ans=pow(10,14);
  long long q=0;
  
  for(int i=0;i<n-1;i++){
    q+=a[i];
    p-=a[i];
    ans=min(ans,max(p-q,q-p));
  }
  
  cout << ans << endl;
}
