#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; 
  cin >> n;
  int a[n];
  long long x=0;
  for(int i=0;i<n;i++){
    cin >> a[i];
    x+=a[i];
  }
  
  
  long long rex=0;
  long long ans=1000000000000000000;
  for(int i=0;i<n-1;i++){
    rex+=a[i];
    long long ansd=abs(x-2*rex);
    ans=min(ans,ansd);
  }
  cout << ans << endl;
}
