#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  long long sum=0;
  int count = 0;
  
  vector<long long> a(N);
  for (int i=0; i<N ;i++){
    cin >> a.at(i);
    
    if(a.at(i)<0){
      a.at(i) = a.at(i)*(-1);
      count ++ ;
    }
    
    sum = sum + a.at(i);
  }
  
  sort(a.begin(),a.end());
  
  if(a.at(0)!=0 && count%2==1){
    cout << sum - 2*a.at(0) << endl;
  }
  else{
    cout << sum << endl;
  }
  
  
}
