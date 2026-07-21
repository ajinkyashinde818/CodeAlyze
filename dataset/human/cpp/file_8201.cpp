#include<iostream>

using namespace std;

int main(){
  long long int n,sm=0,mn=2e15,a[200009];
  cin >> n;
  for(int i=0;i<n;i++){
    cin >> a[i];
    sm+=a[i];
  }
  long long lsm=0;
  for(int i=0;i<n-1;i++){
    lsm+=a[i];
    sm-=a[i];
    mn = min(mn , abs(lsm-sm));
  }
  cout << mn << endl;
}
