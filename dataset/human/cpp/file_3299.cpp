#include<vector>
#include<iostream>
#include<algorithm>
#include<functional>
#include<string>
#include<limits.h>
using namespace std;

int main(){
  
  int i,j;
  long int ans=0;
  int m=INT_MAX;
  int minus=0;
  int n; cin >> n;
  vector<int> a(n);
  for (i=0; i<n; i++){
    cin >> a[i];
  }
  
  for (i=0; i<n; i++){
    if (a[i]==0){
      for (j=0; j<n; j++){
        ans += abs(a[j]);
      }
      cout << ans << endl;
      return 0;
    }
  }
  
  for (i=0; i<n; i++){
    if (a[i]<0){
      minus++;
    }
  }
  
  if (minus % 2 == 0){
    for (j=0; j<n; j++){
      ans += abs(a[j]);
    }
  } else {
    for (j=0; j<n; j++){
      m = min(m, abs(a[j]));
    }
    
    for (j=0; j<n; j++){
      ans += abs(a[j]);
    }
    
    ans -= 2*m;
  }
  
  cout << ans << endl;
 
  return 0;
}
