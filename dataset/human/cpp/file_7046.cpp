#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  int a[n];
  int b[n];
  for(int i=0; i<n; i++) cin>>a[i];
  for(int i=0; i<n; i++) cin>>b[i];

  int count[n+1];
  for(int i=0; i<n+1; i++) count[i]=0;
  for(int i=0; i<n; i++) {
    count[a[i]]++;
    count[b[i]]++;
  }

  int ma = *max_element(count, count+n+1);
  if(ma>n) {
    cout<<"No"<<endl;
    return 0;
  }

  // int maxnum = max_element(count, count+n) -count;


  int change = n-1;
  int fchange = 0;
  int prev = a[0];
  if(a[0]==b[0]) {
    swap(b[0], b[change]);
    change--;
  }
  for(int i=1; i<n; i++) {
    if(a[i]!=prev) {
      prev = a[i];
      change = n-1;
      fchange = 0;
    }
    
    if(a[i]==b[i]) {
      if(b[i]!=b[change] && b[i]!=a[change]) {
        swap(b[i],b[change]);
        change--;
      }
      else if(b[i]!=b[fchange] && b[i]!=a[fchange]) {
        swap(b[i],b[fchange]);
        fchange++;
      }
      else {
        fchange++;
        i--;
      }
    }
  }

  cout<<"Yes"<<endl;
  for(int i=0; i<n-1; i++) cout<<b[i]<<' ';
  cout<<b[n-1]<<endl;


  return 0;
}
