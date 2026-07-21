#include<bits/stdc++.h>
using namespace std;

int main(){
  long n,right = 0,left = 0;
  cin >> n;
  long a[n];
  for(long i = 0;i < n;i++){
    cin >> a[i];
  }
  left = a[0];
  for(long i = 1;i < n;i++){
    right += a[i];
  }
  long kekka = 100000000000000000;
  for(long i = 1;i < n;i++){
    long cur = abs(left - right);
    kekka = min(kekka,cur);
    if(i < n-1){
      left += a[i];
      right -= a[i];
    }
  }
  cout << kekka << endl;
}
