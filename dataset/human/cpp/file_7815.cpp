#include<bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  vector<int> a(n);
  
  long long parsum = 0;
  long long sum = 0;
  
  for(int i = 0; i < n; i++){
    cin >> a.at(i);
    sum += a.at(i);
  }
  
  long long min_dif = LONG_LONG_MAX;
  
  for(int i = 0; i < n - 1; i++){
    parsum += a.at(i);
    long long dif = abs(2 * parsum - sum);
    if(dif < min_dif){
      min_dif = dif;
    }
  }
    
      
  cout << min_dif << endl;
  
    

}
