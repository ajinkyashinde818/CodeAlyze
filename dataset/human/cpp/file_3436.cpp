#include<bits/stdc++.h>
using namespace std;

int main(){
  long n, count=0, ans=0;
  cin >> n;
  vector<long> a(n);
  for(int i=0;i<n;i++){
    cin >> a[i];
    if(a[i]<=0){
      count+=1;
    }
  }
  if(count%2==0){
    for(int i=0;i<n;i++){
      if(a[i]<0){
        a[i] = (-1) * a[i];
      }
      ans+=a[i];
    }
  }else{
    ans=0;
    for(int i=0;i<n;i++){
      if(a[i]<0){
        a[i] = (-1) * a[i];
      }
      ans+=a[i];
    }
    sort(a.begin(), a.end());
    ans -= 2*a[0];
  }
  cout << ans << endl;
}
